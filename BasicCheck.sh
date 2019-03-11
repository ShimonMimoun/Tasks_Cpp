#!/bin/bash
folderName=$1
execute=$2
cd $folderName
make &> /dev/null
if [ $? -gt 0 ] 
then
Compilation=1; 
else
Compilation=0;

   valgrind --tool=memcheck ${@:3} --leak-check=full --error-exitcode=1 -q ./$program &> /dev/null
    if [ $? -gt 0 ] 
    then
    MemoryLeak=1;
    else
    MemoryLeak=0;
    fi

 valgrind --tool=helgrind --error-exitcode=1 -q ./$program &> /dev/null
    if [ $? -gt 0 ] 
    then
    ThreadTrace=1;
    else 
    ThreadTrace=0;
    fi
 fi   


answer=$Compilation$MemoryLeak$ThreadTrace

if [ $answer == '000' ] 
then
    echo "Compilation-PASS   Memory leaks-PASS   Thread race-PASS"
    exit 0
elif [ $answer == '001' ] 
then
      echo "Compilation-PASS   Memory leaks-PASS   Thread race-FAIL"
      exit 1
elif [ $answer == '010' ] 
then
      echo "Compilation-PASS   Memory leaks-FAIL   Thread race-PASS"
      exit 2
elif [ $answer == '011' ] 
then 
      echo "Compilation-PASS   Memory leaks-FAIL   Thread race-FAIL"
      exit 3
else 
      echo "Compilation-FAIL   Memory leaks-FAIL   Thread race-FAIL"
      exit 7
fi

#!/bin/bash
folderName=$1
execute=$2
cd $folderName
make
if [ $? -gt 0 ] 
then
Compilation=1; 
else
Compilation=0;

    valgrind --leak-check=full -v ./$execute > memoryleaks.txt 2>&1
    grep -q "no leaks are possible"  memoryleaks.txt
    if [ $? -gt 0 ] 
    then
    MemoryLeak=1;
    else
    MemoryLeak=0;
    fi

    valgrind --tool=helgrind $folderName/$execute > Threadcheck.txt 2>&1
    grep -q "ERROR SUMMARY: 0 errors" Threadcheck.txt
    if [ $? -gt 0 ] 
    then
    ThreadTrace=1;
    else 
    ThreadTrace=0;
    fi
 fi   
rm memoryleaks.txt
rm Threadcheck.txt

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
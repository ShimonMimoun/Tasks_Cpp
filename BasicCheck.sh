#!/bin/bash

folderName=$1
execute=$2
cd $folderName
make &> /dev/null



if [ $? -gt 0 ]; then
   Compil=1
else
    Compil=0

 valgrind --leak-check=full -v ./$execute > memoryleaks.txt 2>&1
 grep -q "no leaks are possible"  memoryleaks.txt
    if [ $? -gt 0 ]; then
       MemoLa=1
    else
       MemoLa=0
    fi
 
valgrind --tool=helgrind $folderName/$execute > Threadcheck.txt 2>&1
grep -q "ERROR SUMMARY: 0 errors" Threadcheck.txt    if [ $? -gt 0 ]; then 
       TreadTemp=1
    else
       TreadTemp=0
    fi
fi

rm memoryleaks.txt
rm Threadcheck.txt
answer=$Compil$MemoLa$TreadTemp

if [ $answer == '000' ]; then
    echo "Compilation succes  Memory leaks succes Thread succes"
    exit 0
elif [ $answer == '001' ]; then
      echo "Compilation succes   Memory leaks succes   Thread FAIL   "
      exit 1
elif [ $answer == '010' ]; then
      echo "Compilation- ucces   Memory leaks FAIL   Thread succes  "
      exit 2
elif [ $answer == '011' ];then 
      echo "Compilation succes   Memory leaks FAIL   Thread Fail"
      exit 3
else 
      echo "Compilation FAIL   Memory leaks FAIL   Thread FAIL "
      exit 7
fi



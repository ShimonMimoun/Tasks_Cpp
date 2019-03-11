#!/bin/bash

folderName=$1
execute=$2
cd $folderName
make 



if [ $? -eq 0 ]; then
   Compil=0
else
    Compil=1



    valgrind --tool=memcheck ${@:3} --leak-check=full --error-exitcode=1 -q ./$execute &> /dev/null
    if [ $? -eq 0 ]; then
       MemoLa=0
    else
       MemoLa=1
    fi
  valgrind --tool=helgrind --error-exitcode=1 -q ./$execute &> /dev/null
    if [ $? -eq 0 ]; then 
       TreadTemp=0
    else
       TreadTemp=1
    fi 
fi
exittemp=$Compil$MemoLa$TreadTemp


if [ $exittemp == '000' ]; then
    echo "Compilation-PASS   Memory leaks-PASS   Thread race-PASS"
    exit 0
elif [ $exittemp == '001' ]; then
      echo "Compilation-PASS   Memory leaks-PASS   Thread race-FAIL   ERROR number-001"
      exit 1
elif [ $exittemp == '010' ]; then
      echo "Compilation-PASS   Memory leaks-FAIL   Thread race-PASS   ERROR number-010"
      exit 2
elif [ $exittemp == '011' ];then 
      echo "Compilation-PASS   Memory leaks-FAIL   Thread race-FAIL  ERROR number-011"
      exit 3
else 
      echo "Compilation-FAIL   Memory leaks-FAIL   Thread race-FAIL  ERROR number-111"
      exit 7


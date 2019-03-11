#!/bin/bash

folderName=$1
execute=$2
cd $folderName
make &> /dev/null



if [ $? -gt 0 ]; then
   Compil=1
else
    Compil=0

    valgrind --tool=memcheck ${@:3} --leak-check=full --error-exitcode=1 -q ./$execute &> /dev/null
    if [ $? -gt 0 ]; then
       MemoLa=1
    else
       MemoLa=0
    fi
 
    valgrind --tool=helgrind --error-exitcode=1 -q ./$execute &> /dev/null
    if [ $? -gt 0 ]; then 
       TreadTemp=1
    else
       TreadTemp=0
    fi
fi

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



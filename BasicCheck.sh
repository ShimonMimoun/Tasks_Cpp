#!/bin/bash

folderName=$1
execute=$2
cd $folderName
make 



if [ $? -eq 0 ]; then
   Compil=0
else
    Compil=1

    valgrind --tool=memcheck ${@:3} --leak-check=full --error-exitcode=1 -q ./$execute 
    if [ $? -eq 0 ]; then
       MemoLa=0
    else
       MemoLa=1
    fi
 
    valgrind --tool=helgrind --error-exitcode=1 -q ./$execute 
    if [ $? -eq 0 ]; then 
       TreadTemp=0
    else
       TreadTemp=1
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



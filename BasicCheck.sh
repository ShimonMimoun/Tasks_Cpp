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

if [ $Compil$MemoLa$TreadTemp == '000' ]; then
    echo "Compilation ok "
    echo "Memory leaks ok "
    echo "Thread ok"
    exit 0
elif [ $Compil$MemoLa$TreadTemp == '001' ]; then
      echo "Compilation ok "
      echo "Memory leaks ok "
      echo "Thread FAIL"
      exit 1
elif [ $Compil$MemoLa$TreadTemp == '010' ]; then
      echo "Compilation ok "
      echo "Memory leaks FAIL "
      echo "Thread ok  "
      exit 2
elif [ $Compil$MemoLa$TreadTemp == '011' ]; then 
      echo "Compilation ok "
      echo "Memory leaks FAIL "
      echo "Thread Fail"
      exit 3
else 
      echo "Compilation FAIL "
      echo "Memory leaks FAIL "
      echo "Thread FAIL "
      exit 7
fi



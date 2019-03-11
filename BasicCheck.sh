#!/bin/bash

folderName=$1
execute=$2
make 

if [ $? -gt 0 ]; then
   Compil=1
else
    Compil=0

valgrind --tool=helgrind --error-exitcode=1 -q ./$folderName$execute &> /dev/null
    if [ $? -gt 0 ]; then 
       TreadTemp=1
    else
       TreadTemp=0
    fi 

    valgrind --tool=memcheck ${@:3} --leak-check=full --error-exitcode=1 -q ./$folderName$execute &> /dev/null
    if [ $? -gt 0 ]; then
       MemoLa=1
    else
       MemoLa=0
    fi
  
fi
exittemp=$Compil$MemoLa$TreadTemp
if [ $exittemp == '000' ]; then
    echo "Compilation ok "
    echo "Memory leaks ok "
    echo "Thread ok"
    exit 0
elif [ $exittemp == '001' ]; then
      echo "Compilation ok "
      echo "Memory leaks ok "
      echo "Thread FAIL"
      exit 1
elif [ $exittemp == '010' ]; then
      echo "Compilation ok "
      echo "Memory leaks FAIL "
      echo "Thread ok  "
      exit 2
elif [ $exittemp == '011' ]; then 
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

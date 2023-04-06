#!/bin/bash

if [ $# -ne 1 ]
then
echo "USAGE: $0 [arg]"
exit 1
fi

num=$1
while [ $num -ge 1 ]
do
echo $num
num=$(($num-1))
done
echo "Blast off"
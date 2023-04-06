#!/bin/bash

read -p "Enter a number: " num

while [ $num -lt 0 ]
do
read -p "Enter again " num
done

while [ $num -ge 1 ]
do
echo $num
num=$(($num-1))
done
echo "Blast off"
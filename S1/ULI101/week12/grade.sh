#!/bin/bash

read -p "Enter a grade: " g

while ! echo $g | egrep "^[0-9]{1,}$" > /dev/null 2> /dev/null
do
read -p "Not a valid number. Enter a mark (0-100): " g
done

if [ $g -ge 95 ]
then
echo "A+"
elif [ $g -ge 90 ] && [ $g -lt 95 ]
then
echo "A"
elif [ $g -ge 85 ] && [ $g -lt 90 ]
then
echo "B+"
elif [ $g -ge 80 ] && [ $g -lt 85 ]
then
echo "B"
elif [ $g -ge 75 ] && [ $g -lt 80 ]
then
echo "C+"
elif [ $g -ge 70 ] && [ $g -lt 75 ]
then
echo "C"
elif [ $g -ge 65 ] && [ $g -lt 70 ]
then
echo "D+"
elif [ $g -ge 70 ] && [ $g -lt 65 ]
then
echo "D"
else
echo "Fail"
fi
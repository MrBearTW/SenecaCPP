#!/bin/bash

n=1
for file in $(ls)
do
echo File $n $file
n=$(($n+1))
done
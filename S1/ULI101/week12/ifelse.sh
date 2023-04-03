#!/bin/bash

if test -f $1; then
    echo "Filename is $1"
else
    echo "$1 is not exist"
fi

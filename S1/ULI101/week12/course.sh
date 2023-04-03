#!/bin/bash

course=uli101

read -p "Enter you course: " c

if ["$c"=="$course"]; then
    echo "You are correct"
else
    echo "You are incorrect"
fi

#!/bin/bash

set $(ls)
echo "Number of files in current directory are: $#"
echo "Here are the filenames: "
for f in $*
do
    echo $f
done

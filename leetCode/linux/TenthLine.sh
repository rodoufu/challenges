#!/bin/bash
# https://leetcode.com/problems/tenth-line/
# Read from the file file.txt and output the tenth line to stdout.
input="file.txt"
count=0
while IFS= read -r var
do
    if [ "$count" -eq 9 ]; then
        echo "$var"
    elif [ "$count" -ge 10 ]; then
        break
    fi
    count=$((count + 1))
done < "$input"

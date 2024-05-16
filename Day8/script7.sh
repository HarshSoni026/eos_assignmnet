#!/bin/bash

echo "Enter a number:"
read number

if [ $number -gt 0 ]; then
    echo "$number is a positive number."
elif [ $number -lt 0 ]; then
    echo "$number is a negative number."
else
    echo "$number is zero."
fi

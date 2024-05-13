#!/bin/bash

echo "Enter the number of terms in the Fibonacci series:"
read num_terms

a=0
b=1

echo "Fibonacci series with $num_terms terms:"

for ((i=0; i<num_terms; i++)); do
    echo -n "$a "

    next=$((a + b))
    a=$b
    b=$next
done

echo

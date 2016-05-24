#!/bin/bash

if [ $# -lt 1 ]; then
PROG="./logika3.1.1"
else
PROG=$1
fi

one=( 1 1 7 3)
two=( 2 3 5 1)
three=( 2 2 8 5)
four=( 4 5 11 7)
five=( 8 7 8 14)
six=( 14 3 14 6)
result=( -1 -2 6 5)

for ind in `seq 0 3`; do
        out=` $PROG ${one[$ind]} ${two[$ind]} ${three[$ind]} ${four[$ind]} ${five[$ind]} ${six[$ind]}`
        if [ "$out" != "${result[ind]}" ]
        then
                echo "input: " ${one[$ind]} ${two[$ind]} ${three[$ind]} ${four[$ind]} ${five[$ind]} ${six[$ind]}
                echo "output actual: " $out
                echo "output expected: " ${result[$ind]}
        else
                echo "Results are as expected. "
        fi
done

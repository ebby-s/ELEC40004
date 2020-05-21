#!/bin/bash

g++ P1.cpp -o P1
g++ P2.cpp -o P2

./P1 > P1.out.txt
./P2 > P2.out.txt

if ! diff -w P1.out.txt P1.ref.txt; then
exit 1
fi
if ! diff -w P2.out.txt P2.ref.txt; then
exit 1
fi

rm P1
rm P2
echo "success"



#!/bin/bash

g++ test_Nugget_io.cpp -o test_Nugget

echo "0 0
1 -1
 0 100   0 10003
" | ./test_Nugget > Nugg_test.txt

if ! diff -w test_Nugget_io.txt Nugg_test.txt; then
exit 1
fi

rm test_Nugget
rm Nugg_test.txt
echo "success"


#bin/bash

g++ e4_sort.cpp -o e5_sort
g++ e3_is_sorted.cpp -o e5_is_sorted

if echo 1 6 68 3 8 9 23 9 24 6 1 | ./e5_sort | ./e5_is_sorted; then
echo "success"
fi
rm e5_sort
rm e5_is_sorted

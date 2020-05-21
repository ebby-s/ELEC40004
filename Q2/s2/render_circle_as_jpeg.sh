#bin/bash

g++ e6_circle.cpp -o e8_circle

echo 256 256 | ./e8_circle > e8_test.pgm
convert e8_test.pgm e6_256x256_circle.jpg

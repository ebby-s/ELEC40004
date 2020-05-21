#!/bin/bash

g++ GenA.cpp Proxy_Dst2.cpp Nugget.cpp -o GenA_to_Dst2
g++ GenB.cpp Proxy_Dst2.cpp Nugget.cpp -o GenB_to_Dst2

./GenA_to_Dst2 > GenA.sink2.txt
./GenB_to_Dst2 > GenB.sink2.txt

rm GenA_to_Dst2
rm GenB_to_Dst2



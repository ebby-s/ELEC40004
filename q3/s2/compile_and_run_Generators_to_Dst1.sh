#!/bin/bash

g++ GenA.cpp Proxy_Dst1.cpp Nugget.cpp -o GenA_to_Dst1
g++ GenB.cpp Proxy_Dst1.cpp Nugget.cpp -o GenB_to_Dst1

./GenA_to_Dst1 > GenA.sink1.txt
./GenB_to_Dst1 > GenB.sink1.txt

rm GenA_to_Dst1
rm GenB_to_Dst1

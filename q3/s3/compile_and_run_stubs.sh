#!/bin/bash

g++ ProxyA_Impl1.cpp ProxyA_Impl2.cpp Stub1.cpp ProxyA_factory.cpp -o Stub1
g++ ProxyA_Impl1.cpp ProxyA_Impl2.cpp Stub2.cpp ProxyA_factory.cpp -o Stub2

./Stub1 Impl1 > Stub1.Impl1.txt
./Stub1 Impl2 > Stub1.Impl2.txt
./Stub2 Impl1 > Stub2.Impl1.txt
./Stub2 Impl2 > Stub2.Impl2.txt

if ! diff -w Stub1.Impl1.txt Stub1.Impl1.ref.txt; then
exit 1
fi
if ! diff -w Stub1.Impl2.txt Stub1.Impl2.ref.txt; then
exit 1
fi
if ! diff -w Stub2.Impl1.txt Stub2.Impl1.ref.txt; then
exit 1
fi
if ! diff -w Stub2.Impl2.txt Stub2.Impl2.ref.txt; then
exit 1
fi

rm Stub1
rm Stub2
rm Stub1.Impl1.txt
rm Stub1.Impl2.txt
rm Stub2.Impl1.txt
rm Stub2.Impl2.txt

echo "success"


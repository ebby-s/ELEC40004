#include "ProxyA.hpp"
#include "ProxyA_Impl1.hpp"
#include "ProxyA_factory.hpp"

#include <iostream>

int main(int argc, char **argv)
{
    ProxyA *impl = ProxyA_factory(argv[1]);
    ProxyA &proxy = *impl;

    int x=0;
    for(int i=0; i<11; i++){
        proxy.hhh(to_string(i));
        x += proxy.ggg();
        cout << x << " " << proxy.fff() << endl;
    }
}

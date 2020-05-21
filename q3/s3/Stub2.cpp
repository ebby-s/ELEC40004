#include "ProxyA.hpp"
#include "ProxyA_Impl1.hpp"
#include "ProxyA_factory.hpp"

#include <iostream>

int main(int argc, char **argv)
{
    ProxyA *impl0 = ProxyA_factory(argv[1]);
    ProxyA &p0 = *impl0;
    ProxyA *impl1 = ProxyA_factory(argv[1]);
    ProxyA &p1 = *impl1;

    int x=0;
    for(int i=0; i<10; i++){
        if(i&1){
            p0.hhh("4");
        }else{
            p1.hhh("7");
        }
        
        p0.ggg();
        cout << x << " " << p0.fff() << " " << p1.fff() << endl;
    }
}

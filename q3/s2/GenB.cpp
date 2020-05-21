
#include "Proxy.hpp"

int main()
{
    Proxy a;
    Proxy b;

    a.set_X(-2);
    a.set_Y(2.25f);
    a.set_Z("Blah");

    for(int i=0; i<5; i++){
        a.g();
        a.f(4);
        b.set_Y(i);
        b.f(i);
    }
}

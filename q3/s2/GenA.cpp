#include "Proxy.hpp"

int main()
{
    Proxy c;

    c.set_X(4);
    c.set_Y(4.5);
    c.set_Z("Hello");

    for(int i=0; i<5; i++){
        c.g();
        c.f(4);
    }
}

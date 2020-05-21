#include "E.hpp"
#include <cmath>

int main()
{
    E *c1 = new E("M1");
    E *c2 = new E("M2");

    for(int i=0; i<14; i++){
        c1->add(int(cos(i)*183));
        if(i % 2){
            c2->add(int(cos(i)*183));
        }
    }

    c1->print();
    c2->print();

    c1->destroy();
    c2->destroy();
}

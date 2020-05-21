#include "E.hpp"

#include <cmath>

int main()
{
    E c("S1");

    double running=0;

    for(int i=0; i<14; i++){
        for(int j=0; j<30; j++){
            int ij = i*j;
            c.add(int(sin(ij)*145));
        }

        c.print();

        int accumulator=c.rst();
        running += accumulator;

    }

    cout << running << endl;
}

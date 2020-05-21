#ifndef E_HPP
#define E_HPP

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class E
{
private:
    int n;
    int accumulator;
    string name;

public:

E(string name_in)
{
    n = 0;
    accumulator = 0;
    name = name_in;
}

void destroy()
{
    delete this;
}

void add(float x)
{
    n += 1 ;
    accumulator = accumulator + int(x * 1000) / n;
}

float rst()
{
    float r=accumulator;
    n = 0;
    accumulator = 0;
    return r;
}

void print()
{
    cout << name << " " << n << " " << accumulator << endl;
}
};
#endif

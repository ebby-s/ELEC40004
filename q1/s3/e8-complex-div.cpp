#include <iostream>
#include <cmath>

using namespace std;

struct complex
{
    float real;
    float imag;
};

complex add(complex a, complex b);
complex sub(complex a, complex b);
complex mul(complex a, complex b);
complex div(complex a, complex b);

int main()
{
    complex a;
    complex b;

    cin >> a.real >> a.imag >> b.real >> b.imag;

    complex r = div(a,b);

    cout << r.real << r.imag;
}

// Don't modify anything above this line
///////////////////////////////////////////

// TODO: add a definition of div here
complex div(complex a, complex b){
    float den = b.real*b.real + b.imag*b.imag;
    complex out = {(a.real*b.real + a.imag*b.imag)/den, (a.real*-b.imag + a.imag*b.real)/den};
    return out;
}

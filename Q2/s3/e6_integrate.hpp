#ifndef integrate_hpp
#define integrate_hpp

#include <cassert>

// Prototype of the function to be implemented
// Leave this as just a declaration.
float f(float x);

// Numerically integrate the rectangle/Reimann method
float integrate(float a, float b, int n)
{
    // TODO: Implement me
    float acc = 0;
    for(int i=0;i<n;i++) acc += f(a+i*(b-a)/n);
    return acc/n;

}

#endif

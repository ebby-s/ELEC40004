#include <iostream>

using namespace std;

// TODO: Create a function definition of f here which returns x * 10 + x * x

int f(int x){
    return x*(10+x);
}

int main()
{
    ///////////////////////////
    // Don't modify this part
    int x;
    cin >> x;
    int y;

    /////////////////////////////////////////////////////////////////////
    // TODO: Replace the expression x * 10 + x * x with a call to function f

    y= f(x);

    //////////////////////////
    // Don't modify this part
    cout << y;
}

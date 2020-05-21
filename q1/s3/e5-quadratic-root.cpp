#include <iostream>
#include <cmath>

using namespace std;

float root(float a, float b, float c);

int main()
{
    float a, b, c;
    cin >> a >> b >> c;
    
    cout << root(a, b, c) << endl;
}

// Don't modify anything above this line
///////////////////////////////////////////

// TODO: add function definition here
float root(float a, float b, float c){
    return (-b+pow(b*b-4*a*c,0.5))/(2*c); // Assumes largest root == most positive, not largest magnitude
}

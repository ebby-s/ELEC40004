#include <iostream>

using namespace std;

// TODO : Add declaration here
int madd(int x, float y, int z);
///////////////////////////////////////////
// Don't modify anything below this line

int main()
{
    int x, z;
    float y;
    cin >> x >> y >> z;
    
    cout << madd(x,y,z) << endl;
}

int madd(int x, float y, int z)
{
    return x+(int)(y*z);
}

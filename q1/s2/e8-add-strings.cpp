#include <iostream>

using namespace std;

int main()
{
    ////////////////////////////////////
    // Do not change this section
    string x, y;
    string x_plus_y;
    
    cin >> x >> y; // Reading strings that represent integers x and y

    ///////////////////////////
    // Modify or add code here
    
    int xy_total = stoi(x) + stoi(y);
    x_plus_y = to_string(xy_total);

    /////////////////////////////
    // Do not change this section
    cout << x_plus_y; // Printing out string representing (x+y)
}

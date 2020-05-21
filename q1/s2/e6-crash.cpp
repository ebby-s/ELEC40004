#include <iostream>
#include <string>

using namespace std;

int main()
{
    int x;
    string message = "error";

    cin >> x;

    if(x==17){
        cout << message;
    }else{
        int y = 148 / (x - 17 );
        cout << y;
    }
}

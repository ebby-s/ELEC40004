#include <iostream>
#include <string>

using namespace std;

int main()
{
    string values[5];
    
    int i=0;
    while(1){
        string x;
        cin >> x;
        if(cin.fail()){
            break;
        }
        values[i]=x;
        i++;
    }

    while(i>0){
        i=i-1;
        cout << values[i] << endl;
    }
}

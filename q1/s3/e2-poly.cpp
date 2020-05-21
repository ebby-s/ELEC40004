#include<iostream>

using namespace std;

float polyval(float x){
    return -2-8*x;
}

int main(){
    float x;
    cin >> x;
    cout << polyval(x) << endl;
}

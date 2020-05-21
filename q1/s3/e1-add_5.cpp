#include<iostream>

using namespace std;

int add_5(int n){
    return n+5;
}

int main(){
    int n;
    cin >> n;
    cout << add_5(n) << endl;
}

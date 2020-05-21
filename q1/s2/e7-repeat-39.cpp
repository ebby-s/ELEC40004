#include <iostream>
#include <string>

using namespace std;

int no_loop(int i,string message){
    if(i>0){
        cout << message << endl;
        no_loop(i-1,message);
    }
}

int main(){
    string message;
    cin >> message;
    no_loop(39,message);
}

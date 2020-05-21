#include<iostream>
#include<climits>

using namespace std;

int main(){
    int xi=INT_MIN;
    int xi1;
    while(cin >> xi1){
        if(xi1<xi) return 1;
        xi = xi1;
    }
}

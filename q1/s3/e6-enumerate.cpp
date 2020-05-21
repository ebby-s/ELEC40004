#include<iostream>
#include<vector>

using namespace std;

vector<int> enumerate(int x, int y){
    vector<int> list;

    for(x;x<=y;x++) list.push_back(x);
    return list;
}

int main(){
    int x,y;
    vector<int> out;
    cin >> x >> y;

    out = enumerate(x,y);

    for(int i=0;i<out.size()/2;i++){
        swap(out[i],out[out.size()-i-1]);
    }

    while(!out.empty()){
        cout << out[out.size()-1] << endl;
        out.pop_back();
    }
}

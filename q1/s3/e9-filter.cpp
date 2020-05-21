#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<int> filter(vector<string> values){
    vector<int> out;

    for(int i=0;i<values.size();i++){
        int temp = stoi((string) values[i]);
        if(temp*temp<=5) out.push_back(temp);
    }
    return out;
}

int main(){
    vector<string> values;
    vector<int> out;

    while(!cin.fail()){
    string temp;
    cin >> temp;
    values.push_back(temp);
    }

    values.pop_back();
    out = filter(values);

    for(int i=0;i<out.size();i++) cout << (int) out[i] << " ";
    cout << endl;
}

#include <iostream>
#include <string>
#include <vector>
#include<algorithm>

using namespace std;

int main()
{
    std::vector<float> data;

    while(true){
        float x;
        cin >> x;
        if(cin.fail()){
            break;
        }
        data.push_back(x);
    }

    // TODO : Sort the vector here
    sort(&data[0], &data[0] + data.size());


    for(unsigned i=0; i<data.size(); i++){
        cout << data[i] << endl;
    }
}

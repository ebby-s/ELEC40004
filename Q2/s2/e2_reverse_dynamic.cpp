#include<iostream>

using namespace std;

struct dyn_buff{
    string *start;
    int size;
};

dyn_buff create(int size){
    string *start = new string[size];
    dyn_buff res = {start,size};
    return res;
}

void append(dyn_buff *list, string x){
    string *new_start = new string[list->size+1];

    for(int i=0;i < list->size;i++){
        *(new_start + i) = *(list->start + i);
    }
    *(new_start + list->size) = x;

    delete[] list->start;
    list->start = new_start;
    list->size++;
}

int main()
{
    dyn_buff values = create(5);

    int i=0;
    while(1){
        string x;
        cin >> x;
        if(cin.fail()){
            break;
        }
        if(i>=values.size){
            append(&values,x);
        }else{
            *(values.start+i) = x;
        }
        i++;
    }

    while(i>0){
        i=i-1;
        cout << *(values.start+i) << endl;
    }
}


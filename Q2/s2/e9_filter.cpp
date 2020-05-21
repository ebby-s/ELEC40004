#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

struct person
{
    string name;
    int age;
};

/*  Given a pointer to a vector of persons, return a vector of person pointers.
    Pointers should only be returned to people whose age is greater than the filter parameter.
    The pointers should be in the same order as the elements.
*/
vector<person *> find_by_age( vector<person> *values, int filter )
{
    // TODO(e9) : Implement this function
    vector<person*> pass;

    for(int i=0;i<(*values).size();i++){
        if((*values)[i].age > filter){
            pass.push_back(&((*values)[0]) + i);
        }
    }
    return pass;
}

int main()
{
    // TODO(e10) : create at least one test-case for `find_by_age`
    // - return 0 if successful and 1 if a test fails.
    vector<person> people;
    person x;
    x.name = "bob";
    vector<person *> passed;

    for(int i=0;i<80;i++){
        x.age = i;
        people.push_back(x);
    }

    passed = find_by_age(&people,34);

    for(int j=0;j<passed.size();j++){
cout << passed[j]->age << endl;
        if(j+35!=passed[j]->age) return 1;
    }

}

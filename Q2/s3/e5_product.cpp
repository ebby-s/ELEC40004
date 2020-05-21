#include<iostream>
#include<string>

using namespace std;

int main(int argc,char **argv){
	int acc = 1;
	string arg;
	for(int i=1;i<argc;i++){
		arg = argv[i];
		acc *= stoi(arg);
	}

	cout << acc << endl;
}

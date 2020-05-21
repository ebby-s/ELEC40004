#include<iostream>
#include<cmath>
#include<string>
#include "e6_integrate.hpp"

using namespace std;

float f(float x){
	return sin(x)*exp(-cos(x*x));
}

int main(int argc, char **argv){
	cout << integrate(stof(argv[1]),stof(argv[2]),stof(argv[3])) << endl;
}


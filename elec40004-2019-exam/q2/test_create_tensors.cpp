#include<vector>

#include "tensor.hpp"
#include "matrix_tensor.hpp"
#include "order_3_tensor.hpp"
#include "order_n_tensor.hpp"


using namespace std;

int main(){

	vector<size_t> dims;
	dims.push_back(2);
	dims.push_back(2);
	Tensor *tensor;
	size_t value;

	tensor = create_tensor(dims);
	for(int n=2; n<=5; n++){
		value = 0;
		tensor = create_tensor(dims);
		vector<size_t> indexw;
		first_index(dims, indexw);
		do{
			tensor->write(indexw,value);
			value++;
		}while(next_index(dims, indexw));
                value = 0;
                vector<size_t> indexr;
                first_index(dims, indexr);
                do{
                        assert(value == tensor->read(indexr));
                        value++;
                }while(next_index(dims, indexr));
		dims.push_back(2);
		cout << "Pass " << n << endl;
	}
	cout << "Success" << endl;

}

#include "tensor.hpp"


/*
A 3rd order Tensor is a 3D matrix per say but hollow. When you multiply,
you do (Ai1,Bi1,Ci1).(Ai2,Bi2,Ci2) for all i. Or, if you want,
the multiplication of all corresponding coordinate points.
*/
Tensor *multiply(const Tensor *a, const Tensor *b)
{

        vector<size_t> prod_size, index, index_a, index_b;
	float dot;
	Tensor *prod;

    if(a->size().size()==2 && b->size().size()==2){

	prod_size.push_back(a->size()[0]);
	prod_size.push_back(b->size()[1]);
	prod = create_tensor(prod_size);

    first_index(prod->size(), index);
    do{
	dot = 0;
	index_a = index;
	index_b = index;
	for(size_t i=0; i<a->size()[1]; i++){
		index_a[1] = i;
		index_b[0] = i;
		dot += a->read(index_a) * b->read(index_b);
	}
        prod->write(index, dot);
    }while(next_index(prod->size(), index));

    }else if(a->size().size()==3 && b->size().size()==2){

        prod_size.push_back(a->size()[0]);
	prod_size.push_back(a->size()[1]);
        prod_size.push_back(b->size()[1]);
        prod = create_tensor(prod_size);

    first_index(prod->size(), index);
    do{
        dot = 0;
        index_a = index;
        index_b = index;
        for(size_t i=0; i<a->size()[2]; i++){
                index_a[2] = i;
                index_b[0] = i;
		index_b[1] = index_b[2];
                dot += a->read(index_a) * b->read(index_b);
        }
        prod->write(index, dot);
    }while(next_index(prod->size(), index));

    }else{

        prod_size.push_back(a->size()[0]);
        prod_size.push_back(a->size()[1]);
        prod_size.push_back(b->size()[1]);
	prod_size.push_back(b->size()[2]);
        prod = create_tensor(prod_size);

    first_index(prod->size(), index);
    do{
        dot = 0;
        index_a = index;
        index_b = index;
        for(size_t i=0; i<a->size()[2]; i++){
                index_a[2] = i;
                index_b[0] = i;
                index_b[1] = index_b[2];
		index_b[2] = index_b[3];
                dot += a->read(index_a) * b->read(index_b);
        }
        prod->write(index, dot);
    }while(next_index(prod->size(), index));

    }

    return prod;

}

Tensor *add(const Tensor *a, const Tensor *b)
{
    vector<size_t> sum_size, a_size, b_size;
    Tensor *sum;
    if(a->order() >= b->order()){
	a_size = a->size();
	b_size = b->size();
    }else{
	a_size = b->size();
	b_size = a->size();
    }

	sum_size = a_size;

	for(size_t i=0; i<b_size.size(); i++){
		if(b_size[i]>a_size[i]){
			sum_size[i] = b_size[i];
		}
	}
    sum = create_tensor(sum_size);

    vector<size_t> index;
    first_index(a->size(), index);
    do{
	sum->write(index, a->read(index));
    }while(next_index(a->size(), index));

    first_index(b->size(), index);
    do{
        sum->write(index, sum->read(index) + b->read(index));
    }while(next_index(b->size(), index));


    vector<size_t> index_w;

    for(size_t n=0; n<a->size().size(); n++){
	if(sum_size[n] > a->size()[n]){
		for(size_t i=1; i<sum_size[n]; i++){
			first_index(a->size(), index);
			do{
				index_w = index;
				index_w[n] += i;
				sum->write(index_w, sum->read(index_w) + a->read(index));
			}while(next_index(a->size(), index));
		}
	}
    }

    for(size_t n=0; n<b->size().size(); n++){
        if(sum_size[n] > b->size()[n]){
                for(size_t i=1; i<sum_size[n]; i++){
                        first_index(b->size(), index);
                        do{
                                index_w = index;
                                index_w[n] += i;
                                sum->write(index_w, sum->read(index_w) + b->read(index));
                        }while(next_index(b->size(), index));
                }
        }
    }


    return sum;
}

#include "tensor.hpp"

#include "matrix_tensor.hpp"
#include "order_3_tensor.hpp"
#include "order_n_tensor.hpp"

bool is_scalar(const Tensor *x)
{
    const vector<size_t> &d=x->size();
    for(size_t i=0; i<d.size(); i++){
        if(d[i]>1){
            return false;
        }
    }
    return true;
}

bool is_vector(const Tensor *x)
{
    int non_unit_dims = 0;
    vector<size_t> dims = x->size();
    for(int n=0; n<dims.size(); n++){
        if(dims[n] != 1){ non_unit_dims++;}
    }
    return (non_unit_dims == 1);
}

size_t volume(const vector<size_t> &dims)
{
    size_t total=1;
    for(int i=0; i<dims.size(); i++){
        assert(dims[i]>0);
        total *= dims[i];
    }
    return total;
}

size_t index_to_offset(const vector<size_t> &size, const vector<size_t> &index, bool allow_broadcast)
{
    int offset=0;
    int prev_length=1;

    for(int i=0; i<size.size(); i++){
        size_t dim_length=size[i];
        size_t dim_offset=0;

        // Handle the various kinds of implicit extension and broadcasting
        if(i < index.size()){
            dim_offset=index[i];
            if( dim_offset >= dim_length){
                assert(allow_broadcast);
                dim_offset=0;
            }
        }

        offset = offset * prev_length + dim_offset;
        prev_length=dim_length;
    }
    for(int i=size.size(); i<index.size(); i++){
        assert(index[i]==0 || allow_broadcast);
    }
    return offset;
}

/* Convert a linear offset back into the unique index, given tensor size.
    Returns unique vector `index` such that
        offset == ((index[0]*size[0] + index[1])*size[1] + index[2]) * size[2] + ... index[n-1]
    For example, for a matrix, such that:
        offset == index[0]*size[0] + index[1]
*/
vector<size_t> offset_to_index(const vector<size_t> &size, int offset)
{

	vector<size_t> res(size.size(), 0);
	size_t length = 1;
	for(int n=0; n<size.size(); n++){
		length *= size[n];
	}

	for(int i=0; i<size.size(); i++){
		length = length / size[i];
		res.push_back(offset % length);
		offset -= offset % length;
	}

	return res;
}

void first_index(const vector<size_t> &size, vector<size_t> &index)
{
    index.resize(size.size(), 0);
}

bool next_index(const vector<size_t> &size, vector<size_t> &index)
{
    bool carry=true;
    for(int i=0; i<size.size(); i++){
        if(carry){
            if( index[i]+1 < size[i] ){
                index[i] += 1;
                carry=false;
            }else{
                index[i] = 0;
            }
        }
    }
    return !carry;
}


Tensor *create_tensor(const std::vector<size_t> &size)
{
    assert(size.size() >= 2); // We do not support order-0 or order-1 for simplicity

    if(size.size() == 2){
        return new MatrixTensor(size);
    }else if(size.size() == 3){
        return new Order3Tensor(size);
    }else{
        return new OrderNTensor(size);
    }
}



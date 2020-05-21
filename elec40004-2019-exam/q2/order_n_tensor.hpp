#ifndef order_n_tensor_hpp
#define order_n_tensor_hpp

#include "tensor.hpp"

using namespace std;

class OrderNTensor : public Tensor{
private:
    vector<size_t> m_size;
    vector<float> m_values;
public:
    OrderNTensor(const vector<size_t> &_size)
    {
        resize(_size);
    }

    const vector<size_t> &size() const override
    { return m_size; }

    void resize(const vector<size_t> &dims) override
    {
        size_t length = 1;
	for(size_t n=0;n<dims.size(); n++){
            assert(dims[n]>0);
            length *= dims[n];
        }
        m_values.resize(length, 0.0f);
        m_size=dims;
    }

    virtual float read(const vector<size_t> &i) const override
    {

        size_t address = 0;
        size_t dim_size = 1;

	for(size_t n=0;n<m_size.size();n++){
            if(m_size[n]>1 && m_size[n]!=1){
                assert(i[n]<m_size[n]);
            }
            assert(i[n]<m_size[n]);
            address += i[n]*dim_size;
            dim_size *= m_size[n];
        }

        return m_values[address];
    }

    virtual void write(const vector<size_t> &i, float value) override
    {
        size_t address = 0;
        size_t dim_size = 1;

        for(size_t n=0;n<m_size.size();n++){
            if(m_size[n]>1 && m_size[n]!=1){
                assert(i[n]<m_size[n]);
            }
            assert(i[n]<m_size[n]);
            address += i[n]*dim_size;
            dim_size *= m_size[n];
        }

        m_values[address]=value;
    }
};

#endif




#ifndef ProxyA_hpp
#define ProxyA_hpp

#include <string>

using namespace std;

class ProxyA
{
protected:
    int m_a;
    float m_b;
public:
    virtual ~ProxyA() {};

    virtual float fff() const =0;

    virtual int ggg()
    {
        m_a += m_b;
        return m_a*m_a;
    };

    virtual void hhh(string g) =0;
};

#endif

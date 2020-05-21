#ifndef ProxyA_hpp_Impl2
#define ProxyA_hpp_Impl2

#include "ProxyA.hpp"
#include <string>

using namespace std;

class ProxyA_Impl2
	: public ProxyA
{
//protected:
  //  int m_a;
    //float m_b;
public:
    ProxyA_Impl2();

    float fff() const;

//    int ggg();

    void hhh(string g);
};

#endif





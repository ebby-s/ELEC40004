#ifndef ProxyA_hpp_Impl1
#define ProxyA_hpp_Impl1

#include "ProxyA.hpp"
#include <string>

using namespace std;

class ProxyA_Impl1
	: public ProxyA
{
//protected:
  //  int m_a;
    //float m_b;
public:
    ProxyA_Impl1();

    float fff() const;

//    int ggg();

    void hhh(string g);
};

#endif





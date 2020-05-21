#include "ProxyA.hpp"
#include "ProxyA_Impl1.hpp"

#include <string>

ProxyA_Impl1::ProxyA_Impl1()
{
    m_a=1;
    m_b=2;
}

float ProxyA_Impl1::fff() const
{
    return m_b / (1 + abs(m_a));
}
/*
int ProxyA_Impl1::ggg()
{
    m_a += m_b;
    return m_a*m_a;
}
*/
void ProxyA_Impl1::hhh(string g)
{
    m_b=stof(g);
}

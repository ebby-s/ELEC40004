#include "ProxyA.hpp"
#include "ProxyA_Impl2.hpp"

#include <string>

ProxyA_Impl2::ProxyA_Impl2()
{
    m_a=2;
    m_b=1;
}

float ProxyA_Impl2::fff() const
{
    return m_b + m_a;
}
/*
int ProxyA_Impl2::ggg()
{
    m_a += m_b;
    return m_a*m_a;
}
*/
void ProxyA_Impl2::hhh(string g)
{
    m_a=stoi(g);
}

#ifndef Proxy_Dst1_hpp
#define Proxy_Dst1_hpp

#include "Proxy.hpp"

int Proxy::get_X() const
{ return m_x; }

float Proxy::get_Y() const
{ return m_y; }

string Proxy::get_Z() const
{ return m_z; }

void Proxy::set_X(int x)
{
    m_x=x;
}

void Proxy::set_Y(float y)
{
    m_y=y;
}

void Proxy::set_Z(const string &z)
{
    m_z=z;
}

void Proxy::g()
{
    m_f.x = !m_f.x;
    m_f.y += 3;
}

void Proxy::f(int e)
{
    m_x = m_y;
    m_y = e * 2;
    cout << m_f << " " << m_x << endl;
}

#endif

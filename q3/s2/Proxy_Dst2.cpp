#ifndef Proxy_Dst2_hpp
#define Proxy_Dst2_hpp

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
    m_f.x = (m_f.y % 5)==0;
    m_f.y += 7;
}

void Proxy::f(int e)
{
    m_y = e + 3;
    m_x = m_x * e;
    cout << m_y << " " << m_x << endl;
}

#endif

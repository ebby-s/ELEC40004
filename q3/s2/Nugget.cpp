#include<iostream>
#include "Nugget.hpp"

// Should print x and then y, seperated by a space
// See test_Nugget_io_in.txt for examples.
ostream &operator<<(ostream &dst, const Nugget &o)
{ return dst << o.x << " " << o.y ; }
// TODO : Create a definition

istream &operator>>(istream &src, Nugget &o)
{ return src >> o.x >> o.y ; }
// TODO : Create a definition


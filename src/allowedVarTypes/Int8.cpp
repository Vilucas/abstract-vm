#include "Int8.hpp"

Int8::Int8() {

}

Int8::~Int8(){}

Int8::Int8(Int8 const &src)
{
    *this = src;
}

Int8 &
Int8::operator=(Int8 const &rhs)
{
    (void)rhs;
    return *this;
}
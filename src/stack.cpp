#include "stack.hpp"

stack::stack(void) {}

stack::~stack(void) {}
stack::stack(stack const &src)
{
    *this = src;
}

stack &stack::operator=(stack const &rhs)
{
    return *this;
}

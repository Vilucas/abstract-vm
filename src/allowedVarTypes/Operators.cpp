#include "Operators.hpp"

IOperand const *Operators::operator+(IOperand const &rhs)
{
    int precision = std::max(rhs.getPrecision(), this->getPrecision());
    

    
}
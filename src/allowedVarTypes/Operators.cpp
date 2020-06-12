#include "Operators.hpp"
#include "Factory.hpp"

Operators::Operators(){}
Operators::~Operators(){}
Operators::Operators(Operators const &src) {
    *this = src;
}
Operators const & Operators::operator=(Operators const &rhs) {
    (void)rhs;
    return *this;
}

IOperand const *Operators::operator+(IOperand const &rhs) const
{
    Factory f;
    eOperandType type = std::max(rhs.getType(), this->getType());
    std::string str = std::to_string(std::stod(rhs.toString()) + std::stod(this->toString()));
    const IOperand *ret = f.createOperand(type, str);
    return ret;
}
#include "Operators.hpp"

IOperand const *Operators::operator+(IOperand const &rhs) const
{
    eOperandType type = std::max(rhs.getType(), this->getType());
    std::string str = std::to_string(std::stod(rhs.getValue()) + std::stod(this->getValue()));
    const IOperand *ret = IOperand::createOperand(type, str);
    return ret;
}
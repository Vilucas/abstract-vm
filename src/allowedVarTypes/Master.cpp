#include "Master.hpp"

IOperand::IOperand(void) {}


IOperand::IOperand(IOperand const &src) {
    *this = src;
}


IOperand::~IOperand(){}

IOperand & IOperand::operator=(IOperand const &rhs) {
    return *this;
}

#include "vm.hpp"
#include "Master.hpp"

IOperand::IOperand(void) {}


IOperand::IOperand(IOperand const &src) {
    *this = src;
}


IOperand::~IOperand(){
    std::cout << "destru for IOperand" << std::endl;
}

IOperand & IOperand::operator=(IOperand const &rhs) {
    (void)rhs;
    return *this;
}
#include "vm.hpp"
#include "Master.hpp"

IOperand::IOperand(void) {}


IOperand::IOperand(IOperand const &src) {
    *this = src;
}


IOperand::~IOperand(){}

IOperand & IOperand::operator=(IOperand const &rhs) {
    (void)rhs;
    return *this;
}

IOperand const *Operators::operator+(IOperand const &rhs) const  {
   /*
    int precision = (this->getPrecision() >= rhs->getPrecision()) ? this->getPrecision() : rhs->getPrecision();
    IOperand *a = NULL
    a = new 
    return ();
    */
   (void)rhs;
   return NULL;
}

IOperand const *IOperand::createInt8(std::string const& value) const 
{
    IOperand *A = new Int8();
    return A;
}

IOperand const * IOperand::createOperand(eOperandType type, std::string const & value ) const 
{
    (void)type;
    (void)value;
    std::map< eOperandType, std::function<IOperand const * (std::string const &)>> table;
    table = {
       { "Int8", &IOperand::createInt8} 
    };
    return NULL;
}
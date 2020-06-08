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
/*

IOperand const *IOperand::createInt8(std::string const& value) const 
{
    IOperand *ret = new Int8();
    return ret;
}
*/
void    somefct()
{
    return;
}




IOperand const * IOperand::createOperand(eOperandType type, std::string const & value ) const 
{
    (void)type;
    (void)value;
    //DO THE FUNCTION TO ENABLE THE TAB :)
    /*
    std::map< std::string, std::function<IOperand const * (std::string const &)>> table {
       { "0", &somefct},
       { "1", &somefct}
    };
    */
    return NULL;
}
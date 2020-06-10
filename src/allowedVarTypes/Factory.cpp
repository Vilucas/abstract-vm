#include "Factory.hpp"

Factory::Factory (){}

Factory::~Factory(){}

Factory::Factory(Factory const &src) { *this = src; }

Factory const &Factory::operator=(Factory const &rhs){
    static_cast<void> (rhs);
    return *this;
}

IOperand const *Factory::createInt8(std::string const & value) const {
    IOperand *a = new Int8(value);
    return a;
}

IOperand const *Factory::createOperand(eOperandType type, std::string const & value) const {
    
    IOperand const * ret;
    
    std::map<eOperandType, Factory::createInt16 > table {
        {eOperandType::Int_8, &Factory::createInt8 }
    };

    for (auto x : table)
    {
        if (x.first == type)
            return x.second(value);
    }
    return NULL;
}
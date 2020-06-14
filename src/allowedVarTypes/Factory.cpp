#include "Factory.hpp"
#include "exception.hpp"
#include <limits>
#include <math.h>
#include <float.h>

Factory::Factory () {
    this->_table.insert(std::make_pair(eOperandType::Int_8, &Factory::createInt8));
    this->_table.insert(std::make_pair(eOperandType::Int_16, &Factory::createInt16));
    this->_table.insert(std::make_pair(eOperandType::Int_32, &Factory::createInt32));
    this->_table.insert(std::make_pair(eOperandType::Float_, &Factory::createFloat));
    this->_table.insert(std::make_pair(eOperandType::Double_, &Factory::createDouble));
}

Factory::~Factory(){}

Factory::Factory(Factory const &src) { *this = src; }

Factory const &Factory::operator=(Factory const &rhs){
    static_cast<void> (rhs);
    return *this;
}

template<typename T>
void             TestOverflows(std::string const & value)
{
    try { //Testing overflow and underflow for the given type
        if (std::stod(value) > (std::numeric_limits<T>::max()))
            throw(OverflowErrorException());
        if (std::stod(value) < (std::numeric_limits<T>::min()))
            throw(UnderflowErrorException());
    }
    catch (OverflowErrorException &e) {
        std::cout << e.what() << std::endl;
        exit(1);
    }
    catch (UnderflowErrorException &e) {
        std::cout << e.what() << std::endl;
        exit(1);
    }
}

IOperand const *Factory::createInt8(std::string const & value) const {
    TestOverflows<int8_t>(value);
    IOperand *a = new Int8(value);
    return a;
}

IOperand const *Factory::createInt16(std::string const & value) const {
    TestOverflows<int16_t>(value);
    IOperand *a = new Int16(value);
    return a;
}

IOperand const *Factory::createInt32(std::string const & value) const {
    TestOverflows<int32_t>(value);
    IOperand *a = new Int32(value);
    return a;
}

IOperand const *Factory::createFloat(std::string const & value) const {    
    try{ //TestOverflows not working on precision >0 values, weird...
        if (std::stod(value) > FLT_MAX)
            throw(OverflowErrorException());
        if (std::stod(value) < -(FLT_MAX + 1))
            throw(UnderflowErrorException());
    }
    catch(OverflowErrorException &s)
    {
        std::cout << s.what() << std::endl;
        exit(1);
    }
    catch(UnderflowErrorException &s)
    {
        std::cout << s.what() << std::endl;
        exit(1);
    }
    IOperand *a = new Float(value);
    return a;
}

IOperand const *Factory::createDouble(std::string const & value) const {
    try {
        if (std::stod(value) > DBL_MAX)
            throw(OverflowErrorException());
        if (std::stod(value) < -(DBL_MAX + 1))
            throw(UnderflowErrorException());
    }
    catch(OverflowErrorException &s)
    {
        std::cout << s.what() << std::endl;
        exit(1);
    }
    catch(UnderflowErrorException &s)
    {
        std::cout << s.what() << std::endl;
        exit(1);
    }
    IOperand *a = new Double(value);
    return a;
}

//Factory methode return the result of the targeted constructor that had the given value
IOperand const *Factory::createOperand(eOperandType type, std::string const & value) const {
    return (*this.*_table.at(type))(value);
}
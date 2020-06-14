#include "Operators.hpp"
#include "Factory.hpp"
#include "exception.hpp"

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
    std::string const &str = std::to_string(std::stod(rhs.toString()) + std::stod(this->toString()));
    const IOperand *ret = f.createOperand(type, str);
    return ret;
}

IOperand const *Operators::operator-(IOperand const &rhs) const
{
    Factory f;
    eOperandType type = std::max(rhs.getType(), this->getType());
    std::string const &str = std::to_string(std::stod(rhs.toString()) - std::stod(this->toString()));
    const IOperand *ret = f.createOperand(type, str);
    return ret;
}

IOperand const *Operators::operator*(IOperand const &rhs) const
{
    Factory f;
    eOperandType type = std::max(rhs.getType(), this->getType());
    std::string const &str = std::to_string(std::stod(rhs.toString()) * std::stod(this->toString()));
    const IOperand *ret = f.createOperand(type, str);
    return ret;
}

IOperand const *Operators::operator/(IOperand const &rhs) const
{
    Factory f;

    try {
    if (std::stod(rhs.toString()) == 0)
        throw(DivideByZeroException());
    } catch (DivideByZeroException &s) {
        std::cout << s.what() << std::endl;
        exit(1);
    }
    eOperandType type = std::max(rhs.getType(), this->getType());
    std::string const &str = std::to_string(std::stod(rhs.toString()) / std::stod(this->toString()));
    const IOperand *ret = f.createOperand(type, str);
    return ret;
}

IOperand const *Operators::operator%(IOperand const &rhs) const
{
    Factory f;

    try {
    if (std::stod(rhs.toString()) == 0)
        throw(DivideByZeroException());
    } catch (DivideByZeroException &s) {
        std::cout << s.what() << std::endl;
        exit(1);
    }
    eOperandType type = std::max(rhs.getType(), this->getType());
    std::string const &str = std::to_string((std::stoi(rhs.toString())) % (std::stoi(this->toString())));
    const IOperand *ret = f.createOperand(type, str);
    return ret;
}
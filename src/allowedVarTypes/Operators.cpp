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
    std::string str = std::to_string((std::stod(rhs.toString()) + std::stod(this->toString())));
    if (type <= 2)
        str = std::to_string((std::stoi(rhs.toString()) + std::stoi(this->toString())));
    const IOperand *ret = f.createOperand(type, str);
    return ret;
}

IOperand const *Operators::operator-(IOperand const &rhs) const
{
    Factory f;
    eOperandType type = std::max(rhs.getType(), this->getType());
    std::string str = std::to_string((std::stod(rhs.toString()) - std::stod(this->toString())));
    if (type <= 2)
        str = std::to_string((std::stoi(rhs.toString()) - std::stoi(this->toString())));
    const IOperand *ret = f.createOperand(type, str);
    return ret;
}

IOperand const *Operators::operator*(IOperand const &rhs) const
{
    Factory f;

    eOperandType type = std::max(rhs.getType(), this->getType());
    std::string str = std::to_string((std::stod(rhs.toString()) * std::stod(this->toString())));
    if (type <= 2)
        str = std::to_string((std::stoi(rhs.toString()) * std::stoi(this->toString())));
    const IOperand *ret = f.createOperand(type, str);
    return ret;
}

void       testDB0Exception(std::string const &value)
{
    try {
    if (std::stod(value) == 0)
        throw(DivideByZeroException());
    } catch (DivideByZeroException &s) {
        std::cout << s.what() << std::endl;
        exit(1);
    }
}

IOperand const *Operators::operator/(IOperand const &rhs) const
{
    Factory f;

    testDB0Exception(this->toString());
    eOperandType type = std::max(rhs.getType(), this->getType());
    std::string str = std::to_string((std::stod(rhs.toString()) / std::stod(this->toString())));
    if (type <= 2)
        str = std::to_string((std::stoi(rhs.toString()) / std::stoi(this->toString())));
    const IOperand *ret = f.createOperand(type, str);
    return ret;
}

IOperand const *Operators::operator%(IOperand const &rhs) const
{
    Factory f;
    testDB0Exception(this->toString());
    eOperandType type = std::max(rhs.getType(), this->getType());
    std::string const &str = std::to_string((std::stoi(rhs.toString()) % std::stoi(this->toString())));
    const IOperand *ret = f.createOperand(type, str);
    return ret;
}
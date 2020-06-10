#include "stack.hpp"
#include "exception.hpp"

stack::stack(void) {}

stack::~stack(void) {}

stack::stack(stack const &src)

{
    *this = src;
}

stack &stack::operator=(stack const &rhs)
{
    (void)rhs;
    return *this;
}

void stack::ProgramExit() const { exit(0);}

void stack::pop() const {
    std::list<IOperand const *>::iterator it = this->_stack.begin();
    if (this->_stack.empty() == true)
        throw(PopWithEmptyStackException());
    this->_stack.erase(it);
}

void stack::dump() const  {
    std::list<IOperand const *>::iterator it = this->_stack.begin();
    for (it = this->_stack.begin(); it != this->_stack.end() ; it++)
        std::cout << *it << std::endl;
}

void stack::assert(std::string const value) const {
    std::list<IOperand const *>::iterator it = this->_stack.begin();
    if (*it != value)
        throw(AssertErrorException());
}

void stack::add(void) const
{
    if (stack.size() < 2)
        throw(AddErrorException())
    std::list<IOperand const *>::iterator it = this->_stack.begin();
    //IOperand const result = new
}

void stack::sub(void) const 
{
    return;
}

void stack::mul(void) const 
{
}
void stack::div(void) const
{
}

void stack::mod(void) const 
{


}

void stack::print(void) const
{
    std::list<IOperand const *>::iterator it = this->_stack.begin();
    if (*it < -128 || *it > 127)
        throw(AssertErrorException());
    printf("%c\n", char(*it));
}
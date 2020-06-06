#ifndef STACK_HPP
#define STACK_HPP
#include <list>

class stack
{

private:
    //std::list<IOperand const*> _Stack;

public:
    stack();
    stack(stack const &s);
    stack & operator=(stack const &src);
    virtual ~stack();

};

#endif
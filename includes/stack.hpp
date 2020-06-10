#ifndef STACK_HPP
#define STACK_HPP
#include "Master.hpp"
#include <list>

class stack
{

    private:
        std::list<IOperand const*> _stack;
        void pop()  const ;
        void dump() const ; 
        void assert(std::string const value) const;
        void add(std::string const value) const;
        void sub(void) const;
        void mul(void) const;
        void div(void) const;
        void mod(void) const;
        void print(void) const;
        void exit() const ;


    public:
        stack();
        stack(stack const &s);
        stack & operator=(stack const &src);
        virtual ~stack();



};

#endif
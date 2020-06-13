#ifndef STACK_HPP
#define STACK_HPP

#include "vm.hpp"
#include "Master.hpp"
#include <list>
#include <map>

class linesManagement;

class stack
{
    public:
        void push(linesManagement &lm);
        void vmExit();
        void pop();
        void dump();
        void (assert)(linesManagement &lm);
        void (print)(void);
        
        void add();
        /*
        void sub(void);
        void mul(void);
        void div(void);
        void mod(void);
        */
        stack();
        stack(stack const &s);
        stack & operator=(stack const &src);
        virtual ~stack();
        void    launcher(linesManagement lm);

    private:
        std::list<IOperand const *> _stack;
        std::map <const char *, void ((stack::*)(void)) > _dispatchTable {
                {"exit", &stack::vmExit},
                {"pop", &stack::pop},
                {"dump", &stack::dump},
                {"print", &stack::print},
                {"add", &stack::add},
        };
};

#endif
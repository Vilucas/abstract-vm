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
        void vmExit(void);
        void pop(void);
        void dump(void);
        void (assert)(linesManagement &lm);
        void (print)(void);
        void add(void);
        void sub(void);
        void mul(void);
        void div(void);
        void mod(void);
        stack(void);
        stack(stack const &s);
        stack & operator=(stack const &src);
        virtual ~stack();
        void    launcher(linesManagement lm);
        void    checkIfEmpty(size_t itemNeeded);

    private:
        std::list<IOperand const *> _stack;
        std::map <const char *, void ((stack::*)(void)) > _dispatchTable {
                {"exit", &stack::vmExit},
                {"pop", &stack::pop},
                {"dump", &stack::dump},
                {"print", &stack::print},
                {"add", &stack::add},
                {"sub", &stack::sub},
                {"mul", &stack::mul},
                {"div", &stack::div},
                {"mod", &stack::mod}
        };
};

// src/parsing/ValueParsing.cpp
eOperandType ValueLexing(std::vector<std::string> &tab, std::string *value, size_t lineCount);

#endif
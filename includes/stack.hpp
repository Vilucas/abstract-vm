#ifndef STACK_HPP
#define STACK_HPP
#include "Master.hpp"
#include <vector>

class stack
{
    public:
        void push(std::vector<std::string> &rawInstructionsBoard, size_t lineCount);
        void vmExit() const ;
        void pop();
        void dump() const ;

        //void (assert)(std::vector<std::string> &rawInstructionsBoard, size_t lineCount);
        /*
        void add(std::string const value) const;
        void sub(void) const;
        void mul(void) const;
        void div(void) const;
        void mod(void) const;
        void print(void) const;
        */
        stack();
        stack(stack const &s);
        stack & operator=(stack const &src);
        virtual ~stack();

        private:
            std::vector<IOperand const *> _stack;
};

#endif
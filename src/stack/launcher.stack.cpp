#include "vm.hpp"
#include "stack.hpp"
#include "Master.hpp"
#include "Factory.hpp"
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

//launching the stack function's members
void    stack::launcher(linesManagement lm)
{
    if (lm.rawInstructionsBoard.size() < 2) // if instruction without arg -> launch func *ptr associated to the key, then return;
        for (auto &x: this->_dispatchTable)
            if (x.first == lm.rawInstructionsBoard[0])
                return (*this.*_dispatchTable.at(x.first))();
    if (std::strcmp("push", lm.rawInstructionsBoard[0].c_str()) == 0) //kinda dirty :-) but it's ok 
        return this->push(lm);
    if (std::strcmp("assert", lm.rawInstructionsBoard[0].c_str()) == 0)
        return (this->assert)(lm);
    try { std::cout << "Error -> " << std::endl; throw(LexicalErrorException(lm.line_count));} // no instruction executed -> Lexical error (in case parsing failled)
    catch(LexicalErrorException &s) {
        std::cout << s.what() << std::endl;
    }
}
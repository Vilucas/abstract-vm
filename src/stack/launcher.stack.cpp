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

void    stack::launcher(linesManagement lm)
{
    if (lm.rawInstructionsBoard.size() == 1)
        return (*this.*_dispatchTable.at(lm.rawInstructionsBoard[0].c_str()))();
    if (std::strcmp("push", lm.rawInstructionsBoard[0].c_str()) == 0)
        return this->push(lm);
    if (std::strcmp("assert", lm.rawInstructionsBoard[0].c_str()) == 0)
        return (this->assert)(lm);
    try{throw(LexicalErrorException(lm.line_count));}
    catch(LexicalErrorException &s) {
        std::cout << s.what() << std::endl;
    }
}
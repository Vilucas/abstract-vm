#include "vm.hpp"
#include "stack.hpp"
//#include "instructions.hpp"

void    instructions(linesManagement lm)
{
    print(lm.line_count);
    std::map< std::string, std::function<void(stack)>> dispatchTable;
/*
    dispatchTable = {
        {"add", stack::add()},
        {"div", stack::div()}
    };
*/

}
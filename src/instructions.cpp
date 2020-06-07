#include "vm.hpp"
#include "stack.hpp"
#include "Master.hpp"
//#include "instructions.hpp"

void    instructions(linesManagement lm)
{
    void(lm.line_count);
    std::map< std::string, std::function<void(stack)>> dispatchTable;

    //std::cout << eOperandType::Double << std::endl;
/*
    dispatchTable = {
        {"add", stack::add()},
        {"div", stack::div()}
    };
*/

}
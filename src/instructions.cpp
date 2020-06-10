#include "vm.hpp"
#include "stack.hpp"
#include "Master.hpp"
//#include "instructions.hpp"

void    instructions(linesManagement lm, stack Stack)
{
    std::map<std::string, void(stack::*)(void)> tab;
    tab.insert(std::make_pair("exit", &stack::exit))

}
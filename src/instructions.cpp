#include "vm.hpp"
#include "stack.hpp"
#include "Master.hpp"
#include "Factory.hpp"

void    instructions(linesManagement lm, stack &Stack)
{
    Factory f;
    
    //f.createOperand(eOpndType::Int_8, "234");
    int length = lm.rawInstructionsBoard.size();
    for (int i = 0; i < length; i++)
        print(lm.rawInstructionsBoard[i]);
    Stack.push(lm.rawInstructionsBoard, lm.line_count);
    Stack.pop();
    Stack.dump();
    std::map<std::string, void(stack::*)(void)> tab;
   
    //tab.insert(std::make_pair("exit", &stack::exit));
}
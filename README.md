# Abstract-vm
<img src=".img/AbstractVM.png">
The purpose of this project is to create a simple virtual machine that can
interpret programs written in a basic assembly language.  
  
This project made me understand in depth how to support unlimited precision arithmetic between different types of variables.  
  
It's also a very good project to showcase my C++ skills at the date I created it, June 2020.  
  
At the end of the project, the program will have the same behavior as ```man dc``` with a different syntax

---
## Technical Infos and commands
The variable types supported in the VM:  
◦ int8(n) : Creates an 8-bit integer with value n.    
◦ int16(n) : Creates a 16-bit integer with value n.  
◦ int32(n) : Creates a 32-bit integer with value n.  
◦ float(z) : Creates a float with value z.  
◦ double(z) : Creates a double with value z.  
  
To enter a number from different types in the VM, you can use the *push* instruction:  
```push int8(23)```  
  
Each time one variable is created, it's added in a stack-like container.  
Then, you can manipulate these variables using these instructions:  
  
---
  
• pop: Unstacks the value from the top of the stack. If the stack is empty, the
program execution will stop with an error.  
  
• dump: Displays each value of the stack, from the most recent one to the oldest
one WITHOUT CHANGING the stack.  
  
• assert v: Asserts that the value at the top of the stack is equal to the one passed
as parameter for this instruction. If it is not the case, the program execution will
stop with an error.

• add: Unstacks the first two values on the stack, adds them together and stacks the
result.  

• sub: Unstacks the first two values on the stack, subtracts them, then stacks the
result.  
  
• mul: Unstacks the first two values on the stack, multiplies them, then stacks the
result.  
  
• div: Unstacks the first two values on the stack, divides them, then stacks the result.
  
• mod: Unstacks the first two values on the stack, calculates the modulus, then
stacks the result.
  
• print: Asserts that the value at the top of the stack is an 8-bit integer. (If not,
see the instruction assert), then interprets it as an ASCII value and displays the
corresponding character on the standard output.
  
• exit: Terminate the execution of the current program.
  
---

## Install and launch
  
```gcl https://github.com/Vilucas/abstract-vm.git```  
```cd abstract-vm```  
```make```  
```./vm```  

---

## Launch with an instruction file. 
  
```./vm example/example.avm```    
  
  ---
  
All the errors are supposed to be handled. The program won't crash.  
  
There is not much to show on that kind of program, not visually expressive but the code is worth a look.

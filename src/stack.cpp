#include "stack.hpp"
#include "exception.hpp"
#include "Factory.hpp"
#include "vm.hpp"

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

std::string   parseValue(std::string s, size_t lineCount)
{
    std::cout << "'" << s << "'" << std::endl;
    if (s.empty() || s.back() != ')' || (s.size() == 1))
        throw(LexicalErrorException(lineCount));
    s.pop_back(); // delete closing bracket
    if (s[0] == '-' && s.size() == 1) //test if user is trying to screw me over
            throw(LexicalErrorException(lineCount));
    for (size_t i = 0; i < s.size(); i++)
        if (std::isdigit(s[i]) == 0) // isdigit returns non 0 value if the param IS a digit 
        {
            if (s[i] != '-' || (s[i] == '-' && i > 0)) //handling neg values
                throw(LexicalErrorException(lineCount));
        }
    return s;
}

//compare the value of the input with all the available variable types. exit() if fails to find a valid one
eOperandType ValueLexing(std::vector<std::string> &tab, std::string *value, size_t lineCount)
{
    std::vector<std::string> typeBoard = {
        "int8(", "int16(", 
        "int32(", "float(",
        "double(" };

    if (tab.size() != 2)
        throw (LexicalErrorException(lineCount));
    for (size_t i = 0 ; i < typeBoard.size(); i++)
        if (strncmp(tab[1].c_str(), typeBoard[i].c_str(), typeBoard[i].size()) == 0)
        {
            *value = tab[1].substr(typeBoard[i].size(), tab[1].size() - (typeBoard[i]).size());
            *value = parseValue(*value, lineCount); // modify the variable to get the value between the brackets
            return eOperandType(i);
        }
    throw(LexicalErrorException(lineCount));
}

void    stack::push(std::vector<std::string> &rawInstructionsBoard, size_t lineCount)
{
    std::string     value;
    eOperandType    type;
    Factory         f;
    
    try {
        type = ValueLexing( rawInstructionsBoard, &value, lineCount); //get value and type
    } catch (LexicalErrorException &e) {
        std::cout << e.what() << std::endl;
        exit(1);
    }
    this->_stack.push_back(f.createOperand(type, value)); //create appropriate function type
}

void stack::vmExit() const {
    exit(0);
}

//delete top of the stack element
void stack::pop() {
    try {
        if (this->_stack.empty() == true)
            throw(PopWithEmptyStackException());
    }
    catch (PopWithEmptyStackException &e) {
        std::cout << e.what() << std::endl;
        exit(1);
    }
    delete this->_stack[0];
    this->_stack.erase(this->_stack.begin());
}

void stack::dump() const  {
    for (size_t i = 0; i < this->_stack.size(); i++)
        std::cout << "Elem: " << i << " : " << this->_stack[i]->toString() << std::endl;
}
/*
void   (stack::assert)(std::vector<std::string> &rawInstructionsBoard, size_t lineCount) 
{
    std::list<IOperand const *>::iterator it = this->_stack.begin();
    if (*it != value)
        throw(AssertErrorException());
}


void stack::add(void) const
{
    if (stack.size() < 2)
        throw(AddErrorException())
    std::list<IOperand const *>::iterator it = this->_stack.begin();
    //IOperand const result = new
}

void stack::sub(void) const 
{
    return;
}

void stack::mul(void) const 
{
}
void stack::div(void) const
{
}

void stack::mod(void) const 
{


}

void stack::print(void) const
{
    std::list<IOperand const *>::iterator it = this->_stack.begin();
    if (*it < -128 || *it > 127)
        throw(AssertErrorException());
    printf("%c\n", char(*it));
}
*/
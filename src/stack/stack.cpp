#include "stack.hpp"
#include "exception.hpp"
#include "Factory.hpp"

#include "variableDefinition.hpp"

std::string   parseValue(std::string s, size_t lineCount)
{
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
        if (std::strncmp(tab[1].c_str(), typeBoard[i].c_str(), typeBoard[i].size()) == 0)
        {
            *value = tab[1].substr(typeBoard[i].size(), tab[1].size() - (typeBoard[i]).size());
            *value = parseValue(*value, lineCount); // modify the variable to get the value between the brackets
            return eOperandType(i);
        }
    throw(LexicalErrorException(lineCount));
}

void    stack::push(linesManagement &lm)
{
    std::string     value;
    eOperandType    type;
    Factory         f;
    
    try {
        type = ValueLexing(lm.rawInstructionsBoard, &value, lm.line_count); //get value and type
    } catch (LexicalErrorException &e) {
        std::cout << e.what() << std::endl;
        exit(1);
    }
    this->_stack.push_front(f.createOperand(type, value)); //create appropriate function type
}

void stack::vmExit(){
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
    const IOperand *del = (*this->_stack.begin());
    this->_stack.erase(this->_stack.begin());
    delete del;
}

//print the whole stack starting by newest elem
void stack::dump()  {
    if (this->_stack.empty())
    {
        std::cout << "Stack is empty" << std::endl;
        return;
    }
    std::list<IOperand const *>::iterator it = this->_stack.begin();
    size_t elem = 0;
    for (it = this->_stack.begin(); it != this->_stack.end(); it++)
    {
        elem++;
        std::cout << "Elem: " << elem << " : " << (*it)->toString() << std::endl;
    }   
}

//Check if top stack elem has same value than the param
void   (stack::assert)(linesManagement &lm) 
{
    std::string value;
    eOperandType type = ValueLexing(lm.rawInstructionsBoard, &value, lm.line_count);

    try {
        if (std::strcmp(value.c_str(), (*this->_stack.begin())->toString().c_str()) != 0)
            throw(AssertErrorException());
        if (type != (*this->_stack.begin())->getType())
            throw(AssertErrorException());
    } catch(AssertErrorException &s) {
        std::cout << s.what() << std::endl;
        exit(1);
    }
}

// displays the character corresponding to the first elem's value on the standard output.
void (stack::print)(void)
{
    std::list<IOperand const *>::iterator it = this->_stack.begin();
    try {
        if ((*this->_stack.begin())->getType() != eOperandType::Int_8)
            throw(AssertErrorException());
        }
    catch (AssertErrorException &s)
    {   
        std::cout << s.what() << std::endl;
        exit(1);
    }
    printf("%c\n", char(stoi((*it)->toString())));
}

//Add two first elem's value and replace them with the result
void stack::add(void)
{
    try {
        if (this->_stack.size() < 2)
            throw(AddErrorException());
    }
    catch (AddErrorException &s) {
        std::cout << s.what() << std::endl;
        exit(1);
    }
    const IOperand *a = (*this->_stack.begin());
    this->pop();
    const IOperand *b = (*this->_stack.begin());
    this->pop();
    const IOperand *c = *a + *b;
    this->_stack.push_front(c);
    delete a;
    delete b;
}
/*
void stack::sub(void)
{
    return;
}

void stack::mul(void)
{
}
void stack::div(void) const
{
}

void stack::mod(void)
{


}


*/
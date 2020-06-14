#include "stack.hpp"
#include "exception.hpp"
#include "Factory.hpp"
#include "variableDefinition.hpp"


void    stack::push(linesManagement &lm)
{
    std::string     value;
    eOperandType    type;
    Factory         f;
    
    try {
        type = ValueLexing(lm.rawInstructionsBoard, &value, lm.line_count); //get value and type
        // src/parsing/ValueParsing.cpp
    } catch (LexicalErrorException &e) {
        std::cout << e.what() << std::endl;
        exit(1);
    } catch (PrecisionExceptionError &e) {
        std::cout << e.what() << std::endl;
        exit(1);
    }
    this->_stack.push_front(f.createOperand(type, value)); //create appropriate function type
}

void stack::vmExit(){
    if (this->_stack.empty() == true)
        exit(0);
    std::list<IOperand const*>::iterator it = this->_stack.begin();
    for (it = this->_stack.begin(); it != this->_stack.end(); it++)
        delete *it;
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
        std::cout << "Elem " << elem << ": " << (*it)->toString() << std::endl;
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
    std::list<IOperand const *>::iterator it = this->_stack.begin();
    const IOperand *a = *it;
    const IOperand *b = *(++it);
    const IOperand *c = (*a) + (*b);
    this->pop();
    this->pop();
    this->_stack.push_front(c);
}

void stack::sub(void)
{
    try {
        if (this->_stack.size() < 2)
            throw(AddErrorException());
    }
    catch (AddErrorException &s) {
        std::cout << s.what() << std::endl;
        exit(1);
    }
    std::list<IOperand const *>::iterator it = this->_stack.begin();
    const IOperand *a = *it;
    const IOperand *b = *(++it);
    const IOperand *c = (*a) - (*b);
    this->pop();
    this->pop();
    this->_stack.push_front(c);
}

void stack::mul(void)
{
     try {
        if (this->_stack.size() < 2)
            throw(AddErrorException());
    }
    catch (AddErrorException &s) {
        std::cout << s.what() << std::endl;
        exit(1);
    }
    std::list<IOperand const *>::iterator it = this->_stack.begin();
    const IOperand *a = *it;
    const IOperand *b = *(++it);
    const IOperand *c = (*a) * (*b);
    this->pop();
    this->pop();
    this->_stack.push_front(c);

}

void stack::div(void)
{
     try {
        if (this->_stack.size() < 2)
            throw(AddErrorException());
    }
    catch (AddErrorException &s) {
        std::cout << s.what() << std::endl;
        exit(1);
    }
    std::list<IOperand const *>::iterator it = this->_stack.begin();
    const IOperand *a = *it;
    const IOperand *b = *(++it);
    const IOperand *c = (*a) / (*b);
    this->pop();
    this->pop();
    this->_stack.push_front(c);
}

void stack::mod(void)
{
    try {
        if (this->_stack.size() < 2)
            throw(AddErrorException());
    }
    catch (AddErrorException &s) {
        std::cout << s.what() << std::endl;
        exit(1);
    }
    std::list<IOperand const *>::iterator it = this->_stack.begin();
    const IOperand *a = *it;
    const IOperand *b = *(++it);
    const IOperand *c = (*a) % (*b);
    this->pop();
    this->pop();
    this->_stack.push_front(c);
}
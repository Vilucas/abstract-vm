#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <iostream>

class OpenFailException: public std::exception
{
    public:
        virtual const char*  what() const throw() {
            return ("Open failed, Exiting...");
        }
};

class LexicalErrorException: public std::exception
{
    std::string msg;
    public:
        
        LexicalErrorException(size_t line_number)
        {
            std::string new_line = std::to_string(line_number);
            msg = std::string("Lexical error occured at line ") + new_line + ", Exiting ..."; 
        }
        virtual const char* what() const throw() {
            return(msg.c_str());
        }
        virtual ~LexicalErrorException(){};
};

class NoExitException: public std::exception
{
    public:
        virtual const char * what() const throw() {
            return ("No exit found in instruction file, Exiting");
        }
};

class PopWithEmptyStackException : public std::exception
{
    public:
        virtual const char * what() const throw() {
            return ("Trying to pop an item when stack is empty, Exiting...");
        }
};

class AssertErrorException : public std::exception
{
    public:
        virtual const char * what() const throw() {
            return ("Error: Assert error, Exiting...");
        }
};

class EmptyStackException : public std::exception
{
    public:
        virtual const char * what() const throw() {
            return ("Error: Not enough items in the stack, Exiting...");
        }

};

class DivideByZeroException : public std::exception
{
    public:
        virtual const char * what() const throw() {
            return ("Division by zero, Exiting");
        }
};

class OverflowErrorException : public std::exception
{
    public:
        virtual const char * what() const throw() {
            return ("Overflow or underflow error, Exiting...");
        }
};

class UnderflowErrorException : public std::exception
{
    public:
        virtual const char * what() const throw() {
            return ("Underflow error, Exiting...");
        } 
};

class PrecisionExceptionError : public std::exception
{
    public:
        virtual const char * what() const throw() {
            return ("This type can't handle that precision");
        }
};



#endif
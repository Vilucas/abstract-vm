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
            return ("No exit found in instruction file, Exiting...");
        }
};

class PopWithEmptyStackException : public std::exception
{
    public:
        virtual const char * what() const throw() {
            return ("Trying to pop item in an empty stack, Exiting...");
        }
};

class AssertErrorException : public std::exception
{
    public:
        virtual const char * what() const throw() {
            return ("Error: Assert error, Exiting...");
        }
};

class AddErrorException : public std::exception
{
    public:
        virtual const char * what() const throw() {
            return ("Error: add() on a stack with less than two items, Exiting...");
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
#endif
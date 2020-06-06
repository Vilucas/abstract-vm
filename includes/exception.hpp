#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

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
        
        LexicalErrorException(const std::string &line_number)  : msg(std::string("Lexical error occured at line ") + line_number + ", Exiting ...")
        {}
        virtual const char* what() const throw() {
            return(msg.c_str());
        }
        //virtual ~LexicalErrorException() _NOEXCEPT;
};

class NoExitException: public std::exception
{
    public:
        virtual const char * what() const throw() {
            return ("No exit found in instruction file, Exiting...");
        }
};

#endif
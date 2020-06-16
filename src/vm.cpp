#include <fstream>
#include <iostream>
#include "vm.hpp"
#include "stack.hpp"
#include "exception.hpp"

void    checkArg(std::ifstream &fd, int argc, char **argv)
{
    if (argc > 2)
    {
        print(usage);
        exit (1);
    }
    try {
    fd.open(argv[1]);
    if (fd.fail())
            throw(OpenFailException());
    }
    catch(OpenFailException &e) {
        std::cerr << e.what() << std::endl;
        exit(-1);
    }
}

void    noExit(void)
{
    try {
        throw(NoExitException());
    }
    catch(NoExitException &e) {
        std::cerr << e.what() << std::endl;
        exit(1);
    }
}

void    readFromArg(std::ifstream &fd)
{
    linesManagement         lm;
    stack                   Stack;

    lm.line_count = 0;
    while (std::getline(fd,  lm.line))
    {
        lm.line_count += 1;
        if (parsing(lm.line) == true)
        {
            lm.rawInstructionsBoard = lexer(lm);
            Stack.launcher(lm);
        }
    }
    noExit();
}

int main(int argc, char ** argv)
{
    std::ifstream           fd;
    std::istream            &standartInput = std::cin;
    linesManagement         lm;
    stack                   Stack;
    
    try {
    if (argc >= 2)
    {
        checkArg(fd, argc, argv);
        readFromArg(fd);
    }
    std::cout << "$> ";
    while (std::getline(standartInput,  lm.line))
    {
        lm.line_count += 1;
        if (parsing(lm.line) == true)
        {
            lm.rawInstructionsBoard = lexer(lm);
            Stack.launcher(lm);
        }
        std::cout << "$> ";
    }
    noExit();
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        exit(1);
    }
    return (0);
}
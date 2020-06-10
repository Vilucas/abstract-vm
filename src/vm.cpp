#include <fstream>
#include "vm.hpp"
#include "stack.hpp"
#include "exception.hpp"

void    checkArg(std::ifstream &fd, int argc, char **argv)
{
    if (argc != 2)
    {
        print(usage);
        exit (-1);
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
    }
}

int main(int argc, char ** argv)
{
    std::ifstream           fd;
    linesManagement         lm;
    stack                   Stack;

    checkArg(fd, argc, argv);
    while (std::getline(fd,  lm.line))
    {
        std::cout << "original line = '" << lm.line << "'"  << std::endl;
        if (parsing(lm.line) == true)
            lm.rawInstructionsBoard = instructionParsing(lm);
            instructions(lm, Stack);
        lm.line_count += 1;
    }
    noExit();
    return (0);
}
#include <iostream>
#include <fstream>
#include "vm.hpp"
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

int main(int argc, char ** argv)
{
    std::ifstream fd;
    checkArg(fd, argc, argv);
    std::string line;
    size_t line_count = 0;
    while (std::getline(fd,  line))
    {
        std::list<std::string> ret;
        /**
         * Parsing will occur line by line because the program is suposed to manage small files.
         **/ 
        std::cout << "original line = '" << line << "'"  << std::endl;
        try {
            ret = parsing(line, line_count); }
        catch (LexicalErrorException &e) {
            std::cerr << e.what() << std::endl;
            exit(1);
        }
        catch (std::exception &e) {
            std::cout << "An error occured, program will now exit..." << std::endl;
            return (1);
        }
        std::cout << "'" << line << "'" << std::endl;
    }
    try {
        throw(NoExitException());
    }
    catch(NoExitException &e) {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}
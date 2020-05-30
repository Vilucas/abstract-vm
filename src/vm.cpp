#include <iostream>
#include <fstream>
#include "vm.hpp"

void    checkArg(std::ifstream &fd, char **argv)
{
    try {
        fd.open(argv[1]);
        if (fd.fail())
            throw "error";
    } catch(const char *msg ){
        std::cerr << "Error occured while openning the instruction file" << std::endl;
        exit(1);
    }
}

int main(int argc, char ** argv)
{
    std::ifstream fd;
    checkArg(fd, argv);
    std::string line;
    while (std::getline(fd,  line))
    {
        /**
         * Parsing will occur line by line because the program is suposed to manage small files.
         **/
        if (parsing(line) == true)
            std::cout << "'" << line << "'" << std::endl;
        /**
         * Parsing is removing the comments so 'line' might be empty
         **/
        
            
        
            //Dispatch(line);
    }
    return (0);
}
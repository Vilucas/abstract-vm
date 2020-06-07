#ifndef VM_HPP
#define VM_HPP

#include <unistd.h>
#include <list>
#include <algorithm>
#include <string>
#include <iterator>
#include <algorithm>
#include <iostream>
#include <map>
#include <functional>
#include "exception.hpp"

#include "Int8.hpp"


class    linesManagement
{
    public:
        std::string line;
        std::list<std::string> rawInstructionsBoard;
        size_t line_count;
};

#define print(n) (std::cout << "value = '" << n << "'" << std::endl)
#define usage "[usage]: ./abstracrt_vm path_to_instructions_file"
bool    parsing(std::string &line);
std::list<std::string>  instructionParsing(linesManagement lm);
void    instructions(linesManagement lm);
size_t countSpacesAhead(std::string tmp_line, size_t pos);
#endif
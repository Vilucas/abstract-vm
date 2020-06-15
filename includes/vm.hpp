#ifndef VM_HPP
#define VM_HPP

#define print(n) (std::cout << "value = '" << n << "'" << std::endl)
#define usage "[usage]: ./abstracrt_vm path_to_instructions_file"

#include <unistd.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iterator>
#include <algorithm>
#include <iostream>
#include <map>
#include <functional>
#include "exception.hpp"
#include "stack.hpp"

class    linesManagement
{
    public:
        std::string line;
        std::vector<std::string> rawInstructionsBoard;
        size_t line_count;
};


bool                        parsing(std::string &line);
std::vector<std::string>    instructionParsing(linesManagement const &lm);
size_t                      countSpacesAhead(std::string tmp_line, size_t pos);

#endif
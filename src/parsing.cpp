
#include <iostream>
#include "vm.hpp"

bool    commentParsing(std::string &line)
{
    int idx;
    char buffer[line.size()];

    if ((idx = line.find(';')) > 0)
    {
        line.copy(buffer, idx, 0);
        buffer[idx] = '\0';
        line = buffer;
    }
    else if (idx == 0)
        return false;
    return true;
}

bool    parsing(std::string &line)
{
    if (commentParsing(line) == false)              // comments removing 
        return false;
    if (countSpacesAhead(line, 0) == line.size())   // return line full of spaces ? false : true
        return false;
    std::cout << "line in parsing = " << line << std::endl;
    return true;
}
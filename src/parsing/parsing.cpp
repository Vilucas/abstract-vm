
#include <iostream>
#include "vm.hpp"

bool    commentParsing(std::string &line)
{
    int idx;
    char buffer[line.size()];

    if (line.size() == 2)
        if ((line[0] == line[1]) && line[0] == ';')
            exit(1);
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
    return true;
}
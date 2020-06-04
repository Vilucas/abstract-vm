
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

size_t countSpacesAhead(std::string tmp_line, size_t pos)
{
    size_t ret = 0;
    for (int i = pos; i < int(tmp_line.size()) && (tmp_line[i] == ' ' || tmp_line[i] == '\t'); i++)
        ret++;
    return ret;
}

std::list<std::string>  splitString(std::string line)
{
    size_t pos = 0;
    std::list<std::string> ret;
    std::string token;
    while (line[0] && line[0] == ' ')
        line.erase(0, 1);
    while ((pos = line.find(' ')) && line.empty() == false)
    {
        token = line.substr(0, pos);
        ret.push_back(token);
        line.erase(0, pos + countSpacesAhead(line, pos));
    }
    return (ret);
}

int     instructionParsing(std::string &line, size_t line_count)
{
    std::list<std::string> instructionBoard = { "push", "pop",
        "dump", "assert",
        "add", "sub",
        "mul", "div",
        "mod", "print",
        "exit" };

    std::list<std::string> typeBoard = {
        "int8", "int16", 
        "int32", "float",
        "double" };
    //lineStandardization(line);
    std::cout << "line = '" << line << "'" << std::endl;
    std::list<std::string> ret = splitString(line);
    std::list<std::string>::iterator it;
    for (it = ret.begin(); it != ret.end(); it++)
    {
        //std::cout << *it;
        bool found = (std::find(instructionBoard.begin(), instructionBoard.end(), *it) != instructionBoard.end());
        if (!found)
            throw(LexicalErrorException(std::to_string(line_count)));
        std::cout << " = " << found << std::endl;
    }
    return (0);
}

bool    parsing(std::string &line, size_t line_count)
{
    if (commentParsing(line) == false)
        return false;    

    instructionParsing(line, line_count);
    std::cout << "sleep 1" << std::endl;
    sleep(1);
    exit(1);
    //instructionChecker(line);
    std::cout << "'" << line << "'" << std::endl;
}
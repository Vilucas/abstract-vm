
#include <iostream>

int    commentParsing(std::string &line)
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
        return -1;
    return 0;
}

int     instructionParsing(std::string &line)
{
    std::string instructionBoard[11] = {
        "push", "pop",
        "dump", "assert",
        "add", "sub",
        "mul", "div",
        "mod", "print",
        "exit" };
    std::string typeBoard[5] = {
        "int8", "int16",
        "int32", "float"
        "double" };

}

bool    parsing(std::string &line)
{
    if (commentParsing(line) != 0)
        return false;
    if (instructionParsing(line) != 0)
        return false;
    //instructionChecker(line);
    std::cout << "'" << line << "'" << std::endl;
   
    return false;
}
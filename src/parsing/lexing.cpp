#include "vm.hpp"
#include <list>

size_t countSpacesAhead(std::string tmp_line, size_t pos)
{
    size_t ret = 0;
    for (int i = pos; i < int(tmp_line.size()) && (tmp_line[i] == ' ' || tmp_line[i] == '\t'); i++)
        ret++;
    return ret;
}

std::vector<std::string>  splitString(std::string line)
{
    size_t pos = 0;
    std::vector<std::string> ret;
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

std::vector<std::string>     slicingBySpaces(linesManagement const &lm)
{
    std::list<std::string> instructionBoard = { "push", "pop",
        "dump", "assert",
        "add", "sub",
        "mul", "div",
        "mod", "print",
        "exit"};
    std::vector<std::string> ret = splitString(lm.line);
    std::vector<std::string>::iterator it = ret.begin();

    if (ret.size() > 2)
        throw(LexicalErrorException(lm.line_count));
    bool found;
    if ((found = std::find(instructionBoard.begin(), 
        instructionBoard.end(), *it) != instructionBoard.end()) == false)
            throw(LexicalErrorException(lm.line_count));
    return ret;   
}

std::vector<std::string>  lexer(linesManagement const &lm)
{
    try {
        std::vector<std::string> board = slicingBySpaces(lm);
        return (board);
    }
    catch (LexicalErrorException &e) {
            std::cerr << e.what() << std::endl;
            exit(1);
    }
    catch (std::exception &e) {
            std::cout << "An error occured, program will now exit..." << std::endl;
            exit(1);
    }
}
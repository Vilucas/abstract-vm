#include "vm.hpp"

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
/* pseudo code for parsing after important part
void    checktype
std::list<std::string> typeBoard = {
        "int8", "int16", 
        "int32", "float",
        "double" };

    if ret[0] diff of the two isntructions thatb take param -> false
    if ret[1] is ot a correct type -> false
    if whats insine the ret[1] parenthesis is bullshit -> false
*/
std::list<std::string>     slicingBySpaces(linesManagement lm)
{
    std::list<std::string> instructionBoard = { "push", "pop",
        "dump", "assert",
        "add", "sub",
        "mul", "div",
        "mod", "print",
        "exit" };

    std::cout << "line = '" << lm.line << "'" << std::endl;
    std::list<std::string> ret = splitString(lm.line);
    std::list<std::string>::iterator it = ret.begin();

  //  if (ret.size() > 1)
//     CheckTypes(lm, ret)
    if (ret.size() > 2)
        throw(LexicalErrorException(std::to_string(lm.line_count)));
    bool found;
    if ((found = std::find(instructionBoard.begin(), 
        instructionBoard.end(), *it) != instructionBoard.end()) == false)
            throw(LexicalErrorException(std::to_string(lm.line_count)));
    std::cout << *it << found << std::endl;
    return ret;   
}
std::list<std::string>  instructionParsing(linesManagement lm)
{
    try {
        std::list<std::string> board = slicingBySpaces(lm);
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
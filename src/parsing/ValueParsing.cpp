#include "stack.hpp"
#include "exception.hpp"
#include "Master.hpp"

//simply block int8(1.4) and other kind of misuse of variable precision
void          ParsePrecision(std::string s, size_t typeNumber, size_t lineCount)
{
    size_t flag;

    if (s.empty() || s[0] == '.')
        throw(LexicalErrorException(lineCount));
    flag = s.find('.');
    if (flag == std::string::npos)
        return;
    if (typeNumber <= 2)
        throw(PrecisionExceptionError()); //int var type has precision=0
    if ((typeNumber == 3 && (s.size() - (flag + 1) > PRECISION_FLOAT)) || (typeNumber == 4 && (s.size() - (flag + 1) > PRECISION_DOUBLE))) 
        throw(PrecisionExceptionError()); //che1cked precision max for float and double
}

//More than two dots or two minus, or non numerical values
void           ParseInvalidChars(std::string s, size_t lineCount)
{
    size_t tokenPoint = std::count(s.begin(), s.end(), '.');
    size_t tokenMinus = std::count(s.begin(), s.end(), '-');

    if (tokenMinus > 1 || tokenPoint > 1)
        throw(LexicalErrorException(lineCount));
    for (size_t i = 0; i < s.size(); i++)
        if (std::isdigit(s[i]) == 0) // isdigit returns non 0 value if the param IS a digit 
            if ((s[i] != '-' || (s[i] == '-' && i > 0)) && s[i] != '.') //handling neg values
                throw(LexicalErrorException(lineCount));
}

//Parsing the argmuent value # decided not to handle numvers with 000 before actual number , jsut user trying to fk me not interesting
std::string   parseValue(std::string s, size_t lineCount, size_t typeNumber)
{
    if (s.empty() || s.back() != ')' || (s.size() == 1))
        throw(LexicalErrorException(lineCount));
    s.pop_back(); // delete closing bracket
    if ((s[0] == '-' && s.size() == 1) || (s[0] == '.') || (strcmp("-.", s.c_str()) == 0)) //test if user is trying to screw me over
            throw(LexicalErrorException(lineCount));
    ParseInvalidChars(s, lineCount);
    ParsePrecision(s, typeNumber, lineCount);
    return s;
}

//compare the value of the input with all the available variable types. exit() if fails to find a valid one
eOperandType ValueLexing(std::vector<std::string> &tab, std::string *value, size_t lineCount)
{
    std::vector<std::string> typeBoard = {
        "int8(", "int16(", 
        "int32(", "float(",
        "double(" };
    if (tab.size() != 2)
        throw (LexicalErrorException(lineCount));
    for (size_t i = 0 ; i < typeBoard.size(); i++)
        if (std::strncmp(tab[1].c_str(), typeBoard[i].c_str(), typeBoard[i].size()) == 0)
        {
            *value = tab[1].substr(typeBoard[i].size(), tab[1].size() - (typeBoard[i]).size());
            *value = parseValue(*value, lineCount, i); // modify the variable to get the value between the brackets
            return eOperandType(i);
        }
    throw(LexicalErrorException(lineCount));
}
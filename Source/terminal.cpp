#include <iostream>
#include <string>
#include <list>
#include <iterator>

#include <terminal.hpp>
#include <terminal_codes.hpp>

void Terminal::Print(std::string str)
{
    std::cout << str;
}

void Terminal::PrintNewLine()
{
    std::cout << std::endl;
}

void Terminal::PrintWithNewLine(std::string str)
{
    Terminal::Print(str);
    Terminal::PrintNewLine();
}

void Terminal::PrintAnsiEscapeCode(std::list<int> codes_l)
{
    codes_l.unique();

    std::string str;

    for(;!codes_l.empty();codes_l.pop_front()) 
    {
        str += std::to_string(codes_l.front());
        str += codes_l.size() == 1 ? "m" : ";";
    }

    Terminal::Print("\033[" + str);
}

void Terminal::PrintTextStartedOfAnsiEscapeCodes(std::string text, std::list<int> codes_l)
{
    Terminal::PrintAnsiEscapeCode(codes_l);
    Terminal::Print(text);
}

void Terminal::ResetAnsiCodes()
{
    std::list list = { reset_code };
    Terminal::PrintAnsiEscapeCode(list);
}

void Terminal::PrintWithStyling(std::string text, std::list<int> codes_l)
{
    Terminal::PrintTextStartedOfAnsiEscapeCodes(text, codes_l);
    Terminal::ResetAnsiCodes();
}
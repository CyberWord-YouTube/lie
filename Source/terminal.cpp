#include <iostream>
#include <string>

#include <terminal.hpp>

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
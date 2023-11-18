#include <iostream>

#include <terminal.hpp>
#include <terminal_codes.hpp>

int main(int argc, char **argv)
{
    //Init Objects
    Terminal terminal_obj;

    //Print hello in terminal
    terminal_obj.PrintWithNewLine("Hello");
}
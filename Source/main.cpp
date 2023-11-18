#include <iostream>

#include <terminal.hpp>
#include <terminal_codes.hpp>

using namespace CodesConverter;

int main(int argc, char **argv)
{
    //Init Objects
    Terminal terminal_obj;
    bool appWorking = true;

    //Application Loop
    while (appWorking)
    {
        terminal_obj.SetWindowSize();

        terminal_obj.PrintWithNewLine("LIN: " + std::to_string(terminal_obj.GetTerminalLines()));
        terminal_obj.PrintWithNewLine("COL: " + std::to_string(terminal_obj.GetTerminalColumns()));
        sleep(1);
    }

    return 0;
}
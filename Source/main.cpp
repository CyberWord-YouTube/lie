#include <iostream>

#include <terminal.hpp>
#include <terminal_codes.hpp>

using namespace CodesConverter;

int main(int argc, char **argv)
{
    //Init Objects
    Terminal terminal_obj;
    bool appWorking { true };

    //Application Loop
    while (appWorking)
    {
        terminal_obj.UpdateWindowSizeData();

        if (!CompareOldAndNewSize())
        {
            terminal_obj.ClearTerminal();
            terminal_obj.SetCursorPos(1,1);
            terminal_obj.PrintWithNewLine("LIN: " + std::to_string(nl));
            terminal_obj.PrintWithNewLine("COL: " + std::to_string(nc));

        }        
    }

    return 0;
}
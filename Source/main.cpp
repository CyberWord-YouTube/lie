#include <iostream>

#include <terminal.hpp>
#include <terminal_codes.hpp>

using namespace CodesConverter;

void RenderInTerminal(Terminal terminal_obj);

int main(int argc, char **argv)
{
    //Init Objects
    Terminal terminal_obj;
    bool appWorking { true };
    

    //Application Loop
    while (appWorking)
    {
        if (!terminal_obj.CompareOldAndNewSize())
        {
            RenderInTerminal(terminal_obj);
        }

        terminal_obj.UpdateWindowSizeData();        
    }

    return 0;
}
void RenderInTerminal(Terminal terminal)
{
    terminal.ClearTerminal();
    terminal.SetCursorPos(1,1);

}
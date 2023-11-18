#include <string>
#include <list>
#include <sys/ioctl.h>
#include <unistd.h>

class Terminal
{
    private:
        struct winsize wsize;
    public:
        Terminal() 
        {
            this->UpdateWindowSizeData();
        }

        void Print(std::string str);
        void PrintNewLine();
        void PrintWithNewLine(std::string str);
        void PrintAnsiEscapeCode(std::list<int> codes);
        void PrintTextStartedOfAnsiEscapeCodes(std::string text, std::list<int> codes_l);
        void ResetAnsiCodes();
        void PrintWithStyling(std::string text, std::list<int> codes_l);
        
        void UpdateWindowSizeData();
        int GetTerminalLines();
        int GetTerminalColumns();
};
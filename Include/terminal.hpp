#include <string>
#include <list>
#include <sys/ioctl.h>
#include <unistd.h>

class Terminal
{
    private:
        struct winsize wsize;

        int old_lines_count {}
        int new_lines_count {}
        int old_columns_count {}
        int new_columns_count {}
    public:
        Terminal() 
        {
            UpdateWindowSizeData();
            old_lines_count = new_lines_count;
            old_columns_count = new_columns_count;

            new_lines_count = GetTerminalLines();
            new_columns_count = GetTerminalColumns();
        }

        void Print(std::string str);
        void PrintNewLine();
        void PrintWithNewLine(std::string str);
        void PrintAnsiEscapeCode(std::list<int> codes, char aec_cmd_code);
        void PrintTextStartedOfAnsiEscapeCodes(std::string text, std::list<int> codes_l, char aec_cmd_code);
        void ResetAnsiCodes();
        void PrintWithStyling(std::string text, std::list<int> codes_l, char aec_cmd_code);
        
        void UpdateWindowSizeData();
        int GetTerminalLines();
        int GetTerminalColumns();
        void ClearTerminal();
        bool CompareOldAndNewSize();
        
        void SetCursorPos(int x, int y);
};
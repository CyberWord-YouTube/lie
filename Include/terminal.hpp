#include <string>
#include <list>

class Terminal
{
    public:
        void Print(std::string str);
        void PrintNewLine();
        void PrintWithNewLine(std::string str);
        void PrintAnsiEscapeCode(std::list<int> codes);
        void PrintTextStartedOfAnsiEscapeCodes(std::string text, std::list<int> codes_l);
        void ResetAnsiCodes();
        void PrintWithStyling(std::string text, std::list<int> codes_l);
};
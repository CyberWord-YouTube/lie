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
    Print(str);
    PrintNewLine();
}

void Terminal::PrintAnsiEscapeCode(std::list<int> codes_l, char aec_cmd_code)
{
    codes_l.unique();

    std::string str;
    std::string cmd_mode_string{aec_cmd_code};

    for(;!codes_l.empty();codes_l.pop_front()) 
    {
        str += std::to_string(codes_l.front());
        str += codes_l.size() == 1 ? cmd_mode_string : ";";
    }

    Terminal::Print("\033[" + str);
}

void Terminal::PrintTextStartedOfAnsiEscapeCodes(std::string text, std::list<int> codes_l, char aec_cmd_code)
{
    PrintAnsiEscapeCode(codes_l, aec_cmd_code);
    Print(text);
}

void Terminal::ResetAnsiCodes()
{
    std::list list = { reset_code };
    PrintAnsiEscapeCode(list, reset_cmd_code);
}

void Terminal::PrintWithStyling(std::string text, std::list<int> codes_l, char aec_cmd_code)
{
    PrintTextStartedOfAnsiEscapeCodes(text, codes_l, aec_cmd_code);
    ResetAnsiCodes();
}

void Terminal::UpdateWindowSizeData()
{
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &wsize);
}

int Terminal::GetTerminalLines()
{
    return wsize.ws_row;
}

int Terminal::GetTerminalColumns()
{
    return wsize.ws_col;    
}

void Terminal::ClearTerminal()
{
    PrintAnsiEscapeCode({clear_screen_mode}, clear_screen_cmd_code);
}

bool Terminal::CompareOldAndNewSize()
{
    return (old_lines_count == new_lines_count) && (old_columns_count == new_columns_count);
}

void Terminal::SetCursorPos(int x, int y)
{
    PrintAnsiEscapeCode({x, y}, set_cur_pos_cmd_code);
}
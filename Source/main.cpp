#include <iostream>

#include <terminal.hpp>
#include <terminal_codes.hpp>

using namespace CodesConverter;

int main(int argc, char **argv)
{
    //Init Objects
    Terminal terminal_obj;

    //Print hello in terminal
    terminal_obj.PrintWithStyling(" --- LIE", { styles_to_assci_code(e_styles::Inverse, e_style_state::On) });
}
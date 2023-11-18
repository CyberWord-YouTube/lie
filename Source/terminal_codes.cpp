#include <terminal_codes.hpp>

namespace CodesConverter
{
    int colors_enum_to_assci_code_int(e_colors color, e_color_mode mode)
    {
        int color_assci_code = static_cast<int>(color) + static_cast<int>(mode);
        return color_assci_code;
    }

    int styles_enum_to_assci_code_int(e_styles style, e_style_state state)
    {
        int style_assci_code = static_cast<int>(style) + static_cast<int>(state);
        return style_assci_code;
    }
}
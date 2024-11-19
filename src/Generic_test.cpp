// Version 0.0.1 built 241118
// DOF Studio
// Providing a colorful command line output
//

#include "Colorful.hpp"
#include "Colorful_Presets.hpp"
#include "Styleful.hpp"
#include "Styleful_Presets.hpp"


#include <iostream>


int main()
{
    using namespace ColorPresets;
    using namespace StylePresets;

    
    std::cout << red<char> << "Red is for Roster" << reset<char> << std::endl;
    std::cout << green<char> << "Green is for Garage" << reset<char> << std::endl;
    std::cout << blue<char> << "Blue is for Bible ~ Oh, Jesus gush!" << reset<char> << std::endl;

    
    std::cout << yellow<char> << "Yellow is a yielding field" << reset<char> << std::endl;
    std::cout << cyan<char> << "Cyan is the lightblue sky" << reset<char> << std::endl;
    std::cout << pale_violet_red<char> << "Violet Red is the color that we all buy." << reset<char> << std::endl;

    
    std::wcout << magenta<wchar_t> << L"Magenta is developed by Ack" << reset<wchar_t> << std::endl;
    std::wcout << salmon<wchar_t> << L"Salmon is etable if fresh" << reset<wchar_t> << std::endl;
    std::wcout << ggplot2_pink<wchar_t> << L"ggplot2 has a color that is pig-like." << reset<wchar_t> << std::endl;

    
    CL_RGB custom_rgb_fg(255, 165, 0); 
    Color<char> custom_fg(custom_rgb_fg, ColorType::FG);
    std::cout << custom_fg << "Orange is good for autumn" << reset<char> << std::endl;

    
    CL_RGB custom_rgb_bg(128, 0, 128); 
    Color<char> custom_bg(custom_rgb_bg, ColorType::BG);
    std::cout << custom_bg << "Purple is what NYU prides" << reset<char> << std::endl;

    
    std::cout << light_yellow<char> << bg_alice_blue<char> << "I bet you can't see the words with that guy." << reset<char> << std::endl;

    
    std::cout << bold<char> << royal_blue<char> << "Here is the end" << color_reset<char> << style_reset<char> << std::endl;
    std::cout << italic<char> << golden_rod<char> << "Do not append" << reset<char> << style_reset<char> << std::endl;
    std::cout << bold<char> << underline<char> << verdigris<char> << "I'm seeking for an internship; who wants a giant?" << reset<char> << style_reset<char> << std::endl;

    std::cout << std::endl << "I'm Nathmath from DOF Studio. Thank you for using!" << std::endl;

    return 0;
}

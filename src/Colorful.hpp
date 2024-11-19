// Version 0.0.1 built 241118
// DOF Studio
// Providing a colorful command line output
//

#ifndef COLORFUL_H
#define COLORFUL_H

#include <iostream>
#include <string>
#include <type_traits>
#include <sstream>

#ifdef _WIN32
#include <windows.h>
#pragma once
#endif

#include "EscapeEnabled.h"


enum class ColorType
{
    FG = 0x0001,  
    BG = 0x0010,  
};


struct CL_RGB
{
public:
    int r; 
    int g; 
    int b; 

public:
    constexpr CL_RGB() noexcept : r(0), g(0), b(0) {}
    constexpr CL_RGB(int red, int green, int blue) noexcept : r(red), g(green), b(blue) {}
    constexpr CL_RGB(const CL_RGB& x) noexcept : r(x.r), g(x.g), b(x.b) {}
    constexpr CL_RGB(CL_RGB&& x) noexcept : r(x.r), g(x.g), b(x.b) {}
};


template<typename _TypeChar = CHAR>
class ColorFall
{
public:
    extern enum class ColorCode;
    
private:
    ColorType type_;   
    bool is_rgb_;      
    ColorCode code_;   
    CL_RGB rgb_;       

public:
    using StringType = std::basic_string<_TypeChar>;
    using OstreamType = std::basic_ostream<_TypeChar>;

public:
    
    constexpr enum class ColorCode
    {
        
        FG_DEFAULT = 39,
        FG_BLACK = 30,
        FG_RED = 31,
        FG_GREEN = 32,
        FG_YELLOW = 33,
        FG_BLUE = 34,
        FG_MAGENTA = 35,
        FG_CYAN = 36,
        FG_LIGHT_GRAY = 37,
        FG_DARK_GRAY = 90,
        FG_LIGHT_RED = 91,
        FG_LIGHT_GREEN = 92,
        FG_LIGHT_YELLOW = 93,
        FG_LIGHT_BLUE = 94,
        FG_LIGHT_MAGENTA = 95,
        FG_LIGHT_CYAN = 96,
        FG_WHITE = 97,
        
        BG_DEFAULT = 49,
        BG_BLACK = 40,
        BG_RED = 41,
        BG_GREEN = 42,
        BG_YELLOW = 43,
        BG_BLUE = 44,
        BG_MAGENTA = 45,
        BG_CYAN = 46,
        BG_LIGHT_GRAY = 47,
        BG_DARK_GRAY = 100,
        BG_LIGHT_RED = 101,
        BG_LIGHT_GREEN = 102,
        BG_LIGHT_YELLOW = 103,
        BG_LIGHT_BLUE = 104,
        BG_LIGHT_MAGENTA = 105,
        BG_LIGHT_CYAN = 106,
        BG_WHITE = 107,
        
        RESET = 0
    };

public:
    
    constexpr ColorFall(ColorCode code) noexcept : type_(ColorType::FG), is_rgb_(false), code_(code) {}
    constexpr ColorFall(ColorCode code, ColorType type) noexcept : type_(type), is_rgb_(false), code_(code) {}

    
    constexpr ColorFall(const CL_RGB& rgb, ColorType type = ColorType::FG) noexcept : type_(type), is_rgb_(true), rgb_(rgb) {}
    constexpr ColorFall(int r, int g, int b, ColorType type = ColorType::FG) noexcept : type_(type), is_rgb_(true), rgb_(r, g, b) {}

    
    friend OstreamType& operator<<(OstreamType& os, const ColorFall& mod)
    {
        if constexpr (std::is_same_v<_TypeChar, char>)
        {
            if (mod.is_rgb_)
            {
                std::ostringstream oss;
                oss << "\033[" << (mod.type_ == ColorType::FG ? "38;2;" : "48;2;")
                    << mod.rgb_.r << ";" << mod.rgb_.g << ";" << mod.rgb_.b << "m";
                os << oss.str();
            }
            else
            {
                os << "\033[" << static_cast<int>(mod.code_) << "m";
            }
        }
        else if constexpr (std::is_same_v<_TypeChar, wchar_t>)
        {
            if (mod.is_rgb_)
            {
                std::wostringstream woss;
                woss << L"\033[" << (mod.type_ == ColorType::FG ? L"38;2;" : L"48;2;")
                    << mod.rgb_.r << L";" << mod.rgb_.g << L";" << mod.rgb_.b << L"m";
                os << woss.str();
            }
            else
            {
                os << L"\033[" << static_cast<int>(mod.code_) << L"m";
            }
        }
        return os;
    }
};


#endif 

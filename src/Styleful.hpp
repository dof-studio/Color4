// Version 0.0.1 built 241118
// DOF Studio
// Providing a colorful command line output
//

#ifndef STYLEFUL_H
#define STYLEFUL_H

#include <iostream>
#include <string>
#include <type_traits>
#include <sstream>

#ifdef _WIN32
#include <windows.h>
#pragma once
#endif

#include "EscapeEnabled.h"


template<typename _TypeChar>
class StyleFall
{
private:
    extern enum class StyleCode;
    extern enum class FontSize;
    extern enum class FontType;

private:
    bool is_font_size_;                          
    StyleCode code_;                             
    FontSize size_;                              
    FontType font_type_ = FontType::DEFAULT;     
    float scaling_factor_;                       

public:
    using StringType = std::basic_string<_TypeChar>;
    using OstreamType = std::basic_ostream<_TypeChar>;

    
    enum class StyleCode
    {
        RESET = 0,
        BOLD = 1,
        DIM = 2,
        ITALIC = 3,
        UNDERLINE = 4,
        BOLD_OFF = 22,
    };

    
    enum class FontSize
    {
        NORMAL = 0,     
        SMALL  = 1,     
        LARGE  = 2,     
        CUSTOM = 10,    
    };

    
    enum class FontType
    {
        DEFAULT     = 0,
        MONOSPACE   = 1,
        SERIF       = 2,
        SANS_SERIF  = 3,
    };

public:
    
    constexpr StyleFall(StyleCode code) : is_font_size_(false), code_(code), size_(FontSize::NORMAL), scaling_factor_(1.0) {}
    constexpr StyleFall(FontSize size) : is_font_size_(true), size_(size), scaling_factor_(1.0) {}
    constexpr StyleFall(FontSize size, float scaling_factor) : is_font_size_(true), size_(size), scaling_factor_(scaling_factor) {}
    constexpr StyleFall(FontType font_type) : is_font_size_(false), font_type_(font_type) {}

public:
    
    friend OstreamType& operator<<(OstreamType& os, const StyleFall& mod)
    {
        if constexpr (std::is_same_v<_TypeChar, char>)
        {
            
            if (mod.is_font_size_)
            {
                switch (mod.size_)
                {
                case FontSize::SMALL:
                    os << "\033[2m"; 
                    break;
                case FontSize::NORMAL:
                    os << "\033[0m"; 
                    break;
                case FontSize::LARGE:
                    os << "\033[1m"; 
                    break;
                case FontSize::CUSTOM:
                    
                    if (mod.scaling_factor_ > 1.0)
                        os << "\033[1m"; 
                    else if (mod.scaling_factor_ < 1.0)
                        os << "\033[2m"; 
                    else
                        os << "\033[0m"; 
                    break;
                }
            }
            else
            {
                os << "\033[" << static_cast<int>(mod.code_) << "m";
            }

            
            if (mod.code_ == StyleCode::BOLD)
            {
                os << "\033[1m"; 
            }
            else if (mod.code_ == StyleCode::ITALIC)
            {
                os << "\033[3m"; 
            }
            else if (mod.code_ == StyleCode::UNDERLINE)
            {
                os << "\033[4m"; 
            }
            else if (mod.code_ == StyleCode::BOLD_OFF)
            {
                os << "\033[22m"; 
            }

            
            switch (mod.font_type_)
            {
            case FontType::MONOSPACE:
                os << "\033[0m"; 
                os << "[Font: Monospace] ";
                break;
            case FontType::SERIF:
                os << "\033[0m"; 
                os << "[Font: Serif] ";
                break;
            case FontType::SANS_SERIF:
                os << "\033[0m"; 
                os << "[Font: Sans-Serif] ";
                break;
            default:
                break;
            }
        }
        else if constexpr (std::is_same_v<_TypeChar, wchar_t>)
        {
            
            if (mod.is_font_size_)
            {
                switch (mod.size_)
                {
                case FontSize::SMALL:
                    os << L"\033[2m"; 
                    break;
                case FontSize::NORMAL:
                    os << L"\033[0m"; 
                    break;
                case FontSize::LARGE:
                    os << L"\033[1m"; 
                    break;
                case FontSize::CUSTOM:
                    
                    if (mod.scaling_factor_ > 1.0)
                        os << L"\033[1m"; 
                    else if (mod.scaling_factor_ < 1.0)
                        os << L"\033[2m"; 
                    else
                        os << L"\033[0m"; 
                    break;
                }
            }
            else
            {
                os << L"\033[" << static_cast<int>(mod.code_) << L"m";
            }

            
            if (mod.code_ == StyleCode::BOLD)
            {
                os << L"\033[1m"; 
            }
            else if (mod.code_ == StyleCode::ITALIC)
            {
                os << L"\033[3m"; 
            }
            else if (mod.code_ == StyleCode::UNDERLINE)
            {
                os << L"\033[4m"; 
            }
            else if (mod.code_ == StyleCode::BOLD_OFF)
            {
                os << L"\033[22m"; 
            }

            
            switch (mod.font_type_)
            {
            case FontType::MONOSPACE:
                os << L"\033[0m"; 
                os << L"[Font: Monospace] ";
                break;
            case FontType::SERIF:
                os << L"\033[0m"; 
                os << L"[Font: Serif] ";
                break;
            case FontType::SANS_SERIF:
                os << L"\033[0m"; 
                os << L"[Font: Sans-Serif] ";
                break;
            default:
                break;
            }
        }
        return os;
    }
};

#endif 

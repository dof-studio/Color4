// Version 0.0.1 built 241118
// DOF Studio
// Providing a colorful command line output
//

#include <iostream>
#include <string>
#include <type_traits>
#include <sstream>

#include "Styleful.hpp"


#ifdef STYLEFUL_H


template<typename _TypeChar = CHAR>
using Style = StyleFall<_TypeChar>;


namespace StylePresets
{
    
    template<typename _TypeChar = CHAR>
    constexpr Style<_TypeChar> style_reset = Style<_TypeChar>(Style<_TypeChar>::StyleCode::RESET);

    
    template<typename _TypeChar = CHAR>
    constexpr Style<_TypeChar> bold = Style<_TypeChar>(Style<_TypeChar>::StyleCode::BOLD);

    template<typename _TypeChar = CHAR>
    constexpr Style<_TypeChar> italic = Style<_TypeChar>(Style<_TypeChar>::StyleCode::ITALIC);

    template<typename _TypeChar = CHAR>
    constexpr Style<_TypeChar> underline = Style<_TypeChar>(Style<_TypeChar>::StyleCode::UNDERLINE);

    template<typename _TypeChar = CHAR>
    constexpr Style<_TypeChar> bold_off = Style<_TypeChar>(Style<_TypeChar>::StyleCode::BOLD_OFF);

    
    template<typename _TypeChar = CHAR>
    inline const Style<_TypeChar> smaller = Style<_TypeChar>(Style<_TypeChar>::FontSize::SMALL);

    template<typename _TypeChar = CHAR>
    inline const Style<_TypeChar> normal = Style<_TypeChar>(Style<_TypeChar>::FontSize::NORMAL);

    template<typename _TypeChar = CHAR>
    inline const Style<_TypeChar> larger = Style<_TypeChar>(Style<_TypeChar>::FontSize::LARGE);

    
    template<typename _TypeChar = CHAR>
    inline const Style<_TypeChar> monospace = Style<_TypeChar>(Style<_TypeChar>::FontType::MONOSPACE);

    template<typename _TypeChar = CHAR>
    inline const Style<_TypeChar> serif = Style<_TypeChar>(Style<_TypeChar>::FontType::SERIF);

    template<typename _TypeChar = CHAR>
    inline const Style<_TypeChar> sans_serif = Style<_TypeChar>(Style<_TypeChar>::FontType::SANS_SERIF);
}

#endif 

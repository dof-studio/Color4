# Color4
Make your command line application more vivid by giving its `colors`, `styles`, `underscores`, and more! Just as easy as using a `std::cout`.

# What is it like?
![image](https://github.com/user-attachments/assets/de7bb322-ef7a-4ed4-9fac-7866fa1b7fbb)


# All headers with plenty of presets
All headers, use it as easy as `#include<iostream>`. Presets headers contain more than 1000 lines! Here's a snapshot.
```cpp
    template<typename _TypeChar = CHAR>
    constexpr Color<_TypeChar> black = Color<_TypeChar>(Color<_TypeChar>::ColorCode::FG_BLACK);
    template<typename _TypeChar = CHAR>
    constexpr Color<_TypeChar> red = Color<_TypeChar>(Color<_TypeChar>::ColorCode::FG_RED);
    template<typename _TypeChar = CHAR>
    constexpr Color<_TypeChar> green = Color<_TypeChar>(Color<_TypeChar>::ColorCode::FG_GREEN);
    template<typename _TypeChar = CHAR>
    constexpr Color<_TypeChar> yellow = Color<_TypeChar>(Color<_TypeChar>::ColorCode::FG_YELLOW);
    template<typename _TypeChar = CHAR>
    constexpr Color<_TypeChar> blue = Color<_TypeChar>(Color<_TypeChar>::ColorCode::FG_BLUE);
    template<typename _TypeChar = CHAR>
    constexpr Color<_TypeChar> magenta = Color<_TypeChar>(Color<_TypeChar>::ColorCode::FG_MAGENTA);
    template<typename _TypeChar = CHAR>
    constexpr Color<_TypeChar> cyan = Color<_TypeChar>(Color<_TypeChar>::ColorCode::FG_CYAN);

    ...
```

# Easy-enough-to-use
```cpp
    #include "Colorful.hpp"
    #include "Colorful_Presets.hpp"
    #include "Styleful.hpp"
    #include "Styleful_Presets.hpp"

    using namespace ColorPresets;
    using namespace StylePresets;

    std::cout << red<char> << "Red is for Roster" << reset<char> << std::endl;
    std::cout << green<char> << "Green is for Garage" << reset<char> << std::endl;
    std::cout << blue<char> << "Blue is for Bible ~ Oh, Jesus gush!" << reset<char> << std::endl;
```


# Customizable RGB and combination
```cpp
    #include "Colorful.hpp"
    #include "Colorful_Presets.hpp"
    #include "Styleful.hpp"
    #include "Styleful_Presets.hpp"

    using namespace ColorPresets;
    using namespace StylePresets;

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
```

# More examples
Refers to `src/Generic_test.cpp`


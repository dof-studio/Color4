// Version 0.0.1 built 241118
// DOF Studio
// Providing a colorful command line output
//

#ifdef _WIN32
#include <windows.h>
#pragma once
#endif


namespace ConsoleUtils {
#ifdef _WIN32
    inline void enableAnsiEscapeCodes()
    {
        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        if (hOut != INVALID_HANDLE_VALUE)
        {
            DWORD dwMode = 0;
            if (GetConsoleMode(hOut, &dwMode))
            {
                dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
                SetConsoleMode(hOut, dwMode);
            }
        }
    }
    class enableSnsiEscapeCodesClass {
    public:
        static void enableAnsiEscapeCodes() {
#ifdef _WIN32
            HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
            if (hOut != INVALID_HANDLE_VALUE)
            {
                DWORD dwMode = 0;
                if (GetConsoleMode(hOut, &dwMode))
                {
                    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
                    SetConsoleMode(hOut, dwMode);
                }
            }
#endif
        }
    };
#endif
}


#ifdef _WIN32
namespace {
    struct ConsoleInitializer {
        ConsoleInitializer() {
            ConsoleUtils::enableAnsiEscapeCodes();
        }
    } consoleInitializer; 
}
#endif

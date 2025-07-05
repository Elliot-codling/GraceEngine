#pragma once
#include <iostream>
#include <string>

inline const char* c_GREEN = "\033[92m";
inline const char* c_MAGENTA = "\033[95m";
inline const char* c_YELLOW = "\033[93m";
inline const char* c_RED = "\033[91m";
inline const char* c_DEFAULT = "\033[39;49m";

/*
Output to the terminal
Print out in the format: [day/month/year] [hour:minute:second] [infoType] content
Used for debugging purposes and logging

Examples of info:
- SFML initialised
- GraceEngine configuration

Examples of debug:
- User specific output e.g index: 1
- Accessible outside the engine

Examples of warnings:
- Sprites, text not initialised
- Logical errors (texture directories mis-spelt etc)

Examples of errors:
- Game crashing functions
- C++ errors print here

*/
class DebugHandler
{
public:
    static void printDebugInfo(const std::string &content) { std::cout << getTimeAndDate() << c_MAGENTA << "DEBUG"<< c_DEFAULT << "] "<< content << "\n"; }
    static void printDebugInfo(const int content) { std::cout << getTimeAndDate() << c_MAGENTA << "DEBUG"<< c_DEFAULT << "] "<< std::to_string(content) << "\n"; }
    static void printDebugInfo(const float content) { std::cout << getTimeAndDate() << c_MAGENTA << "DEBUG"<< c_DEFAULT << "] "<< std::to_string(content) << "\n"; }
protected:
    // Can be accessed via graceengine when that class inherits this
    // Anything outside graceengine cannot access this

    static void printInfo(const std::string &content) { std::cout << getTimeAndDate() << c_GREEN << "INFO"<< c_DEFAULT << "] "<< content << "\n"; }
    static void printInfo(const int content) { std::cout << getTimeAndDate() << c_GREEN << "INFO"<< c_DEFAULT << "] "<< std::to_string(content) << "\n"; }
    static void printInfo(const float content) { std::cout << getTimeAndDate() << c_GREEN << "INFO"<< c_DEFAULT << "] "<< std::to_string(content) << "\n"; }

    static void printWarningInfo(const std::string &content) { std::cout << getTimeAndDate() << c_YELLOW << "WARNING"<< c_DEFAULT << "] "<< content << "\n"; }
    static void printWarningInfo(const int content) { std::cout << getTimeAndDate() << c_YELLOW << "WARNING"<< c_DEFAULT << "] "<< std::to_string(content) << "\n"; }
    static void printWarningInfo(const float content) { std::cout << getTimeAndDate() << c_YELLOW << "WARNING"<< c_DEFAULT << "] "<< std::to_string(content) << "\n"; }

    static void printErrorInfo(const std::string &content) { std::cout << getTimeAndDate() << c_RED << "ERROR"<< c_DEFAULT << "] "<< content << "\n"; }
    static void printErrorInfo(const int content) { std::cout << getTimeAndDate() << c_RED << "ERROR"<< c_DEFAULT << "] "<< std::to_string(content) << "\n"; }
    static void printErrorInfo(const float content) { std::cout << getTimeAndDate() << c_RED << "ERROR"<< c_DEFAULT << "] "<< std::to_string(content) << "\n"; }

private:
    [[nodiscard]] static std::string getTimeAndDate();

};

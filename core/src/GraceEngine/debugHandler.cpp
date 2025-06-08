#include <GraceEngine/debugHandler.h>

#define GREEN "\033[92m"
#define MAGENTA "\033[95m"
#define YELLOW "\033[93m"
#define RED "\033[91m"
#define DEFAULT "\033[39;49m"

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

void debugHandler::printInfo(const std::string &content)
{
    std::cout << getTimeAndDate() << GREEN << "INFO"<< DEFAULT << "] "<< content << "\n";
}

void debugHandler::printDebugInfo(const std::string &content)
{
    std::cout << getTimeAndDate() << MAGENTA << "DEBUG"<< DEFAULT << "] "<< content << "\n";
}


void debugHandler::printWarningInfo(const std::string &content)
{
    std::cout << getTimeAndDate() << YELLOW << "WARNING"<< DEFAULT << "] "<< content << "\n";
}

void debugHandler::printErrorInfo(const std::string &content)
{
    std::cout << getTimeAndDate() << RED << "ERROR"<< DEFAULT << "] "<< content << "\n";
    std::cout << "Press Enter to close window...";
    //Pause the program before it crashes
    std::cin.get();
    exit(EXIT_FAILURE);
}


char* debugHandler::getTimeAndDate()
{
    //Get current time
    time_t timeStamp = time(nullptr);
    //Create time struct based on local time
    tm datetime = *localtime(&timeStamp);


    static char output[50];
    //Get dd/mm/yyyy hr:min:sec
    strftime(output, 50, "[%d/%m/%Y] [%H:%M:%S] [", &datetime);
    return output;
}

#include <GraceEngine/debugHandler.h>


//Get the date and time to put at the start of a debug message
std::string debugHandler::getTimeAndDate()
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

#pragma once
#include <iostream>
#include <ctime>

class debugHandler {
protected:
    //Can be accessed via graceengine when that class inherits this
    //Anything outside of graceengine cannot access this
    void printInfo(const std::string &content);
    void printDebugInfo(const std::string &content);
    void printWarningInfo(const std::string &content);
    void printErrorInfo(const std::string &content);

private:
    char* getTimeAndDate();

};
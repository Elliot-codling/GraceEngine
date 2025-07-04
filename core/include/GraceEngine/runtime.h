#pragma once
#include "../../../include/mainScript.h"

//Access to the debug handler
class runtime : public debugHandler
{
public:
    //Starts the window
    runtime(const std::string &name, const int &width, const int &height, const sf::Color &color = {0, 0, 0});
    ~runtime() = default;

    static void printErrorInfo(const std::string &content) { debugHandler::printErrorInfo(content); }

    //Update loop
    int update();
    //End the program
    static int end();

private:
    //Set up variables for fixed update
    //runs once per 16.666ms (updates at 60fps)
    float m_fixedTime = 1.f / 60.f;
    float m_timeSinceLastUpdate = 0.f;
    float m_deltaTime = 0.f;
    sf::Clock m_clock;
    sf::Time m_timeElapsed;

    graceEngine m_window;
};

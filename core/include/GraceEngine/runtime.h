#pragma once
#include "../../../GraceEditor/include/mainScript.h"

#include <sstream>
#include <csignal>

//Access to the debug handler

class runtime : public debugHandler
{
public:
    runtime(const std::string &name, int width, int height, sf::Color color = {0, 0, 0});
    ~runtime() { debugHandler::printInfo("Destroyed runtime"); }

    void printErrorInfo(const std::string &content) { debugHandler::printErrorInfo(content); }

    int update();
    int end();

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

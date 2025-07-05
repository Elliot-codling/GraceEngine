#pragma once
#include "../../include/mainScript.h"

// Access to the debug handler
class Runtime : public DebugHandler
{
public:
    // Starts the window
    Runtime(const char* name, int width, int height, sf::Color color = {0, 0, 0});
    ~Runtime() = default;

    static void printErrorInfo(const std::string &content) { DebugHandler::printErrorInfo(content); }

    // Update loop
    int update();
    // End the program
    static int end();

private:
    // Set up variables for fixed update
    // runs once per 16.666ms (updates at 60fps)
    const float c_fixedTime = 1.f / 60.f;
    float m_timeSinceLastUpdate = 0.f;
    float m_deltaTime = 0.f;
    sf::Clock m_clock;
    sf::Time m_timeElapsed;

    GraceEngine m_window;
};

// Runtime code that controls what scripts are executed and when
#include "../include/runtime.h"

Runtime::Runtime(const char* name, const int width, const int height, const sf::Color color):
m_window(name, width, height, color)
{
    //Start the program
    runtimeFunctions::start(m_window);
}


//Update the program
int Runtime::update()
{
    //Game loop
    while (m_window.isRunning())
    {
        m_timeElapsed = m_clock.restart();
        m_timeSinceLastUpdate += m_timeElapsed.asSeconds();

        while (m_timeSinceLastUpdate >= m_fixedTime)
        {
            m_deltaTime = m_timeSinceLastUpdate / m_fixedTime;
            runtimeFunctions::fixedUpdate(m_window, m_deltaTime);
            //Update current frametime
            m_window.setFrametime(m_timeElapsed.asSeconds());
            m_timeSinceLastUpdate -= m_fixedTime;
        }
        runtimeFunctions::update(m_window);
    }
    return 0;
}

int Runtime::end()
{
    //Destroy objects
    runtimeFunctions::end();
    return 0;
}

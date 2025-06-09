// Runtime code that controls what scripts are executed and when
#include <GraceEngine/runtime.h>

runtime::runtime(const std::string &name, const int &width, const int &height, const sf::Color &color):
m_window(name, width, height, color)
{
    //Start the program
    runtimeFunctions::start(m_window);
}


//Update the program
int runtime::update()
{
    //Game loop
    while (m_window.isRunning())
    {
        m_timeElapsed = m_clock.restart();
        m_timeSinceLastUpdate += m_timeElapsed.asSeconds();

        switch (m_timeSinceLastUpdate >= m_fixedTime)
        {
            case true:
                m_deltaTime = m_timeSinceLastUpdate / m_fixedTime;
                runtimeFunctions::fixedUpdate(m_window, m_deltaTime);
                //Update current frametime
                m_window.setFrametime(m_timeElapsed.asSeconds());
                m_timeSinceLastUpdate = 0;
                break;
            case false:
                runtimeFunctions::update(m_window);
                break;
        }
    }
    return 0;
}

int runtime::end()
{
    //Destroy objects
    runtimeFunctions::end();
    return 0;
}

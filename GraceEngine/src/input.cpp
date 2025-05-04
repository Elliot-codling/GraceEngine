#include "../include/input.h"
//Clear current events
//Then gather new events happening in the window and store them to the queue
void gameEvents::updateEvents(sf::RenderWindow& target)
{
    m_currentEvents.clear();
    while (target.pollEvent(m_eventQueue))
    {
        m_currentEvents.push_back(m_eventQueue.type);
    }
}

//Check through the current event list and check if any match the requested event type
//Close the window if the close button has been pressed
bool gameEvents::getEvent(bool& windowOpen, sf::Event::EventType eventType) const
{
    for (auto& event : m_currentEvents)
    {
        if (event == sf::Event::Closed)
        {
            windowOpen = false;
        }
        if (event == eventType)
        {
            return true;
        }
    }
    return false;
}

//Get current mouse position relative to window
sf::Vector2f gameEvents::getMousePos(sf::RenderWindow& target)
{
    sf::Vector2f position = { static_cast<float>(sf::Mouse::getPosition(target).x) , static_cast<float>(sf::Mouse::getPosition(target).y) };
    return position;
}

#include <GraceEngine/input.h>

// Clear current events
// Then gather new events happening in the window and store them to the queue
void GameEvents::updateEvents(sf::RenderWindow &target)
{
    m_currentEvents.clear();
    while (target.pollEvent(m_eventQueue))
    {
        m_currentEvents.push_back(m_eventQueue.type);
    }
}

// Check through the current event list and check if any match the requested event type
// Close the window if the close button has been pressed
bool GameEvents::getEvent(bool &windowOpen, const sf::Event::EventType eventType) const
{
    for (auto &event : m_currentEvents)
    {
        if (event == sf::Event::Closed)
        {
            windowOpen = false;
            return false;
        }
        if (event == eventType)
        {
            return true;
        }
    }
    return false;
}

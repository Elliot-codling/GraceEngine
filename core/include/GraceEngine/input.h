#pragma once
#include <SFML/Graphics.hpp>

//Used for events
//MAY BE USED FOR INPUT TOO
class gameEvents
{
public:
    //Nothing needed for the constructor
    gameEvents() = default;
    ~gameEvents() = default;

    //Must be called every frame to gather new events
    void updateEvents(sf::RenderWindow& target);
    //Used for when an event is needed
    bool getEvent(bool& windowOpen, sf::Event::EventType eventType) const;

    //Mouse input
    sf::Vector2f getMousePos(sf::RenderWindow& target);

private:
    sf::Event m_eventQueue{};
    std::vector<sf::Event::EventType> m_currentEvents;
};


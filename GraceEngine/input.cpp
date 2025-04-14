#include "input.h"

gameEvents::gameEvents() {

}

gameEvents::~gameEvents() {

}

void gameEvents::updateEvents(sf::RenderWindow& target)
{
	m_currentEvents.clear();
	while (target.pollEvent(m_eventQueue))
	{
		m_currentEvents.push_back(m_eventQueue.type);
	}
}


bool gameEvents::getEvent(bool& windowOpen, sf::Event::EventType eventType)
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


sf::Vector2f gameEvents::getMousePos(sf::RenderWindow& target)
{
	sf::Vector2f position = { float(sf::Mouse::getPosition(target).x) , float(sf::Mouse::getPosition(target).y) };
	return position;
}

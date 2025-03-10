#pragma once
#include <SFML/Graphics.hpp>

class gameEvents
{

public:
	//Nothing needed for the constructor
	gameEvents();
	~gameEvents();

	//Used for when an event is needed
	void updateEvents(sf::RenderWindow& target);
	bool getEvent(bool& windowOpen, sf::Event::EventType eventType);

	sf::Vector2f getMousePos(sf::RenderWindow& target)
	{
		sf::Vector2f position = { float(sf::Mouse::getPosition(target).x) , float(sf::Mouse::getPosition(target).y) };
		return position;
	}

private:
	sf::Event eventQueue;
	std::vector<sf::Event::EventType> currentEvents;
};


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
private:
	sf::Event eventQueue;
	std::vector<sf::Event::EventType> currentEvents;
};


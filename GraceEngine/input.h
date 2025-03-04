#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class gameEvents
{
public:
	//Nothing needed for the constructor
	gameEvents();
	~gameEvents();

	//Used for when an event is needed
	void updateEvents(RenderWindow& target);
	bool getEvent(bool& windowOpen, Event::EventType eventType);
private:
	Event eventQueue;
	vector<Event::EventType> currentEvents;
};


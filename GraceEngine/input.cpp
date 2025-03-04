#include "input.h"

gameEvents::gameEvents() {

}

gameEvents::~gameEvents() {

}

void gameEvents::updateEvents(RenderWindow& target)
{
	currentEvents.clear();
	while (target.pollEvent(eventQueue))
	{
		currentEvents.push_back(eventQueue.type);
	}
}


bool gameEvents::getEvent(bool& windowOpen, Event::EventType eventType)
{
	for (auto& event : currentEvents)
	{
		if (event == Event::Closed)
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
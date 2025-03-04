#pragma once
//Import the other files that will be used to create the engine
#include "object.h"
#include "input.h"

#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

// Main game engine
//Used to initialise the window of SFML
class graceEngine
{
public:
	graceEngine(string name, uint16_t width, uint16_t height, Color color = {0, 0, 0});
	~graceEngine();

	void renderObjects();

	//Check if the window is running
	bool isRunning() { return windowOpen; }
	void stopRunning() { windowOpen = false; }

	int getWidth() { return window.getSize().x; }
	int getHeight() { return window.getSize().y; }

	//Render and the renderQueue - spriteObject
	void pushToQueue(spriteObject object);
	void popFromQueue(int index);
	void popFromQueue(spriteObject object);
	void reloadObject(spriteObject object);
	//Render and the renderQueue - textObject
	void pushToQueue(textObject object);
	void popFromQueue(textObject object);
	void reloadObject(textObject object);

	void printQueue();
	void orderRenderQueue();

	//Functions passed onto other files
	void setAngle(spriteObject& object, float angle);
	//Used for when an event is needed
	//This is so that the main program can use window.updateEvents()
	//Instead of creating an object for input.h
	void updateEvents();
	bool getEvent(Event::EventType eventType);
	
private:
	bool windowOpen;
	Color backgroundColor;

	//SFML render objects
	RenderWindow window;

	//Render Queue
	vector<unique_ptr<gameObject>> renderQueue;

	//Used for events;
	gameEvents eventHandler;
};

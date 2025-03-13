#pragma once
//Import the other files that will be used to create the engine
#include "object.h"
#include "input.h"

#include <SFML/Graphics.hpp>
#include <iostream>
// Main game engine
//Used to initialise the window of SFML
class graceEngine
{
public:
	graceEngine(std::string name, uint16_t width, uint16_t height, sf::Color color = {0, 0, 0});
	~graceEngine();

	void renderObjects(std::vector<sf::RectangleShape*>* debugQueue = nullptr);
	void clearLayer(int layerNumber);

	//Check if the window is running
	bool isRunning() { return windowOpen; }
	void stopRunning() { windowOpen = false; }

	int getWidth() { return window.getSize().x; }
	int getHeight() { return window.getSize().y; }

	//Camera movement and window relativity
	void incrementCamera(sf::Vector2f position);
	void setCameraSize(sf::Vector2f cameraSize);

	//Relative position of object to window
	sf::Vector2i getRelativePosition(spriteObject* object) { return window.mapCoordsToPixel(object->getPosition()); }
	sf::Vector2i getRelativePosition(textObject* object) { return window.mapCoordsToPixel(object->getPosition()); }
	//Set world position to window position
	void setRelativePosition(spriteObject* object, sf::Vector2f position) { object->setPosition(window.mapPixelToCoords({ int(position.x), int(position.y) })); }
	void setRelativePosition(textObject* object, sf::Vector2f position) { object->setPosition(window.mapPixelToCoords({ int(position.x), int(position.y) })); }


	//Render and the renderQueue - spriteObject
	void pushToQueue(spriteObject* object);
	void popFromQueue(spriteObject* object);
	std::vector<spriteObject*> getSpriteQueue() { return renderQueueSprite; }

	//Render and the renderQueue - textObject
	void pushToQueue(textObject* object);
	void popFromQueue(textObject* object);
	std::vector<textObject*> getTextQueue() { return renderQueueText; }

	// Functions passed onto other files ---------------------------------------
	// Prevents the game.cpp file from having to create an eventHandler
	void updateEvents();
	bool getEvent(sf::Event::EventType eventType);

	sf::Vector2f getMousePos();

private:
	bool windowOpen;
	sf::Color backgroundColor;

	//SFML render objects
	sf::RenderWindow window;

	//Camera
	sf::View* camera;

	//Render Queues
	std::vector<spriteObject*> renderQueueSprite;
	std::vector<textObject*> renderQueueText;
	void sortRenderQueue();

	//Used for events;
	gameEvents eventHandler;
};

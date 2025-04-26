#pragma once
//Include all required external dependencies
#include <SFML/graphics.hpp>
#include <iostream>

//Import the other files that will be used to create the engine
#include "object.h"
#include "input.h"

class debugShape;
// Main game engine
//Used to initialise the window of SFML
class graceEngine
{
public:
	graceEngine(std::string name, int width, int height, sf::Color color = {0, 0, 0});
	~graceEngine();

	void renderObjects();
	void renderObjects(std::vector<debugShape*>* debugQueue);
	void clearLayer(int layerNumber);

	//Check if the window is running
	bool isRunning() { return m_windowOpen; }
	void stopRunning() { m_windowOpen = false; }

	int getWidth() { return m_window.getSize().x; }
	int getHeight() { return m_window.getSize().y; }

	//Camera movement and window relativity
	void incrementCamera(sf::Vector2f position);
	sf::Vector2f getCameraPos() { return m_camera->getCenter(); }
	void setCameraSize(sf::Vector2f cameraSize);

	//Relative position of object to window
	sf::Vector2i getRelativePosition(spriteObject* object) { return m_window.mapCoordsToPixel(object->getPosition()); }
	sf::Vector2i getRelativePosition(textObject* object) { return m_window.mapCoordsToPixel(object->getPosition()); }

	//Set world position to window position
	void setRelativePosition(spriteObject* object, sf::Vector2f position) { object->setPosition(m_window.mapPixelToCoords({ static_cast<int>(position.x), static_cast<int>(position.y) })); }
	void setRelativePosition(textObject* object, sf::Vector2f position) { object->setPosition(m_window.mapPixelToCoords({ int(position.x), int(position.y) })); }


	//Render and the renderQueue - spriteObject
	void pushToQueue(spriteObject* object);
	void popFromQueue(spriteObject* object);
	std::vector<spriteObject*> getSpriteQueue() { return m_renderQueueSprite; }

	//Render and the renderQueue - textObject
	void pushToQueue(textObject* object);
	void popFromQueue(textObject* object);
	std::vector<textObject*> getTextQueue() { return m_renderQueueText; }

	// Functions passed onto other files ---------------------------------------
	// Prevents the game.cpp file from having to create an eventHandler
	void updateEvents();
	bool getEvent(sf::Event::EventType eventType);

	sf::Vector2f getMousePos();

private:
	bool m_windowOpen;
	sf::Color m_backgroundColor;

	//SFML render objects
	sf::RenderWindow m_window;

	//Camera
	sf::View* m_camera;

	//Render Queues
	std::vector<spriteObject*> m_renderQueueSprite;
	std::vector<textObject*> m_renderQueueText;


	void sortRenderQueue();

	//Used for events;
	gameEvents m_eventHandler;
};


class debugShape
{
public:
	debugShape(spriteObject* object);
	~debugShape();

	void setShapePosition(sf::Vector2f position) { rectangle->setPosition(position); }
	sf::RectangleShape getShape() { return *rectangle; }


private:
	sf::RectangleShape* rectangle = new sf::RectangleShape;

};


class debugHandler
{
public:
	debugHandler() = default;
	~debugHandler() = default;
	void pushToDebugQueue(debugShape &shape) { debugQueue.push_back(&shape); }
	std::vector<debugShape*>* getDebugQueue() { return &debugQueue; }

private:
	std::vector<debugShape*> debugQueue;
};

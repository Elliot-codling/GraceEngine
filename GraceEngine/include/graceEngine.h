#pragma once
//Include all required external dependencies
#include <SFML/Graphics.hpp>

//Import the other files that will be used to create the engine
#include "object.h"
#include "input.h"

//EXPERIMENTAL SUBJECT TO CHANGE
class debugShape;

//Grace engine initialisation - window control
class graceEngine
{
public:
	graceEngine(const std::string &name, int width, int height, sf::Color color = {0, 0, 0});
	~graceEngine();

	void renderObjects();
	void renderObjects(const std::vector<debugShape*>* debugQueue);
	void clearLayer(int layerNumber);

	//Check if the window is running
	bool isRunning() const { return m_windowOpen; }
	void stopRunning() { m_windowOpen = false; }

	int getWidth() const { return static_cast<int>(m_window.getSize().x); }
	int getHeight() const { return static_cast<int>(m_window.getSize().y); }

	//Camera movement and window relativity
	void incrementCamera(sf::Vector2f position);
	sf::Vector2f getCameraPos() const { return m_camera->getCenter(); }
	void setCameraSize(sf::Vector2f cameraSize);

	//Relative position of object to window
	sf::Vector2i getRelativePosition(const spriteObject* object) const { return m_window.mapCoordsToPixel(object->getPosition()); }
	sf::Vector2i getRelativePosition(const textObject* object) const { return m_window.mapCoordsToPixel(object->getPosition()); }

	//Set world position to window position
	void setRelativePosition(const spriteObject* object, sf::Vector2f position) const { object->setPosition(m_window.mapPixelToCoords({ static_cast<int>(position.x), static_cast<int>(position.y) })); }
	void setRelativePosition(textObject* object, sf::Vector2f position) const { object->setPosition(m_window.mapPixelToCoords({ static_cast<int>(position.x), static_cast<int>(position.y) })); }


	//Render and the renderQueue - spriteObject
	void pushToQueue(spriteObject* object);
	void popFromQueue(spriteObject* object);
	std::vector<spriteObject*> getSpriteQueue() { return m_renderQueueSprite; }

	//Render and the renderQueue - textObject
	void pushToQueue(textObject* object);
	void popFromQueue(textObject* object);
	std::vector<textObject*> getTextQueue() { return m_renderQueueText; }

	// Functions passed onto other files ---------------------------------------
	// Prevents the users from having to create an eventHandler
	void updateEvents();
	bool getEvent(sf::Event::EventType eventType);

	sf::Vector2f getMousePos();

private:
	//SFML window
	sf::RenderWindow m_window;
	//Window properties
	bool m_windowOpen;
	sf::Color m_backgroundColor;

	//Camera
	sf::View* m_camera;

	//Render Queues
	std::vector<spriteObject*> m_renderQueueSprite;
	std::vector<textObject*> m_renderQueueText;

	void sortRenderQueue();

	//Create event handler;
	gameEvents m_eventHandler;
};

//EXPERIMENTAL SUBJECT TO CHANGE
class debugShape
{
public:
	debugShape(const spriteObject* object);
	~debugShape();

	void setShapePosition(sf::Vector2f position) const { rectangle->setPosition(position); }
	sf::RectangleShape getShape() const { return *rectangle; }


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

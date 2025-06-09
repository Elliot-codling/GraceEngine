#pragma once
//Include all required external dependencies
#include <SFML/Graphics.hpp>

//Import the other files that will be used to create the engine
#include <GraceEngine/debugHandler.h>
#include <GraceEngine/object.h>
#include <GraceEngine/input.h>

//Grace engine initialisation - window control
class graceEngine: public debugHandler, public gameEvents
{
public:
	graceEngine(const std::string &name, const int &width, const int &height, const sf::Color &color = {0, 0, 0});
	~graceEngine();

	void renderObjects();
	//void renderObjects(const std::vector<debugShape*>* debugQueue);
	void clearLayer(const int &layerNumber);

	//Set target fps and get current fps
	void setTargetFramerate(const int &targetFPS) { m_window.setFramerateLimit(targetFPS); }
	//Used by runtime.cpp - Sets the frametime of the current frame
	void setFrametime(const float &currentFrametime) { m_frametime = currentFrametime; }
	[[nodiscard]] float getFramerate() const { return 1.f / m_frametime; }

	//Check if the window is running
	[[nodiscard]] bool isRunning() const { return m_windowOpen; }
	void stopRunning() { m_windowOpen = false; }

	[[nodiscard]] int getWidth() const { return static_cast<int>(m_window.getSize().x); }
	[[nodiscard]] int getHeight() const { return static_cast<int>(m_window.getSize().y); }

	//Camera movement and window relativity
	void incrementCamera(const sf::Vector2f &position);
	[[nodiscard]] sf::Vector2f getCameraPos() const { return m_camera->getCenter(); }
	void setCameraSize(const sf::Vector2f &cameraSize);

	//Relative position of object to window
	[[nodiscard]] sf::Vector2i getRelativePosition(const spriteObject* object) const { return m_window.mapCoordsToPixel(object->getPosition()); }
	[[nodiscard]] sf::Vector2i getRelativePosition(const textObject* object) const { return m_window.mapCoordsToPixel(object->getPosition()); }

	//Set world position to window position
	void setRelativePosition(const spriteObject* object, const sf::Vector2f &position) const { object->setPosition(m_window.mapPixelToCoords({ static_cast<int>(position.x), static_cast<int>(position.y) })); }
	void setRelativePosition(const textObject* object, const sf::Vector2f &position) const { object->setPosition(m_window.mapPixelToCoords({ static_cast<int>(position.x), static_cast<int>(position.y) })); }


	//Render and the renderQueue - spriteObject
	void pushToQueue(spriteObject* object);
	void popFromQueue(const spriteObject* object);
	[[nodiscard]] std::vector<spriteObject*> getSpriteQueue() { return m_renderQueueSprite; }

	//Render and the renderQueue - textObject
	void pushToQueue(textObject* object);
	void popFromQueue(const textObject* object);
	[[nodiscard]] std::vector<textObject*> getTextQueue() { return m_renderQueueText; }

	// Functions passed onto other files ---------------------------------------
	// Prevents the users from having to create an eventHandler
	void updateEvents() { gameEvents::updateEvents(m_window); }
	bool getEvent(const sf::Event::EventType &eventType) { return gameEvents::getEvent(m_windowOpen, eventType); }

	[[nodiscard]] sf::Vector2f getMousePos() const { return gameEvents::getMousePos(m_window); }

	//Private variables
private:
	//SFML window
	sf::RenderWindow m_window;
	//Window properties
	bool m_windowOpen;
	sf::Color m_backgroundColor;

	//Camera
	sf::View* m_camera;

	//Render Queues
	//Render queue for pointers and other for reference
	std::vector<spriteObject*> m_renderQueueSprite;
	std::vector<textObject*> m_renderQueueText;

	//Frametime of the current frame
	float m_frametime;

	//Private functions
private:
	void sortRenderQueue();
};
#include "../include/graceEngine.h"

#include <cmath>
// GraceEngine Constructor -----------------------------------------------------------------------------------
graceEngine::graceEngine(const std::string &name, int width, int height, sf::Color color)
{
	m_window.create(sf::VideoMode(width, height), name);

	//Constructor should create the render window
	if (m_window.isOpen())
	{
		m_windowOpen = true;
	}
	else
	{		//If it cannot initialise SFML, exit program
		std::cout << "Failed to initialise: SFML Window";
		std::cin.get();
		exit(EXIT_FAILURE);
	}
	m_backgroundColor = color;

	//Experimental changes to be made
	m_window.setKeyRepeatEnabled(false);
	m_window.setFramerateLimit(60);

	m_camera = new sf::View(sf::FloatRect(0.f, 0.f, width, height));
	m_camera->setCenter({std::round(width / 2.f), std::round(height / 2.f) });
	m_window.setView(*m_camera);
}


graceEngine::~graceEngine()
{
	for (spriteObject* object: m_renderQueueSprite)
	{
		delete object;
	}
	m_renderQueueSprite.clear();

	for (textObject* object: m_renderQueueText)
	{
		delete object;
	}
	m_renderQueueText.clear();

	delete m_camera;
}

// GraceEngine main functions ---------------------------------------------------------------------------

//Events ----------------------------------
void graceEngine::updateEvents()
{
	m_eventHandler.updateEvents(m_window);
}

bool graceEngine::getEvent(sf::Event::EventType eventType)
{
	return m_eventHandler.getEvent(m_windowOpen, eventType);
}

sf::Vector2f graceEngine::getMousePos()
{
	return m_eventHandler.getMousePos(m_window);
}

//Camera movement ---------------------------------------------

void graceEngine::incrementCamera(sf::Vector2f position)
{
	m_camera->move(position);
	m_window.setView(*m_camera);
}


void graceEngine::setCameraSize(sf::Vector2f cameraSize)
{
	m_camera->setSize(cameraSize);
	m_window.setView(*m_camera);
}


// Render and Queue ----------------------------------------

//Items can be pushed onto the render queue
void graceEngine::pushToQueue(spriteObject* object)
{
	m_renderQueueSprite.push_back(object);
}

void graceEngine::pushToQueue(textObject* object)
{
	m_renderQueueText.push_back(object);
}


//Go through the renderQueue and identify the index where the specified object is
//Remove the object by its index value
void graceEngine::popFromQueue(spriteObject* object)
{
	int index = 0;
	for (int i = 0; i <= m_renderQueueSprite.size(); i++)
	{
		if (m_renderQueueSprite[i]->getId() == object->getId())
		{
			index = i;
			break;
		}
	}
	m_renderQueueSprite.erase(m_renderQueueSprite.begin() + index);
}

void graceEngine::popFromQueue(textObject* object)
{
	int index = 0;
	for (int i = 0; i <= m_renderQueueText.size(); i++)
	{
		if (m_renderQueueText[i]->getId() == object->getId())
		{
			index = i;
			break;
		}
	}
	m_renderQueueText.erase(m_renderQueueText.begin() + index);
}

//Sorts the renderQueue from the smallest layer number to the largest
//Whatever was last pushed to the queue will be on top if all the layer numbers are the same
void graceEngine::sortRenderQueue()
{
	std::vector<spriteObject*> tempList;
	tempList.push_back(m_renderQueueSprite[0]);
	int lengthOfQueue = 0;
	spriteObject* object = nullptr;
	for (int indexOfObject = 1; indexOfObject < size(m_renderQueueSprite); indexOfObject++)
	{
		object = m_renderQueueSprite[indexOfObject];
		lengthOfQueue = size(tempList);
		for (int index = 0; index < lengthOfQueue; index++)
		{
			//Insert only if at the correct index
			if (object->getLayer() < tempList[index]->getLayer())
			{
				tempList.insert(tempList.begin() + index, object);
				break;
			}

			//For the last item
			if (index == lengthOfQueue - 1)
			{
				tempList.insert(tempList.begin() + index + 1, object);
				break;
			}
		}
	}

	object = nullptr;		//Object can be set to a null pointer
	m_renderQueueSprite = tempList;
	delete object;		//Ensure no memory leaks

}

//Clears a layer based on the number provided
void graceEngine::clearLayer(int layerNumber)
{
	//Deletes all objects in a given layer
	for (auto& object: m_renderQueueSprite)
	{
		if (object->getLayer() == layerNumber)
		{
			popFromQueue(object);
		}
	}

	for (auto& object : m_renderQueueText)
	{
		if (object->getLayer() == layerNumber)
		{
			popFromQueue(object);
		}
	}
}

//Render the vector of gameObjects
void graceEngine::renderObjects()
{
	m_window.clear(m_backgroundColor);
	if (m_renderQueueSprite.size() != 0) {
		sortRenderQueue();		//Sort renderQueue
	}

	//Iterate through the display vector and then draw the object to the display
	for (auto& object : m_renderQueueSprite)
	{
		object->render(m_window);
	}

	for (auto& object : m_renderQueueText)
	{
		object->render(m_window);
	}

	m_window.display();
}

//DEBUG RENDERER SUBJECT TO CHANGE
void graceEngine::renderObjects(const std::vector<debugShape*>* debugQueue)
{
	m_window.clear(m_backgroundColor);
	sortRenderQueue();		//Sort renderQueue

	//Iterate through the display vector and then draw the object to the display
	for (auto& object: m_renderQueueSprite)
	{
		object->render(m_window);
	}

	for (auto& object: m_renderQueueText)
	{
		object->render(m_window);
	}

	for (auto shape : *debugQueue)
	{
		m_window.draw(shape->getShape());
	}

	m_window.display();
}



//DEBUGGING PURPOSES
debugShape::debugShape(const spriteObject* object)
{
	rectangle->setSize(object->getSize());
	rectangle->setPosition(object->getPosition());
	rectangle->setFillColor(sf::Color::Yellow);
}


debugShape::~debugShape()
{
	delete rectangle;
}

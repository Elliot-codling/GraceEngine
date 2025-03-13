#include "graceEngine.h"
// GraceEngine Constructor -----------------------------------------------------------------------------------
graceEngine::graceEngine(std::string name, uint16_t const width, uint16_t const height, sf::Color color):
window(sf::VideoMode({width, height}), name)
{
	//Constructor should create the render window
	if (window.isOpen())
	{
		windowOpen = true;
	}
	else
	{		//If cannot initialise SFML, exit program
		std::cout << "Failed to initialise: SFML Window";
		std::cin.get();
		exit(EXIT_FAILURE);
	}
	backgroundColor = color;

	//Experimental changes to be made
	window.setKeyRepeatEnabled(false);
	window.setFramerateLimit(60);

	camera = new sf::View(sf::FloatRect(0.f, 0.f, width, height));
	camera->setCenter({ 240, 300 });
	window.setView(*camera);
}


graceEngine::~graceEngine()
{
	for (spriteObject* object: renderQueueSprite)
	{
		delete object;
	}
	renderQueueSprite.clear();

	for (textObject* object: renderQueueText)
	{
		delete object;
	}
	renderQueueText.clear();

	delete camera;
}

// GraceEngine main functions ---------------------------------------------------------------------------

//Events ----------------------------------
void graceEngine::updateEvents()
{
	eventHandler.updateEvents(window);
}

bool graceEngine::getEvent(sf::Event::EventType eventType)
{
	return eventHandler.getEvent(windowOpen, eventType);
}

sf::Vector2f graceEngine::getMousePos()
{
	return eventHandler.getMousePos(window);
}

//Camera movement ---------------------------------------------

void graceEngine::incrementCamera(sf::Vector2f position)
{
	camera->move(position);
	window.setView(*camera);
}


void graceEngine::setCameraSize(sf::Vector2f cameraSize)
{
	camera->setSize(cameraSize);
	window.setView(*camera);
}


// Render and Queue ----------------------------------------

//Items can be pushed onto the render queue
void graceEngine::pushToQueue(spriteObject* object)
{
	renderQueueSprite.push_back(object);
}

void graceEngine::pushToQueue(textObject* object)
{
	renderQueueText.push_back(object);
}


//Go through the renderQueue and identify the index where the specified object is
//Remove the object by its index value
void graceEngine::popFromQueue(spriteObject* object)
{
	int index;
	for (int i = 0; i <= renderQueueSprite.size(); i++)
	{
		if (renderQueueSprite[i]->getId() == object->getId())
		{
			index = i;
			break;
		}
	}
	renderQueueSprite.erase(renderQueueSprite.begin() + index);
}

void graceEngine::popFromQueue(textObject* object)
{
	int index;
	for (int i = 0; i <= renderQueueText.size(); i++)
	{
		if (renderQueueText[i]->getId() == object->getId())
		{
			index = i;
			break;
		}
	}
	renderQueueText.erase(renderQueueText.begin() + index);
}

void graceEngine::sortRenderQueue()
{
	//Sorts the renderQueue from the smallest layer number to the largest
	//Whatever was last pushed to the queue will be on top if all the layer numbers are the same
	std::vector<spriteObject*> tempList;
	tempList.push_back(renderQueueSprite[0]);
	int lengthOfQueue;
	spriteObject* object = nullptr;
	for (int indexOfOjbect = 1; indexOfOjbect < size(renderQueueSprite); indexOfOjbect++)
	{
		object = renderQueueSprite[indexOfOjbect];
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
	renderQueueSprite = tempList;
	delete object;		//Ensure no memory leaks
	
}



void graceEngine::clearLayer(int layerNumber)
{
	//Deletes all objects in a given layer
	for (auto& object: renderQueueSprite)
	{
		if (object->getLayer() == layerNumber)
		{
			popFromQueue(object);
		}
	}

	for (auto& object : renderQueueText)
	{
		if (object->getLayer() == layerNumber)
		{
			popFromQueue(object);
		}
	}
}



//Render the vector of gameObjects
void graceEngine::renderObjects(std::vector<sf::RectangleShape*>* debugQueue)
{
	window.clear(backgroundColor);
	sortRenderQueue();		//Sort renderQueue

	//Iterate through the display vector and then draw the object to the display
	for (auto& object: renderQueueSprite)
	{
		object->render(window);
	}

	for (auto& object: renderQueueText)
	{
		object->render(window);
	}

	if (debugQueue != nullptr)
	{
		for (auto shape: *debugQueue)
		{
			window.draw(*shape);
		}
	}

	window.display();
}
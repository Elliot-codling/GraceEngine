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
	
}


graceEngine::~graceEngine()
{
	for (gameObject* object: renderQueue)
	{
		delete object;
	}
	renderQueue.clear();
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
// ----------------------------------------

//Items can be pushed onto the render queue
void graceEngine::pushToQueue(spriteObject* object)
{
	renderQueue.push_back(object);
}

void graceEngine::pushToQueue(textObject* object)
{
	renderQueue.push_back(object);
}


//Remove an item from the queue by its index number
void graceEngine::popFromQueue(int index)
{
	renderQueue.erase(renderQueue.begin() + index);
}

//Go through the renderQueue and identify the index where the specified object is
//Remove the object by its index value
void graceEngine::popFromQueue(spriteObject* object)
{
	int index;
	for (int i = 0; i <= renderQueue.size(); i++)
	{
		if (renderQueue[i]->getId() == object->getId())
		{
			index = i;
			break;
		}
	}
	popFromQueue(index);
}

void graceEngine::popFromQueue(textObject* object)
{
	int index;
	for (int i = 0; i <= renderQueue.size(); i++)
	{
		if (renderQueue[i]->getId() == object->getId())
		{
			index = i;
			break;
		}
	}
	popFromQueue(index);
}

void graceEngine::printQueue()
{
	for (auto& object: renderQueue)
	{
		std::cout << object->getId() << "\n";
		
	}
}

void graceEngine::orderRenderQueue()
{
	/*
	bool swapped;
	do
	{
		swapped = false;
		for (int index = 0; index < renderQueue.size() - 1; index++)
		{
			if (renderQueue[index]->getLayer() > renderQueue[index + 1]->getLayer())
			{

				swap(renderQueue[index], renderQueue[index + 1]);
				swapped = true;
			}
		}
	} while (swapped);
	*/
	std::vector<gameObject*> tempList;
	int lengthOfQueue;
	for (gameObject* object: renderQueue)
	{
		lengthOfQueue = sizeof(tempList);
		for (int index = lengthOfQueue; index > -1; index--)
		{
			if (tempList[index]->getLayer() < object->getLayer())
			{
				tempList.insert(tempList.begin() + index + 1, object);
				break;
			}
			else
			{
				if (index == 0)
				{
					tempList.insert(tempList.begin() + index, object);
					
				}
				continue;
			}
		}
	}

	for (gameObject* object : tempList)
	{
		std::cout << object->getId() << "\n";
	}



}


//Render the vector of gameObjects
void graceEngine::renderObjects()
{
	window.clear(backgroundColor);

	//sort(renderQueue.begin(), renderQueue.end());
	//orderRenderQueue();

	//Iterate through the display vector and then draw the object to the display
	for (auto& object: renderQueue)
	{
		object->render(window);
	}
	window.display();
}
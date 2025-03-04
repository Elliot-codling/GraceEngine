#include "graceEngine.h"
// GraceEngine Constructor -----------------------------------------------------------------------------------
graceEngine::graceEngine(string name, uint16_t const width, uint16_t const height, Color color):
window(VideoMode({width, height}), name)
{
	//Constructor should create the render window
	if (window.isOpen())
	{
		windowOpen = true;
	}
	else
	{		//If cannot initialise SFML, exit program
		cout << "Failed to initialise: SFML Window";
		_getch();
		exit(EXIT_FAILURE);
	}
	backgroundColor = color;

	//Experimental changes to be made
	window.setKeyRepeatEnabled(false);
	window.setFramerateLimit(60);
	
}


graceEngine::~graceEngine()
{
	
}

// GraceEngine main functions ---------------------------------------------------------------------------

//Events ----------------------------------
void graceEngine::updateEvents()
{
	eventHandler.updateEvents(window);
}

bool graceEngine::getEvent(Event::EventType eventType)
{
	return eventHandler.getEvent(windowOpen, eventType);
}
// ----------------------------------------

//Items can be pushed onto the render queue
void graceEngine::pushToQueue(spriteObject object)
{
	renderQueue.push_back(make_unique<spriteObject>(object));
}

void graceEngine::pushToQueue(textObject object)
{
	renderQueue.push_back(make_unique<textObject>(object));
}


//Remove an item from the queue by its index number
void graceEngine::popFromQueue(int index)
{
	renderQueue.erase(renderQueue.begin() + index);
}

//Go through the renderQueue and identify the index where the specified object is
//Remove the object by its index value
void graceEngine::popFromQueue(spriteObject object)
{
	int index;
	for (int i = 0; i <= renderQueue.size(); i++)
	{
		if (renderQueue[i]->getId() == object.getId())
		{
			index = i;
			break;
		}
	}
	popFromQueue(index);
}

void graceEngine::popFromQueue(textObject object)
{
	int index;
	for (int i = 0; i <= renderQueue.size(); i++)
	{
		if (renderQueue[i]->getId() == object.getId())
		{
			index = i;
			break;
		}
	}
	popFromQueue(index);
}


//Reload the object in the vector as it currently is not referenced
void graceEngine::reloadObject(spriteObject object)
{
	popFromQueue(object);
	pushToQueue(object);
}

void graceEngine::reloadObject(textObject object)
{
	popFromQueue(object);
	pushToQueue(object);
}

void graceEngine::printQueue()
{
	for (auto& object: renderQueue)
	{
		cout << object->getId() << "\n";
		
	}
}

void graceEngine::orderRenderQueue()
{
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
}


//Render the vector of gameObjects
void graceEngine::renderObjects()
{
	window.clear(backgroundColor);

	//sort(renderQueue.begin(), renderQueue.end());
	orderRenderQueue();

	//Iterate through the display vector and then draw the object to the display
	for (auto& object: renderQueue)
	{
		object->render(window);
	}
	window.display();
}
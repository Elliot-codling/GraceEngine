#include <GraceEngine/window.h>
#include <cmath>
// GraceEngine Constructor -----------------------------------------------------------------------------------
GraceEngine::GraceEngine(const char* name, const int width, const int height, const sf::Color color)
{
	m_window.create(sf::VideoMode(width, height), name);

	// Constructor should create the render window
	if (m_window.isOpen())
	{
		m_windowOpen = true;
        DebugHandler::printInfo("Created SFML window: '" + std::string(name) + "'");
	}
	else
	{
		// If it cannot initialise SFML, exit program
        DebugHandler::printErrorInfo("Failed to initialise: '" + std::string(name) + "'");
	}
	m_backgroundColor = color;

	// Experimental changes to be made
	m_window.setKeyRepeatEnabled(false);

	m_camera = new sf::View(sf::FloatRect(0.f, 0.f, static_cast<float>(width), static_cast<float>(height)));
	m_camera->setCenter({std::round(static_cast<float>(width) / 2.f), std::round(static_cast<float>(height) / 2.f) });
	m_window.setView(*m_camera);
}

GraceEngine::~GraceEngine()
{

}

// GraceEngine main functions ---------------------------------------------------------------------------

// Camera movement ---------------------------------------------

void GraceEngine::incrementCamera(const sf::Vector2f position)
{
	m_camera->move(position);
	m_window.setView(*m_camera);
}


void GraceEngine::setCameraSize(const sf::Vector2f cameraSize)
{
	m_camera->setSize(cameraSize);
	m_window.setView(*m_camera);
}


// Render and Queue ----------------------------------------

// Items can be pushed onto the render queue
void GraceEngine::pushToQueue(SpriteObject* object)
{
	m_renderQueueSprite.emplace_back(object);
}


void GraceEngine::pushToQueue(TextObject* object)
{
	m_renderQueueText.emplace_back(object);
}


// Go through the renderQueue and identify the index where the specified object is
// Remove the object by its index value
void GraceEngine::popFromQueue(const SpriteObject* object)
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

void GraceEngine::popFromQueue(const TextObject* object)
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


// Sorts the renderQueue from the smallest layer number to the largest
// Whatever was last pushed to the queue will be on top if all the layer numbers are the same
// TODO: Update to use an array instead
void GraceEngine::sortRenderQueue()
{
	std::vector<SpriteObject*> tempList;
	tempList.emplace_back(m_renderQueueSprite[0]);
	size_t lengthOfQueue = 0;
	SpriteObject* object = nullptr;
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

// Clears a layer based on the number provided
void GraceEngine::clearLayer(const int layerNumber)
{
	//Deletes all objects in a given layer
	for (auto& object: m_renderQueueSprite)
	{
		if (object->getLayer() == layerNumber)
		{
			popFromQueue(object);
		}
	}

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

// Render the vector of gameObjects
void GraceEngine::renderObjects()
{
	m_window.clear(m_backgroundColor);
	if (!m_renderQueueSprite.empty())
	{
		sortRenderQueue();		//Sort renderQueue
	}

	for (SpriteObject* object: m_renderQueueSprite)
	{
		object->render(m_window);
	}

	for (auto& object : m_renderQueueText)
	{
		object->render(m_window);
	}

	m_window.display();
}
#include <GraceEngine/window.h>
#include <cmath>
// GraceEngine Constructor -----------------------------------------------------------------------------------
GraceEngine::GraceEngine(const char* name, const uint16_t width, const uint16_t height, const sf::Color color)
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

// Sorts the renderQueue from the smallest layer number to the largest
// Whatever was last pushed to the queue will be on top if all the layer numbers are the same
// TODO: Update to use an array instead
std::vector<SpriteObject> GraceEngine::sortRenderQueue()
{
	std::vector<SpriteObject> tempList;
	//tempList.emplace_back(m_spriteList[0]);
	size_t lengthOfQueue = 0;
	SpriteObject* object = nullptr;
	for (int indexOfObject = 1; indexOfObject < size(m_spriteList); indexOfObject++)
	{
		object = &m_spriteList[indexOfObject];
		lengthOfQueue = size(tempList);
		for (int index = 0; index < lengthOfQueue; index++)
		{
			//Insert only if at the correct index
			if (object->getLayerNumber() < tempList[index].getLayerNumber())
			{
				tempList.insert(tempList.begin() + index, *object);
				break;
			}

			//For the last item
			if (index == lengthOfQueue - 1)
			{
				tempList.insert(tempList.begin() + index + 1, *object);
				break;
			}
		}
	}

	object = nullptr;		//Object can be set to a null pointer
	delete object;		//Ensure no memory leaks

	tempList.clear();
	return tempList;
}


// Clears a layer based on the number provided
void GraceEngine::clearLayer(const uint16_t layerNumber)
{
	//Deletes all objects in a given layer
	for (auto& object: m_spriteList)
	{
		if (object.getLayerNumber() == layerNumber)
		{
			popFromRender(&object);
		}
	}

	for (auto& object: m_spriteList)
	{
		if (object.getLayerNumber() == layerNumber)
		{
			popFromRender(&object);
		}
	}

	for (auto& object : m_textList)
	{
		if (object.getLayerNumber() == layerNumber)
		{
			popFromRender(&object);
		}
	}
}


// Render the vector of gameObjects
void GraceEngine::renderObjects()
{
	m_window.clear(m_backgroundColor);
	if (!m_spriteList.empty())
	{
		// TODO: Change the queue from std::vector to a map
	}

	for (SpriteObject &object: m_spriteList)
	{
		object.render(m_window);
	}

	for (TextObject &object : m_textList)
	{
		object.render(m_window);
	}

	m_window.display();
}
#include <GraceEngine/object.h>
#include <GraceEngine/debugHandler.h>

// spriteObject constructor ---------------------------------------------------------------------------------
//Texture will be loaded from the directory given by string

spriteObject::spriteObject(const std::string &objectId, const std::string &textureDir, const sf::Vector2f &position, const sf::Vector2f &size, const uint8_t &objectLayer)
{
	//Assign an id to the object
	setId(objectId);

	//Load the texture from the directory provided
	if (!m_texture->loadFromFile(textureDir))
	{
		printWarningInfo("Sprite object: '" + getId() + "' is not initialised");
		return;
	}

	//Apply texture to sprite, set its position and then apply its scale
	m_sprite->setTexture(*m_texture);
	m_sprite->setPosition(position.x, position.y);

	setSize(size);
	setLayer(objectLayer);

	//Once it's passed through, the object has initialised successfully
	initialiseObject();
}

//Assuming texture has loaded, set the sprite to the textureFile
spriteObject::spriteObject(const std::string &objectId, const sf::Texture &textureFile, const sf::Vector2f &position, const sf::Vector2f &size, const uint8_t &objectLayer)
{
	//Assign the object its id
	setId(objectId);

	//Apply texture to sprite, set its position and then apply its scale
	*m_texture = textureFile;
	m_sprite->setTexture(textureFile);
	m_sprite->setPosition(position.x, position.y);

	setSize(size);
	setLayer(objectLayer);

	//Once it's passed through, the object has initialised successfully
	initialiseObject();
}

spriteObject::~spriteObject()
{
	destroyObject();
	delete m_texture;
	delete m_sprite;
	if (m_isDebugging)
	{
		printInfo("Deleted: '" + getId() + "'");
	}
}

//Replace the sprite texture with a new specified directory
void spriteObject::replaceTexture(const std::string &textureDir, const sf::Vector2f &size) const
{
	if (!m_texture->loadFromFile(textureDir))
	{
		return;
	}

	//Apply new texture
	m_sprite->setScale(size.x / static_cast<float>(m_texture->getSize().x), size.y / static_cast<float>(m_texture->getSize().y));
	m_sprite->setTexture(*m_texture);
}

//A permanent offset value
void spriteObject::setOffset(const sf::Vector2f &objectOffset)
{
	sharedData::setOffset(objectOffset);		//Define the offset value
	incrementPosition(objectOffset);		//Move the object
}


//Set the size of the sprite
//If the sprite has a repeated texture then do texture rect instead
void spriteObject::setSize(const sf::Vector2f &size) const
{
	if (!m_texture->isRepeated())
	{
		m_sprite->setScale(size.x / static_cast<float>(m_texture->getSize().x), size.y / static_cast<float>(m_texture->getSize().y));
	}
	else
	{
		m_sprite->setTextureRect(sf::IntRect(0, 0, static_cast<int>(size.x), static_cast<int>(size.y)));
	}
}

//Set the texture rect position
void spriteObject::setSpriteRectPos(const sf::Vector2f &position) const
{
	m_sprite->setTextureRect(sf::IntRect(static_cast<int>(position.x), static_cast<int>(position.y), m_sprite->getTextureRect().width, m_sprite->getTextureRect().height));
}


//Set the Origin point of the sprite
void spriteObject::setOrigin(const sf::Vector2f &origin) const
{
	m_sprite->setOrigin(origin.x / m_sprite->getScale().x, origin.y / m_sprite->getScale().y);
}


//Return an object ID if the selected sprite has collided with the object
std::string spriteObject::collisionBox(const spriteObject* object) const
{
	if (!(getPosition().x <= object->getPosition().x + object->getSize().x))
	{
		return "";
	}
	if (!(getPosition().x + getSize().x >= object->getPosition().x))
	{
		return "";
	}
	if (!(getPosition().y <= object->getPosition().y + object->getSize().y))
	{
		return "";
	}
	if (!(getPosition().y + getSize().y >= object->getPosition().y))
	{
		return "";
	}

	return object->getId();
}

//Create rectangle, set its size, pos and colour and then print out to terminal
void spriteObject::setDebugActive(const sf::Color &color)
{
	m_debugRect = new sf::RectangleShape;
	m_debugRect->setSize(getSize());
	m_debugRect->setPosition(getPosition());
	m_debugRect->setFillColor(color);
	m_isDebugging = true;
	debugHandler::printInfo("Sprite object: '" + getId() + "' is in debug");
}

//Render object, if in debug render debug rect too
void spriteObject::render(sf::RenderTarget &target) const
{
	//Draw debug rect if it is currently debugging
	if (m_isDebugging)
	{
		target.draw(*m_debugRect);
	}
	target.draw(*m_sprite);
}






// textObject constructor ------------------------------------------------------------------------------
textObject::textObject(const std::string &objectId, const std::string &message, const sf::Vector2f &position, const std::string &fontDir, const uint8_t &fontSize, const uint8_t &objectLayer)
{
	setId(objectId);
	if (!m_font->loadFromFile(fontDir))
	{
		printWarningInfo("Text object: '" + getId() + "' is not initialised.");
		return;
	}

	m_text->setFont(*m_font);
	m_text->setCharacterSize(fontSize);
	m_text->setString(message);

	setPosition(position);
	setLayer(objectLayer);
}

textObject::textObject(const std::string &objectId, const std::string &message, const sf::Vector2f &position, const sf::Font &fontFile, const uint8_t &fontSize, const uint8_t &objectLayer)
{
	*m_font = fontFile;

	m_text->setFont(*m_font);
	m_text->setCharacterSize(fontSize);
	m_text->setString(message);

	setPosition(position);
	setId(objectId);
	setLayer(objectLayer);
}

textObject::~textObject()
{
	//De-initialise object
	destroyObject();
	delete m_font;
	delete m_text;
}

void textObject::setPosition(const sf::Vector2f &position) const
{
	sf::Vector2f offSet;
	offSet.x = { m_text->getGlobalBounds().left - m_text->getPosition().x};
	offSet.y = { m_text->getGlobalBounds().top - m_text->getPosition().y };

	m_text->setPosition({ position.x - offSet.x, position.y - offSet.y });
}

void textObject::setOrigin(const sf::Vector2f &origin) const
{
	m_text->setOrigin(origin.x, origin.y);
}

#include "../include/object.h"
// spriteObject constructor ---------------------------------------------------------------------------------
//Texture will be loaded from the directory given by string

spriteObject::spriteObject(const std::string &objectId, const std::string &textureDir, sf::Vector2f position, sf::Vector2f size, short objectLayer)
{
	//Load the texture from the directory provided
	if (!m_texture->loadFromFile(textureDir))
	{
		return;
	}

	//Apply texture to sprite, set its position and then apply its scale
	m_sprite->setTexture(*m_texture);
	m_sprite->setPosition(position.x, position.y);

	//Cannot use texture rect for a file directory
	m_sprite->setScale(static_cast<int>(size.x / m_texture->getSize().x), static_cast<int>(size.y / m_texture->getSize().y));

	setId(objectId);
	setLayer(objectLayer);
}

//Assuming texture has loaded, set the sprite to the textureFile
spriteObject::spriteObject(const std::string &objectId, sf::Texture& textureFile, sf::Vector2f position, sf::Vector2f size, short objectLayer)
{
	//Apply texture to sprite, set its position and then apply its scale
	m_texture = &textureFile;
	m_sprite->setTexture(textureFile);
	m_sprite->setPosition(position.x, position.y);

	setSize(size);	//Call set size function

	setId(objectId);
	setLayer(objectLayer);
}

spriteObject::~spriteObject()
{
	std::cout << "Deleted: " << getId() << "\n";

}

//Replace the sprite texture with a new specified directory
void spriteObject::replaceTexture(const std::string &textureDir, sf::Vector2f size) {
	if (!m_texture->loadFromFile(textureDir)) {
		return;
	}

	//Apply new texture
	m_sprite->setScale(size.x / m_texture->getSize().x, size.y / m_texture->getSize().y);
	m_sprite->setTexture(*m_texture);
}

//A permanent offset value
void spriteObject::setOffset(sf::Vector2f objectOffset)
{
	sharedData::setOffset(objectOffset);		//Define the offset value
	incrementPosition(objectOffset);		//Move the object
}


//Set the size of the sprite
//If the sprite has a repeated texture then do texture rect instead
void spriteObject::setSize(sf::Vector2f size)
{
	if (!m_texture->isRepeated())
	{
		m_sprite->setScale(size.x / m_texture->getSize().x, size.y / m_texture->getSize().y);
	}
	else
	{
		m_sprite->setTextureRect(sf::IntRect(0, 0, size.x, size.y));
	}
}

//Set the texture rect position
void spriteObject::setSpriteRectPos(sf::Vector2f position)
{
	m_sprite->setTextureRect(sf::IntRect(position.x, position.y, m_sprite->getTextureRect().width, m_sprite->getTextureRect().height));
}


//Set the Origin point of the sprite
void spriteObject::setOrigin(sf::Vector2f origin)
{
	m_sprite->setOrigin(origin.x / m_sprite->getScale().x, origin.y / m_sprite->getScale().y);
}


//Return true if the object has hit the predefined border
bool spriteObject::leftBorder(sf::Vector2i relativePosition, int borderLeft)
{
	if (relativePosition.x >= borderLeft)
	{
		return false;
	}
	return true;
}

bool spriteObject::rightBorder(sf::Vector2i relativePosition, int borderRight)
{
	if (relativePosition.x <= borderRight)
	{
		return false;
	}
	return true;
}

bool spriteObject::topBorder(sf::Vector2i relativePosition, int borderTop)
{
	if (relativePosition.y >= borderTop)
	{
		return false;
	}
	return true;
}

bool spriteObject::bottomBorder(sf::Vector2i relativePosition, int borderBottom)
{
	if (relativePosition.y <= borderBottom)
	{
		return false;
	}
	return true;
}

//Return an object ID if the selected sprite has collided with the object
std::string spriteObject::collisionBox(spriteObject* object)
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




// textObject constructor ------------------------------------------------------------------------------
textObject::textObject(const std::string &objectId, const std::string &message, sf::Vector2f position, const std::string &fontDir, int fontSize, short objectLayer)
{
	if (!m_font->loadFromFile(fontDir))
	{
		return;
	}

	m_text->setFont(*m_font);
	m_text->setCharacterSize(fontSize);
	m_text->setString(message);

	setPosition(position);
	setId(objectId);
	setLayer(objectLayer);
}

textObject::textObject(const std::string &objectId, const std::string &message, sf::Vector2f position, const sf::Font& fontFile, int fontSize, short objectLayer)
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
}

void textObject::setOrigin(sf::Vector2f origin)
{
	m_text->setOrigin(origin.x, origin.y);
}


void textObject::setPosition(sf::Vector2f position)
{
	sf::Vector2f offSet;
	offSet.x = { m_text->getGlobalBounds().left - m_text->getPosition().x};
	offSet.y = { m_text->getGlobalBounds().top - m_text->getPosition().y };

	m_text->setPosition({ position.x - offSet.x, position.y - offSet.y });
}
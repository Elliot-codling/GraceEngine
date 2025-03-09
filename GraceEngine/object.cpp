#include "object.h"
// spriteObject constructor ---------------------------------------------------------------------------------
//Texture will be loaded from the directory given by string

spriteObject::spriteObject(std::string objectId, std::string textureDir, sf::Vector2i position, sf::Vector2f size, short objectLayer)
{
	//Load the texture from the directory provided
	if (!texture.loadFromFile(textureDir))
	{
		return;
	}

	//Apply texture to sprite, set its position and then apply its scale
	sprite.setTexture(texture);
	sprite.setPosition(position.x, position.y);
	sprite.setScale(size.x / texture.getSize().x, size.y / texture.getSize().y);

	setId(objectId);
	setLayer(objectLayer);
}

//Assuming texture has loaded, set the sprite to the textureFile
spriteObject::spriteObject(std::string objectId, sf::Texture& textureFile, sf::Vector2i position, sf::Vector2f size, short objectLayer)
{
	//Apply texture to sprite, set its position and then apply its scale
	sprite.setTexture(textureFile);
	sprite.setPosition(position.x, position.y);
	sprite.setScale(size.x / textureFile.getSize().x, size.y / textureFile.getSize().y);

	setId(objectId);
	setLayer(objectLayer);
}

spriteObject::~spriteObject()
{

}

//Replace the sprite texture with a new specified directory
void spriteObject::replaceTexture(std::string textureDir, sf::Vector2f size) {
	if (!texture.loadFromFile(textureDir)) {
		return;
	}

	//Apply new texture
	sprite.setScale(size.x / texture.getSize().x, size.y / texture.getSize().y);
	sprite.setTexture(texture);
	
}

void spriteObject::setOrigin(sf::Vector2f origin, sf::Vector2i offSet)
{
	sprite.setOrigin(origin.x / sprite.getScale().x, origin.y / sprite.getScale().y);
	incrementPosition({ offSet.x, offSet.y });
}



bool spriteObject::left(int velocity, int borderLeft)
{
	if (getPosition().x > borderLeft)
	{
		incrementPosition({  -velocity, 0 });
		return false;
	}
	return true;
}

bool spriteObject::right(int velocity, int borderRight)
{
	if (getPosition().x < borderRight)
	{
		incrementPosition({ velocity, 0 });
		return false;
	}
	return true;
}

bool spriteObject::up(int velocity, int borderTop)
{
	if (getPosition().y > borderTop)
	{
		incrementPosition({0, -velocity });
		return false;
	}
	return true;
}

bool spriteObject::down(int velocity, int borderBottom)
{
	if (getPosition().y < borderBottom)
	{
		incrementPosition({ 0, velocity});
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
	else if (!(getPosition().x + getSize().x >= object->getPosition().x))
	{
		return "";
	}
	else if (!(getPosition().y <= object->getPosition().y + object->getSize().y))
	{
		return "";
	}
	else if (!(getPosition().y + getSize().y >= object->getPosition().y))
	{
		return "";
	}
	
	return object->getId();
}




// textObject constructor ------------------------------------------------------------------------------
textObject::textObject(std::string objectId, std::string message, sf::Vector2i position, std::string fontDir, int fontSize, short objectLayer)
{
	if (!font.loadFromFile(fontDir))
	{
		return;
	}

	text.setFont(font);
	text.setCharacterSize(fontSize);
	text.setString(message);

	text.setPosition({float(position.x), float(position.y)});
	setId(objectId);
	setLayer(objectLayer);
}

textObject::~textObject()
{
}

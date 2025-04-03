#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class sharedData
{
public:
	std::string getId() { return id; }
	short getLayer() { return layer; }
	sf::Vector2f getVelocity() { return velocity; }
	sf::Vector2f getOffset() { return offset; }

	void setId(std::string objectID) { id = objectID; }
	void setLayer(short objectLayer) { layer = objectLayer; }
	void setVelocity(sf::Vector2f objectVelocity) { velocity = objectVelocity; }
	virtual void setOffset(sf::Vector2f objectOffset) { offset = objectOffset; }

private:
	short layer;
	std::string id;
	sf::Vector2f velocity;
	sf::Vector2f offset;

};

// spriteObject class --------------------------------------------------
class spriteObject: public sharedData
{
public:
	//Constructor
	spriteObject(std::string objectId, std::string textureDir, sf::Vector2f position, sf::Vector2f size, short objectLayer = 0);
	spriteObject(std::string objectId, sf::Texture& textureFile, sf::Vector2f position, sf::Vector2f size, short objectLayer = 0);
	~spriteObject();

	//Child functions ----------------------------
	void replaceTexture(std::string textureDir, sf::Vector2f size);

	//Get size and position functions
	sf::Vector2f getPosition() { return { sprite->getGlobalBounds().left, sprite->getGlobalBounds().top }; }
	sf::Vector2f getSize() { return {sprite->getGlobalBounds().width, sprite->getGlobalBounds().height}; }
	float getAngle() { return sprite->getRotation(); }

	//Transform functions
	void setPosition(sf::Vector2f position) { sprite->setPosition(position.x + getOffset().x, position.y + getOffset().y); }
	void incrementPosition(sf::Vector2f position) { sprite->setPosition(sprite->getPosition().x + position.x, sprite->getPosition().y + position.y); }
	void setOffset(sf::Vector2f objectOffset) override
	{
		sharedData::setOffset(objectOffset);
		incrementPosition(objectOffset);
	}

	//Scale
	void setSize(sf::Vector2f size);
	void setSpriteRectPos(sf::Vector2f position);

	//Rotations
	void setOrigin(sf::Vector2f origin);
	void setAngle(float angle) { sprite->setRotation(angle); }
	void incrementAngle(float angle) { sprite->rotate(angle); }

	//Transform  but with borders
	bool leftBorder(sf::Vector2i relativePosition, int borderLeft);
	bool rightBorder(sf::Vector2i relativePosition, int borderRight);
	bool topBorder(sf::Vector2i relativePosition, int borderTop);
	bool bottomBorder(sf::Vector2i relativePosition, int borderBottom);

	//Collisions
	std::string collisionBox(spriteObject* object);

	//Overwritten functions -----------------------------------
	void render(sf::RenderTarget& target) { target.draw(*sprite); }

private:
	sf::Texture* texture = new sf::Texture;
	sf::Sprite* sprite = new sf::Sprite;
};



// textObject class -----------------------------------------------------------------------
class textObject: public sharedData
{
public:
	//Constructor
	textObject(std::string objectId, std::string message, sf::Vector2f position, std::string fontDir, int fontSize, short objectLayer = 0);
	~textObject();

	//Get functions
	sf::Vector2f getPosition() { return { text.getGlobalBounds().left, text.getGlobalBounds().top }; }
	sf::Vector2f getSize() { return { text.getLocalBounds().width, text.getLocalBounds().height }; }

	//Transform
	void setPosition(sf::Vector2f position);
	void incrementPosition(sf::Vector2f position) { text.setPosition(text.getPosition().x + position.x, text.getPosition().y + position.y); }

	//Scale
	void setFontSize(int fontSize) { text.setCharacterSize(fontSize); }

	//Rotations
	void setOrigin(sf::Vector2f origin);
	void setAngle(float angle) { text.setRotation(angle); }
	void incrementAngle(float angle) { text.rotate(angle); }

	//Update the message of the text
	void updateString(std::string newMessage) { text.setString(newMessage); }

	//Overwritten functions ----------------------------------------
	void render(sf::RenderTarget& target) { target.draw(text); }

private:
	sf::Font font;
	sf::Text text;
};
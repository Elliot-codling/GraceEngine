#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class sharedData
{
public:
	std::string getId() { return m_id; }
	short getLayer() { return m_layer; }
	sf::Vector2f getVelocity() { return m_velocity; }
	sf::Vector2f getOffset() { return m_offset; }

	void setId(std::string objectID) { m_id = objectID; }
	void setLayer(short objectLayer) { m_layer = objectLayer; }
	void setVelocity(sf::Vector2f objectVelocity) { m_velocity = objectVelocity; }
	virtual void setOffset(sf::Vector2f objectOffset) { m_offset = objectOffset; }

private:
	short m_layer;
	std::string m_id;
	sf::Vector2f m_velocity;
	sf::Vector2f m_offset;

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
	sf::Vector2f getPosition() { return { m_sprite->getGlobalBounds().left, m_sprite->getGlobalBounds().top }; }
	sf::Vector2f getSize() { return { m_sprite->getGlobalBounds().width, m_sprite->getGlobalBounds().height}; }
	float getAngle() { return m_sprite->getRotation(); }

	//Transform functions
	void setPosition(sf::Vector2f position) { m_sprite->setPosition(position.x + getOffset().x, position.y + getOffset().y); }
	void incrementPosition(sf::Vector2f position) { m_sprite->setPosition(m_sprite->getPosition().x + position.x, m_sprite->getPosition().y + position.y); }
	void setOffset(sf::Vector2f objectOffset) override;

	//Scale
	void setSize(sf::Vector2f size);
	void setSpriteRectPos(sf::Vector2f position);

	//Rotations
	void setOrigin(sf::Vector2f origin);
	void setAngle(float angle) { m_sprite->setRotation(angle); }
	void incrementAngle(float angle) { m_sprite->rotate(angle); }

	//Transform  but with borders
	bool leftBorder(sf::Vector2i relativePosition, int borderLeft);
	bool rightBorder(sf::Vector2i relativePosition, int borderRight);
	bool topBorder(sf::Vector2i relativePosition, int borderTop);
	bool bottomBorder(sf::Vector2i relativePosition, int borderBottom);

	//Collisions
	std::string collisionBox(spriteObject* object);

	//Overwritten functions -----------------------------------
	void render(sf::RenderTarget& target) { target.draw(*m_sprite); }

private:
	sf::Texture* m_texture = new sf::Texture;
	sf::Sprite* m_sprite = new sf::Sprite;
};



// textObject class -----------------------------------------------------------------------
class textObject: public sharedData
{
public:
	//Constructor
	textObject(std::string objectId, std::string message, sf::Vector2f position, std::string fontDir, int fontSize, short objectLayer = 0);
	~textObject();

	//Get functions
	sf::Vector2f getPosition() { return { m_text.getGlobalBounds().left, m_text.getGlobalBounds().top }; }
	sf::Vector2f getSize() { return { m_text.getLocalBounds().width, m_text.getLocalBounds().height }; }

	//Transform
	void setPosition(sf::Vector2f position);
	void incrementPosition(sf::Vector2f position) { m_text.setPosition(m_text.getPosition().x + position.x, m_text.getPosition().y + position.y); }

	//Scale
	void setFontSize(int fontSize) { m_text.setCharacterSize(fontSize); }

	//Rotations
	void setOrigin(sf::Vector2f origin);
	void setAngle(float angle) { m_text.setRotation(angle); }
	void incrementAngle(float angle) { m_text.rotate(angle); }

	//Update the message of the text
	void updateString(std::string newMessage) { m_text.setString(newMessage); }

	//Overwritten functions ----------------------------------------
	void render(sf::RenderTarget& target) { target.draw(m_text); }

private:
	sf::Font m_font;
	sf::Text m_text;
};
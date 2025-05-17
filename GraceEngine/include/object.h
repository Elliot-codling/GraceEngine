#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

//Sprite and Text objects will share some functions
//This class will be inherited between them
class sharedData
{
public:
	virtual ~sharedData() = default;

	//Get functions
	std::string getId() { return m_id; }
	short getLayer() const { return m_layer; }
	sf::Vector2f getVelocity() const { return m_velocity; }
	sf::Vector2f getOffset() const { return m_offset; }

	//Set functions
	void setId(const std::string& objectID) { m_id = objectID; }
	void setLayer(short objectLayer) { m_layer = objectLayer; }
	void setVelocity(sf::Vector2f objectVelocity) { m_velocity = objectVelocity; }
	virtual void setOffset(sf::Vector2f objectOffset) { m_offset = objectOffset; }

private:
	//Inherited variables
	short m_layer = 0;
	std::string m_id;
	sf::Vector2f m_velocity;
	sf::Vector2f m_offset;

};

// spriteObject class --------------------------------------------------
class spriteObject : public sharedData
{
public:
	//Constructor
	spriteObject(const std::string &objectId, const std::string &textureDir, sf::Vector2f position, sf::Vector2f size, short objectLayer = 0);
	spriteObject(const std::string &objectId, sf::Texture& textureFile, sf::Vector2f position, sf::Vector2f size, short objectLayer = 0);
	~spriteObject() override;

	void replaceTexture(const std::string &textureDir, sf::Vector2f size);

	//Get size and position functions
	sf::Vector2f getPosition() const { return { m_sprite->getGlobalBounds().left, m_sprite->getGlobalBounds().top }; }
	sf::Vector2f getSize() const { return { m_sprite->getGlobalBounds().width, m_sprite->getGlobalBounds().height}; }
	float getAngle() const { return m_sprite->getRotation(); }

	//Transform functions
	void setPosition(sf::Vector2f position) const { m_sprite->setPosition(position.x + getOffset().x, position.y + getOffset().y); }
	void incrementPosition(sf::Vector2f position) const { m_sprite->setPosition(m_sprite->getPosition().x + position.x, m_sprite->getPosition().y + position.y); }
	void setOffset(sf::Vector2f objectOffset) override;

	//Scale
	void setSize(sf::Vector2f size);
	void setSpriteRectPos(sf::Vector2f position);

	//Rotations
	void setOrigin(sf::Vector2f origin);
	void setAngle(float angle) const { m_sprite->setRotation(angle); }
	void incrementAngle(float angle) const { m_sprite->rotate(angle); }

	//Check if the relative position is near predefined borders
	bool leftBorder(sf::Vector2i relativePosition, int borderLeft);
	bool rightBorder(sf::Vector2i relativePosition, int borderRight);
	bool topBorder(sf::Vector2i relativePosition, int borderTop);
	bool bottomBorder(sf::Vector2i relativePosition, int borderBottom);

	//Collisions
	std::string collisionBox(spriteObject* object);

	//Render Object
	void render(sf::RenderTarget& target) const { target.draw(*m_sprite); }

private:
	sf::Texture* m_texture = new sf::Texture;
	sf::Sprite* m_sprite = new sf::Sprite;
};



// textObject class -----------------------------------------------------------------------
class textObject : public sharedData
{
public:
	//Constructor
	textObject(const std::string &objectId, const std::string &message, sf::Vector2f position, const std::string &fontDir, int fontSize, short objectLayer = 0);
	textObject(const std::string &objectId, const std::string &message, sf::Vector2f position, const sf::Font& fontFile, int fontSize, short objectLayer = 0);
	~textObject() override;

	//Size and position
	sf::Vector2f getPosition() const { return { m_text->getGlobalBounds().left, m_text->getGlobalBounds().top }; }
	sf::Vector2f getSize() const { return { m_text->getLocalBounds().width, m_text->getLocalBounds().height }; }

	//Transform
	void setPosition(sf::Vector2f position);
	void incrementPosition(sf::Vector2f position) const { m_text->setPosition(m_text->getPosition().x + position.x, m_text->getPosition().y + position.y); }

	//Scale
	void setFontSize(int fontSize) const { m_text->setCharacterSize(fontSize); }

	//Rotations
	void setOrigin(sf::Vector2f origin);
	void setAngle(float angle) const { m_text->setRotation(angle); }
	void incrementAngle(float angle) const { m_text->rotate(angle); }

	//Update the message of the text
	void updateString(const std::string &newMessage) const { m_text->setString(newMessage); }

	//Render Text
	void render(sf::RenderTarget& target) const { target.draw(*m_text); }

private:
	//Store font and text as ptr
	sf::Font* m_font = new sf::Font;
	sf::Text* m_text = new sf::Text;
};

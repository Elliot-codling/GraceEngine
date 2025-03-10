#pragma once
#include <SFML/Graphics.hpp>

class sharedData
{
public:
	std::string getId() { return id; }
	short getLayer() { return layer; }

	void setId(std::string objectID) { id = objectID; }
	void setLayer(short objectLayer) { layer = objectLayer; }

private:
	short layer;
	std::string id;
};

// spriteObject class --------------------------------------------------
class spriteObject: public sharedData
{
public:
	//Constructor
	spriteObject(std::string objectId, std::string textureDir, sf::Vector2i position, sf::Vector2f size, short objectLayer = 0);
	spriteObject(std::string objectId, sf::Texture& textureFile, sf::Vector2i position, sf::Vector2f size, short objectLayer = 0);
	~spriteObject();

	//Child functions ----------------------------
	void replaceTexture(std::string textureDir, sf::Vector2f size);

	//Get size and position functions
	sf::Vector2f getPosition() { return sf::Vector2f{ sprite.getGlobalBounds().left, sprite.getGlobalBounds().top }; }
	sf::Vector2f getSize() { return sf::Vector2f{sprite.getGlobalBounds().width, sprite.getGlobalBounds().height}; }
	float getAngle() { return sprite.getRotation(); }

	//Transform functions
	void setPosition(sf::Vector2i position) { sprite.setPosition(position.x, position.y); }
	void incrementPosition(sf::Vector2i position) { sprite.setPosition(sprite.getPosition().x + position.x, sprite.getPosition().y + position.y); }
#
	//Scale
	void setSize(sf::Vector2f size) { sprite.setScale(size.x / texture.getSize().x, size.y / texture.getSize().y); }

	//Rotations
	void setOrigin(sf::Vector2f origin, sf::Vector2i offSet);
	void setAngle(float angle) { sprite.setRotation(angle); }
	void incrementAngle(float angle) { sprite.rotate(angle); }

	//Transform  but with borders
	bool left(int velocity, int borderLeft);
	bool right(int velocity, int borderRight);
	bool up(int velocity, int borderTop);
	bool down(int velocity, int borderBottom);

	//Collisions
	std::string collisionBox(spriteObject* object);

	//Overwritten functions -----------------------------------
	void render(sf::RenderTarget& target) { target.draw(sprite); }

private:
	sf::Texture texture;
	sf::Sprite sprite;
};



// textObject class -----------------------------------------------------------------------
class textObject: public sharedData
{
public:
	//Constructor
	textObject(std::string objectId, std::string message, sf::Vector2i position, std::string fontDir, int fontSize, short objectLayer = 0);
	~textObject();

	//Get functions
	sf::Vector2f getPosition() { return text.getPosition(); }
	sf::Vector2f getSize() { return sf::Vector2f(text.getLocalBounds().width, text.getLocalBounds().height); }

	//Transform
	void setPosition(sf::Vector2i position) { text.setPosition(position.x, position.y); }
	void incrementPosition(sf::Vector2i position) { text.setPosition(text.getPosition().x + position.x, text.getPosition().y + position.y); }

	//Scale
	void setFontSize(int fontSize) { text.setCharacterSize(fontSize); }

	//Rotations
	void setOrigin(sf::Vector2f origin) { text.setOrigin(origin.x, origin.y); }
	void setAngle(int angle) { text.setRotation(angle); }
	void incrementAngle(int angle) { text.rotate(angle); }

	//Update the message of the text
	void updateString(std::string newMessage) { text.setString(newMessage); }

	//Overwritten functions ----------------------------------------
	void render(sf::RenderTarget& target) { target.draw(text); }

private:
	sf::Font font;
	sf::Text text;
};
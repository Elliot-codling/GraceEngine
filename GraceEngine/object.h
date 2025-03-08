#pragma once
#include <SFML/Graphics.hpp>


//Base gameObject that will be sent to the renderer
//This allows both the sprites and the text to be passed into the renderer
class gameObject
{
public:
	//Base class that will be sent however the code will never be executed here
	virtual ~gameObject() {};
	virtual void render(sf::RenderTarget& target) = 0;

	//Shared functions
	std::string getId() { return id; }
	int getLayer() { return layer; }

	void setId(std::string& objectId) { id = std::move(objectId); }
	void setLayer(short& objectLayer) { layer = objectLayer; }

private:
	short layer = 0;
	std::string id;

	//spriteObject Specific functions
	virtual void replaceTexture(std::string textureDir, sf::Vector2f size) = 0;
	virtual void setSize(sf::Vector2f size) = 0;

	//textObject specific functions
	
};

// spriteObject class --------------------------------------------------
class spriteObject : public gameObject
{
public:
	//Constructor
	spriteObject(std::string objectId, std::string textureDir, sf::Vector2i position, sf::Vector2f size, short objectLayer = 0);
	spriteObject(std::string objectId, sf::Texture& textureFile, sf::Vector2i position, sf::Vector2f size, short objectLayer = 0);
	~spriteObject() override;

	//Child functions ----------------------------
	void replaceTexture(std::string textureDir, sf::Vector2f size) override;

	//Get size and position functions
	sf::Vector2f getPosition() { return sprite.getPosition(); }
	sf::Vector2f getSize() { return sf::Vector2f{ texture.getSize().x * sprite.getScale().x, texture.getSize().y * sprite.getScale().y }; }

	//Transform functions
	void setPosition(sf::Vector2i position) { sprite.setPosition(position.x, position.y); }
	void incrementPosition(sf::Vector2i position) { sprite.setPosition(sprite.getPosition().x + position.x, sprite.getPosition().y + position.y); }
#
	//Scale
	void setSize(sf::Vector2f size) override { sprite.setScale(size.x / texture.getSize().x, size.y / texture.getSize().y); }

	//Rotations
	void setOrigin(sf::Vector2f origin) { sprite.setOrigin(origin.x / sprite.getScale().x, origin.y / sprite.getScale().y); }
	void setAngle(float angle) { sprite.setRotation(angle); }
	void incrementAngle(float angle) { sprite.rotate(angle); }

	//Transform  but with borders
	bool left(int velocity, int borderLeft);
	bool right(int velocity, int borderRight);
	bool up(int velocity, int borderTop);
	bool down(int velocity, int borderBottom);

	//Overwritten functions -----------------------------------
	void render(sf::RenderTarget& target) override { target.draw(sprite); }

private:
	sf::Texture texture;
	sf::Sprite sprite;
};



// textObject class -----------------------------------------------------------------------
class textObject : public gameObject
{
public:
	//Constructor
	textObject(std::string objectId, std::string message, sf::Vector2i position, std::string fontDir, int fontSize, short objectLayer = 0);
	~textObject() override;

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
	void render(sf::RenderTarget& target) override { target.draw(text); }

private:
	sf::Font font;
	sf::Text text;

	//Not used
	void replaceTexture(std::string textureDir, sf::Vector2f size) override { return; }
	void setSize(sf::Vector2f size) override { return; };
};
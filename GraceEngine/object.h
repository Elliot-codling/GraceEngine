#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <conio.h>

using namespace std;
using namespace sf;
//Base gameObject that will be sent to the renderer
//This allows both the sprites and the text to be passed into the renderer
class gameObject
{
public:
	//Base class that will be sent however the code will never be executed here
	virtual ~gameObject() {};
	virtual void render(RenderTarget& target) = 0;

	//Shared functions
	string getId() { return id; }
	int getLayer() { return layer; }

	void setId(string& objectId) { id = objectId; }
	void setLayer(int& objectLayer) { layer = objectLayer; }

private:
	int layer = 0;
	string id;

	//spriteObject Specific functions
	virtual void replaceTexture(string textureDir, Vector2f size) = 0;

	//textObject specific functions
	
};

// spriteObject class --------------------------------------------------
class spriteObject : public gameObject
{
public:
	//Constructor
	spriteObject(string objectId, string textureDir, Vector2i position, Vector2f size, int objectLayer = 0);
	spriteObject(string objectId, Texture& textureFile, Vector2i position, Vector2f size, int objectLayer = 0);
	~spriteObject() override;

	//Child functions ----------------------------
	void replaceTexture(string textureDir, Vector2f size) override;

	//Get size and position functions
	Vector2f getPosition() { return sprite.getPosition(); }
	Vector2f getSize() { return Vector2f{ texture.getSize().x * sprite.getScale().x, texture.getSize().y * sprite.getScale().y }; }

	//Transform functions
	void setPosition(Vector2i position) { sprite.setPosition(position.x, position.y); }
	void incrementPosition(Vector2i position) { sprite.setPosition(sprite.getPosition().x + position.x, sprite.getPosition().y + position.y); }
#
	//Scale
	void setSize(Vector2f size) { sprite.setScale(size.x / texture.getSize().x, size.y / texture.getSize().y); }

	//Rotations
	void setOrigin(Vector2f origin) { sprite.setOrigin(origin.x / sprite.getScale().x, origin.y / sprite.getScale().y); }
	void setAngle(float angle) { sprite.setRotation(angle); }
	void incrementAngle(float angle) { sprite.rotate(angle); }

	//Transform  but with borders
	bool left(int velocity, int borderLeft);
	bool right(int velocity, int borderRight);
	bool up(int velocity, int borderTop);
	bool down(int velocity, int borderBottom);

	//Overwritten functions -----------------------------------
	void render(RenderTarget& target) override { target.draw(sprite); }

private:
	Texture texture;
	Sprite sprite;
};



// textObject class -----------------------------------------------------------------------
class textObject : public gameObject
{
public:
	//Constructor
	textObject(string objectId, string message, Vector2i position, string fontDir, int fontSize, int objectLayer = 0);
	~textObject() override;

	//Get functions
	Vector2f getPosition() { return text.getPosition(); }
	Vector2f getSize() { return Vector2f(text.getLocalBounds().width, text.getLocalBounds().height); }

	//Transform
	void setPosition(Vector2i position) { text.setPosition(position.x, position.y); }
	void incrementPosition(Vector2i position) { text.setPosition(text.getPosition().x + position.x, text.getPosition().y + position.y); }

	//Scale
	void setFontSize(int fontSize) { text.setCharacterSize(fontSize); }

	//Rotations
	void setOrigin(Vector2f origin) { text.setOrigin(origin.x, origin.y); }
	void setAngle(int angle) { text.setRotation(angle); }
	void incrementAngle(int angle) { text.rotate(angle); }

	//Update the message of the text
	void updateString(string newMessage) { text.setString(newMessage); }

	//Overwritten functions ----------------------------------------
	void render(RenderTarget& target) override { target.draw(text); }

private:
	Font font;
	Text text;

	//Not used
	void replaceTexture(string textureDir, Vector2f size) override { return; }
};
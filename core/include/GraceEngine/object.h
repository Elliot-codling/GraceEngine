#pragma once
#include <SFML/Graphics.hpp>
#include <GraceEngine/debugHandler.h>

//Sprite and Text objects will share some functions
//This class will be inherited between them
//Nodiscard -> warn users if a get function is called but not used in program
class sharedData
{
public:
	virtual ~sharedData() = default;

	//Get functions
	[[nodiscard]] std::string getId() const { return m_id; }
	[[nodiscard]] uint8_t getLayer() const { return m_layer; }
	[[nodiscard]] sf::Vector2f getVelocity() const { return m_velocity; }
	[[nodiscard]] sf::Vector2f getOffset() const { return m_offset; }

	//Set functions
	void setId(const std::string& objectID) { m_id = objectID; }
	void setLayer(const uint8_t &objectLayer) { m_layer = objectLayer; }
	void setVelocity(const sf::Vector2f &objectVelocity) { m_velocity = objectVelocity; }
	virtual void setOffset(const sf::Vector2f &objectOffset) { m_offset = objectOffset; }

	[[nodiscard]] bool isInitialised() const { return m_initialised; }

protected:
	void initialiseObject() { m_initialised = true; }
	void destroyObject() { m_initialised = false; }

private:
	//Inherited variables
	uint8_t m_layer = 0;
	std::string m_id;
	sf::Vector2f m_velocity;
	sf::Vector2f m_offset;
	bool m_initialised = false;

};

// spriteObject class --------------------------------------------------
class spriteObject : public sharedData, public debugHandler
{
public:
	//Constructor
	spriteObject(const std::string &objectId, const std::string &textureDir, const sf::Vector2f &position, const sf::Vector2f &size, const uint8_t &objectLayer = 0);
	spriteObject(const std::string &objectId, const sf::Texture &textureFile, const sf::Vector2f &position, const sf::Vector2f &size, const uint8_t &objectLayer = 0);
	~spriteObject() override;

	void replaceTexture(const std::string &textureDir, const sf::Vector2f &size) const;

	//Get size and position functions - warn user if it is not used
	[[nodiscard]] sf::Vector2f getPosition() const { return { m_sprite->getGlobalBounds().left, m_sprite->getGlobalBounds().top }; }
	[[nodiscard]] sf::Vector2f getSize() const { return { m_sprite->getGlobalBounds().width, m_sprite->getGlobalBounds().height}; }
	[[nodiscard]] float getAngle() const { return m_sprite->getRotation(); }

	//Transform functions
	void setPosition(const sf::Vector2f &position) const { m_sprite->setPosition(position.x + getOffset().x, position.y + getOffset().y); }
	void incrementPosition(const sf::Vector2f &position) const { m_sprite->setPosition(m_sprite->getPosition().x + position.x, m_sprite->getPosition().y + position.y); }
	void setOffset(const sf::Vector2f &objectOffset) override;

	//Scale
	void setSize(const sf::Vector2f &size) const;
	void setSpriteRectPos(const sf::Vector2f &position) const;

	//Rotations
	void setOrigin(const sf::Vector2f &origin) const;
	void setAngle(const float &angle) const { m_sprite->setRotation(angle); }
	void incrementAngle(const float &angle) const { m_sprite->rotate(angle); }

	//Check if the relative position is near predefined borders
	[[nodiscard]] static bool leftBorder(const sf::Vector2i &relativePosition, const int &borderLeft) { return relativePosition.x >= borderLeft; }
	[[nodiscard]] static bool rightBorder(const sf::Vector2i &relativePosition, const int &borderRight) { return relativePosition.x <= borderRight;}
	[[nodiscard]] static bool topBorder(const sf::Vector2i &relativePosition, const int &borderTop) { return relativePosition.y >= borderTop; }
	[[nodiscard]] static bool bottomBorder(const sf::Vector2i &relativePosition, const int &borderBottom) { return relativePosition.y <= borderBottom; }

	//Collisions
	std::string collisionBox(const spriteObject* object) const;

	//Debug
	void setDebugActive(const sf::Color &color = {255, 255, 255});

	//Render Object
	void render(sf::RenderTarget &target) const;

private:
	sf::Texture* m_texture = new sf::Texture;
	sf::Sprite* m_sprite = new sf::Sprite;

	//Initialise debug rectangle - Default: Not in debug mode
	sf::RectangleShape* m_debugRect = nullptr;
	bool m_isDebugging = false;
};





// textObject class -----------------------------------------------------------------------
class textObject : public sharedData, public debugHandler
{
public:
	//Constructor
	textObject(const std::string &objectId, const std::string &message, const sf::Vector2f &position, const std::string &fontDir, const uint8_t &fontSize, const uint8_t &objectLayer = 0);
	textObject(const std::string &objectId, const std::string &message, const sf::Vector2f &position, const sf::Font &fontFile, const uint8_t &fontSize, const uint8_t &objectLayer = 0);
	~textObject() override;

	//Size and position
	[[nodiscard]] sf::Vector2f getPosition() const { return { m_text->getGlobalBounds().left, m_text->getGlobalBounds().top }; }
	[[nodiscard]] sf::Vector2f getSize() const { return { m_text->getLocalBounds().width, m_text->getLocalBounds().height }; }

	//Transform
	void setPosition(const sf::Vector2f &position) const;
	void incrementPosition(const sf::Vector2f &position) const { m_text->setPosition(m_text->getPosition().x + position.x, m_text->getPosition().y + position.y); }

	//Scale
	void setFontSize(const uint8_t &fontSize) const { m_text->setCharacterSize(fontSize); }

	//Rotations
	void setOrigin(const sf::Vector2f &origin) const;
	void setAngle(const float &angle) const { m_text->setRotation(angle); }
	void incrementAngle(const float &angle) const { m_text->rotate(angle); }

	//Update the message of the text
	void updateString(const std::string &newMessage) const { m_text->setString(newMessage); }

	//Render Text
	void render(sf::RenderTarget& target) const { target.draw(*m_text); }

private:
	//Store font and text as ptr
	sf::Font* m_font = new sf::Font;
	sf::Text* m_text = new sf::Text;
};

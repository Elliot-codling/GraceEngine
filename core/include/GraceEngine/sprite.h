#pragma once
#include <GraceEngine/debugHandler.h>
#include <GraceEngine/sharedObjectClass.h>

// spriteObject class --------------------------------------------------
class spriteObject : public sharedData, public debugHandler
{
public:
	//Constructor
	spriteObject(const std::string& objectId, const std::string& textureDir, const sf::Vector2f& position, const sf::Vector2f& size, const uint8_t& objectLayer = 0);
	spriteObject(const std::string& objectId, const sf::Texture& textureFile, const sf::Vector2f& position, const sf::Vector2f& size, const uint8_t& objectLayer = 0);
	~spriteObject() override;

	void replaceTexture(const std::string& textureDir, const sf::Vector2f& size) const;

	//Get size and position functions - warn user if it is not used
	[[nodiscard]] sf::Vector2f getPosition() const { return { m_sprite->getGlobalBounds().left, m_sprite->getGlobalBounds().top }; }
	[[nodiscard]] sf::Vector2f getSize() const { return { m_sprite->getGlobalBounds().width, m_sprite->getGlobalBounds().height }; }
	[[nodiscard]] float getAngle() const { return m_sprite->getRotation(); }

	//Transform functions
	void setPosition(const sf::Vector2f& position) const { m_sprite->setPosition(position.x + getOffset().x, position.y + getOffset().y); }
	void incrementPosition(const sf::Vector2f& position) const { m_sprite->setPosition(m_sprite->getPosition().x + position.x, m_sprite->getPosition().y + position.y); }
	void setOffset(const sf::Vector2f& objectOffset) override;

	//Scale
	void setSize(const sf::Vector2f& size) const;
	void setSpriteRectPos(const sf::Vector2f& position) const;

	//Rotations
	void setOrigin(const sf::Vector2f& origin) const;
	void setAngle(const float& angle) const { m_sprite->setRotation(angle); }
	void incrementAngle(const float& angle) const { m_sprite->rotate(angle); }

	//Check if the relative position is near predefined borders
	[[nodiscard]] static bool leftBorder(const sf::Vector2i& relativePosition, const int& borderLeft) { return relativePosition.x >= borderLeft; }
	[[nodiscard]] static bool rightBorder(const sf::Vector2i& relativePosition, const int& borderRight) { return relativePosition.x <= borderRight; }
	[[nodiscard]] static bool topBorder(const sf::Vector2i& relativePosition, const int& borderTop) { return relativePosition.y >= borderTop; }
	[[nodiscard]] static bool bottomBorder(const sf::Vector2i& relativePosition, const int& borderBottom) { return relativePosition.y <= borderBottom; }

	//Collisions
	std::string collisionBox(const spriteObject* object) const;

	//Debug
	void setDebugActive(const sf::Color& color = { 255, 255, 255 });

	//Render Object
	void render(sf::RenderTarget& target) const;

private:
	sf::Texture* m_texture = new sf::Texture;
	sf::Sprite* m_sprite = new sf::Sprite;

	//Initialise debug rectangle - Default: Not in debug mode
	sf::RectangleShape* m_debugRect = nullptr;
	bool m_isDebugging = false;
};
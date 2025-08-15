#pragma once
#include <GraceEngine/debugHandler.h>
#include <GraceEngine/sharedObjectClass.h>

// spriteObject class --------------------------------------------------
class SpriteObject : public SharedData, public DebugHandler
{
public:
	// Constructor
	SpriteObject(const char* objectId, const char* textureDir, sf::Vector2f position, sf::Vector2f size, uint8_t objectLayer = 0);
	SpriteObject(const char* objectId, const sf::Texture& textureFile, sf::Vector2f position, sf::Vector2f size, uint8_t objectLayer = 0);
	~SpriteObject() override;

	// ### Position ###
	// Get the position of the object, one uses global bounds while the other uses the sprite position
	[[nodiscard]] sf::Vector2f getPosition() const { return m_sprite->getPosition() - getOffset(); };		// <-- Not affected by rotation
	[[nodiscard]] sf::Vector2f getGlobalPosition() const { return { m_sprite->getGlobalBounds().left, m_sprite->getGlobalBounds().top }; }

	void setPosition(const sf::Vector2f position) const { m_sprite->setPosition(position.x + getOffset().x, position.y + getOffset().y); }
	void incrementPosition(const sf::Vector2f position) const { m_sprite->setPosition(m_sprite->getPosition().x + position.x, m_sprite->getPosition().y + position.y); }
	// Offset values and origin values
	void setOffset(sf::Vector2f objectOffset) override;
	void setOrigin(sf::Vector2f origin) const;

	// ### Scale ###
	// Get the size of the object, one uses global bounds while the other calculates the size of the sprite
	[[nodiscard]] sf::Vector2f getSize() const { return {static_cast<float>(m_texture->getSize().x) * m_sprite->getScale().x, static_cast<float>(m_texture->getSize().y) * m_sprite->getScale().y};} // <-- Not affected by rotation
	[[nodiscard]] sf::Vector2f getGlobalSize() const { return { m_sprite->getGlobalBounds().width, m_sprite->getGlobalBounds().height }; }
	void setSize(sf::Vector2f size) const;

	// ### Rotation ###
	[[nodiscard]] float getAngle() const { return m_sprite->getRotation(); }
	void setAngle(const float angle) const { m_sprite->setRotation(angle); }
	void incrementAngle(const float angle) const { m_sprite->rotate(angle); }

	// Texture
	void replaceTexture(const char* textureDir, sf::Vector2f size) const;
	void setSpriteRectPos(sf::Vector2f position) const;

	// Collisions
	// Check if the relative position is near predefined borders
	[[nodiscard]] static bool leftBorder(const sf::Vector2i relativePosition, const int borderLeft) { return relativePosition.x >= borderLeft; }
	[[nodiscard]] static bool rightBorder(const sf::Vector2i relativePosition, const int borderRight) { return relativePosition.x <= borderRight; }
	[[nodiscard]] static bool topBorder(const sf::Vector2i relativePosition, const int borderTop) { return relativePosition.y >= borderTop; }
	[[nodiscard]] static bool bottomBorder(const sf::Vector2i relativePosition, const int borderBottom) { return relativePosition.y <= borderBottom; }
	// Simple AABB collision
	std::string collisionBox(const SpriteObject* object) const;

	// Debug
	void setDebugActive(sf::Color color = { 255, 255, 255 });

	// Render Object
	void render(sf::RenderTarget& target) const;

private:
	sf::Texture* m_texture = new sf::Texture;
	sf::Sprite* m_sprite = new sf::Sprite;

	// Initialise debug rectangle - Default: Not in debug mode
	sf::RectangleShape* m_debugRect = nullptr;

	bool m_isDebugging = false;
};
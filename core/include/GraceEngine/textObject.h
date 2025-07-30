#pragma once
#include <GraceEngine/debugHandler.h>
#include <GraceEngine/sharedObjectClass.h>

// textObject class -----------------------------------------------------------------------
class TextObject : public SharedData, public DebugHandler
{
public:
	// Constructor
	TextObject(const char* objectId, const char* message, sf::Vector2f position, const char* fontDir, uint8_t fontSize, uint8_t objectLayer = 0);
	TextObject(const char* objectId, const char* message, sf::Vector2f position, const sf::Font& fontFile, uint8_t fontSize, uint8_t objectLayer = 0);
	~TextObject() override;

	// Size and position
	[[nodiscard]] sf::Vector2f getPosition() const { return { m_text->getGlobalBounds().left, m_text->getGlobalBounds().top }; }
	[[nodiscard]] sf::Vector2f getSize() const { return { m_text->getLocalBounds().width, m_text->getLocalBounds().height }; }

	// Transform
	void setPosition(sf::Vector2f position) const;
	void incrementPosition(const sf::Vector2f position) const { m_text->setPosition(m_text->getPosition().x + position.x, m_text->getPosition().y + position.y); }

	// Scale
	void setFontSize(const uint8_t fontSize) const { m_text->setCharacterSize(fontSize); }

	// Rotations
	void setOrigin(sf::Vector2f origin) const;
	void setAngle(const float angle) const { m_text->setRotation(angle); }
	void incrementAngle(const float angle) const { m_text->rotate(angle); }

	// Update the message of the text
	void updateString(const char* newMessage) const { m_text->setString(newMessage); }

	// Render Text
	void render(sf::RenderTarget& target) const;

private:
	// Store font and text as ptr
	sf::Font* m_font = new sf::Font;
	sf::Text* m_text = new sf::Text;
};

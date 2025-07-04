#pragma once
#include <GraceEngine/debugHandler.h>
#include <GraceEngine/sharedObjectClass.h>

// textObject class -----------------------------------------------------------------------
class textObject : public sharedData, public debugHandler
{
public:
	//Constructor
	textObject(const std::string& objectId, const std::string& message, const sf::Vector2f& position, const std::string& fontDir, const uint8_t& fontSize, const uint8_t& objectLayer = 0);
	textObject(const std::string& objectId, const std::string& message, const sf::Vector2f& position, const sf::Font& fontFile, const uint8_t& fontSize, const uint8_t& objectLayer = 0);
	~textObject() override;

	//Size and position
	[[nodiscard]] sf::Vector2f getPosition() const { return { m_text->getGlobalBounds().left, m_text->getGlobalBounds().top }; }
	[[nodiscard]] sf::Vector2f getSize() const { return { m_text->getLocalBounds().width, m_text->getLocalBounds().height }; }

	//Transform
	void setPosition(const sf::Vector2f& position) const;
	void incrementPosition(const sf::Vector2f& position) const { m_text->setPosition(m_text->getPosition().x + position.x, m_text->getPosition().y + position.y); }

	//Scale
	void setFontSize(const uint8_t& fontSize) const { m_text->setCharacterSize(fontSize); }

	//Rotations
	void setOrigin(const sf::Vector2f& origin) const;
	void setAngle(const float& angle) const { m_text->setRotation(angle); }
	void incrementAngle(const float& angle) const { m_text->rotate(angle); }

	//Update the message of the text
	void updateString(const std::string& newMessage) const { m_text->setString(newMessage); }

	//Render Text
	void render(sf::RenderTarget& target) const { target.draw(*m_text); }

private:
	//Store font and text as ptr
	sf::Font* m_font = new sf::Font;
	sf::Text* m_text = new sf::Text;
};

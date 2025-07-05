#include <GraceEngine/textObject.h>

// TODO: Add more comments

// TextObject constructor ------------------------------------------------------------------------------
TextObject::TextObject(const char* objectId, const char* message, const sf::Vector2f position, const char* fontDir, const uint8_t fontSize, const uint8_t objectLayer)
{
	setId(objectId);
	if (!m_font->loadFromFile(fontDir))
	{
		printWarningInfo("Text object: '" + std::string(getId()) + "' is not initialised.");
		return;
	}

	m_text->setFont(*m_font);
	m_text->setCharacterSize(fontSize);
	m_text->setString(message);

	setPosition(position);
	setLayer(objectLayer);
}

TextObject::TextObject(const char* objectId, const char* message, const sf::Vector2f position, const sf::Font& fontFile, const uint8_t fontSize, const uint8_t objectLayer)
{
	*m_font = fontFile;

	m_text->setFont(*m_font);
	m_text->setCharacterSize(fontSize);
	m_text->setString(message);

	setPosition(position);
	setId(objectId);
	setLayer(objectLayer);
}

TextObject::~TextObject()
{
	//De-initialise object
	destroyObject();
	delete m_font;
	delete m_text;
}

void TextObject::setPosition(const sf::Vector2f position) const
{
	sf::Vector2f offSet;
	offSet.x = { m_text->getGlobalBounds().left - m_text->getPosition().x };
	offSet.y = { m_text->getGlobalBounds().top - m_text->getPosition().y };

	m_text->setPosition({ position.x - offSet.x, position.y - offSet.y });
}

void TextObject::setOrigin(const sf::Vector2f origin) const
{
	m_text->setOrigin(origin.x, origin.y);
}

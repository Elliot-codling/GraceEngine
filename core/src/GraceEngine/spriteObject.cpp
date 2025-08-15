#include <GraceEngine/spriteObject.h>


// SpriteObject constructor ---------------------------------------------------------------------------------
// Texture will be loaded from the directory given by string

SpriteObject::SpriteObject(const char* objectId, const char* textureDir, const sf::Vector2f position, const sf::Vector2f size, const uint8_t objectLayer)
{
	// Assign an id to the object
	setId(objectId);

	// Load the texture from the directory provided
	if (!m_texture->loadFromFile(textureDir))
	{
		printWarningInfo("Sprite object: '" + std::string(getId()) + "' is not initialised");
		return;
	}

	// Apply texture to sprite, set its position and then apply its scale
	m_sprite->setTexture(*m_texture);
	m_sprite->setPosition(position.x, position.y);

	setSize(size);
	setLayerNumber(objectLayer);

	// Once it's passed through, the object has initialised successfully
	initialiseObject();
}

// Assuming texture has loaded, set the sprite to the textureFile
SpriteObject::SpriteObject(const char* objectId, const sf::Texture& textureFile, const sf::Vector2f position, const sf::Vector2f size, const uint8_t objectLayer)
{
	// Assign the object its id
	setId(objectId);

	// Apply texture to sprite, set its position and then apply its scale
	*m_texture = textureFile;
	m_sprite->setTexture(textureFile);
	m_sprite->setPosition(position.x, position.y);

	setSize(size);
	setLayerNumber(objectLayer);

	// Once it's passed through, the object has initialised successfully
	initialiseObject();
}

SpriteObject::~SpriteObject()
{
	destroyObject();
	if (m_isDebugging)
	{
		printInfo("Deleted: '" + std::string(getId()) + "'");
	}
}

// Replace the sprite texture with a new specified directory
void SpriteObject::replaceTexture(const char* textureDir, const sf::Vector2f size) const
{
	if (!m_texture->loadFromFile(textureDir))
	{
		return;
	}

	// Apply new texture
	m_sprite->setScale(size.x / static_cast<float>(m_texture->getSize().x), size.y / static_cast<float>(m_texture->getSize().y));
	m_sprite->setTexture(*m_texture);
}

// Set the texture rect position
void SpriteObject::setSpriteRectPos(const sf::Vector2f position) const
{
	m_sprite->setTextureRect(sf::IntRect(static_cast<int>(position.x), static_cast<int>(position.y), m_sprite->getTextureRect().width, m_sprite->getTextureRect().height));
}


// Create a rectangle, set its size, pos and colour and then print out to terminal
void SpriteObject::setDebugActive(const sf::Color color)
{
	m_debugRect = new sf::RectangleShape;
	m_debugRect->setSize(getSize());
	m_debugRect->setFillColor(color);
	m_debugRect->setPosition(getPosition());
	m_isDebugging = true;
    DebugHandler::printInfo("Sprite object: '" + std::string(getId()) + "' is in debug");
}

// Render object, if in debug render debug rect too
void SpriteObject::render(sf::RenderTarget& target) const
{
	// Draw debug rect if it is currently debugging
	if (m_isDebugging)
	{
		m_debugRect->setSize(getSize());
		m_debugRect->setRotation(m_sprite->getRotation());
		m_debugRect->setPosition(getPosition() + getOffset());
		m_debugRect->setOrigin(m_debugRect->getSize().x / 2.f, m_debugRect->getSize().y / 2.f);
		target.draw(*m_debugRect);
	}
	if (isObjectVisible())
	{
		target.draw(*m_sprite);
	}

}
#include <GraceEngine/spriteObject.h>

// This file is used for transformations in the spriteObject header file


// Define object offset value
void SpriteObject::setOffset(const sf::Vector2f objectOffset)
{
    SharedData::setOffset(objectOffset);		// Define the offset value
    incrementPosition(objectOffset);		// Move the object
}

// Set the Origin point of the sprite
void SpriteObject::setOrigin(const sf::Vector2f origin) const
{
    m_sprite->setOrigin(origin.x / m_sprite->getScale().x, origin.y / m_sprite->getScale().y);
}


// Set the size of the sprite
// If the sprite has a repeated texture then do texture rect instead
void SpriteObject::setSize(const sf::Vector2f size) const
{
    if (!m_texture->isRepeated())
    {
        m_sprite->setScale(size.x / static_cast<float>(m_texture->getSize().x), size.y / static_cast<float>(m_texture->getSize().y));
    }
    else
    {
        m_sprite->setTextureRect(sf::IntRect(0, 0, static_cast<int>(size.x), static_cast<int>(size.y)));
    }
}
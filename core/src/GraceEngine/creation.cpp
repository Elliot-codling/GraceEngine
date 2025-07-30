#include <GraceEngine/creation.h>

Create::~Create()
{
    m_spriteList.clear();
    m_textList.clear();
}

SpriteObject* Create::createSprite(const char* objectId, const char* textureDir, sf::Vector2f position, sf::Vector2f size, uint8_t objectLayer)
{
    m_spriteList.emplace_back(objectId, textureDir, position, size, objectLayer);
    return &m_spriteList.back();
}
SpriteObject* Create::createSprite(const char* objectId, const sf::Texture& textureFile, sf::Vector2f position, sf::Vector2f size, uint8_t objectLayer)
{
    m_spriteList.emplace_back(objectId, textureFile, position, size, objectLayer);
    return &m_spriteList.back();
}

// TextObject
TextObject* Create::createText(const char* objectId, const char* message, sf::Vector2f position, const char* fontDir, uint8_t fontSize, uint8_t objectLayer)
{
    m_textList.emplace_back(objectId, message, position, fontDir, fontSize, objectLayer);
    return &m_textList.back();
}

TextObject* Create::createText(const char* objectId, const char* message, sf::Vector2f position, const sf::Font& fontFile, uint8_t fontSize, uint8_t objectLayer)
{
    m_textList.emplace_back(objectId, message, position, fontFile, fontSize, objectLayer);
    return &m_textList.back();
}
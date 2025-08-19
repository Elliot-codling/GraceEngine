#include <GraceEngine/creation.h>

Create::~Create()
{
    m_spriteList.clear();
    m_textList.clear();
}

SpriteObject* Create::createSprite(const char* objectId, const char* textureDir, sf::Vector2f position, sf::Vector2f size, uint8_t objectLayer)
{
    auto* sprite = new SpriteObject(objectId, textureDir, position, size, objectLayer);
    m_spriteList.emplace_back(*sprite);
    return sprite;
}
SpriteObject* Create::createSprite(const char* objectId, const sf::Texture& textureFile, sf::Vector2f position, sf::Vector2f size, uint8_t objectLayer)
{
    auto* sprite = new SpriteObject(objectId, textureFile, position, size, objectLayer);
    m_spriteList.emplace_back(*sprite);
    return sprite;
}

// TextObject
TextObject* Create::createText(const char* objectId, const char* message, const sf::Vector2f position, const char* fontDir, const uint8_t fontSize, const uint8_t objectLayer)
{
    auto* text = new TextObject(objectId, message, position, fontDir, fontSize, objectLayer);
    m_textList.emplace_back(*text);
    return text;
}

TextObject* Create::createText(const char* objectId, const char* message, const sf::Vector2f position, const sf::Font& fontFile, const uint8_t fontSize, const uint8_t objectLayer)
{
    auto* text = new TextObject(objectId, message, position, fontFile, fontSize, objectLayer);
    m_textList.emplace_back(*text);
    return text;
}
#pragma once
#include <GraceEngine/SpriteObject.h>
#include <GraceEngine/TextObject.h>

class Create
{
public:
    Create() = default;
    ~Create();
    // SpriteObject
    [[nodiscard]] SpriteObject* createSprite(const char* objectId, const char* textureDir, sf::Vector2f position, sf::Vector2f size, uint8_t objectLayer = 0);
    [[nodiscard]] SpriteObject* createSprite(const char* objectId, const sf::Texture& textureFile, sf::Vector2f position, sf::Vector2f size, uint8_t objectLayer = 0);

    // TextObject
    [[nodiscard]] TextObject* createText(const char* objectId, const char* message, sf::Vector2f position, const char* fontDir, uint8_t fontSize, uint8_t objectLayer = 0);
    [[nodiscard]] TextObject* createText(const char* objectId, const char* message, sf::Vector2f position, const sf::Font& fontFile, uint8_t fontSize, uint8_t objectLayer = 0);

protected:
    std::vector<SpriteObject> m_spriteList;
    std::vector<TextObject> m_textList;
};
#include <GraceEngine/scene.h>

Scene::Scene(const char* sceneName, const uint32_t vectorSize)
{
    // Set name and vector size
    m_sceneName = sceneName;
    m_spriteList.reserve(vectorSize);
}

/* Steps:
 * 1. Create a pointer to a SpriteObject.
 * 2. Check if we have met the capacity of the list, if we have then print a warning and return the temporary sprite.
 * 3. Else, add sprite to queue as well as the index.
 * 4. Return the memory location of the new sprite.
 */
SpriteObject* Scene::createSprite(const char* objectId, const char *textureDir, const sf::Vector2f position, const sf::Vector2f size, const uint8_t objectLayer)
{
    SpriteObject* newSprite = new SpriteObject(objectId, textureDir, position, size, objectLayer);
    if (m_spriteList.size() >= m_spriteList.capacity()) {
        printWarningInfo("Could not add new sprite, size has exceeded capacity.");
        return newSprite;
    }

    m_spriteList.emplace_back(*newSprite);
    m_spriteRenderList.emplace_back(m_spriteList.size() - 1);
    return &m_spriteList.back();
}

SpriteObject* Scene::createSprite(const char* objectId, const sf::Texture &textureFile, sf::Vector2f position, sf::Vector2f size, uint8_t objectLayer)
{
    SpriteObject* newSprite = new SpriteObject(objectId, textureFile, position, size, objectLayer);
    if (m_spriteList.size() >= m_spriteList.capacity()) {
        printWarningInfo("Could not add new sprite, size has exceeded capacity.");
        return newSprite;
    }

    m_spriteList.emplace_back(*newSprite);
    m_spriteRenderList.emplace_back(m_spriteList.size() - 1);
    return &m_spriteList.back();
}

/* Steps:
 * 1. Create a pointer to a new TextObject.
 * 2. Add to the vector.
 * 3. Return the memory location of the TextObject.
 */

TextObject* Scene::createText(const char* objectId, const char* message, const sf::Vector2f position, const char* fontDir, const uint8_t fontSize) {
    m_textList.emplace_back(objectId, message, position, fontDir, fontSize);
    TextObject* textLocation = &m_textList.back();
    return textLocation;
}

TextObject* Scene::createText(const char* objectId, const char* message, const sf::Vector2f position, const sf::Font &fontFile, const uint8_t fontSize) {
    m_textList.emplace_back(objectId, message, position, fontFile, fontSize);
    return &m_textList.back();
}


void Scene::clearLayer(const uint16_t layerNumber)
{
    // TODO: Needs to be completed
}
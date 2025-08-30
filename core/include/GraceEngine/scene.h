#pragma once
#include <GraceEngine/spriteObject.h>
#include <GraceEngine/textObject.h>

class Scene : DebugHandler {
public:
    explicit Scene(const char* sceneName, uint32_t vectorSize);
    ~Scene() = default;

    // SpriteObject
    [[nodiscard]] SpriteObject* createSprite(const char* objectId, const char* textureDir, sf::Vector2f position, sf::Vector2f size, uint8_t objectLayer = 0);
    [[nodiscard]] SpriteObject* createSprite(const char* objectId, const sf::Texture& textureFile, sf::Vector2f position, sf::Vector2f size, uint8_t objectLayer = 0);

    // Render and the renderQueue - SpriteObject
    static void pushToRender(SpriteObject* object) { object->setObjectVisible(true); }
    static void popFromRender(SpriteObject* object) { object->setObjectVisible(false); }


    // TextObject
    [[nodiscard]] TextObject* createText(const char* objectId, const char* message, sf::Vector2f position, const char* fontDir, uint8_t fontSize);
    [[nodiscard]] TextObject* createText(const char* objectId, const char* message, sf::Vector2f position, const sf::Font& fontFile, uint8_t fontSize);
    // Render and the renderQueue - textObject
    static void pushToRender(TextObject* object) { object->setObjectVisible(true); }
    static void popFromRender(TextObject* object) { object->setObjectVisible(false); }

    // Return vectors
    [[nodiscard]] std::vector<SpriteObject>* getSpriteQueue() { return &m_spriteList; }
    [[nodiscard]] std::vector<TextObject>* getTextQueue() { return &m_textList; }
    [[nodiscard]] std::vector<size_t>* getSpriteRenderList() { return &m_spriteRenderList; }

    // Layers
    void clearLayer(uint16_t layerNumber);

private:
    const char* m_sceneName;
    // Vector to hold the sprite objects
    std::vector<SpriteObject> m_spriteList;
    // Vector of indexes of each sprite. This can be sorted so that the correct order of sprites are rendered
    std::vector<size_t> m_spriteRenderList;
    // Vector to hold the text objects
    std::vector<TextObject> m_textList;
};


#include <GraceEngine/renderer.h>

// Renders objects in the scene to the screen
void Renderer::renderScene(sf::RenderWindow& target, const sf::Color backgroundColor, Scene* scene)
{
    target.clear(backgroundColor);

    // Create pointers to each queue
    const std::vector<SpriteObject>* spriteList = scene->getSpriteQueue();
    std::vector<TextObject>* textList = scene->getTextQueue();
    const std::vector<size_t>* spriteRenderList = scene->getSpriteRenderList();

    // Render objects in the m_spriteList based on the order from the spriteRenderList
    for (const size_t objectIndex: (*spriteRenderList))
    {
        (*spriteList)[objectIndex].render(target);
    }

    // Render text from the m_textList in order
    // No sorting for text
    for (TextObject &object : (*textList))
    {
        object.render(target);
    }

    target.display();
}

std::vector<size_t>* Renderer::sortSpriteQueue(std::vector<SpriteObject>* spriteList, std::vector<size_t> *spriteRenderList) {
    // TODO: Only sort the queue if an objects layer has changed (dirty)
    if (!spriteList->empty())
    {
        // Sort the queue from the smallest layer number to the largest
        // Objects with the smallest layer number renders first
        // While the largest layer numbered objects renders last
        std::sort(spriteRenderList->begin(), spriteRenderList->end(),
        [spriteList](const size_t a, const size_t b) {
            return (*spriteList)[a].getLayerNumber() < (*spriteList)[b].getLayerNumber();
        });
    }
    return spriteRenderList;
}

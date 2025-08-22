#pragma once
#include <SFML/Graphics.hpp>
#include <GraceEngine/scene.h>

// Renders objects to the window
class Renderer {
public:
    virtual ~Renderer() = default;
protected:
    // Inherited by the GraceEngine class but not overwritten
    virtual void renderScene(sf::RenderWindow& target, sf::Color backgroundColor, Scene* scene);

    // Sorts the size_t list based on layer numbers
private:
    static std::vector<size_t>* sortSpriteQueue(std::vector<SpriteObject>* spriteList, std::vector<size_t>* spriteRenderList);
};


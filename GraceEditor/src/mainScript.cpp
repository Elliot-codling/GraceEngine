#include "../include/mainScript.h"

// Declare objects here
// SpriteObject* object = new SpriteObject(INFO HERE);

// Runs once, used to set up objects and the window
int runtimeFunctions::start(GraceEngine &window)
{
    window.setVsyncEnabled();
    return 0;
}

// Game loop, runs every frame
int runtimeFunctions::update(GraceEngine &window, const float deltaTime)
{
    window.updateEvents();

    if (window.getEvent(sf::Event::KeyPressed))
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            window.stopRunning();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::F1))
        {
            GraceEngine::printDebugInfo("Hello, World!");
        }
    }
    window.renderObjects();
    return 0;
}

int runtimeFunctions::fixedUpdate(GraceEngine &window, const float deltaTime)
{
    // Add movement and transform code here
    return 0;
}


int runtimeFunctions::end()
{
    return 0;
}
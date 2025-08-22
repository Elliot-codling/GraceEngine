#include "../include/mainScript.h"
#include <GraceEngine/scene.h>

#include "GraceEngine/sceneManager.h"
// Declare objects here
// SpriteObject* object;
float sizeFactor = 0.9f;
Scene* mainScene;
SpriteObject* player;

// Runs once, used to set up objects and the window
int runtimeFunctions::start(GraceEngine &window)
{
    window.setVsyncEnabled();
    //object = window.createSprite(INFO);
    mainScene = sceneManager.createScene("mainScene");
    mainScene->defineName("myScene");
    mainScene->defineVectorSize(2);
    player = mainScene->createSprite("player", "assets/textures/spaceship.png", {0, 0}, {64, 64}, 2);
    mainScene->pushToRender(player);

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
    window.renderScene(mainScene);
    return 0;
}

int runtimeFunctions::fixedUpdate(GraceEngine &window, const float deltaTime)
{
    // Add movement and transform code here
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        player->incrementPosition({-10, 0});
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        player->incrementPosition({10, 0});
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        player->incrementPosition({0, -10});
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        player->incrementPosition({0, 10});
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        player->incrementAngle(-10);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        player->incrementAngle(10);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
        player->setSize(player->getSize() * sizeFactor);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
        player->setSize(player->getSize() * (2 - sizeFactor));
    }

    return 0;
}

int runtimeFunctions::end()
{
    return 0;
}
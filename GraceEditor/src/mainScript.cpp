#include "../include/mainScript.h"

float scaleFactor = 0.9f;
SpriteObject* player;
SpriteObject* player2;
// Declare objects here
// SpriteObject* object;

// Runs once, used to set up objects and the window
int runtimeFunctions::start(GraceEngine &window)
{
    window.setVsyncEnabled();
    //object = window.createSprite(INFO);
    player = window.createSprite("player", "assets/textures/spaceship.png", {0, 0}, {64, 64});
    //player->setDebugActive();
    player->setOrigin({32, 32});
    player->setOffset({32, 32});
    window.pushToRender(player);

    //window.pushToRender(window.createText("text", "Hello World!", {50, 50}, "assets/font/Roboto.ttf", 30));
    //player2 = window.createSprite("player2", "assets/textures/spaceship.png", {0, 0}, {64, 64}, 1);
    //window.pushToRender(player2);
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
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::F2)) {
            window.printDebugInfo(player->isObjectVisible());
        }
    }
    window.renderObjects();
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
        player->setSize({player->getSize().x * scaleFactor, player->getSize().y * scaleFactor});

    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
        player->setSize({player->getSize().x * (2 - scaleFactor), player->getSize().y * (2 - scaleFactor)});

    }


    return 0;
}

int runtimeFunctions::end()
{
    return 0;
}
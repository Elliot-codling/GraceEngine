#include "../include/mainScript.h"

//Declare objects here
//spriteObject* object = new spriteObject(INFO HERE);

//Runs once, used to set up objects and the window
int runtimeFunctions::start(graceEngine &window)
{
    window.setTargetFramerate(60);
    return 0;
}

//Game loop, runs every frame
int runtimeFunctions::update(graceEngine &window)
{   //Update window events and check which keys have been pressed
    window.updateEvents();
    if (window.getEvent(sf::Event::KeyPressed))
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            window.stopRunning();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::F1))
        {
            window.printDebugInfo("Hello, World!");
        }
    }
    window.renderObjects();
    return 0;
}

int runtimeFunctions::fixedUpdate(graceEngine &window, float &deltaTime)
{
    //Add movement and transform code here
    return 0;
}


int runtimeFunctions::end()
{   //Destroy any objects you want here [EXPERIMENTAL]
    return 0;
}
#include "../include/main.h"

int windowWidth = 1280, windowHeight = 720;

//Declare objects here
//spriteObject* object = new spriteObject(INFO HERE);

//Runs once, used to set up objects and the window
graceEngine* runtimeFunctions::start() {
	graceEngine* window = new graceEngine("SFML App", windowWidth, windowHeight);
	window->setTargetFramerate(60);
	return window;
}

//Game loop, runs every frame
int runtimeFunctions::update(graceEngine &window) {
	window.updateEvents();

	if (window.getEvent(sf::Event::KeyPressed)) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			window.stopRunning();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::F1)) {
			window.printDebugInfo("Hello, World!");
		}
	}
	window.renderObjects();
	return 0;
}

int runtimeFunctions::fixedUpdate(float &deltaTime) {
	//Add movement code here
	return 0;
}


int runtimeFunctions::end() {
	return 0;
}
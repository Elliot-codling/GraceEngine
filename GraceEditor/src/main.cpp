#include "../include/main.h"

int windowWidth = 1280, windowHeight = 720;

//Declare objects here
//spriteObject* object = new spriteObject(INFO HERE);

//Runs once, used to set up objects and the window
graceEngine* runtimeFunctions::start() {
	graceEngine* window = new graceEngine("SFML App", windowWidth, windowHeight);

	return window;
}

//Game loop, runs every frame
int runtimeFunctions::logic(graceEngine &window) {
	window.updateEvents();

	if (window.getEvent(sf::Event::KeyPressed)) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			window.stopRunning();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::F1)) {
			window.printDebugInfo("Hello, World!");
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::F2)) {
			int _ = 5/0; //Causes a crash to demonstrate an error message
		}
	}
	window.renderObjects();
	return 0;
}

int runtimeFunctions::end() {
	return 0;
}
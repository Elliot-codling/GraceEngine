#include "../include/main.h"
#include <ctime>
#include <cmath>

int windowWidth = 1280, windowHeight = 720;

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
			throw std::runtime_error("Oh no, I caused a crash!");
		}
	}
	window.renderObjects();
	return 0;
}


int runtimeFunctions::end() {
	return 0;
}
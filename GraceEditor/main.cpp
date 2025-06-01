#include "../GraceEngine//include/graceEngine.h"
#include <iostream>
#include <ctime>
#include <cmath>

int windowWidth = 1280, windowHeight = 720;

int main() {
	graceEngine window("SFML App", windowWidth, windowHeight);

	while (window.isRunning()) {
		window.updateEvents();

		if (window.getEvent(sf::Event::KeyPressed)) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
				window.stopRunning();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::F1)) {
				std::cout << "Hello World!\n";
			}
		}
		window.renderObjects();
	}

	return 0;
}
#include "graceEngine.h"
#include <iostream>
#include <ctime>

using namespace sf;
using namespace std;

int main() {
	graceEngine window("SFML App", 480, 600);
	
	//Make sure the background textures are not overwritten
	Texture texture;
	texture.loadFromFile("textures/background-stars.png");
	srand(time(NULL));
	int rotations[4] = { 0, 90, 180, 270 };
	for (int y = 0; y<11; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			//Rotate the sprites based on a random num generator
			int randomNum = rand() % 4;
			randomNum = rotations[randomNum];

			spriteObject* background = new spriteObject("bgStar", texture, { 64 * x, 64 * y }, {64, 64});
			background->setOrigin({ 32, 32 });
			background->setAngle(randomNum);

			window.pushToQueue(background);
		}
	}
	

	//PlayerShip
	spriteObject* playerShip = new spriteObject("player", "textures/spaceship.png", { 50, 100 }, { 60, 68 });
	window.pushToQueue(playerShip);

	//Scoreboard
	int score = 0;
	textObject* scoreboard = new textObject("score", "Score: " + to_string(score), { 50, 10 }, "font/Roboto.ttf", 30);
	scoreboard->setOrigin({ scoreboard->getSize().x / 2, scoreboard->getSize().y / 2 });
	window.pushToQueue(scoreboard);


	Vector2f playerSize = { 60, 68 };
	
	while (window.isRunning()) {
		window.updateEvents();
		
		if (window.getEvent(Event::KeyPressed)) {
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				window.stopRunning();
			}

			if (Keyboard::isKeyPressed(Keyboard::F))
			{
				window.orderRenderQueue();
			}

			if (Keyboard::isKeyPressed(Keyboard::Up))
			{
				playerSize.x++;
				playerSize.y++;
				playerShip->setSize(playerSize);
			}

			if (Keyboard::isKeyPressed(Keyboard::Down))
			{
				playerSize.x--;
				playerSize.y--;
				playerShip->setSize(playerSize);
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::A))
		{
			playerShip->left(10, 10);
		}

		if (Keyboard::isKeyPressed(Keyboard::D))
		{
			playerShip->right(10, window.getWidth() - playerShip->getSize().x - 10);
		}

		window.renderObjects();
	}

	//Delete all pointers and the renderQueue
	window.~graceEngine();
	return 0;

}
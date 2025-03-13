#include "graceEngine.h"
#include <iostream>
#include <ctime>

# define M_PI           3.14159265358979323846  //Pi

using namespace sf;
using namespace std;


void moveBullets(graceEngine& target)
{
	auto renderQueue = target.getSpriteQueue();
	for (auto& object: renderQueue)
	{
		if (object->getId() == "bullet")
		{
			object->incrementPosition(object->getVelocity());
			if (target.getRelativePosition(object).x >= target.getWidth() || target.getRelativePosition(object).x + object->getSize().x <= 0)
			{
				target.popFromQueue(object);
			}
		}
	}
}


void playerMovement(spriteObject* player, graceEngine& window)
{
	
	if (!player->leftBorder(window.getRelativePosition(player),0) && Keyboard::isKeyPressed(Keyboard::A))
	{
		player->incrementPosition({-player->getVelocity().x, 0});
	}
	

	if (!player->rightBorder(window.getRelativePosition(player), window.getWidth() - player->getSize().x) && Keyboard::isKeyPressed(Keyboard::D))
	{
		player->incrementPosition({ player->getVelocity().x, 0 });
	}

	if (!player->topBorder(window.getRelativePosition(player), 0) && Keyboard::isKeyPressed(Keyboard::W))
	{
		player->incrementPosition({ 0, -player->getVelocity().y });
	}

	if (!player->bottomBorder(window.getRelativePosition(player), window.getHeight() - player->getSize().y) && Keyboard::isKeyPressed(Keyboard::S))
	{
		player->incrementPosition({ 0, player->getVelocity().y });
	}
	
}


int main() {
	graceEngine window("SFML App", 480, 600, {0, 0, 192});

	//Make sure the background textures are not overwritten
	/*
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
			background->setOrigin({ 32, 32 }, {32, 32});
			background->setAngle(randomNum);

			window.pushToQueue(background);
		}
	}
	*/

	spriteObject* background = new spriteObject("bg", "textures/ground.png", { 0, 0 }, { 3648, 3200 }, 10);
	window.pushToQueue(background);
	
	//PlayerShip
	spriteObject* playerShip = new spriteObject("player", "textures/spaceship.png", { (window.getWidth() / 2) - 30, (window.getHeight() / 2) - 34 }, { 60, 68 }, 5);
	playerShip->setOrigin({ 30, 34 }, { 30, 34 });
	playerShip->setVelocity({ 10, 10 });
	window.pushToQueue(playerShip);

	//Scoreboard
	int score = 0;
	textObject* scoreboard = new textObject("score", "Score: " + to_string(score), { 50, 10 }, "font/Roboto.ttf", 30);
	scoreboard->setOrigin({ scoreboard->getSize().x / 2, scoreboard->getSize().y / 2 });
	window.setRelativePosition(scoreboard, { 60, 10 });
	window.pushToQueue(scoreboard);
	
	float zoom = 1.f;
	Vector2f cameraSize = { 480, 600 };

	

	while (window.isRunning()) {
		window.updateEvents();
		
		if (window.getEvent(Event::KeyPressed)) {
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				window.stopRunning();
			}

			if (Keyboard::isKeyPressed(Keyboard::Space))
			{
				Vector2i position = { int(playerShip->getPosition().x) + 30 - 10, int(playerShip->getPosition().y) + 34 - 10 };
				spriteObject* bulletObject = new spriteObject("bullet", "textures/bullet.png", position, { 40, 13 }, 1);
				float radians = playerShip->getAngle() * M_PI / 180.f;


				bulletObject->setVelocity({ float(sin(radians)), -float(cos(radians))});
				bulletObject->setAngle(playerShip->getAngle() - 90.f);
				window.pushToQueue(bulletObject);
			}

			if (Keyboard::isKeyPressed(Keyboard::F))
			{
				window.printQueue();
			}
		}

		

		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			window.incrementCamera({ 0, -10 });
			window.setRelativePosition(scoreboard, { 60, 10 });
			if (playerShip->bottomBorder(window.getRelativePosition(playerShip), window.getHeight() - playerShip->getSize().y))
			{
				playerShip->incrementPosition({ 0, -10 });
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			window.incrementCamera({ 0, 10 });
			window.setRelativePosition(scoreboard, { 60, 10 });
			if (playerShip->topBorder(window.getRelativePosition(playerShip), 0))
			{
				playerShip->incrementPosition({ 0, 10 });
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			window.incrementCamera({ -10, 0 });
			window.setRelativePosition(scoreboard, { 60, 10 });
			if (playerShip->rightBorder(window.getRelativePosition(playerShip), window.getWidth() - playerShip->getSize().x))
			{
				playerShip->incrementPosition({ -10, 0 });
			}
			
		}

		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			window.incrementCamera({ 10, 0 });
			window.setRelativePosition(scoreboard, { 60, 10 });
			if (playerShip->leftBorder(window.getRelativePosition(playerShip), 0))
			{
				playerShip->incrementPosition({ 10, 0 });
			}
		}

		playerMovement(playerShip, window);

		moveBullets(window);

		window.renderObjects();
	}
	return 0;

}
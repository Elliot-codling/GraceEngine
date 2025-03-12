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
			background->setOrigin({ 32, 32 }, {32, 32});
			background->setAngle(randomNum);

			window.pushToQueue(background);
		}
	}
	
	//PlayerShip
	spriteObject* playerShip = new spriteObject("player", "textures/spaceship.png", { (window.getWidth() / 2) - 30, (window.getHeight() / 2) - 34 }, { 60, 68 });
	playerShip->setOrigin({ 30, 34 }, { 30, 34 });
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

			if (Keyboard::isKeyPressed(Keyboard::Left))
			{
				playerShip->incrementAngle(-10.f);
			}

			if (Keyboard::isKeyPressed(Keyboard::Right))
			{
				playerShip->incrementAngle(10.f);
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
		}

		if (Keyboard::isKeyPressed(Keyboard::A))
		{
			window.incrementCamera({ -1.f, 0.f });
			//playerShip->incrementPosition({ -1.f, 0.f });
		}

		if (Keyboard::isKeyPressed(Keyboard::D))
		{
			window.incrementCamera({ 1.f, 0.f });
			//playerShip->incrementPosition({ 1.f, 0.f });
		}

		moveBullets(window);

		window.renderObjects();
	}

	//Delete all pointers and the renderQueue
	window.~graceEngine();
	return 0;

}
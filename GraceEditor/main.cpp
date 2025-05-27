#include "../GraceEngine//include/graceEngine.h"
#include <iostream>
#include <ctime>
#include <cmath>

# define PI           3.14159265358979323846  //Pi

using namespace sf;
using namespace std;

float zoom;
float windowWidth = 1280, windowHeight = 720;
Vector2f cameraSize = { windowWidth, windowHeight };
Vector2f wirePos = { 0, 0 };
float guiSize = 30;

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
			if (target.getRelativePosition(object).y >= target.getHeight() || target.getRelativePosition(object).y + object->getSize().y <= 0)
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


	//Correct the coords if gone over the border
	if (player->leftBorder(window.getRelativePosition(player), 0))
	{
		//window.setRelativePosition(player, { 0, float(window.getRelativePosition(player).y) });
		window.setRelativePosition(player, { 0, float(window.getRelativePosition(player).y)});
	}

	if (player->topBorder(window.getRelativePosition(player), 0))
	{
		window.setRelativePosition(player, { float(window.getRelativePosition(player).x), 0});
	}


	if (player->rightBorder(window.getRelativePosition(player), window.getWidth() - player->getSize().x))
	{
		window.setRelativePosition(player, { window.getWidth() - player->getSize().x, float(window.getRelativePosition(player).y) });
	}

	if (player->bottomBorder(window.getRelativePosition(player), window.getHeight() - player->getSize().y))
	{
		window.setRelativePosition(player, { float(window.getRelativePosition(player).x), window.getHeight() - player->getSize().y });
	}

	//cout << "X: " << player->getPosition().x << " Y: " << player->getPosition().y << "\n";
}

void cameraMovement(graceEngine& window, textObject* scoreboard, spriteObject* bg, spriteObject* wire, spriteObject* playerShip)
{
	if (Keyboard::isKeyPressed(Keyboard::E))
	{
		zoom = 1.1f;
		if (cameraSize.x > 7680)
		{
			return;
		}
		cameraSize.x *= zoom;
		cameraSize.y *= zoom;

		window.setCameraSize(cameraSize);
		scoreboard->setFontSize((cameraSize.x / window.getWidth() * guiSize));
		window.setRelativePosition(scoreboard, { 0, 0 });

		//Background
		bg->setSize(cameraSize);
		bg->setSpriteRectPos({ (float(window.getWidth()) - cameraSize.x) / 2.f, (window.getHeight() - cameraSize.y) / 2.f });
		window.setRelativePosition(bg, { 0, 0 });

		wire->setSize(cameraSize);
		wire->setSpriteRectPos({ (float(window.getWidth()) - cameraSize.x) / 2.f, (window.getHeight() - cameraSize.y) / 2.f });
		window.setRelativePosition(wire, { 0, 0 });
	}

	if (Keyboard::isKeyPressed(Keyboard::Q))
	{
		zoom = 0.9f;
		//Cannot be smaller than that size
		if (cameraSize.x < windowWidth)
		{
			return;
		}
		cameraSize.x *= zoom;
		cameraSize.y *= zoom;

		window.setCameraSize(cameraSize);
		scoreboard->setFontSize((cameraSize.x / window.getWidth()) * guiSize);
		window.setRelativePosition(scoreboard, { 0, 0 });

		bg->setSize(cameraSize);
		bg->setSpriteRectPos({ (float(window.getWidth()) - cameraSize.x) / 2.f, (window.getHeight() - cameraSize.y) / 2.f });
		window.setRelativePosition(bg, { 0, 0 });

		wire->setSize(cameraSize);
		wire->setSpriteRectPos({ (float(window.getWidth()) - cameraSize.x) / 2.f, (window.getHeight() - cameraSize.y) / 2.f });
		window.setRelativePosition(wire, { 0, 0 });
	}

	if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		window.incrementCamera({ 0, -10 });
		window.setRelativePosition(scoreboard, { 0, 0 });
		if (playerShip->bottomBorder(window.getRelativePosition(playerShip), window.getHeight() - playerShip->getSize().y))
		{
			playerShip->incrementPosition({ 0, -10 });
		}
		window.setRelativePosition(bg, { 0, 0 });
		bg->setSpriteRectPos(window.getCameraPos());

		wirePos.y -= 15;
		window.setRelativePosition(wire,{0, 0});
		wire->setSpriteRectPos(wirePos);
	}

	if (Keyboard::isKeyPressed(Keyboard::Down))
	{
		window.incrementCamera({ 0, 10 });
		window.setRelativePosition(scoreboard, { 0, 0 });
		if (playerShip->topBorder(window.getRelativePosition(playerShip), 0))
		{
			playerShip->incrementPosition({ 0, 10 });
		}
		window.setRelativePosition(bg, { 0, 0 });
		bg->setSpriteRectPos(window.getCameraPos());

		wirePos.y += 15;
		window.setRelativePosition(wire, { 0, 0 });
		wire->setSpriteRectPos(wirePos);
	}

	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		window.incrementCamera({ -10, 0 });
		window.setRelativePosition(scoreboard, { 0, 0 });
		if (playerShip->rightBorder(window.getRelativePosition(playerShip), window.getWidth() - playerShip->getSize().x))
		{
			playerShip->incrementPosition({ -10, 0 });
		}
		window.setRelativePosition(bg, { 0, 0 });
		bg->setSpriteRectPos(window.getCameraPos());

		wirePos.x -= 15;
		window.setRelativePosition(wire, { 0, 0 });
		wire->setSpriteRectPos(wirePos);
	}

	if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		window.incrementCamera({ 10, 0 });
		window.setRelativePosition(scoreboard, { 0, 0 });
		if (playerShip->leftBorder(window.getRelativePosition(playerShip), 0))
		{
			playerShip->incrementPosition({ 10, 0 });
		}
		window.setRelativePosition(bg, { 0, 0 });
		bg->setSpriteRectPos(window.getCameraPos());

		wirePos.x += 15;
		window.setRelativePosition(wire, { 0, 0 });
		wire->setSpriteRectPos(wirePos);
	}
}


int main() {
	graceEngine window("SFML App", windowWidth, windowHeight, {0, 0, 192});

	Texture textureBg;
	textureBg.loadFromFile("assets/textures/dirt.png");
	textureBg.setRepeated(true);

	spriteObject* bg = new spriteObject("bg", textureBg, { 0, 0 }, { windowWidth, windowHeight }, 0);
	//window.pushToQueue(bg);

	Texture textureWire;
	textureWire.loadFromFile("assets/textures/wire.png");
	textureWire.setRepeated(true);

	spriteObject* wire = new spriteObject("wire", textureWire, { 0, 0 }, { windowWidth, windowHeight }, 1);
	window.pushToQueue(wire);


	//PlayerShip
	spriteObject* playerShip = new spriteObject("player", "assets/textures/spaceship.png", { (window.getWidth() / 2.f) - 30, (window.getHeight() / 2.f) - 34 }, { 60, 68 }, 2);
	playerShip->setOrigin({ 30, 34 });
	playerShip->setOffset({ 30, 34 });

	playerShip->setVelocity({ 10, 10 });
	window.pushToQueue(playerShip);

	//Scoreboard
	int score = 0;
	textObject* scoreboard = new textObject("score", "Score: " + to_string(score), { 0, 0 }, "assets/font/Roboto.ttf", 30, 3);
	//scoreboard->setOrigin({ scoreboard->getSize().x / 2, scoreboard->getSize().y / 2 }, { scoreboard->getSize().x / 2, scoreboard->getSize().y / 2 });
	window.pushToQueue(scoreboard);

	debugHandler handler;
	debugShape playerDebugShape(playerShip);
	handler.pushToDebugQueue(playerDebugShape);


	while (window.isRunning()) {
		window.updateEvents();

		if (window.getEvent(Event::KeyPressed)) {
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				window.stopRunning();
			}

			if (Keyboard::isKeyPressed(Keyboard::Space))
			{
				Vector2f position = { playerShip->getPosition().x + 30 - 10, playerShip->getPosition().y + 34 - 10 };
				spriteObject* bulletObject = new spriteObject("bullet", "textures/bullet.png", position, { 40, 13 }, 1);
				float radians = playerShip->getAngle() * PI / 180.f;


				bulletObject->setVelocity({ float(sin(radians)), -float(cos(radians))});
				bulletObject->setAngle(playerShip->getAngle() - 90.f);
				window.pushToQueue(bulletObject);
			}

			if (Keyboard::isKeyPressed(Keyboard::F))
			{
				window.popFromQueue(wire);
			}
		}
		playerMovement(playerShip, window);
		cameraMovement(window, scoreboard, bg, wire, playerShip);
		moveBullets(window);

		playerDebugShape.setShapePosition(playerShip->getPosition());

		window.renderObjects(handler.getDebugQueue());
	}
	return 0;

}
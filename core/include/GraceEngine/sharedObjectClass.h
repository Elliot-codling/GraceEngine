#pragma once
#include <SFML/Graphics.hpp>
//Sprite and Text objects will share some functions
//This class will be inherited between them
//Nodiscard -> warn users if a get function is called but not used in program
class SharedData
{
public:
	virtual ~SharedData() = default;

	//Get functions
	[[nodiscard]] const char* getId() const { return m_id; }
	[[nodiscard]] uint8_t getLayer() const { return m_layer; }
	[[nodiscard]] sf::Vector2f getVelocity() const { return m_velocity; }
	[[nodiscard]] sf::Vector2f getOffset() const { return m_offset; }

	//Set functions
	void setId(const char* objectID) { m_id = objectID; }
	void setLayer(const uint8_t objectLayer) { m_layer = objectLayer; }
	void setVelocity(const sf::Vector2f objectVelocity) { m_velocity = objectVelocity; }
	virtual void setOffset(const sf::Vector2f objectOffset) { m_offset = objectOffset; }

	[[nodiscard]] bool isInitialised() const { return m_initialised; }

protected:
	void initialiseObject() { m_initialised = true; }
	void destroyObject() { m_initialised = false; }

private:
	//Inherited variables
	uint8_t m_layer = 0;
	const char* m_id = new char;
	sf::Vector2f m_velocity;
	sf::Vector2f m_offset;
	bool m_initialised = false;

};
#pragma once
#include <SFML/Graphics.hpp>
// Sprite and Text objects will share some functions
// This class will be inherited between them
// Nodiscard -> warn users if a get function is called but not used in program
class SharedData
{
public:
	virtual ~SharedData() = default;

	// Get functions
	[[nodiscard]] const char* getId() const { return m_id; }
	[[nodiscard]] uint8_t getLayer() const { return m_layer; }
	[[nodiscard]] sf::Vector2f getOffset() const { return m_offset; }
	[[nodiscard]] bool isObjectVisible() const { return m_objectVisible; }

	// Set functions
	void setId(const char* objectID) { m_id = objectID; }
	void setLayer(const uint8_t objectLayer) { m_layer = objectLayer; }
	void setObjectVisible(bool isVisible) { m_objectVisible = isVisible; }
	virtual void setOffset(const sf::Vector2f objectOffset) { m_offset = objectOffset; }

	[[nodiscard]] bool isInitialised() const { return m_initialised; }

protected:
	void initialiseObject() { m_initialised = true; }
	void destroyObject() { m_initialised = false; }

private:
	// Inherited variables
	uint8_t m_layer = 0;
	const char* m_id = new char;
	sf::Vector2f m_offset;

	// Is the object initisaled
	bool m_initialised = false;
	// Determines if the object is going to rendered to the screen
	bool m_objectVisible = false;

};
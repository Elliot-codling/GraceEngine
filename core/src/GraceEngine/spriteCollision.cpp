#include <GraceEngine/spriteObject.h>

// This file is used to calculate the collision between the current object and the targeted object

// Return an object ID if the selected sprite has collided with the object
std::string SpriteObject::collisionBox(const SpriteObject* object) const
{
    if (!(getPosition().x <= object->getPosition().x + object->getSize().x))
    {
        return "";
    }
    if (!(getPosition().x + getSize().x >= object->getPosition().x))
    {
        return "";
    }
    if (!(getPosition().y <= object->getPosition().y + object->getSize().y))
    {
        return "";
    }
    if (!(getPosition().y + getSize().y >= object->getPosition().y))
    {
        return "";
    }

    return object->getId();
}
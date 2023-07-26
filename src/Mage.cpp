#include "Mage.h"
#include "King.h"
#include "Controller.h"

sf::Vector2f& Mage::setObjectDirection() //set Mage  direction
{
	return this->setDirection();
}

// handlleCollission with the objects
void Mage::handlleCollission(Objects& obj) 
{
	obj.handlleCollission(*this);
}
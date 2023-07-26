#include "Warrior.h"
#include "King.h"
#include "Controller.h"

sf::Vector2f& Warrior::setObjectDirection() 
{
	return this->setDirection();
}

void Warrior::handlleCollission(Objects& obj) 
{
	obj.handlleCollission(*this);
}

#include "Dwarf.h"
#include "King.h"
#include "Controller.h"


sf::Vector2f& Dwarf::setDirection() //set Dwarf  direction
{
	float deltaTime = Controller::getDeltaTime(); 
	srand(time(NULL));
	int randNum = rand() % 4;

	sf::Vector2f direction(0.0f, 0.0f);

	switch (randNum)
	{
		case 0: direction.x = 40 * deltaTime; break;
		case 1: direction.x = -40 * deltaTime; break;
		case 2: direction.y = 40 * deltaTime; break;
		case 3: direction.y = -40 * deltaTime; break;
	}		

	return direction;
}

// handlleCollission with the objects
void Dwarf::handlleCollission(Objects& obj) 
{
	obj.handlleCollission(*this);
}

void Dwarf::handlleCollission(King& obj) 
{
	this->setWrongMoveBool(true);
}

void Dwarf::handlleCollission(Warrior& obj) 
{
	this->setWrongMoveBool(true);
}

void Dwarf::handlleCollission(Mage& obj) 
{
	this->setWrongMoveBool(true);
}

void Dwarf::handlleCollission(Theif& obj)
{
	this->setWrongMoveBool(true);
}

void Dwarf::handlleCollission(Wall& obj)
{
	this->setWrongMoveBool(true);
}


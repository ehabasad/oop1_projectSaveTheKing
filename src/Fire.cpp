#include "Fire.h"
#include "King.h"
#include "Controller.h"

// handlleCollission with the objects

void Fire::handlleCollission(Objects& obj)
{
	obj.handlleCollission(*this);
}

void Fire::handlleCollission(King& obj)
{
	this->setStay(false);
	obj.removalLife(15);
}

void Fire::handlleCollission(Mage& obj)
{
	this->setStay(false);
}

void Fire::handlleCollission(Warrior& obj)
{
	obj.setWrongMoveBool(true);
}

void Fire::handlleCollission(Theif& obj)
{
	obj.setWrongMoveBool(true);
}

void Fire::handlleCollission(Dwarf& obj)
{
	obj.setWrongMoveBool(true);
}



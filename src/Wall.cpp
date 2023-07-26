#include "Wall.h"
#include "King.h"
#include "Controller.h"

void Wall::handlleCollission(Objects& obj) 
{
	obj.handlleCollission(*this);
}

void Wall::handlleCollission(King& obj)
{
	obj.setWrongMoveBool(true);
}

void Wall::handlleCollission(Warrior& obj)
{
	obj.setWrongMoveBool(true);
}

void Wall::handlleCollission(Mage& obj)
{
	obj.setWrongMoveBool(true);
}

void Wall::handlleCollission(Theif& obj)
{
	obj.setWrongMoveBool(true);
}

void Wall::handlleCollission(Dwarf& obj)
{
	obj.setWrongMoveBool(true);
}

#include "Orc.h"
#include "King.h"
#include "Key.h"
#include "Controller.h"
#include "Objects.h"

void Orc::handlleCollission(Objects& obj)
{
	obj.handlleCollission(*this);
}

void Orc::handlleCollission(King& obj) 
{
	obj.setWrongMoveBool(true);
}

void Orc::handlleCollission(Warrior& obj)
{
	this->setStay(false);
}

void Orc::handlleCollission(Mage& obj)
{
	obj.setWrongMoveBool(true);
}

void Orc::handlleCollission(Theif& obj)
{
	obj.setWrongMoveBool(true);
}

void Orc::handlleCollission(Dwarf& obj)
{
	obj.setWrongMoveBool(true);
}

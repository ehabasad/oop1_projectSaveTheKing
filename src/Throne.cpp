#include "Throne.h"
#include "King.h"
#include "Mage.h"
#include "Warrior.h"
#include "Theif.h"


void Throne::handlleCollission(Objects& obj)
{
	obj.handlleCollission(*this);
}

void Throne::handlleCollission(King& obj) 
{
	obj.winKing(1);
	this->setStay(false);
}

void Throne::handlleCollission(Mage& obj)
{
	obj.setWrongMoveBool(true);
}

void Throne::handlleCollission(Theif& obj)
{
	obj.setWrongMoveBool(true);
}

void Throne::handlleCollission(Warrior& obj)
{
	obj.setWrongMoveBool(true);
}

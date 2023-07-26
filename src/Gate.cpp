#include "Gate.h"
#include "King.h"
#include "Controller.h"

// handlleCollission with the objects

void Gate::handlleCollission(Objects& obj) 
{
	obj.handlleCollission(*this);
}

void Gate::handlleCollission(King& obj)
{
	obj.setWrongMoveBool(true);
}

void Gate::handlleCollission(Warrior& obj)
{
	obj.setWrongMoveBool(true);
}

void Gate::handlleCollission(Mage& obj)
{
	obj.setWrongMoveBool(true);
}

void Gate::handlleCollission(Theif& obj)
{
	if (obj.getKey() > 0) {
		obj.numKey(-1);
		this->setStay(false);
	}
	else{
		obj.setWrongMoveBool(true);
	}
}

void Gate::handlleCollission(Dwarf& obj)
{
	obj.setWrongMoveBool(true);
}


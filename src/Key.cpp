#include "Key.h"
#include "King.h"
#include "Mage.h"
#include "Theif.h"


// handlleCollission with the objects

void Key::handlleCollission(Objects& obj)
{
	obj.handlleCollission(*this);
}

void Key::handlleCollission(Theif& obj)
{
	obj.numKey(1);
	this->setStay(false);
}


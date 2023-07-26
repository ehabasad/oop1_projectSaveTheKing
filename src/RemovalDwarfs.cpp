#include "RemovalDwarfs.h"
#include "King.h"

void RemovalDwarfs::handlleCollission(Objects& obj)
{
	obj.handlleCollission(*this);
}

void RemovalDwarfs::handlleCollission(King& obj)
{
	this->setStay(false);
}
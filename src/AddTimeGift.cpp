#include "AddTimeGift.h"
#include "King.h"

void AddTimeGift::handlleCollission(Objects& obj)
{
	obj.handlleCollission(*this);
}

void AddTimeGift::handlleCollission(King& obj) 
{
	obj.setTime(10);
	this->setStay(false);
}


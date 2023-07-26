#include "ReduceTimeGift.h"
#include "King.h"

void ReduceTimeGift::handlleCollission(Objects& obj)
{
	obj.handlleCollission(*this);
}

void ReduceTimeGift::handlleCollission(King& obj) 
{
	obj.setTime(-10);
	this->setStay(false);
}
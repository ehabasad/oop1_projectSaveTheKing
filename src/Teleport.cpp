#include "Teleport.h"
#include "King.h"
#include "Controller.h"


void Teleport::handlleCollission(Objects& obj)
{
	obj.handlleCollission(*this);
}

void Teleport::handlleCollission(King& obj) 
{
	obj.setCurrPos(this->getNextPos());
}

void Teleport::handlleCollission(Warrior& obj) 
{
	obj.setCurrPos(this->getNextPos());
}

void Teleport::handlleCollission(Theif& obj)
{
	obj.setCurrPos(this->getNextPos());
}

sf::Vector2f& Teleport::getNextPos() 
{
	return m_nextPos;
}

void Teleport::setNextPos(sf::Vector2f& postion)
{
	m_nextPos = postion;
}
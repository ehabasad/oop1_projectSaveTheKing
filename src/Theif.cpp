#include "Theif.h"
#include "King.h"
#include "Controller.h"


int Theif::m_key = 0;

sf::Vector2f& Theif::setObjectDirection() //set monster advancing direction
{
	return this->setDirection();
}

void Theif::handlleCollission(Objects& obj)
{
	obj.handlleCollission(*this);
}

int Theif::getKey() const
{
	return m_key;
}

void Theif::numKey(int key)
{
	m_key += key;
}

void Theif::setKeyStart()
{
	m_key = 0;
}


#include "King.h"
#include "Fire.h"
#include "AddTimeGift.h"
#include "RemovalDwarfs.h"
#include "ReduceTimeGift.h"
#include "Key.h"
#include "Warrior.h"
#include "Mage.h"
#include "Theif.h"
#include "Controller.h"
#include "Board.h"

sf::Vector2f King::m_myPos;

sf::Vector2f& King::setObjectDirection() //set King  direction
{
	return this->setDirection();
}

// handlleCollission with the objects

void King::handlleCollission(Objects& obj)
{
	obj.handlleCollission(*this);
}

void King::handlleCollission(Warrior& obj)
{
	m_life--;
	Controller::kingCollision();
}

void King::handlleCollission(Dwarf& obj)
{
	m_life--;
	Controller::kingCollision();
}

void King::handlleCollission(Throne& obj)
{
	m_throne += 1;
	obj.setStay(false);
}

void King::removalLife(int life)
{
	m_life--;
	Controller::kingCollision();
}

int King::getLevel() const
{
	return m_level;
}

void King::setGameLevel(int level)
{
	m_level += level;
}

int King::getLife() const
{
	return m_life;
}

void King::setStartLife()
{
	m_life = 4;
}
int King::getTime() const
{
	return m_time;
}

int King::getThrone() const
{
	return m_throne;
}

void King::winKing(int throne)
{
	m_throne += throne;
}

void King::setTime(int time)
{
	m_time += time;
}

void King::setGameTimeStart()
{
	m_time = 0;
}

void King::setThroneStart()
{
	m_throne = 0;
}

void King::setlevelStart()
{
	m_level = 0;
}

void King::setLife(int life)
{
	m_life += life;
}

sf::Vector2f King::kingPosFun()
{
	return m_myPos;
}

void King::setStaticKingPos(sf::Vector2f& a)
{
	m_myPos.x = a.x;
	m_myPos.y = a.y;
}

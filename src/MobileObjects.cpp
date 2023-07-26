#include "MobileObjects.h"
#include "Board.h"
#include "King.h"
#include "Controller.h"

MobileObjects::MobileObjects(sf::Vector2f postion, char character, sf::Texture tex) 
	: Objects(postion, character)
{
	m_tex = tex;
	m_currPos = Objects::getStartPos();
	m_rec.setPosition(postion.x, postion.y);
	m_rec.setOutlineColor(sf::Color::Transparent);
	m_rec.setOutlineThickness(1);
	m_rec.setTexture(&m_tex);

	m_sprite.setTexture(m_tex);
}

sf::Vector2f& MobileObjects::getCurrPos()
{
	return m_currPos;
}

void MobileObjects::setCurrPos(sf::Vector2f& postion)
{
	m_currPos = postion;
}

sf::Vector2f& MobileObjects::setDirection() //set object advance direction
{
	float deltaTime = Controller::getDeltaTime();
	sf::Vector2f vec(0.0f, 0.0f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		vec.y = deltaTime * (-200);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		vec.y = deltaTime * (200);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		vec.x = deltaTime * (200);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		vec.x = deltaTime * (-200);

	return vec;
}


void MobileObjects::setTex(sf::Texture tex)
{
	m_tex = tex;
	m_rec.setTexture(&m_tex);
}

void MobileObjects::setRec(sf::Vector2f postion) //set rectangle position
{
	m_rec.setPosition(postion.x, postion.y);
}

sf::RectangleShape& MobileObjects::getRec()
{
	return m_rec;
}

void MobileObjects::moveObj()
{
	m_direction = setDirection();

	if (inBounds(m_direction))
		MoveObjectsByDirection();
}

bool MobileObjects::inBounds(sf::Vector2f& direction) //is next step in bounds
{
	if (this->getRec().getGlobalBounds().top + direction.y < 0 ||
		this->getRec().getGlobalBounds().left + direction.x < 0 ||
		this->getRec().getPosition().y + 70 + direction.y > 800 ||
		this->getRec().getPosition().x + 70 + direction.x > 1200)
		return false;

	return true;
}

void MobileObjects::MoveObjectsByDirection() //move mobile objects
{
	this->getRec().move(m_direction);
	sf::Vector2f temp = this->getRec().getPosition();
	this->setCurrPos(temp);

	if (this->getChar() == 'K') //if its King
		King::setStaticKingPos(temp);
}

void MobileObjects::itsWrongMove() //make move not possible
{
	this->setWrongMoveBool(false);

	sf::Vector2f temp(this->getCurrPos());

	if (m_direction.x == 0) //the last move is or up or down
	{
		if (m_direction.y > 0)
			temp.y -= 20;
		else
			temp.y += 20;
	}
	else //the last move is or right or left
	{
		if (m_direction.x > 0)
			temp.x -= 20;
		else
			temp.x += 20;
	}

	this->getRec().setPosition(temp);
	this->setCurrPos(temp);

	if (this->getChar() == 'K') //if its King
		King::setStaticKingPos(temp);
}

sf::Vector2f& MobileObjects::getDirection()
{
	return m_direction;
}

void MobileObjects::setWrongMoveBool(bool temp)
{
	m_wrongMove = temp;
}

bool MobileObjects::getBool() const
{
	return m_wrongMove;
}

void MobileObjects::setRecSize(sf::Vector2f size)
{
	m_rec.setSize(sf::Vector2f(size.x, size.y));
}

int MobileObjects::getTime() const
{
	return m_time;
}
void MobileObjects::setTime(int time)
{
	m_time += time;
}

void MobileObjects::reduceTime(int time)
{
	m_time -= time;
}

void MobileObjects::setGameTimeStart()
{
	m_time = 0;
}

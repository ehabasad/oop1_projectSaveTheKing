#include "Objects.h"

Objects::Objects(sf::Vector2f postion, char character = NULL) : m_char(character), m_startPostion(postion)
{
}

sf::Vector2f& Objects::getStartPos()
{
	return m_startPostion;
}

void Objects::setStartPos(sf::Vector2f& postion)
{
	m_startPostion = postion;
}

char Objects::getChar() const
{
	return m_char;
}

void Objects::setChar(char a)
{
	m_char = a;
}


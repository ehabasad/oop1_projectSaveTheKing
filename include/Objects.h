#pragma once
#include <SFML/Graphics.hpp>

//forward declaration of all objects in project
class MobileObjects;
class King;
class Mage;
class Warrior;
class StaticObjects;
class Gift;
class Fire;
class Key;
class Wall;
class Theif;
class Throne;
class RemovalDwarfs;
class AddTimeGift;
class ReduceTimeGift;
class Gate;
class Teleport;
class Dwarf;
class Board;
class Orc;

class Objects
{
public:
	Objects() {}
	Objects(sf::Vector2f, char); //constructor
	~Objects() = default;

	sf::Vector2f& getStartPos();
	void setStartPos(sf::Vector2f&);
	char getChar() const;
	void setChar(char);

	virtual void handlleCollission(Objects&) = 0;
	virtual void handlleCollission(Dwarf&) = 0;
	virtual void handlleCollission(King&) = 0;
	virtual void handlleCollission(Warrior&) = 0;
	virtual void handlleCollission(Mage&) = 0;
	virtual void handlleCollission(Fire&) = 0;
	virtual void handlleCollission(Key&) = 0;
	virtual void handlleCollission(Throne&) = 0;
	virtual void handlleCollission(Theif&) = 0;
	virtual void handlleCollission(Wall&) = 0;
	virtual void handlleCollission(Gate&) = 0;
	virtual void handlleCollission(Orc&) = 0;
	virtual void handlleCollission(Teleport&) = 0;
	virtual void handlleCollission(AddTimeGift&) = 0;
	virtual void handlleCollission(RemovalDwarfs&) = 0;
	virtual void handlleCollission(ReduceTimeGift&) = 0;

private:
	sf::Vector2f m_startPostion;
	char m_char;
};
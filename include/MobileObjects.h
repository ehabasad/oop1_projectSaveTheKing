#pragma once
#include "Objects.h"
#include <SFML/Graphics.hpp>

class MobileObjects : public Objects
{
public:
	MobileObjects() {}
	MobileObjects(sf::Vector2f, char, sf::Texture); //constructor

	~MobileObjects() = default;
	
	sf::Vector2f& getCurrPos();
	sf::RectangleShape& getRec();
	sf::Vector2f& getDirection();
	void setRec(sf::Vector2f);
	void setCurrPos(sf::Vector2f&);
	void setTex(sf::Texture);
	void setRecSize(sf::Vector2f);
	int getTime() const;
	void setTime(int time);
	void reduceTime(int time);
	void setGameTimeStart();
	bool getBool() const;
	void moveObj();
	void itsWrongMove();
	void setWrongMoveBool(bool);
	void MoveObjectsByDirection();

	virtual sf::Vector2f& setDirection() ;
	virtual bool inBounds(sf::Vector2f&);

	virtual void handlleCollission(Teleport&) = 0;
	virtual void handlleCollission(Objects&) = 0;
	virtual void handlleCollission(King&) = 0;
	virtual void handlleCollission(Warrior&) = 0;
	virtual void handlleCollission(Mage&) = 0;
	virtual void handlleCollission(Fire&) = 0;
	virtual void handlleCollission(Gate&) = 0;
	virtual void handlleCollission(Key&) = 0;
	virtual void handlleCollission(Dwarf&) = 0;
	virtual void handlleCollission(Orc&) = 0;
	virtual void handlleCollission(Theif&) = 0;
	virtual void handlleCollission(Throne&) = 0;
	virtual void handlleCollission(Wall&) = 0;
	virtual void handlleCollission(AddTimeGift&) = 0;
	virtual void handlleCollission(RemovalDwarfs&) = 0;
	virtual void handlleCollission(ReduceTimeGift&) = 0;

private:
	bool m_wrongMove = false;

	bool m_found ;
	int m_time = 0;

	sf::Texture m_tex;
	sf::Sprite m_sprite;
	sf::Vector2f m_currPos;
	sf::RectangleShape m_rec;
	sf::Vector2f m_direction;
};
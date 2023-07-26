
#pragma once
#include "StaticObjects.h"

class Teleport : public StaticObjects
{
public:
	using StaticObjects::StaticObjects; //using StaticObjects constructor
	~Teleport() = default;

	virtual void handlleCollission(Objects& obj) override;
	virtual void handlleCollission(King& obj) override;
	virtual void handlleCollission(Warrior& obj) override;
	virtual void handlleCollission(Theif& obj) override;

	virtual void handlleCollission(Mage& obj) override {}
	virtual void handlleCollission(Orc& obj) override {}
	virtual void handlleCollission(Dwarf& obj) override {}
	virtual void handlleCollission(Teleport& obj) override {}
	virtual void handlleCollission(Wall& obj) override {}
	virtual void handlleCollission(Fire& obj) override {}
	virtual void handlleCollission(Gate& obj) override {}
	virtual void handlleCollission(Throne& obj) override {}
	virtual void handlleCollission(RemovalDwarfs& obj) override {}
	virtual void handlleCollission(AddTimeGift& obj) override {}
	virtual void handlleCollission(ReduceTimeGift& obj) override {}
	virtual void handlleCollission(Key& obj) override {}

	sf::Vector2f& getNextPos() ;
	void setNextPos(sf::Vector2f& postion);

private:

	sf::Vector2f m_nextPos;
	sf::Vector2f m_startPostion;
	char m_char;
};
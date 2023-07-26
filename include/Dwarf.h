#pragma once
#include "MobileObjects.h"
#include "Board.h"

class Dwarf : public MobileObjects
{
public:
	using MobileObjects::MobileObjects; //using MobileObjects constructor
	~Dwarf() = default;

	sf::Vector2f& setDirection();

	virtual void handlleCollission(Objects& obj) override;
	virtual void handlleCollission(King& obj) override;
	virtual void handlleCollission(Warrior& obj) override;
	virtual void handlleCollission(Mage& obj) override;
	virtual void handlleCollission(Theif& obj) override;
	
	virtual void handlleCollission(Orc& obj) override {}
	virtual void handlleCollission(Dwarf& obj) override{}
	virtual void handlleCollission(Teleport& obj) override {}
	virtual void handlleCollission(Wall& obj) override;
	virtual void handlleCollission(Fire& obj) override {}
	virtual void handlleCollission(Gate& obj) override {}
	virtual void handlleCollission(Throne& obj) override {}
	virtual void handlleCollission(RemovalDwarfs& obj) override {}
	virtual void handlleCollission(AddTimeGift& obj) override {}
	virtual void handlleCollission(ReduceTimeGift& obj) override {}
	virtual void handlleCollission(Key& obj) override {}

	

};
#pragma once
#include "MobileObjects.h"

class Mage : public MobileObjects
{
public:
	using MobileObjects::MobileObjects; //using monster constructor
	~Mage() = default;

	virtual sf::Vector2f& setObjectDirection() ;

	virtual void handlleCollission(Objects& obj) override;

	virtual void handlleCollission(King& obj) override{}
	virtual void handlleCollission(Key& obj) override {}
	virtual void handlleCollission(Wall& obj) override {}
	virtual void handlleCollission(Gate& obj) override {}
	virtual void handlleCollission(Fire& obj) override {}
	virtual void handlleCollission(Orc& obj) {}
	virtual void handlleCollission(Throne& obj) {}
	virtual void handlleCollission(Dwarf& obj) {}
	virtual void handlleCollission(Teleport& obj) {}
	virtual void handlleCollission(Theif& obj) {}
	virtual void handlleCollission(Warrior& obj) {}
	virtual void handlleCollission(AddTimeGift& obj) {}
	virtual void handlleCollission(RemovalDwarfs& obj) {}
	virtual void handlleCollission(ReduceTimeGift& obj) {}
	virtual void handlleCollission(Mage& obj) {}

private:
	
};
#pragma once
#include "Objects.h"

class StaticObjects : public Objects
{
public:
	using Objects::Objects; //using object constructor
	~StaticObjects() = default;

	void setStay(bool); //set existance of a static object
	bool getStay() const;

	virtual void handlleCollission(Objects&) = 0;
	virtual void handlleCollission(King& obj) = 0;
	virtual void handlleCollission(Warrior&) = 0;
	virtual void handlleCollission(Mage&) = 0;
	virtual void handlleCollission(Dwarf&) = 0;
	virtual void handlleCollission(Teleport&) = 0;
	virtual void handlleCollission(Fire&) = 0;
	virtual void handlleCollission(Key&) = 0;
	virtual void handlleCollission(Wall&) = 0;
	virtual void handlleCollission(Gate&) = 0;
	virtual void handlleCollission(Orc&) = 0;
	virtual void handlleCollission(Theif&) = 0;
	virtual void handlleCollission(Throne&) = 0;
	virtual void handlleCollission(AddTimeGift&) = 0;
	virtual void handlleCollission(RemovalDwarfs&) = 0;
	virtual void handlleCollission(ReduceTimeGift&) = 0;

private:
	bool m_found = true;

};
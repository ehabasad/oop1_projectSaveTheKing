#pragma once
#include "StaticObjects.h"

class Gift : public StaticObjects
{
public:
	using StaticObjects::StaticObjects; //using static objects constructor
	~Gift () = default;

	virtual void handlleCollission(Objects&) = 0;
	virtual void handlleCollission(King& obj) = 0;
	virtual void handlleCollission(Warrior&) = 0;
	virtual void handlleCollission(Mage&) = 0;
	virtual void handlleCollission(Theif&) = 0;
	virtual void handlleCollission(Gate&) = 0;
	virtual void handlleCollission(Orc&) = 0;
	virtual void handlleCollission(Dwarf&) = 0;
	virtual void handlleCollission(Teleport&) = 0;
	virtual void handlleCollission(Fire&) = 0;
	virtual void handlleCollission(Key&) = 0;
	virtual void handlleCollission(Wall&) = 0;
	virtual void handlleCollission(Throne&) = 0;
	virtual void handlleCollission(AddTimeGift&) = 0;
	virtual void handlleCollission(RemovalDwarfs&) = 0;
	virtual void handlleCollission(ReduceTimeGift&) = 0;
	
};
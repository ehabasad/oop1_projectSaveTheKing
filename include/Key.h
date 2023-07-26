#pragma once
#include "StaticObjects.h"

class Key : public StaticObjects
{
public:
	using StaticObjects::StaticObjects; //using static object consturctor
	~Key() = default;

	virtual void handlleCollission(Objects& obj) override;
	virtual void handlleCollission(Theif& obj) override;

	virtual void handlleCollission(King& obj) override{}
	virtual void handlleCollission(Mage& obj) override{}
	virtual void handlleCollission(Warrior& obj) override{}
	virtual void handlleCollission(Orc& obj) override {}
	virtual void handlleCollission(Teleport& obj) override {}
	virtual void handlleCollission(Dwarf& obj) override {}
	virtual void handlleCollission(Gate& obj) override {}
	virtual void handlleCollission(Fire&) override {}
	virtual void handlleCollission(Key&) override {}
	virtual void handlleCollission(Wall&) override {}
	virtual void handlleCollission(Throne&) override {}
	virtual void handlleCollission(AddTimeGift&) override {}
	virtual void handlleCollission(RemovalDwarfs&) override {}
	virtual void handlleCollission(ReduceTimeGift&) override {}
};
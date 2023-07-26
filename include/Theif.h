#pragma once
#include "MobileObjects.h"
class Theif : public MobileObjects
{
public:
	using MobileObjects::MobileObjects; //using monster constructor
	~Theif() = default;


	virtual sf::Vector2f& setObjectDirection() ;

	virtual void handlleCollission(Objects& obj) override;

	virtual void handlleCollission(Orc& obj) override {}
	virtual void handlleCollission(King& obj) override {}
	virtual void handlleCollission(Key& obj) override {}
	virtual void handlleCollission(Wall& obj) override {}
	virtual void handlleCollission(Gate& obj) override {}
	virtual void handlleCollission(Fire& obj) override {}
	virtual void handlleCollission(AddTimeGift& obj) override {}
	virtual void handlleCollission(RemovalDwarfs& obj) override {}
	virtual void handlleCollission(ReduceTimeGift& obj) override {}
	virtual void handlleCollission(Throne& obj) override {}
	virtual void handlleCollission(Theif& obj)  override {}
	virtual void handlleCollission(Warrior& obj)  override {}
	virtual void handlleCollission(Mage& obj) override {}
	virtual void handlleCollission(Dwarf& obj) override {}
	virtual void handlleCollission(Teleport& obj) {}


	int getKey() const;
	void numKey(int);
	void setKeyStart();

	

private:
	static int m_key;
};
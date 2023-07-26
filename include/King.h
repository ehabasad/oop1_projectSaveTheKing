#pragma once
#include"MobileObjects.h"




class King : public MobileObjects
{
public:
	using MobileObjects::MobileObjects; //using monster constructor
	~King() = default;

	virtual sf::Vector2f& setObjectDirection() ;

	virtual void handlleCollission(Objects&) override;
	virtual void handlleCollission(Throne&) override;
	virtual void handlleCollission(Warrior&) override;
	virtual void handlleCollission(Dwarf&) override;

	virtual void handlleCollission(Teleport&) override {}
	virtual void handlleCollission(Mage&) override {}
	virtual void handlleCollission(Fire&) override {}
	virtual void handlleCollission(Theif&) override {}
	virtual void handlleCollission(Key&) override {}
	virtual void handlleCollission(Orc&) override {}
	virtual void handlleCollission(Gate&) override {}
	virtual void handlleCollission(Wall&) override {}
	virtual void handlleCollission(AddTimeGift&) override {}
	virtual void handlleCollission(RemovalDwarfs&) override {}
	virtual void handlleCollission(ReduceTimeGift&) override {}
	virtual void handlleCollission(King&) override {}

	void removalLife(int);
	int getLevel() const;
	void setGameLevel(int);
	int getLife() const;
	void setLife(int);
	int getTime() const;
	int getThrone() const;
	void winKing(int );
	
	void setTime(int);
	
	void setGameTimeStart();
	void setThroneStart();
	void setStartLife();
	void setlevelStart();


	static sf::Vector2f kingPosFun();
	static void setStaticKingPos(sf::Vector2f&);

private:
	static sf::Vector2f m_myPos;
	Board* m_board;
	int m_life = 4;
	int m_throne = 0;
	int m_level = 0;
	int m_time = 0;

};
#pragma once
#include "Objects.h"
#include "Toolbar.h"
#include "Menu.h"
#include "StaticObjects.h"
#include "Mage.h"
#include "Warrior.h"
#include "King.h"
#include "MobileObjects.h"
#include "Gift.h"
#include "Fire.h"
#include "Wall.h"
#include "Theif.h"
#include "Teleport.h"
#include "Gate.h"
#include "Throne.h"
#include "Dwarf.h"
#include "Key.h"
#include "Orc.h"
#include <memory>
#include <ReduceTimeGift.h>
#include <AddTimeGift.h>
#include <RemovalDwarfs.h>
#include <fstream>

class Board
{
public:
	Board(); //constructor
	~Board(); 

	bool readBoard();

	Menu& getMenu();
	Toolbar& getToolbar();
	King& getKing();
	Theif& getTheif();

	void teleportPos();
	void restartStaticPos(); 
	void restartMobilePos();
	void fileRestart(); //set mark in case of restart level
	void loadTex(); //private
	void drawStatics(sf::RenderWindow&);
	void drawMobile(sf::RenderWindow&);
	void drawDwarf(sf::RenderWindow& window);
	void drawKing(sf::RenderWindow&);
	void moveObj();
	void handlleCollisionsCheck();
	void cleanObject();
	void cleanDwarf();
	void checkWrongMove();
	int getTime(); //const

	std::vector <sf::Texture> getTextureVec();

	static int getRows();
	static int getCols();

private:

	King m_king;
	Theif m_theif;
	Toolbar m_toolbar;
	Menu m_menu;

	std::ifstream myFile;
	std::vector <sf::Texture> m_textureVec;
 	std::vector <std::string> m_picNameVec;

	
	std::vector<std::unique_ptr<Dwarf>> m_dwarfObject;
	std::vector <std::unique_ptr<StaticObjects>> m_staticObject;
	std::vector <std::unique_ptr<MobileObjects>> m_mobileObject;

	
	int m_time = 0;
	int m_rowSize;
	int m_colSize;
	
	sf::Vector2f m_vec;

	static int m_rows;
	static int m_cols;

	int m_currentObject = 0;

};

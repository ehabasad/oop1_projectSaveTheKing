#include "Board.h"
#include <fstream>


int Board::m_rows = 0;
int Board::m_cols = 0;

Board::Board()
{
	m_picNameVec = { "KingK.gif", "Warrior.png", "mage.jpg", "fire.png","throne.jpeg", "wall.png", "gate.jpg" , "gift2.png" ,"wall.jpg" , "thief.png" ,"mage.png" , "key1.png" , "teleport.png" , "dwarf.png" , "orc.png"};

	myFile.open("Board.txt"); //file to read from

	if (myFile.fail())
	{
		std::cout << "Open The File Failed()\n";
		exit(EXIT_FAILURE);
	}

}

Board::~Board()
{
	myFile.close();
}

void Board::loadTex() //load textures for all objects
{
	m_textureVec.resize(15);
	for (int i = 0; i < m_textureVec.size() ; i++)
	{
		m_textureVec[i].loadFromFile(m_picNameVec[i]);
		m_textureVec[i].setSmooth(true);
	}
}

bool Board::readBoard()
{
	int randNum; //randNum for rand
	
	if (!(myFile >> m_rows >> m_cols >> m_time)) //if there is no more levels - return false;
		return false;

	myFile.get();

	m_rowSize = 800 / m_rows;
	m_colSize = 1200 / m_cols;

	m_theif.setKeyStart();
	m_king.setGameTimeStart();
	m_king.setTime(m_time);
	m_king.setGameLevel(1);


	for (int ROWS = 0; ROWS < m_rows; ROWS++)
	{
		for (int COLS = 0; COLS < m_cols; COLS++)
		{
			sf::Vector2f postion; //set object position
			postion.x = COLS * m_colSize;
			postion.y = ROWS * m_rowSize;

			char character;
			myFile.get(character);

			switch (character)
			{
			case 'K': //King object
				m_king.setCurrPos(postion);
				m_king.setStaticKingPos(postion);
				m_king.setStartPos(postion);
				m_king.setChar('K');
				m_king.getRec().setSize(sf::Vector2f(m_rowSize, m_rowSize));
				m_king.setTex(m_textureVec[0]);
				break;

			case 'W': //Warrior object
				m_mobileObject.push_back(std::make_unique<Warrior>(postion, 'W', m_textureVec[1]));
				
				break;
			case 'M': //Mage object
				m_mobileObject.push_back(std::make_unique<Mage>(postion, 'M', m_textureVec[10]));
				
				break;
			case 'T': //Theif object
				m_mobileObject.push_back(std::make_unique<Theif>(postion, 'T', m_textureVec[9]));			
				break;
			case '^': //Dwarf object
				m_dwarfObject.push_back(std::make_unique<Dwarf>(postion, '^', m_textureVec[13]));
				break;

			case 'G': //gift object

				randNum = rand() % 3; //determine which gift type 

				if(randNum == 0 && m_time > 20)
					m_staticObject.push_back(std::make_unique<ReduceTimeGift>(postion, 'G'));
				else if(randNum == 1)
					m_staticObject.push_back(std::make_unique<RemovalDwarfs>(postion, 'G'));
				else
					m_staticObject.push_back(std::make_unique<AddTimeGift>(postion, 'G'));
					
				
				break;

			case '*': //Fire object
				m_staticObject.push_back(std::make_unique<Fire>(postion, '*')); break;
			case '#': //Gate object
				m_staticObject.push_back(std::make_unique<Gate>(postion, '#')); break;
			case '=': //Wall object
				m_staticObject.push_back(std::make_unique<Wall>(postion, '=')); break;
			case '@': //Throne object
				m_staticObject.push_back(std::make_unique<Throne>(postion, '@')); break;
			case 'F': //Key object
				m_staticObject.push_back(std::make_unique<Key>(postion, 'F')); break;
			case 'X': //Teleport object
				m_staticObject.push_back(std::make_unique<Teleport>(postion, 'X')); break;
			case '!': //Orc object
				m_staticObject.push_back(std::make_unique<Orc>(postion, '!')); break;
			
			default: continue;
			}
		}
		myFile.get();
	}
	myFile.get(); 

	return true;
}

void Board::drawStatics(sf::RenderWindow& window) //draw all static objects on window
{
	sf::RectangleShape rec;
	rec.setSize(sf::Vector2f(m_colSize, m_rowSize));
	rec.setOutlineColor(sf::Color::Transparent);
	sf::Vector2f postion;

	char character;
	for (int i = 0; i < m_staticObject.size(); i++)
	{
		if (!(m_staticObject[i]->getStay())) //if this object is no need in this specific case.
			continue;

		postion = m_staticObject[i].get()->getStartPos();
		rec.setPosition(postion.x,postion.y);
		character = m_staticObject[i]->getChar();
		
		switch (character) //set textures as apropriate
		{
		case '*': rec.setTexture(&m_textureVec[3]); break;
		case '@': rec.setTexture(&m_textureVec[4]); break;
		case '#': rec.setTexture(&m_textureVec[6]); break;
		case 'F': rec.setTexture(&m_textureVec[11]); break;
		case 'G': rec.setTexture(&m_textureVec[7]); break;
		case '=': rec.setTexture(&m_textureVec[8]); break;
		case 'X': rec.setTexture(&m_textureVec[12]); break;
		case '!': rec.setTexture(&m_textureVec[14]); break;
	
		default: break;
		}

		window.draw(rec);
	}
}

void Board::drawMobile(sf::RenderWindow& window) //draw all mobile on the window
{
	sf::Vector2f postion;
	for (int i = 0; i < m_mobileObject.size(); i++)
	{
		m_mobileObject[i]->setRecSize(sf::Vector2f(m_rowSize, m_rowSize));

		postion = m_mobileObject[i]->getCurrPos();
		m_mobileObject[i]->getRec().setPosition(postion.x, postion.y);
		window.draw(m_mobileObject[i]->getRec());
	}
}

void Board::drawDwarf(sf::RenderWindow& window) //draw all Dwarf on the window
{
	sf::Vector2f postion;
	for (int i = 0; i < m_dwarfObject.size(); i++)
	{
		m_dwarfObject[i]->setRecSize(sf::Vector2f(m_rowSize, m_rowSize));

		postion = m_dwarfObject[i]->getCurrPos();
		m_dwarfObject[i]->getRec().setPosition(postion.x, postion.y);
		window.draw(m_dwarfObject[i]->getRec());
	}
}


void Board::drawKing(sf::RenderWindow& window) //draw King on window
{
	sf::Vector2f postion;
	postion = m_king.getCurrPos();
	m_king.getRec().setPosition(postion.x, postion.y);
	window.draw(m_king.getRec());
}


void Board::moveObj() //move all mobile objects
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
	{
			m_currentObject++;
			if (m_currentObject == m_mobileObject.size()+1)
				m_currentObject = 0;	
	}
	if (m_currentObject == m_mobileObject.size())
	{
		m_king.moveObj();
	}
	else
	{
		m_mobileObject[m_currentObject]->moveObj();
	}
	
	for (int i = 0; i < m_dwarfObject.size(); i++) {
		m_dwarfObject[i]->moveObj();
	}
	
}

int Board::getRows()
{
	return m_rows;
}

int Board::getCols()
{
	return m_cols;
}

void Board::handlleCollisionsCheck() //check collision for all objects- double dispatch
{
	sf::RectangleShape rec;
	rec.setSize(sf::Vector2f(m_rowSize - 5, m_rowSize - 5));
	int n;

	// collisions king with static , mobile , dwarfs
	for (int i = 0; i < m_staticObject.size(); i++) 
	{
		
		rec.setPosition(m_staticObject[i]->getStartPos());

		if (m_staticObject[i]->getStay() && m_king.getRec().getGlobalBounds().intersects(rec.getGlobalBounds()))
		{
			m_king.handlleCollission(*m_staticObject[i]);
			
			if (m_staticObject[i]->getChar() == 'G') {
				if(strcmp(typeid(m_staticObject[i]).name() , "RemovalDwarfs" ))
					m_dwarfObject.clear();
			}
	
			
			break; 
		}

	}
	
	for (int i = 0; i < m_dwarfObject.size(); i++) 
	{

		if (m_king.getRec().getGlobalBounds().intersects(m_dwarfObject[i]->getRec().getGlobalBounds()))
		{
			m_king.handlleCollission(*m_dwarfObject[i]);
			break;
		}
	}


	for (int i = 0; i < m_mobileObject.size(); i++)
	{
		if (m_king.getRec().getGlobalBounds().intersects(m_mobileObject[i]->getRec().getGlobalBounds()))
		{
			m_king.handlleCollission(*m_mobileObject[i]);
			break;
		}
	}

	//-----------------------

	// collisions mobile with static , dwarfs
	for (int i = 0; i < m_mobileObject.size(); i++) 
	{
		for (int j = 0; j < m_staticObject.size(); j++)
		{
			if (!(m_staticObject[j]->getStay())) //this static doesn't exist
				continue;

			rec.setPosition(m_staticObject[j]->getStartPos());

			if (m_mobileObject[i]->getRec().getGlobalBounds().intersects(rec.getGlobalBounds())) {
				
				m_mobileObject[i]->handlleCollission(*m_staticObject[j]);

				if (m_mobileObject[i]->getChar() == 'W') 
					if (m_staticObject[j]->getChar() == '!') 				
						m_staticObject[j] = std::make_unique<Key>(m_staticObject[j]->getStartPos(), 'F');

			}
				
		}
	}

	for (int i = 0; i < m_mobileObject.size(); i++)
	{
		for (int j = 0; j < m_dwarfObject.size(); j++)
		{
			rec.setPosition(m_dwarfObject[j]->getStartPos());
			if (m_mobileObject[i]->getRec().getGlobalBounds().intersects(rec.getGlobalBounds()))
				m_mobileObject[i]->handlleCollission(*m_dwarfObject[j]);
		}
	}
	//-----------------
	//// collisions dward with static 
	for (int i = 0; i < m_dwarfObject.size(); i++)
	{
		for (int j = 0; j < m_staticObject.size(); j++)
		{
			
			rec.setPosition(m_staticObject[j]->getStartPos());
			if (m_dwarfObject[i]->getRec().getGlobalBounds().intersects(rec.getGlobalBounds()))
				m_dwarfObject[i]->handlleCollission(*m_staticObject[j]);
		}
	}

}

void Board::restartStaticPos() //set all static objects back to exist
{
	for (int i = 0; i < m_staticObject.size(); i++)
		m_staticObject[i]->setStay(true);
}

void Board::restartMobilePos() //restart all mobile objects positions
{
	for (int i = 0; i < m_mobileObject.size(); i++)
		m_mobileObject[i]->setCurrPos(m_mobileObject[i]->getStartPos());

	for (int i = 0; i < m_dwarfObject.size(); i++)
		m_dwarfObject[i]->setCurrPos(m_dwarfObject[i]->getStartPos());

	m_king.setCurrPos(m_king.getStartPos());
}

void Board::fileRestart() //for reading file again
{
	myFile.clear();
	myFile.seekg(0);
}

void Board::cleanObject() //delete all objects
{
	m_mobileObject.clear();
	m_dwarfObject.clear();
	m_staticObject.clear();
}

void Board::cleanDwarf() //delete dwarf
{
	m_dwarfObject.clear();
}

void Board::teleportPos() // for set the teleport postion 
{
	m_vec.x = -1;
	m_vec.y = -1;
	int  firstPos = 0;

	for (int i = 0; i < m_staticObject.size(); i++)
	{
		if (m_staticObject[i] != nullptr) {
			if (m_staticObject[i]->getChar() == 'X') {
				if (m_vec.x == -1) {
					firstPos = i;
				}
				static_cast<Teleport&>(*m_staticObject[i]).setNextPos(m_vec);
				m_vec = static_cast<Teleport&>(*m_staticObject[i]).getStartPos();
				m_vec.x += 50;
			}
		}
	}
	static_cast<Teleport&>(*m_staticObject[firstPos]).setNextPos(m_vec);
}

Menu& Board::getMenu()
{
	return m_menu;
}

Toolbar& Board::getToolbar()
{
	return m_toolbar;
}

King& Board::getKing()
{
	return m_king;
}

Theif& Board::getTheif()
{
	return m_theif;
}

std::vector <sf::Texture> Board::getTextureVec()
{
	return m_textureVec;
}

void Board::checkWrongMove() //check if move is legal
{
	if (m_king.getBool())
		m_king.itsWrongMove();

	for (int i = 0; i < m_mobileObject.size(); i++)
		if (m_mobileObject[i]->getBool())
			m_mobileObject[i]->itsWrongMove();

	for (int i = 0; i < m_dwarfObject.size(); i++)
		if (m_dwarfObject[i]->getBool())
			m_dwarfObject[i]->itsWrongMove();
}

int Board::getTime()
{
	return m_time;
}


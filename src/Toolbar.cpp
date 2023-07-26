#include "Toolbar.h"

Toolbar::Toolbar() //constructor- loading pics and m_font
{
	setDetails();
	setLevelText();
	setTimeText();
	setLifeText();
	setKeyText();
}

void Toolbar::drawToolbarText(sf::RenderWindow& window, int level,  int life,  int time  ,int key)
{
	//draw all text data visable during game
	for (int i = 0; i < m_details.size(); i++)
	{
		switch(i)
		{
			case 0:
				m_details[i].setString(convertIntToString(level));
				break;
				
			case 1:
				m_details[i].setString(convertIntToString(life));
				break;
				
			case 2:
				m_details[i].setString(convertIntToString(time));
				if (time >= 0 && time < 10)
					m_details[i].setPosition(985, 830);
				break;

			case 3:
				m_details[i].setString(convertIntToString(key));
				break;
		}
	}
	for (int i = 0; i < m_details.size(); i++)
		window.draw(m_details[i]);

	window.draw(m_level);
	window.draw(m_life);
	window.draw(m_time);
	window.draw(m_key);

}

void Toolbar::setDetails()
{
	m_font.loadFromFile("arial.ttf");

	m_details.resize(4);

	for (int i = 0; i < m_details.size(); i++)
	{
		m_details[i].setFont(m_font);
		m_details[i].setCharacterSize(30);
		m_details[i].setFillColor(sf::Color::Blue);
	}
	m_details[0].setPosition(180, 850);
	m_details[1].setPosition(375, 850);
	m_details[2].setPosition(580, 850);
	m_details[3].setPosition(325, 780);
}

void Toolbar::setLevelText()
{
	m_level.setFont(m_font);
	m_level.setCharacterSize(30);
	m_level.setLetterSpacing(2);
	m_level.setPosition(50, 850);
	m_level.setFillColor(sf::Color::Red);
	m_level.setString("Level: ");
}

void Toolbar::setLifeText()
{
	m_life.setFont(m_font);
	m_life.setCharacterSize(30);
	m_life.setLetterSpacing(2);
	m_life.setPosition(245, 850);
	m_life.setFillColor(sf::Color::Red);
	m_life.setString("Life: ");
}

void Toolbar::setTimeText()
{
	m_time.setFont(m_font);
	m_time.setCharacterSize(30);
	m_time.setLetterSpacing(2);
	m_time.setPosition(450, 850);
	m_time.setFillColor(sf::Color::Red);
	m_time.setString("Time: ");
}

void Toolbar::setKeyText()
{
	m_key.setFont(m_font);
	m_key.setCharacterSize(30);
	m_key.setLetterSpacing(2);
	m_key.setPosition(50, 780);
	m_key.setFillColor(sf::Color::Red);
	m_key.setString("The Theif Have        Keys");
}

std::string Toolbar::convertIntToString(int i) //convert int to text 
{
	std::stringstream itos;
	itos << i;
	return itos.str();
}


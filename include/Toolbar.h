#pragma once
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <sstream>
#include <string>

const int DETAILS = 5;
const int SIZE = 70;

class Toolbar
{
public:
	Toolbar(); //constructor
	~Toolbar() = default;

	
	void drawToolbarText(sf::RenderWindow&, int, int, int ,int );

	std::string convertIntToString(int i);

	void setDetails();
	void setLevelText();
	void setLifeText();
	void setTimeText();

	void setKeyText();

private:

	sf::RectangleShape m_pictureRec;
	sf::Texture m_texture;

	sf::Font m_font;

	sf::Text m_level;
	sf::Text m_life;
	sf::Text m_time;
	sf::Text m_key;

	std::vector <sf::Text> m_details;
};
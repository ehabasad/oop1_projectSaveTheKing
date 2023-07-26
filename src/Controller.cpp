#include "Controller.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

bool Controller::KingMobileCollision = false;
float Controller::deltaTime = 0;

Controller::Controller() //load song, pic and m_font
{
	m_font.loadFromFile("arial.ttf");
	m_tex.loadFromFile("play.jpeg");

	m_tex.setSmooth(true);
	m_backGroundPic.setTexture(&m_tex);
	m_backGroundPic.setSize(sf::Vector2f(1200, 900));
	
}

void Controller::run() //run game
{
	sf::RenderWindow window(sf::VideoMode(1200.f, 900.f), "Save The King :)"); 
	bool moveNextLevel, gameDone = false;

	startMenuFunc(window);

	if (isHelpOpen)
		helpMenu(window);

	if (!window.isOpen())
		return;

	m_board.loadTex(); 

	while (true)
	{
		moveNextLevel = false;

		m_music.openFromFile("play.wav");
		m_music.play();
				
		if (!m_board.readBoard()) 
		{
			if (endGameMenuWin(window))
				return;

			else 
				continue;
		}

		while (window.isOpen())
		{
			window.clear();

			window.draw(m_backGroundPic);

			drawBoard(window);
			//get to tool bar picture and detalis
			m_board.getToolbar().drawToolbarText(window,
				m_board.getKing().getLevel(),
				m_board.getKing().getLife(),
				m_board.getKing().getTime(),
				m_board.getTheif().getKey());

			window.display();

			deltaTime = m_deltaTime.restart().asSeconds();
			
			if (m_board.getTime() > 0)
				timeFunc();

			for (auto event = sf::Event{}; window.pollEvent(event);) {
				switch (event.type) {
					case sf::Event::Closed:
						window.close();
						m_board.cleanObject();
						return;
					case sf::Event::KeyPressed:
						if (event.key.code == sf::Keyboard::Escape)
							window.close();
						break;

					default:
						break;
				}
			}
			
			m_board.moveObj(); //move all mobile objects
			m_board.teleportPos(); // telport postion
			m_board.handlleCollisionsCheck(); //check collisions
			m_board.checkWrongMove(); //check wrong move

			checkGame(window, moveNextLevel, gameDone); 
			
			if (gameDone) 
				return; 
			
			if (moveNextLevel) 	
				break;	
		}
	}
}

void Controller::startMenuFunc(sf::RenderWindow& window) //starting screen menu
{
	
	while (window.isOpen())
	{
		window.clear();


		m_board.getMenu().drawPic(window);
		m_board.getMenu().drawOptions(window);

		for (auto event = sf::Event{}; window.pollEvent(event);)
		{
			switch (event.type)
			{
			case sf::Event::MouseButtonPressed:
				
				if (isMouseOver(window, m_board.getMenu().getQuitIcon())) //quit game button pressed
					window.close();

				if (isMouseOver(window, m_board.getMenu().getStartIcon())) //start game button pressed
				{
					window.clear();
					isGameOpen = true;
				}
				if (isMouseOver(window, m_board.getMenu().getHelpIcon())) //help game button pressed
				{
					window.clear();
					isHelpOpen = true;
				}
					
				break;

			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Escape)
					window.close();
				break;

			case sf::Event::MouseMoved: //colorized buttons
				if (isMouseOver(window, m_board.getMenu().getStartIcon()))
					m_board.getMenu().setStartIconBound(sf::Color::Yellow);
				else
					m_board.getMenu().setStartIconBound(sf::Color::Black);

				if (isMouseOver(window, m_board.getMenu().getQuitIcon()))
					m_board.getMenu().setQuitIconBound(sf::Color::Yellow);
				else
					m_board.getMenu().setQuitIconBound(sf::Color::Black);

				if (isMouseOver(window, m_board.getMenu().getHelpIcon()))
					m_board.getMenu().setHelpIconBound(sf::Color::Yellow);
				else
					m_board.getMenu().setHelpIconBound(sf::Color::Black);
			}
		}
		if (isGameOpen || isHelpOpen)
			break;

		window.display();
	}
}

bool Controller::isMouseOver(sf::RenderWindow& window, sf::RectangleShape shape)
{
	sf::FloatRect shapePos = shape.getGlobalBounds();

	if (shapePos.contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
		return true;
	return false;
}


void Controller::drawBoard(sf::RenderWindow& window) //draw all the objects							 
{
	m_board.drawKing(window);
	m_board.drawMobile(window);
	m_board.drawDwarf(window);
	m_board.drawStatics(window);
}

void Controller::checkGame(sf::RenderWindow& window, bool& moveNextLevel, bool& gameDone)
{
	switch (checkGameRules())
	{

	case Options::RestartMobile: 
		m_board.restartMobilePos();

		if (m_board.getTime() > 0)
			m_board.getKing().setTime(4);

		break;

	case Options::NextLevel:
		m_board.cleanObject();
		m_board.getKing().setGameTimeStart();
		m_board.getKing().setThroneStart();
		moveNextLevel = true;
		break;

	case Options::GameOver:
		if (endGameMenuLost(window))
			gameDone = true;
		else
			moveNextLevel = true;
		break;

	case Options::TimesUp:
		if (endGameMenuLost(window))
			gameDone = true;

		break;

	case Options::Nothing: break;
	}
}

Options Controller::checkGameRules() //rules forcing
{
	if (m_board.getKing().getTime() == 0)
		return Options::TimesUp;

	if (m_board.getKing().getThrone() > 0 ) //end level
		return Options::NextLevel;

	if (m_board.getKing().getLife() == 0) 
		return Options::GameOver;

	if (KingMobileCollision)
	{
		KingMobileCollision = false;
		return Options::RestartMobile;
	}
	return Options::Nothing;
}

void Controller::kingCollision()
{
	KingMobileCollision = true;
}

float Controller::getDeltaTime()
{
	return deltaTime;
}

void Controller::restartLevelFunction() //restart level
{
	m_board.getKing().setLife(-1);
	m_board.restartMobilePos();
	m_board.restartStaticPos();
	
	if (m_board.getTime() > 0)
		m_board.getKing().setTime(m_board.getTime());
}

bool Controller::endGameMenuWin(sf::RenderWindow& window) //end game menu screen
{
	m_board.cleanObject();

	sf::Font m_font;
	m_font.loadFromFile("arial.ttf");
	sf::Text text1, text2;
	text1.setFont(m_font);
	text2.setFont(m_font);
	text1.setPosition(860.f, 100.f);
	text2.setPosition(750.f, 150.f);
	
	text1.setCharacterSize(45);
	text2.setCharacterSize(45);
	
	text1.setFillColor(sf::Color::Black);
	text2.setFillColor(sf::Color::Black);

	text1.setString("You Win!");
	text2.setString("Wish To Play Again?");


	m_music.openFromFile("win.wav");
	m_music.play();
	 	
	while (window.isOpen())
	{
		window.clear();

		m_board.getMenu().drawWinPic(window);
		window.draw(text1);
		window.draw(text2);
		

		window.display();

		for (auto event = sf::Event{}; window.pollEvent(event);)
		{
			switch (event.type)
			{
			case sf::Event::MouseButtonPressed:
				if (isMouseOver(window, m_board.getMenu().getQuitIcon()))
					window.close();

				if (isMouseOver(window, m_board.getMenu().getStartIcon()))
				{
				
					m_board.fileRestart();
					m_board.getKing().setlevelStart(); //make the level -> 1
					m_board.getKing().setStartLife(); //make the life -> 3				
					m_board.getTheif().setKeyStart(); // make the key -> 0

					return false;
				}
				break;

			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Escape)
					window.close();
				break;

			case sf::Event::MouseMoved:
				if (isMouseOver(window, m_board.getMenu().getStartIcon()))
					m_board.getMenu().setStartIconBound(sf::Color::Blue);
				else
					m_board.getMenu().setStartIconBound(sf::Color::White);

				if (isMouseOver(window, m_board.getMenu().getQuitIcon()))
					m_board.getMenu().setQuitIconBound(sf::Color::Blue);
				else
					m_board.getMenu().setQuitIconBound(sf::Color::White);
			}
		}
	}

	return true;
}

bool Controller::endGameMenuLost(sf::RenderWindow& window) //end game lost menu screen
{
	m_board.cleanObject();

	sf::Text text1, text2;
	text1.setFont(m_font);
	text2.setFont(m_font);
	text1.setPosition(120.f, 100.f);
	text2.setPosition(10.f, 150.f);
	text1.setCharacterSize(45);
	text2.setCharacterSize(45);
	text1.setFillColor(sf::Color::Black);
	text2.setFillColor(sf::Color::Black);

	text1.setString("You Lose!");
	text2.setString("Wish To Play Again?");


	m_music.openFromFile("gameover.wav");
	m_music.play();

	while (window.isOpen())
	{
		window.clear();

		m_board.getMenu().drawLosePic(window);
		window.draw(text1);
		window.draw(text2);

		window.display();

		for (auto event = sf::Event{}; window.pollEvent(event);)
		{
			switch (event.type)
			{
			case sf::Event::MouseButtonPressed:
				if (isMouseOver(window, m_board.getMenu().getQuitIcon()))
					window.close();

				if (isMouseOver(window, m_board.getMenu().getStartIcon()))
				{
					m_board.fileRestart();
					m_board.getKing().setlevelStart(); //make the level -> 1
					m_board.getKing().setStartLife(); //make the life -> 3
					m_board.getTheif().setKeyStart(); // make the key -> 0
					
					return false;
				}
				break;

			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Escape)
					window.close();
				break;
				

			case sf::Event::MouseMoved:
				if (isMouseOver(window, m_board.getMenu().getStartIcon()))
					m_board.getMenu().setStartIconBound(sf::Color::Blue);
				else
					m_board.getMenu().setStartIconBound(sf::Color::White);

				if (isMouseOver(window, m_board.getMenu().getQuitIcon()))
					m_board.getMenu().setQuitIconBound(sf::Color::Red);
				else
					m_board.getMenu().setQuitIconBound(sf::Color::White);
			}
		}
	}
	return true;
}

bool Controller::helpMenu(sf::RenderWindow& window) //end game menu screen
{
	m_board.cleanObject();

	
	sf::Font m_font;
	m_font.loadFromFile("arial.ttf");
	sf::Text text1, text2;
	text1.setFont(m_font);
	text2.setFont(m_font);
	text1.setPosition(9.f, 0.f);
	text2.setPosition(9.f, 50.f);

	text1.setCharacterSize(30);
	text2.setCharacterSize(30);

	text1.setFillColor(sf::Color::Black);
	text2.setFillColor(sf::Color::Black);

	text1.setString("Done By");
	text2.setString("Ehab & Lammah -_-");


	while (window.isOpen())
	{
		window.clear();

		m_board.getMenu().drawHelpPic(window);
		window.draw(text1);
		window.draw(text2);

		window.display();

		for (auto event = sf::Event{}; window.pollEvent(event);)
		{
			switch (event.type)
			{
			case sf::Event::MouseButtonPressed:
				if (isMouseOver(window, m_board.getMenu().getQuitIcon()))
					window.close();

				if (isMouseOver(window, m_board.getMenu().getStartIcon()))
				{

					m_board.fileRestart();
					m_board.getKing().setlevelStart(); //make the level -> 1
					m_board.getKing().setStartLife(); //make the life -> 3
					m_board.getTheif().setKeyStart(); // make the key -> 0

					return false;
				}
				break;

			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Escape)
					window.close();
				break;

			case sf::Event::MouseMoved:
				if (isMouseOver(window, m_board.getMenu().getStartIcon()))
					m_board.getMenu().setStartIconBound(sf::Color::Blue);
				else
					m_board.getMenu().setStartIconBound(sf::Color::White);

				if (isMouseOver(window, m_board.getMenu().getQuitIcon()))
					m_board.getMenu().setQuitIconBound(sf::Color::Blue);
				else
					m_board.getMenu().setQuitIconBound(sf::Color::White);
			}
		}
	}

	return true;
}

void Controller::timeFunc() //function the timer
{
	m_gameTime = m_gameClock.getElapsedTime();

	if (m_gameTime.asSeconds() > 1)
	{
		m_board.getKing().setTime(-1);
		m_gameClock.restart();
	}
}

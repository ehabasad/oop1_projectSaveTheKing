#pragma once
#include "Board.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

enum class Options //enum to determine which situation are we in
{
	GameOver, 
	NextLevel,
	RestartMobile,
	TimesUp,
	Nothing
};

class Controller
{
public:
	Controller();
	~Controller() = default;
	void run();

	void startMenuFunc(sf::RenderWindow& window);
	void drawBoard(sf::RenderWindow&);
	bool isMouseOver(sf::RenderWindow& window, sf::RectangleShape shape);

	void checkGame(sf::RenderWindow&, bool&, bool&);
	Options checkGameRules();
	bool endGameMenuWin(sf::RenderWindow&);
	bool endGameMenuLost(sf::RenderWindow&);
	void restartLevelFunction();
	bool helpMenu(sf::RenderWindow& window);
	void timeFunc();

	static void kingCollision();
	static float getDeltaTime();

private:

	bool isGameOpen = false;
	bool isHelpOpen = false;

	sf::Texture m_tex;
	sf::RectangleShape m_backGroundPic;
	sf::Clock m_gameClock;
	sf::Time m_gameTime;
	sf::Font m_font;
	sf::Music m_music;
	sf::Clock m_deltaTime;
	
	Board m_board;

	static float deltaTime;
	static bool KingMobileCollision;

	
};
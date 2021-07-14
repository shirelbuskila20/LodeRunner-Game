#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <memory>
#include "Utilities.h"
#include "Player.h"
#include "Level.h"
#include "GameMenu.h"
using std::unique_ptr;
using std::make_unique;

class Controller
{
public:
	Controller();
	~Controller()=default;
	bool run(sf::RenderWindow& window);
	void draw(sf::RenderWindow& window, float deltaTime);
	void checkEvent(sf::RenderWindow& window, sf::Clock& clock, sf::Event Event);
	void printPlayer(sf::RenderWindow& window);
	bool isWall(sf::Vector2f location);
	void digging(sf::Vector2f location);
	int getLevelNum()const;
	void addMonster();

protected:
	void restartLevel(sf::RenderWindow& window);
	void levelManege(sf::RenderWindow& window, sf::Time deltaTime);
	void levelUp(sf::RenderWindow& window);
	bool levelFinished()const;
	bool isOver()const;
	int m_levelNum;
	Player m_player;
	Level m_level;
	GameMenu m_gameMenu;
	sf::Clock m_clock;
	sf::Clock m_timeLeft;
};


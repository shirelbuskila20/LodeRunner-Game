#pragma once
#include <SFML/Graphics.hpp>
#include "ResourcesManage.h"
#include "Player.h"
class GameMenu
{
public:
	GameMenu(Player& player);
	~GameMenu()=default;
	void drawOnScreen(sf::RenderWindow& window,int levelNumber, int time);



private:
	void playerLive();
	void playerScore();
	void levelTime(int time);
	void levelNum(int levelNumber);
	sf::Sprite m_menu;;
	sf::Font m_font;
	sf::Sprite m_playerSprite;
	sf::Text m_liveText;
	sf::Sprite m_moneySprite;
	sf::Text m_moneyText;
	sf::Sprite m_timeSprite;
	sf::Text m_timeText;
	sf::Text m_levelText;
	Player& m_player;
	int m_time;

};

#pragma once
#include <vector>
#include "Monster.h"
#include "MonsterConstMove.h"
#include "MonsterRandom.h"
#include "MonsterToPlayer.h"
#include "GameBoard.h"
#include"Player.h"
#include "GameMenu.h"
using std::vector;
class Level
{
public:
	Level(Player& player,int levelNum);
	~Level()=default;
	void run(sf::RenderWindow& window, Player& player, int levelNum);
	void draw(sf::RenderWindow& window, GameMenu& menu,int levelNum,Player& player);
	void insertMonster(sf::Vector2f location, Player& player);
	void moveDynamic(float& deltaTime, Player& player);
	bool isWall3(sf::Vector2f location);
	void digging3(sf::Vector2f location);
	void resetVectorS();
	int timePassed(Player& player);
	void stopMusic();

protected:
	void handleCollisionsWithMonster(Object& gameObject);
	void printMonster(sf::RenderWindow& window);
	vector<unique_ptr<Monster>> m_monsters;
	GameBoard m_board;
	sf::Clock m_timePassed;
	sf::Music m_music;

};


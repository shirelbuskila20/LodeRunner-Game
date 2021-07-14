#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <SFML/Graphics.hpp>
#include "Utilities.h"
#include "StaticObject.h"
#include "Ladder.h"
#include "Money.h"
#include "Present.h"
#include "PresentMoreLive.h"
#include "PresentMoreMonster.h"
#include "PresentMoreScore.h"
#include "PresentMoreTime.h"
#include "Rod.h"
#include "Wall.h"
#include <experimental/vector>
#include "Player.h"
using std::vector;
using std::string;
using std::getline;
using std::ifstream;
using std::cout;
using std::unique_ptr;
using std::make_unique;
const string BOARD_FILE = "Board.txt";
class Level;
class GameBoard
{
public:
	GameBoard(Player& player, int levelNum);
	~GameBoard()=default;
	void readFile(int levelNum);
	void insertData(Level& level, Player& player);
	void drawOnWindow(sf::RenderWindow& window) ;
	void handleCollisions(Object& gameObject);
	bool isWall2(sf::Vector2f location );
	void digging2(sf::Vector2f location);
	void resetVector();


protected:
	sf::RectangleShape m_background;
	vector <string> m_gameBoard;//לוח המשחק
	vector<unique_ptr<StaticObject>> m_sobject;
	ifstream m_board;//פתיחת קובץ
	int m_numRow;
	int m_numCol;
	Player& m_player;
	float m_clockOfLevel;


};


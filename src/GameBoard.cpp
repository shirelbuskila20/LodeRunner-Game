#include "GameBoard.h"
#include "Level.h"
//--------------------------------------------------------------------------------------------
// c-tor
GameBoard::GameBoard(Player& player,int levelNum):m_background({WINDOW_WIDTH,BOARD_HEIGHT}), m_player(player)
{
	m_background.setPosition(sf::Vector2f(0, 0));
	m_background.setFillColor(sf::Color::Green);

}

//--------------------------------------------------------------------------------------------
// הפונקציה קוראת נתונים מהקובץ
void GameBoard::readFile(int levelNum)
{
	
	string file = "LEVEL" + std::to_string(levelNum) + ".txt";

	m_board = ifstream(file);
	if (!m_board.is_open())
	{
		std::cout << "cant open the file\n";
		exit(EXIT_FAILURE);
	}
}

//--------------------------------------------------------------------------------------------
// הפונקציה מכניסה נתונים לוקטור
void GameBoard::insertData(Level& level, Player& player)
{
	m_gameBoard.clear();
	m_board >> m_numRow >> m_numCol >> m_clockOfLevel;;
	char c;
	string line;
	getline(m_board, line);
	getline(m_board, line);
	int row=0, col=0;
	while (row<=m_numRow)
	{

		for (auto c : line)
		{
			sf::Vector2f location(ROW_HIGHT * col, ROW_HIGHT * row);
			switch (c)
			{
			case MONEY:
				m_player.setMoney();
				m_sobject.push_back(std::make_unique<Money>(sf::Vector2f(location),money_b) );
				break;

			case LADDER:
				m_sobject.push_back(std::make_unique<Ladder>(sf::Vector2f(location),ladder_b));
				break;

			case ROD:
				m_sobject.push_back(std::make_unique<Rod>(sf::Vector2f(location),rod_b));
				break;

			case WALL:
				m_sobject.push_back(std::make_unique<Wall>(sf::Vector2f(location),wall_b));
				break;

			case PRESENT:
			{
				int randomNum = (rand() % 4);
				switch (randomNum)
				{
				case 0:
					m_sobject.push_back(make_unique<PresentMoreLive>(sf::Vector2f(location), present_b));
					break;
				case 1:
					m_sobject.push_back(make_unique<PresentMoreMonster>(sf::Vector2f(location), present_b));
					break;
				case 2:
					m_sobject.push_back(make_unique<PresentMoreScore>(sf::Vector2f(location), present_b));
					break;
				case 3:
					m_sobject.push_back(make_unique<PresentMoreTime>(sf::Vector2f(location), present_b));//time
					break;
				default:
					break;
				}
			}
				break;

			case PLAYER:
				player.setLocation(location);
				player.setTime(m_clockOfLevel);
				break;

			case MONSTER:
				level.insertMonster(sf::Vector2f(location),player);
				break;
			default:
				break;
				
			}
			col++;
		}
		m_gameBoard.push_back(line);
		col = 0;
		row++;
		getline(m_board, line);
	}
	
}

//--------------------------------------------------------------------------------------------
// הפונקציה מציירת על המסך
void GameBoard::drawOnWindow(sf::RenderWindow& window) 
{
	window.clear();
	window.draw(m_background);
	for (auto& d : m_sobject)
		d->drawOnWindow(window);
}

//--------------------------------------------------------------------------------------------
// בדיקת התנגשויות של השחקן או המפלצות מול הוקטור של האובייקטים הסטטיים
void GameBoard::handleCollisions(Object& gameObject)
{
	
	for(int i=0;i<m_sobject.size();i++)
	{
		if (gameObject.checkCollision(m_sobject[i]->getGlobalBounds()))
		{
			
			gameObject.handleCollision(*m_sobject[i]);
			std::experimental::erase_if(m_sobject, [](auto& staticObject)
				{
					return staticObject->isDisposed();
				});
			if (typeid(*m_sobject[i]) != typeid(Ladder))
				m_player.setIsLadder(false);
			return;
		}
	}
}

//--------------------------------------------------------------------------------------------
// בדיקה אם המיקום הוא קיר או מוט או סולם
bool GameBoard::isWall2(sf::Vector2f location)
{
	for (auto& staticObject : m_sobject)
		if((typeid(*staticObject)==typeid(Wall))|| (typeid(*staticObject) == typeid(Rod)) || (typeid(*staticObject) == typeid(Ladder)))
			if (staticObject->getGlobalBounds().contains(location))
				return true;
	return false;
}

//--------------------------------------------------------------------------------------------
// פונקציה שחופרת לפי המיקום
void GameBoard::digging2(sf::Vector2f location)
{
	for (int i = 0; i < m_sobject.size(); i++)
		if (m_sobject[i]->getGlobalBounds().contains(location))
		{

			m_sobject.erase(m_sobject.begin() + i);
			break;
		}

}

//--------------------------------------------------------------------------------------------
// מאפסת את הוקטור
void GameBoard::resetVector()
{
	m_sobject.clear();
}

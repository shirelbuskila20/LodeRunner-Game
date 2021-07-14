#include "Controller.h"
//--------------------------------------------------------------------------------------------
// c-tor
Controller::Controller():m_levelNum(0), m_player(*this),m_level(m_player,m_levelNum),m_gameMenu(m_player)
{
}

//--------------------------------------------------------------------------------------------
// מנהלת את ניהול השלבים ומחזירה אם ניצח או הפסיד
bool Controller::run(sf::RenderWindow& window)
{
    window.clear();
    while (window.isOpen())
    {
        window.clear();
        while (!isOver())//השחקן הפסיד
        {
       
            if ((levelFinished() || m_level.timePassed(m_player) <= 0))//השלב הסתיים או שהזמן נגמר
            {
                m_level.stopMusic();
                m_level.resetVectorS();
                window.clear();
                if (m_level.timePassed(m_player) > 0)//השלב הסתיים
                {
                    m_levelNum++;
                    if (m_levelNum < NUM_OF_LEVELS)
                    {
                        window.clear();
                        levelUp(window);
                    }
                    if (m_levelNum == NUM_OF_LEVELS)
                        return true;
                  
                }
                else//נגמר הזמן
                {
                    window.clear();
                    m_player.decreaseLive();
                    restartLevel(window);
                    
                }
             

            }

            auto deltaTime = m_clock.restart();
            levelManege(window, deltaTime);
        }
        m_level.stopMusic();
        return false;
    }
    m_level.stopMusic();
    return true;
}

//--------------------------------------------------------------------------------------------
//פונקציה שמנהלת את השלב
void Controller::levelManege(sf::RenderWindow& window, sf::Time deltaTime)
{
    sf::Event event;
    while (window.pollEvent(event))
        checkEvent(window, m_clock, event);
    auto time = deltaTime.asSeconds();
    m_level.moveDynamic(time, m_player);
    window.clear();
    draw(window, deltaTime.asSeconds());
    window.display();
}

//--------------------------------------------------------------------------------------------
// הפונקציה מאפסת את הנתונים ומעלה שלב
void Controller::levelUp(sf::RenderWindow& window)
{
    window.clear();
    if (m_player.getScore() != 0)
        m_player.setScore(50);
    m_player.setLive(3);
    m_player.setTime(0);
    m_player.startDirectionFace();
    m_level.run(window, m_player,m_levelNum);
}

//--------------------------------------------------------------------------------------------
//מתחיל שלב מחדש
void Controller::restartLevel(sf::RenderWindow& window)
{
    m_player.startDirectionFace();
    m_level.run(window, m_player, m_levelNum);
}

//--------------------------------------------------------------------------------------------
// הפונקציה מציירת על המסך
void Controller::draw(sf::RenderWindow& window, float deltaTime) 
{
    window.clear();
    m_level.draw(window, m_gameMenu,m_levelNum, m_player);
    printPlayer(window);
}

//--------------------------------------------------------------------------------------------
// הפונקציה בודקת אירועים מהמקלדת
void Controller::checkEvent(sf::RenderWindow& window, sf::Clock& clock, sf::Event event)
{
    switch (event.type)
    {
    case sf::Event::Closed:
        window.close();
        exit(0);
        break;

    case sf::Event::KeyPressed:
        if (event.key.code == sf::Keyboard::Escape)
        {
            window.close();
            break;
        }
        m_player.setDirection(event.key.code);
        break;
    }
            
}
   
//--------------------------------------------------------------------------------------------
// הפונקציה מדפיסה את השחקן
void Controller::printPlayer(sf::RenderWindow& window) 
{
    m_player.drawOnWindow(window);
}

//--------------------------------------------------------------------------------------------
// בודק אם המיקום הוא קיר
bool Controller::isWall(sf::Vector2f location)
{
    return m_level.isWall3(location);
}

//--------------------------------------------------------------------------------------------
// פונקצית עזר לחפירה
void Controller::digging(sf::Vector2f location)
{
    m_level.digging3(location);
}

//--------------------------------------------------------------------------------------------
//בודק אם המשחק נגמר
bool Controller::isOver()const
{
    if( (m_player.getLivePlayer() <= 0 ))
        return true;
    else
        return false;
}

//--------------------------------------------------------------------------------------------
//בודק אם סיים את השלב
bool Controller::levelFinished()const
{
    return m_player.getMoneyLeft() <= 0;
}

//--------------------------------------------------------------------------------------------
//מחזיר את מספר השלב הנוכחי
int Controller::getLevelNum()const
{
    return m_levelNum;
}

//--------------------------------------------------------------------------------------------
//מוסיף מפלצת לוקטור
void Controller::addMonster()
{
    m_level.insertMonster({ROW_HIGHT,ROW_HIGHT }, m_player);
}



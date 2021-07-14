#include "Level.h"
//--------------------------------------------------------------------------------------------
// c-tor
Level::Level(Player& player, int levelNum):m_board(player,levelNum)
{
    m_timePassed.restart();  
}

//--------------------------------------------------------------------------------------------
// הפונקציה קוראת מקובץ ומכניסה לוקטור
void Level::run(sf::RenderWindow& window, Player& player,int levelNum)
{
    (*ResourcesManage::instance().getMusic()).play();
    m_timePassed.restart();
    m_board.readFile(levelNum);
    m_board.insertData(*this,player);
}

//--------------------------------------------------------------------------------------------
// הפונקציה מציירת על החלון
void Level::draw(sf::RenderWindow& window, GameMenu& menu, int levelNum, Player& player)
{
    m_board.drawOnWindow(window);
    menu.drawOnScreen(window, levelNum,timePassed(player));
    printMonster(window);
}

//--------------------------------------------------------------------------------------------
// הפונקציה מכניסה מפלצות לפי מספר רנדומלי
void Level::insertMonster(sf::Vector2f location, Player& player)
{
    int randomNum = (rand() % 3);
    switch (randomNum)
    {
    case 0://מפלצת עם תזוזה קבועה
        m_monsters.push_back(make_unique<MonsterConstMove>(sf::Vector2f(location), monsterConstMove_b));
        break;
    case 1://מפלצת עם תזוזה רנדומלית
        m_monsters.push_back(make_unique<MonsterRandom>(sf::Vector2f(location), monsterRandom_b));
        break;
    case 2://מפלצת חכמה עם תזוזה לשחקן
        m_monsters.push_back(make_unique<MonsterToPlayer>(sf::Vector2f(location), monsterToPlayer_b,player));
        break;
    default:
        break;
    }

}

//--------------------------------------------------------------------------------------------
// הפונקציה מדפיסה מפלצות
void Level::printMonster(sf::RenderWindow& window)
{
    for (auto& d : m_monsters)
        d->drawOnWindow(window);
}

//--------------------------------------------------------------------------------------------
// הפונקציה מזיזה את האובייקטים הדינאמיים ובודקת התנגשויות
void Level::moveDynamic(float& deltaTime,Player&player)
{
    player.move(deltaTime);
    m_board.handleCollisions(player);
    handleCollisionsWithMonster(player);
    for (auto& d : m_monsters)
    {

        d->move(deltaTime);
        m_board.handleCollisions(*d);
    }
}

//--------------------------------------------------------------------------------------------
// פונקצית עזר לבדיקה אם במיקום יש קיר
bool Level::isWall3(sf::Vector2f location)
{
    return m_board.isWall2(location);
}

//--------------------------------------------------------------------------------------------
//פונקציית עזר לחפירה
void Level::digging3(sf::Vector2f location)
{
    m_board.digging2(location);
}

//--------------------------------------------------------------------------------------------
// בדיקת התנגשויות של השחקן עם המפלצות
void Level::handleCollisionsWithMonster(Object& gameObject)
{
    for (auto& monster : m_monsters)
    {
        if (gameObject.checkCollision(monster->getGlobalBounds()))
        {
            gameObject.handleCollision(*monster);
        }
    }
}

//--------------------------------------------------------------------------------------------
//הפונקציה מאפסת את הוקטורים
void Level::resetVectorS()
{
    m_monsters.clear();
    m_board.resetVector();

}

//--------------------------------------------------------------------------------------------
//בדיקת כמה זמן עבר
int Level::timePassed(Player& player)
{
    return player.getTime() - m_timePassed.getElapsedTime().asSeconds();
}

//--------------------------------------------------------------------------------------------
// הפונקציה מפסיקה את המוזיקה
void Level::stopMusic()
{
    (*ResourcesManage::instance().getMusic()).stop();
}





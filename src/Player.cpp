#include "Player.h"
#include "Controller.h"
//--------------------------------------------------------------------------------------------
//c-tor
Player::Player(Controller& controller)
    :DynamicObject(sf::Vector2f(0, 0), player_b), m_controller(controller), m_time(60), m_score(0), m_live(3), m_numOfMoney(0), m_leftTime(0)
{
    m_sprite.scale(0.95f, 0.95f);
}

//--------------------------------------------------------------------------------------------
//כיון לפי המקלדת
void Player::setDirection(sf::Keyboard::Key key)
{
    switch (key)
    {
    case sf::Keyboard::Right:
        startDirectionFace();

        m_direction = Direction::RIGHT;
        break;

    case sf::Keyboard::Left:
      m_sprite.scale(-1, 1);
        m_direction = Direction::LEFT;
        break;

    case sf::Keyboard::Up:
        if (m_isLadder)//רק כשהוא על סולם מאפשר עליה
        {
            m_direction = Direction::UP;
            m_isLadder = false;
            break;
        }
       else
         break;

    case sf::Keyboard::Down:       
        if (m_isLadder)//רק כשהוא על סולם מאפשר ירידה
        {
          m_direction = Direction::DOWN;
            m_isLadder = false;
            break;
        }
        else
            break;

    case sf::Keyboard::Space: m_direction = Direction::STAY;  break;

    case sf::Keyboard::X://ימין
        if ((m_controller.isWall({ m_sprite.getPosition().x + ROW_HIGHT,m_sprite.getPosition().y+10+ROW_HIGHT })))
            m_controller.digging({ m_sprite.getPosition().x + ROW_HIGHT,m_sprite.getPosition().y+10+ ROW_HIGHT });
            break;

    case sf::Keyboard::Z://שמאל
        if ((m_controller.isWall({ m_sprite.getPosition().x - ROW_HIGHT,m_sprite.getPosition().y+10+ ROW_HIGHT })))
            m_controller.digging({ m_sprite.getPosition().x - ROW_HIGHT,m_sprite.getPosition().y+10+ ROW_HIGHT });
        break;
    }
}

//--------------------------------------------------------------------------------------------
namespace
{
sf::Vector2f dirToVector(Player::Direction dir)
{
    switch (dir)
    {
    case Player::Direction::RIGHT: return { 1, 0 };
    case Player::Direction::LEFT: return { -1, 0 };
    case Player::Direction::UP: return { 0, -1 };
    case Player::Direction::DOWN: return { 0, 1 };
    case Player::Direction::STAY: return { 0, 0 };
    }
    return { 0, 0 }; 
}
}

//--------------------------------------------------------------------------------------------
//תזוזה של השחקן
void Player::move(float deltaTime)
{
    if (!m_isLadder)
    {
        while (!m_controller.isWall({ m_sprite.getPosition().x,m_sprite.getPosition().y + ROW_HIGHT }))
        {
            m_sprite.move(dirToVector(Player::Direction::DOWN) * 100.f * deltaTime);
        }
    }

    if (!outOfBoard())
    {
        m_prevPosition = m_sprite.getPosition();
        m_sprite.move(dirToVector(m_direction) * 100.f * deltaTime);
    }
    else
        m_sprite.setPosition(m_prevPosition);
}

//--------------------------------------------------------------------------------------------
//מחזיר מיקום
sf::Vector2f Player::getPosition()const
{
    return m_sprite.getPosition();
}

//--------------------------------------------------------------------------------------------
//מחזיר את החיים של השחקן
int Player::getLivePlayer() const
{
    return m_live;
}

//--------------------------------------------------------------------------------------------
//מחזיר כמה כסף נשאר לאסוף
int Player::getMoneyLeft() const
{
    return m_numOfMoney;
}

//--------------------------------------------------------------------------------------------
//מחזיר את הנקודות שלו
int Player::getScore() const
{
    return m_score;
}

//--------------------------------------------------------------------------------------------
//מוסיף ציון
void Player::setScore(int i)
{
    m_score += i;
}

//--------------------------------------------------------------------------------------------
//טיפול בהתנגשות
void Player::handleCollision(Object& gameObject)
{
    if (&gameObject == this) return;
    //double dispatch
    gameObject.handleCollision(*this);
}

//--------------------------------------------------------------------------------------------
//התנגשות עם קיר
void Player::handleCollision(Wall& wall)
{
    setDirection(sf::Keyboard::Space);
}

//--------------------------------------------------------------------------------------------
//התנגשות עם מפלצת עם תזוזה קבועה
void Player::handleCollision(MonsterConstMove& gameObject)
{
    m_sound.setBuffer((*ResourcesManage::instance().getPtrToMusic(monsterToPlayer_m)));
    m_sound.play();
    m_live--;
    startDirectionFace();
    m_sprite.setPosition(m_firstLocation);
}

//--------------------------------------------------------------------------------------------
//התנגשות עם מפלצת עם תזוזה רנדומלית
void Player::handleCollision(MonsterRandom& gameObject)
{
    m_sound.setBuffer((*ResourcesManage::instance().getPtrToMusic(monsterToPlayer_m)));
    m_sound.play();
    m_live--;
    startDirectionFace();
    m_sprite.setPosition(m_firstLocation);
}

//--------------------------------------------------------------------------------------------
//התנגשות עם מפלצת עם תזוזה לכיון השחקן
void Player::handleCollision(MonsterToPlayer& gameObject)
{
    m_sound.setBuffer((*ResourcesManage::instance().getPtrToMusic(monsterToPlayer_m)));
    m_sound.play();
    m_live--;
    startDirectionFace();
    m_sprite.setPosition(m_firstLocation);
}

//--------------------------------------------------------------------------------------------
//התנגשות עם כסף
void Player::handleCollision(Money& money)
{
    m_sound.setBuffer((*ResourcesManage::instance().getPtrToMusic(moneySound_m)));
    m_sound.play();
    m_numOfMoney--;
    setScore( 2*m_controller.getLevelNum());
  
}

//--------------------------------------------------------------------------------------------
//מציב את המיקום הראשוני
void Player::setLocation(sf::Vector2f& location)
{
    m_sprite.setPosition(location);
    m_firstLocation = location;
}

//--------------------------------------------------------------------------------------------
//האם סולם
void Player::setIsLadder(bool flag)
{
    m_isLadder = flag;
}

//--------------------------------------------------------------------------------------------
//סופר כמה כסף יש בקובץ
void Player::setMoney()
{
    m_numOfMoney++;
}

//--------------------------------------------------------------------------------------------
//מאפס את מספר המטבעות
void Player::restartMoney()
{
    m_numOfMoney = 0;
}

//--------------------------------------------------------------------------------------------
//מאפס את הפרצוף של השחקן
void Player::startDirectionFace()
{
    m_sprite.setScale(1, 1);
    m_sprite.scale(0.3f, 0.3f);
    m_sprite.scale(0.95f, 0.95f);
}

//--------------------------------------------------------------------------------------------
//השמה
void Player::setLive(int live)
{
    m_live = live;
}
//--------------------------------------------------------------------------------------------
//מחזיר זמן
int Player::getTime() const
{
    return m_time;
}
//--------------------------------------------------------------------------------------------
//vanv
void Player::setTime(int time)
{
    m_time = time;
}

//--------------------------------------------------------------------------------------------
// מחשב כמה זמן נשאר
void Player::setTimeLeft(sf::Clock& clock)
{
    if (m_time - (clock.getElapsedTime().asSeconds()) <= 0)
    {
        m_time = m_leftTime;
        clock.restart();
        m_sprite.setPosition(m_startPosition);
    }
}

//--------------------------------------------------------------------------------------------
//מוריד 1 מהחיים
void Player::decreaseLive()
{
    m_live--;
}

//--------------------------------------------------------------------------------------------
//התנגשות עם סולם
void Player::handleCollision(Ladder& ladder)
{
    m_isLadder = true;
}

//--------------------------------------------------------------------------------------------
//התנגשות עם מתנה
void Player::handleCollision(PresentMoreLive& gameObject)
{
    m_sound.setBuffer((*ResourcesManage::instance().getPtrToMusic(presentMusic_m)));
    m_sound.play();
    m_live++;
}

//--------------------------------------------------------------------------------------------
//התנגשות עם מתנה
void Player::handleCollision(PresentMoreMonster& gameObject)
{
    m_sound.setBuffer((*ResourcesManage::instance().getPtrToMusic(presentMusic_m)));
    m_sound.play();
    m_controller.addMonster();

}

//--------------------------------------------------------------------------------------------
//התנגשות עם מתנה
void Player::handleCollision(PresentMoreScore& gameObject)
{
    m_sound.setBuffer((*ResourcesManage::instance().getPtrToMusic(presentMusic_m)));
    m_sound.play();
    m_score+=20;

}

//--------------------------------------------------------------------------------------------
//התנגשות עם מתנה
void Player::handleCollision(PresentMoreTime& gameObject)
{
    m_sound.setBuffer((*ResourcesManage::instance().getPtrToMusic(presentMusic_m)));
    m_sound.play();
    m_time += 10;
}



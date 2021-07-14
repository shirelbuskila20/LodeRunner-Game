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
//���� ��� ������
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
        if (m_isLadder)//�� ����� �� ���� ����� ����
        {
            m_direction = Direction::UP;
            m_isLadder = false;
            break;
        }
       else
         break;

    case sf::Keyboard::Down:       
        if (m_isLadder)//�� ����� �� ���� ����� �����
        {
          m_direction = Direction::DOWN;
            m_isLadder = false;
            break;
        }
        else
            break;

    case sf::Keyboard::Space: m_direction = Direction::STAY;  break;

    case sf::Keyboard::X://����
        if ((m_controller.isWall({ m_sprite.getPosition().x + ROW_HIGHT,m_sprite.getPosition().y+10+ROW_HIGHT })))
            m_controller.digging({ m_sprite.getPosition().x + ROW_HIGHT,m_sprite.getPosition().y+10+ ROW_HIGHT });
            break;

    case sf::Keyboard::Z://����
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
//����� �� �����
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
//����� �����
sf::Vector2f Player::getPosition()const
{
    return m_sprite.getPosition();
}

//--------------------------------------------------------------------------------------------
//����� �� ����� �� �����
int Player::getLivePlayer() const
{
    return m_live;
}

//--------------------------------------------------------------------------------------------
//����� ��� ��� ���� �����
int Player::getMoneyLeft() const
{
    return m_numOfMoney;
}

//--------------------------------------------------------------------------------------------
//����� �� ������� ���
int Player::getScore() const
{
    return m_score;
}

//--------------------------------------------------------------------------------------------
//����� ����
void Player::setScore(int i)
{
    m_score += i;
}

//--------------------------------------------------------------------------------------------
//����� ��������
void Player::handleCollision(Object& gameObject)
{
    if (&gameObject == this) return;
    //double dispatch
    gameObject.handleCollision(*this);
}

//--------------------------------------------------------------------------------------------
//������� �� ���
void Player::handleCollision(Wall& wall)
{
    setDirection(sf::Keyboard::Space);
}

//--------------------------------------------------------------------------------------------
//������� �� ����� �� ����� �����
void Player::handleCollision(MonsterConstMove& gameObject)
{
    m_sound.setBuffer((*ResourcesManage::instance().getPtrToMusic(monsterToPlayer_m)));
    m_sound.play();
    m_live--;
    startDirectionFace();
    m_sprite.setPosition(m_firstLocation);
}

//--------------------------------------------------------------------------------------------
//������� �� ����� �� ����� ��������
void Player::handleCollision(MonsterRandom& gameObject)
{
    m_sound.setBuffer((*ResourcesManage::instance().getPtrToMusic(monsterToPlayer_m)));
    m_sound.play();
    m_live--;
    startDirectionFace();
    m_sprite.setPosition(m_firstLocation);
}

//--------------------------------------------------------------------------------------------
//������� �� ����� �� ����� ����� �����
void Player::handleCollision(MonsterToPlayer& gameObject)
{
    m_sound.setBuffer((*ResourcesManage::instance().getPtrToMusic(monsterToPlayer_m)));
    m_sound.play();
    m_live--;
    startDirectionFace();
    m_sprite.setPosition(m_firstLocation);
}

//--------------------------------------------------------------------------------------------
//������� �� ���
void Player::handleCollision(Money& money)
{
    m_sound.setBuffer((*ResourcesManage::instance().getPtrToMusic(moneySound_m)));
    m_sound.play();
    m_numOfMoney--;
    setScore( 2*m_controller.getLevelNum());
  
}

//--------------------------------------------------------------------------------------------
//���� �� ������ �������
void Player::setLocation(sf::Vector2f& location)
{
    m_sprite.setPosition(location);
    m_firstLocation = location;
}

//--------------------------------------------------------------------------------------------
//��� ����
void Player::setIsLadder(bool flag)
{
    m_isLadder = flag;
}

//--------------------------------------------------------------------------------------------
//���� ��� ��� �� �����
void Player::setMoney()
{
    m_numOfMoney++;
}

//--------------------------------------------------------------------------------------------
//���� �� ���� �������
void Player::restartMoney()
{
    m_numOfMoney = 0;
}

//--------------------------------------------------------------------------------------------
//���� �� ������ �� �����
void Player::startDirectionFace()
{
    m_sprite.setScale(1, 1);
    m_sprite.scale(0.3f, 0.3f);
    m_sprite.scale(0.95f, 0.95f);
}

//--------------------------------------------------------------------------------------------
//����
void Player::setLive(int live)
{
    m_live = live;
}
//--------------------------------------------------------------------------------------------
//����� ���
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
// ���� ��� ��� ����
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
//����� 1 ������
void Player::decreaseLive()
{
    m_live--;
}

//--------------------------------------------------------------------------------------------
//������� �� ����
void Player::handleCollision(Ladder& ladder)
{
    m_isLadder = true;
}

//--------------------------------------------------------------------------------------------
//������� �� ����
void Player::handleCollision(PresentMoreLive& gameObject)
{
    m_sound.setBuffer((*ResourcesManage::instance().getPtrToMusic(presentMusic_m)));
    m_sound.play();
    m_live++;
}

//--------------------------------------------------------------------------------------------
//������� �� ����
void Player::handleCollision(PresentMoreMonster& gameObject)
{
    m_sound.setBuffer((*ResourcesManage::instance().getPtrToMusic(presentMusic_m)));
    m_sound.play();
    m_controller.addMonster();

}

//--------------------------------------------------------------------------------------------
//������� �� ����
void Player::handleCollision(PresentMoreScore& gameObject)
{
    m_sound.setBuffer((*ResourcesManage::instance().getPtrToMusic(presentMusic_m)));
    m_sound.play();
    m_score+=20;

}

//--------------------------------------------------------------------------------------------
//������� �� ����
void Player::handleCollision(PresentMoreTime& gameObject)
{
    m_sound.setBuffer((*ResourcesManage::instance().getPtrToMusic(presentMusic_m)));
    m_sound.play();
    m_time += 10;
}



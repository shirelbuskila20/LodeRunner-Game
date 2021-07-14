#include "MonsterRandom.h"
//--------------------------------------------------------------------------------------------
//c-tor
MonsterRandom::MonsterRandom(const sf::Vector2f& location, int index) :Monster(location, index)
{
    m_direction =convertDirection(Direction_t(0));
}

//--------------------------------------------------------------------------------------------
//תזוזה של המפלצת הרנדומלית
void MonsterRandom::move(float deltaTime)
{

    m_prevPosition = m_sprite.getPosition();
    int switchDirection = ((rand() % 50));

    if ((deltaTime < switchDirection)
        && isCentered(m_sprite.getPosition(), getCenter(m_sprite.getPosition())))
    {
        m_direction = convertDirection(getRandDirection());
    }
    if (!outOfBoard())
    {
        m_sprite.move(m_direction * deltaTime * 60.f);
    }
    else
    {
        m_sprite.setPosition(getCenter(m_prevPosition));
    }

}


//--------------------------------------------------------------------------------------------
//טיפול בהתנגשויות
void MonsterRandom::handleCollision(Object& gameObject)
{
    if (&gameObject == this) return;
    gameObject.handleCollision(*this);
}

//--------------------------------------------------------------------------------------------
//טיפול אצל השחקן
void MonsterRandom::handleCollision(Player& player)
{
    player.handleCollision(*this);
}

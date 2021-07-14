#include "MonsterToPlayer.h"
//--------------------------------------------------------------------------------------------
//c-tor
MonsterToPlayer::MonsterToPlayer(const sf::Vector2f& location, int index, Player& player) :Monster(location, index),m_player(player)
{
	m_direction = convertDirection(Direction_t(0));
}

//--------------------------------------------------------------------------------------------
//תזוזה של המפלצת החכמה - שימוש במרחק מנהטן
void MonsterToPlayer::move(float deltaTime)
{
	m_prevPosition = m_sprite.getPosition();
	sf::Vector2f  destination, minDestination, a;
	float distanceFromPlayer1 = std::abs(m_player.getPosition().x - m_sprite.getPosition().x) + std::abs(m_player.getPosition().y - m_sprite.getPosition().y);


	for (int index = 0; index < 4; index++)
	{

		m_direction = convertDirection(Direction_t(index));
		destination = m_direction * deltaTime * 60.f + m_sprite.getPosition();
		auto distanceFromPlayer2 = (std::abs(m_player.getPosition().x - destination.x) + std::abs(m_player.getPosition().y - destination.y));
		if ((distanceFromPlayer2 < distanceFromPlayer1))
		{

			a = m_direction * deltaTime * 60.f;

		}
	}
	if (outOfBoard()||m_isWall)
	{
		m_sprite.setPosition(m_prevPosition);
		sf::Vector2f dire;
		dire = sf::Vector2f(m_direction.x * -1, m_direction.y * -1);

		m_direction = dire;
		a = m_direction * deltaTime * 60.f;
		
		m_isWall = false;
		
	}
	m_sprite.move(a);


}

//--------------------------------------------------------------------------------------------
//התנגשות עם קירות
void MonsterToPlayer::handleCollision(Wall& wall)
{
	m_isWall = true;
}

//--------------------------------------------------------------------------------------------
//טיפול בהתנגשות
void MonsterToPlayer::handleCollision(Object& gameObject)
{
	if (&gameObject == this) return;
	gameObject.handleCollision(*this);
}

//--------------------------------------------------------------------------------------------
//טיפול אצל השחקן
void MonsterToPlayer::handleCollision(Player& player)
{
	player.handleCollision(*this);
}


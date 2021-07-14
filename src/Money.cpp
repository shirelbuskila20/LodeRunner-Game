#include "Money.h"

//--------------------------------------------------------------------------------------------
//c-tor
Money::Money(const sf::Vector2f &location, int index) :StaticObject(location, index)
{
}

//--------------------------------------------------------------------------------------------
//����� �������
void Money::handleCollision(Object& gameObject)
{
	if (&gameObject == this) return;
	gameObject.handleCollision(*this);
}

//--------------------------------------------------------------------------------------------
//����� ��� �����
void Money::handleCollision(Player& player)
{
	m_isDisposed = true;
	player.handleCollision(*this);
}

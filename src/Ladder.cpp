#include "Ladder.h"
//--------------------------------------------------------------------------------------------
// c-tor
Ladder::Ladder(const sf::Vector2f& location, int index) :StaticObject(location, index)
{
}

//--------------------------------------------------------------------------------------------
//����� �������
void Ladder::handleCollision(Object& gameObject)
{
	if (&gameObject == this) return;
	//double dispatch
	gameObject.handleCollision(*this);
}

//--------------------------------------------------------------------------------------------
//����� ��� �����
void Ladder::handleCollision(Player& gameObject)
{
	gameObject.handleCollision(*this);
}


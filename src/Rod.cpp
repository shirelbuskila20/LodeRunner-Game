#include "Rod.h"
//--------------------------------------------------------------------------------------------
//c-tor
Rod::Rod(const sf::Vector2f& location, int index) :StaticObject(location, index)
{
}

//--------------------------------------------------------------------------------------------
//����� ����������
void Rod::handleCollision(Object& gameObject)
{
	if (&gameObject == this) return;
	//double dispatch
	gameObject.handleCollision(*this);
}
//--------------------------------------------------------------------------------------------
//����� ��� �����
void Rod::handleCollision(Player& player)
{
	player.handleCollision(*this);
}

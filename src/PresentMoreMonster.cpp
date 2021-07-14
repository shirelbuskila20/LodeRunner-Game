#include "PresentMoreMonster.h"
#include "Level.h"

//--------------------------------------------------------------------------------------------
//c-tor
PresentMoreMonster::PresentMoreMonster(const sf::Vector2f& location, int index)
	: Present(location, index)
{
}

//--------------------------------------------------------------------------------------------
//����� ����������
void PresentMoreMonster::handleCollision(Object& gameObject)
{
	if (&gameObject == this) return;
	gameObject.handleCollision(*this);
}

//--------------------------------------------------------------------------------------------
//����� ��� �����
void PresentMoreMonster::handleCollision(Player& player)
{
	m_isDisposed = true;
	player.handleCollision(*this);
}

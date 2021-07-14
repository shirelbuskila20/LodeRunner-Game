#include "PresentMoreTime.h"
//--------------------------------------------------------------------------------------------
//c-tor
PresentMoreTime::PresentMoreTime(const sf::Vector2f& location, int index): Present(location, index)
{
}

//--------------------------------------------------------------------------------------------
//����� ���������
void PresentMoreTime::handleCollision(Object& gameObject)
{
	if (&gameObject == this) return;
	gameObject.handleCollision(*this);
}

//--------------------------------------------------------------------------------------------
//����� ��� �����
void PresentMoreTime::handleCollision(Player& player)
{
	m_isDisposed = true;
	player.handleCollision(*this);
}

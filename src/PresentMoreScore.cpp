#include "PresentMoreScore.h"
//--------------------------------------------------------------------------------------------
//c-tor
PresentMoreScore::PresentMoreScore(const sf::Vector2f& location, int index)
	: Present(location, index)
{
}

//--------------------------------------------------------------------------------------------
//����� ����������
void PresentMoreScore::handleCollision(Object& gameObject)
{
	if (&gameObject == this) return;
	gameObject.handleCollision(*this);
}

//--------------------------------------------------------------------------------------------
//����� ��� �����
void PresentMoreScore::handleCollision(Player& player)
{
	m_isDisposed = true;
	player.handleCollision(*this);
}

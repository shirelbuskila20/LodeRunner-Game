#include "MonsterConstMove.h"
//--------------------------------------------------------------------------------------------
//c-tor
MonsterConstMove::MonsterConstMove(const sf::Vector2f& location, int index) :Monster(location, index)
{
}

//--------------------------------------------------------------------------------------------
//����� �� ����� ������
void MonsterConstMove::move(float deltaTime)
{
	if (outOfBoard())
	{
		m_dir = 0 - m_dir;
	}
	m_sprite.move(m_dir * deltaTime, 0);
}

//--------------------------------------------------------------------------------------------
//������� ����
void MonsterConstMove::handleCollision(Wall& wall)
{
	m_dir = 0 - m_dir;
}

//--------------------------------------------------------------------------------------------
//����� ����������
void MonsterConstMove::handleCollision(Object& gameObject)
{
	if (&gameObject == this) return;
	gameObject.handleCollision(*this);
}

//--------------------------------------------------------------------------------------------
//������� ����� ��� �����
void MonsterConstMove::handleCollision(Player& player)
{
	player.handleCollision(*this);
}

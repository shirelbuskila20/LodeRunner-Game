#include "Monster.h"
//--------------------------------------------------------------------------------------------
//c-tor
Monster::Monster(const sf::Vector2f& location, int index):DynamicObject(location,index)
{
	m_sprite.scale(0.95f, 0.95f);
	m_rect.setPosition(m_location);
}

//--------------------------------------------------------------------------------------------
//d-tor
Monster::~Monster()
{
}

//--------------------------------------------------------------------------------------------
//מחזיר כיוון רנדומלי
Direction_t Monster::getRandDirection()
{
	Direction_t arr[] = { LEFT,RIGHT,UP,DOWN };
	return arr[rand() % 4];
}

//--------------------------------------------------------------------------------------------
//ממיר לוקטור 2f
sf::Vector2f Monster::convertDirection(Direction_t dir)
{
	switch (dir)
	{
	case RIGHT:
		return sf::Vector2f(1, 0);
		break;
	case LEFT:
		return sf::Vector2f(-1, 0);
		break;
	case UP:
		return sf::Vector2f(0, -1);
		break;
	case DOWN:
		return sf::Vector2f(0, 1);
		break;
	case STAY:
		return sf::Vector2f(0, 0);
		break;
	}
}

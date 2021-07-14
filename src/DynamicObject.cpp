#include"DynamicObject.h"
//--------------------------------------------------------------------------------------------
// c-tor
DynamicObject::DynamicObject(const sf::Vector2f& location, int index) :Object(location, index)
{
}
//--------------------------------------------------------------------------------------------
// d-tor
DynamicObject::~DynamicObject()
{
}

//--------------------------------------------------------------------------------------------
//בדיקה אם יצא מגבולות המסך
bool DynamicObject::outOfBoard()
{
		return m_sprite.getPosition().x > WINDOW_WIDTH || m_sprite.getPosition().y> BOARD_HEIGHT ||
			m_sprite.getPosition().x < 0 || m_sprite.getPosition().y < 0;
}



bool DynamicObject::isCentered(sf::Vector2f pos, sf::Vector2f center)
{
	return abs(pos.x - center.x) < 5 && abs(pos.y - center.y) < 5;
}
sf::Vector2f DynamicObject::getCenter(sf::Vector2f pos)
{
	sf::Vector2f newPos;
	newPos.x = (pos.x - ((int)pos.x % 32)) + 32 / 2;
	newPos.y = (pos.y - ((int)pos.y % 32)) + 32 / 2;
	return newPos;
}


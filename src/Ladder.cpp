#include "Ladder.h"
//--------------------------------------------------------------------------------------------
// c-tor
Ladder::Ladder(const sf::Vector2f& location, int index) :StaticObject(location, index)
{
}

//--------------------------------------------------------------------------------------------
//בדיקת התנגשות
void Ladder::handleCollision(Object& gameObject)
{
	if (&gameObject == this) return;
	//double dispatch
	gameObject.handleCollision(*this);
}

//--------------------------------------------------------------------------------------------
//טיפול אצל השחקן
void Ladder::handleCollision(Player& gameObject)
{
	gameObject.handleCollision(*this);
}


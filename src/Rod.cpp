#include "Rod.h"
//--------------------------------------------------------------------------------------------
//c-tor
Rod::Rod(const sf::Vector2f& location, int index) :StaticObject(location, index)
{
}

//--------------------------------------------------------------------------------------------
//טיפול בהתנגשויות
void Rod::handleCollision(Object& gameObject)
{
	if (&gameObject == this) return;
	//double dispatch
	gameObject.handleCollision(*this);
}
//--------------------------------------------------------------------------------------------
//טיפול אצל השחקן
void Rod::handleCollision(Player& player)
{
	player.handleCollision(*this);
}

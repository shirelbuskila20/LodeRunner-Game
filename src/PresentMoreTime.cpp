#include "PresentMoreTime.h"
//--------------------------------------------------------------------------------------------
//c-tor
PresentMoreTime::PresentMoreTime(const sf::Vector2f& location, int index): Present(location, index)
{
}

//--------------------------------------------------------------------------------------------
//טיפול בהתנגשיות
void PresentMoreTime::handleCollision(Object& gameObject)
{
	if (&gameObject == this) return;
	gameObject.handleCollision(*this);
}

//--------------------------------------------------------------------------------------------
//טיפול אצל השחקן
void PresentMoreTime::handleCollision(Player& player)
{
	m_isDisposed = true;
	player.handleCollision(*this);
}

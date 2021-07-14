#include "PresentMoreLive.h"
//--------------------------------------------------------------------------------------------
//c-tor
PresentMoreLive::PresentMoreLive(const sf::Vector2f& location, int index)
	: Present(location, index)
{
}

//--------------------------------------------------------------------------------------------
//טיפול בהתנגשיות 
void PresentMoreLive::handleCollision(Object& gameObject)
{
	if (&gameObject == this) return;
	gameObject.handleCollision(*this);
}

//--------------------------------------------------------------------------------------------
//טיפול אצל השחקן
void PresentMoreLive::handleCollision(Player& player)
{
	m_isDisposed = true;
	player.handleCollision(*this);
}

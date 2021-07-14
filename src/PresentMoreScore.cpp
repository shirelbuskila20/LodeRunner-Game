#include "PresentMoreScore.h"
//--------------------------------------------------------------------------------------------
//c-tor
PresentMoreScore::PresentMoreScore(const sf::Vector2f& location, int index)
	: Present(location, index)
{
}

//--------------------------------------------------------------------------------------------
//טיפול בהתנגשויות
void PresentMoreScore::handleCollision(Object& gameObject)
{
	if (&gameObject == this) return;
	gameObject.handleCollision(*this);
}

//--------------------------------------------------------------------------------------------
//טיפול אצל השחקן
void PresentMoreScore::handleCollision(Player& player)
{
	m_isDisposed = true;
	player.handleCollision(*this);
}

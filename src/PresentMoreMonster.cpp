#include "PresentMoreMonster.h"
#include "Level.h"

//--------------------------------------------------------------------------------------------
//c-tor
PresentMoreMonster::PresentMoreMonster(const sf::Vector2f& location, int index)
	: Present(location, index)
{
}

//--------------------------------------------------------------------------------------------
//טיפול בהתנגשויות
void PresentMoreMonster::handleCollision(Object& gameObject)
{
	if (&gameObject == this) return;
	gameObject.handleCollision(*this);
}

//--------------------------------------------------------------------------------------------
//טיפול אצל השחקן
void PresentMoreMonster::handleCollision(Player& player)
{
	m_isDisposed = true;
	player.handleCollision(*this);
}

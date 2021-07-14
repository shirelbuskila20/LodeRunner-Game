#include "Object.h"
#include "Monster.h"
#include "Wall.h"
#include "Player.h"
#include "Ladder.h"
#include "Rod.h"
#include "Money.h"
#include "Present.h"

//--------------------------------------------------------------------------------------------
//c-tor
Object::Object(const sf::Vector2f &location, int index):m_location(location), m_sprite(), m_index (index), m_rect({IMG_WIDTH,IMG_HEIGHT})
{
	m_sprite.setTexture((*ResourcesManage::instance().getPtrToTexture(index)));
	m_sprite.setPosition(m_location);
	m_sprite.scale(0.3f,0.3f);

}

//--------------------------------------------------------------------------------------------
//d-tor
Object::~Object()
{
}

//--------------------------------------------------------------------------------------------
//פונקציה שמדפיסה את האוביקט
void Object::drawOnWindow(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}

//--------------------------------------------------------------------------------------------
//בדיקת התנגשות - הצלבה בין 2 אוביקטים
bool Object::checkCollision(const sf::FloatRect& floatRect) const
{
	
		sf::FloatRect rect = m_sprite.getGlobalBounds();
		rect.height -= 2;
		rect.left += 2;
		rect.top += 2;
		rect.width -= 2;


		return rect.intersects(floatRect);
	
}

//--------------------------------------------------------------------------------------------
//מחזיר גבולות של המלבן
sf::FloatRect Object::getGlobalBounds() const
{
	return m_sprite.getGlobalBounds();
}

//--------------------------------------------------------------------------------------------
//מחזיר אם צריך למחוק
bool Object:: isDisposed() const
{
	return m_isDisposed;
}
#pragma once
#include "Object.h"

class DynamicObject : public Object
{
public:
	DynamicObject(const sf::Vector2f& location, int index);
	 virtual ~DynamicObject()=0;
	virtual void move(float deltaTime) =0;
	virtual void handleCollision(Object& gameObject) = 0;
	virtual void handleCollision(PresentMoreLive& gameObject) = 0;
	virtual void handleCollision(PresentMoreMonster& gameObject) = 0;
	virtual void handleCollision(PresentMoreScore& gameObject) = 0;
	virtual void handleCollision(PresentMoreTime& gameObject) = 0;
	virtual void handleCollision(Wall& gameObject) = 0;
	virtual void handleCollision(MonsterConstMove& gameObject) = 0;
	virtual void handleCollision(MonsterRandom& gameObject) = 0;
	virtual void handleCollision(MonsterToPlayer& gameObject) = 0;
	virtual void handleCollision(Player& gameObject) = 0;
	virtual void handleCollision(Ladder& gameObject) = 0;
	virtual void handleCollision(Money& gameObject) = 0;
	virtual void handleCollision(Rod& gameObject) = 0;
	bool isCentered(sf::Vector2f pos, sf::Vector2f center);
	sf::Vector2f getCenter(sf::Vector2f pos);
	bool outOfBoard();

protected:
	sf::Vector2f m_startPosition;
	sf::Vector2f m_prevPosition;
	sf::Vector2f m_position;




};

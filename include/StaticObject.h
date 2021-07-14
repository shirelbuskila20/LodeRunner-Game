#pragma once
#include "Object.h"
#include <SFML/Graphics.hpp>
#include "Utilities.h"
#include "ResourcesManage.h"

class StaticObject : public Object
{
public:
	StaticObject(const sf::Vector2f &location, int index);
	virtual ~StaticObject()= 0;
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




protected:
	
};


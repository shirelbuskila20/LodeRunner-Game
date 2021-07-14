#pragma once
#include"StaticObject.h"
class Present : public StaticObject
{
public:
	Present(const sf::Vector2f& location, int index);
	virtual ~Present() = 0;
	virtual void handleCollision(Object& gameObject) =0;
	virtual void handleCollision(PresentMoreLive& gameObject)=0;
	virtual void handleCollision(PresentMoreMonster& gameObject)=0;
	virtual void handleCollision(PresentMoreScore& gameObject) =0;
	virtual void handleCollision(PresentMoreTime& gameObject) =0;
	virtual void handleCollision(Wall& gameObject) = 0;
	virtual void handleCollision(MonsterConstMove& gameObject) = 0;
	virtual void handleCollision(MonsterRandom & gameObject) = 0;
	virtual void handleCollision(MonsterToPlayer& gameObject) = 0;
	virtual void handleCollision(Player& gameObject) = 0;
	virtual void handleCollision(Ladder& gameObject) = 0;
	virtual void handleCollision(Money& gameObject) = 0;
	virtual void handleCollision(Rod& gameObject) = 0;




protected:

};

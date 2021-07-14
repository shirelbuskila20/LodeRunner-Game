#pragma once
#include "Monster.h"
#include "Wall.h"
class MonsterRandom : public Monster
{
public:
	MonsterRandom(const sf::Vector2f& location, int index);
	~MonsterRandom()=default;
	virtual void move(float deltaTime);
	virtual void handleCollision(Object& gameObject)override;
	virtual void handleCollision(Wall& gameObject)override {};
	virtual void handleCollision(MonsterConstMove& gameObject) override {}
	virtual void handleCollision(MonsterRandom& gameObject) override {}
	virtual void handleCollision(MonsterToPlayer& gameObject)override {}
	virtual void handleCollision(Player& gameObject) override;
	virtual void handleCollision(Ladder& gameObject) override {}
	virtual void handleCollision(Money& gameObject)override {}
	virtual void handleCollision(Rod& gameObject)override {}
	virtual void handleCollision(PresentMoreLive& gameObject) override {}
	virtual void handleCollision(PresentMoreMonster& gameObject) override {}
	virtual void handleCollision(PresentMoreScore& gameObject) override {}
	virtual void handleCollision(PresentMoreTime& gameObject)override {}
protected:
	float m_time = 0;
};

#pragma once
#include "Monster.h"
#include "Player.h"
#include "Utilities.h"
#include "Wall.h"
class MonsterToPlayer : public Monster
{
public:
	MonsterToPlayer(const sf::Vector2f& location, int index,  Player& player);
	~MonsterToPlayer()=default;
	virtual void move(float deltaTime);
	virtual void handleCollision(Object& gameObject)override;
	virtual void handleCollision(Wall& gameObject)override;
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
	Player& m_player;
	Direction_t m_wantedDirection;
	int m_index1;
};


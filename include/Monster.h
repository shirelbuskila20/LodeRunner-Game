#pragma once
#include "DynamicObject.h"
#include"ResourcesManage.h"
#include "Utilities.h"
#include <iostream>
#include "Player.h"


class Monster : public DynamicObject
{
public:
	Monster(const sf::Vector2f& location, int index);
	virtual ~Monster()=0;
	virtual void move(float deltaTime)=0;
    Direction_t getRandDirection();
    sf::Vector2f convertDirection(Direction_t dir);
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
    sf::Vector2f m_direction;
    sf::Vector2f m_newDirection;
    bool m_isWall = false;
};


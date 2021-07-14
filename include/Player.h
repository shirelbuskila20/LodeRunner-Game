#pragma once
#include "DynamicObject.h"
#include"ResourcesManage.h"
#include "Utilities.h"
#include <SFML/Graphics.hpp>

class Controller;
class Player : public DynamicObject
{
public:
	Player(Controller& controller);//(const sf::Vector2f& location, int index);
	~Player()=default;
	void setDirection(sf::Keyboard::Key key);
	virtual void move(float deltaTime)override;
	sf::Vector2f getPosition()const;
	enum Direction { RIGHT, DOWN, LEFT, UP, STAY };
	int getLivePlayer() const;
	int getMoneyLeft() const;
	int getScore() const;
	void setScore(int i);
	virtual void handleCollision(Object& gameObject)override;
	virtual void handleCollision(Wall& gameObject)override;
	virtual void handleCollision(MonsterConstMove& gameObject) override;
	virtual void handleCollision(MonsterRandom& gameObject) override;
	virtual void handleCollision(MonsterToPlayer& gameObject)override;
	virtual void handleCollision(Player& gameObject) override {}
	virtual void handleCollision(Ladder& gameObject) override;
	virtual void handleCollision(Money& gameObject)override;
	virtual void handleCollision(Rod& gameObject)override {}
	virtual void handleCollision(PresentMoreLive& gameObject) override;
	virtual void handleCollision(PresentMoreMonster& gameObject) override;
	virtual void handleCollision(PresentMoreScore& gameObject) override;
	virtual void handleCollision(PresentMoreTime& gameObject)override;
	void setLocation(sf::Vector2f& location);
	void setIsLadder(bool flag);
	void setMoney();
	void restartMoney();
	void startDirectionFace();
	void setLive(int live);
	int getTime()const;
	void setTime(int time);
	void setTimeLeft(sf::Clock& clock);
	void decreaseLive();


protected:
	sf::Vector2f m_firstLocation;
	Direction m_direction = Direction::STAY;
	Controller& m_controller;
	int m_live;
	int m_numOfMoney;
	int m_score ;
	bool m_isLadder = false;
	int m_time;
	int m_leftTime;
	sf::Sound m_sound;

};


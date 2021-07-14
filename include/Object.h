#pragma once
#include <SFML/Graphics.hpp>
#include "ResourcesManage.h"
#include "Utilities.h"
class Player;
class Rod;
class Ladder;
class Money;
class Present;
class PresentMoreLive;
class PresentMoreMonster;
class PresentMoreScore;
class PresentMoreTime;
class Wall;
class Monster;
class MonsterConstMove;
class MonsterRandom;
class MonsterToPlayer;
class Object
{
public:
	Object(const sf::Vector2f& location, int index);
	virtual ~Object() = 0;
	virtual void drawOnWindow(sf::RenderWindow& window);
	bool checkCollision(const sf::FloatRect& floatRect) const;
	virtual void handleCollision(Object& gameObject)=0;
	virtual void handleCollision(Wall& gameObject)=0;
	virtual void handleCollision(MonsterConstMove& gameObject) =0;
	virtual void handleCollision(MonsterRandom& gameObject) =0;
	virtual void handleCollision(MonsterToPlayer& gameObject) =0;
	virtual void handleCollision(Player& gameObject)=0;
	virtual void handleCollision(Ladder& gameObject)=0;
	virtual void handleCollision(Money& gameObject) =0;
	virtual void handleCollision(Rod& gameObject) =0;
	virtual void handleCollision(PresentMoreLive& gameObject) =0;
	virtual void handleCollision(PresentMoreMonster& gameObject) =0;
	virtual void handleCollision(PresentMoreScore& gameObject) =0;
	virtual void handleCollision(PresentMoreTime& gameObject)=0;


	sf::FloatRect getGlobalBounds() const;
	
	bool isDisposed() const;

protected:
	sf::Vector2f m_location;
	sf::Sprite m_sprite;
	int m_index;
	sf::RectangleShape m_rect;
	bool m_isDisposed = false;
};


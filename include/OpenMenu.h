#pragma once
#include "ResourcesManage.h"
#include "Controller.h"
#include "Utilities.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
class OpenMenu
{
public:
	OpenMenu();
	~OpenMenu()=default;
	void run();


private:
	sf::Sprite m_sprite;
	Controller m_controller;
	void menu(sf::RenderWindow& window);
	//void mapToGame(sf::RenderWindow& window);
	Buttons getMenuButton(sf::Vector2f buttonPos);
	sf::Sound m_sound;
};

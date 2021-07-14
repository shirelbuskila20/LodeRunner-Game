#include "GameMenu.h"
//--------------------------------------------------------------------------------------------
// c-tor
GameMenu::GameMenu(Player& player)
	:m_player(player)
{
//רקע
	m_menu.setTexture((*ResourcesManage::instance().getPtrToTexture(menu_b)));
	m_menu.setPosition({0,BOARD_HEIGHT});
//פונט
	m_font = (*ResourcesManage::instance().getFont());
}

//--------------------------------------------------------------------------------------------
// הלוח מדפיסה על החלון
void GameMenu::drawOnScreen(sf::RenderWindow& window,int levelNumber,int time)
{
	playerLive();
	playerScore();
	levelTime(time);
	levelNum(levelNumber);
	window.draw(m_menu);
	window.draw(m_liveText);
	window.draw(m_moneyText);
	window.draw(m_timeText);
	window.draw(m_levelText);
	window.draw(m_playerSprite);
	window.draw(m_moneySprite);
	window.draw(m_timeSprite);
}

//--------------------------------------------------------------------------------------------
// הפונקציה מטפלת בחיי השחקן
void GameMenu::playerLive()
{
	
	m_liveText.setFont(m_font);
	m_liveText.setPosition({ 205,BOARD_HEIGHT + 45 });
	m_liveText.setString(std::to_string(m_player.getLivePlayer()));
	m_liveText.setCharacterSize(40.f);
	m_playerSprite.setTexture((*ResourcesManage::instance().getPtrToTexture(player_b)));
	m_playerSprite.setPosition({ 130,BOARD_HEIGHT + 30 });
	m_playerSprite.setScale(0.3f, 0.3f);
}

//--------------------------------------------------------------------------------------------
//הפונקציה מטפלת בנקודות השחקן
void GameMenu::playerScore()
{

	m_moneyText.setFont(m_font);
	m_moneyText.setPosition({ 405,BOARD_HEIGHT + 45 });
	m_moneyText.setString(std::to_string(m_player.getScore()));//
	m_moneyText.setCharacterSize(40.f);
	m_moneySprite.setTexture((*ResourcesManage::instance().getPtrToTexture(money_b)));
	m_moneySprite.setPosition({ 330,BOARD_HEIGHT + 20 });
	m_moneySprite.setScale(0.3f, 0.3f);
}

//--------------------------------------------------------------------------------------------
// הפונקציה מטפלת בזמן השלב
void GameMenu::levelTime(int time)
{

	m_timeText.setPosition({ 605,BOARD_HEIGHT + 45 });
	m_timeText.setCharacterSize(40.f);

	m_timeSprite.setTexture((*ResourcesManage::instance().getPtrToTexture(clock_b)));
	m_timeSprite.setPosition({ 530,BOARD_HEIGHT + 30 });
	m_timeSprite.setScale(0.3f, 0.3f);


	auto color = sf::Color();
	if (time / 60 >= 10 && time % 60 >= 10)
		m_timeText = sf::Text(std::to_string(time / 60) + ":" + std::to_string(time % 60),m_font);
	else if (time / 60 < 10 && time % 60 >= 10)
		m_timeText = sf::Text(std::to_string(0) + std::to_string(time / 60) + ":" + std::to_string(time % 60),m_font);
	else if (time / 60 >= 10 && time % 60 < 10)
		m_timeText = sf::Text(std::to_string(time / 60) + ":" + std::to_string(0) + std::to_string(time % 60),m_font);
	else
		m_timeText = sf::Text(std::to_string(0) + std::to_string(time / 60) + ":" + std::to_string(0) + std::to_string(time % 60),m_font);
	if (time % 60 <= 5 && time / 60 < 1)
		color = sf::Color::Red;
	else
		color = sf::Color::White;
	m_timeText.setPosition({ 605,BOARD_HEIGHT + 45 });
	m_timeText.setCharacterSize(40.f);
	m_timeText.setColor(color);


}

//--------------------------------------------------------------------------------------------
// הפונקציה מטפלת במספר השלב
void GameMenu::levelNum(int levelNumber)
{
	m_levelText.setFont(m_font);
	m_levelText.setPosition({ 805,BOARD_HEIGHT + 40});
	m_levelText.setString(("LEVEL: "+ std::to_string(levelNumber)));
	m_levelText.setCharacterSize(50.f);
}

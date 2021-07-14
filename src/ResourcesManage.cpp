#include "ResourcesManage.h"
//--------------------------------------------------------------------------------------------
//c-tor
ResourcesManage::ResourcesManage()
{
	insertImgsToVector();
	insertMusicToVector();
	m_font.loadFromFile("C:/Windows/Fonts/Impact.ttf");
	m_music_Background.openFromFile("playGame.wav");
}

//--------------------------------------------------------------------------------------------
//singleton
ResourcesManage& ResourcesManage::instance()
{
	static ResourcesManage inst;
	return inst;
}

//--------------------------------------------------------------------------------------------
//מחזיר מצביע למיקום
sf::Texture* ResourcesManage::getPtrToTexture(const int index)
{
	return m_imgs[index].get();
}

//--------------------------------------------------------------------------------------------
//מחזיר מצביע למיקום
sf::SoundBuffer* ResourcesManage::getPtrToMusic(const int index)
{
	return m_music[index].get();
}

//--------------------------------------------------------------------------------------------
//הכנסה לוקטור תמונות
void ResourcesManage::insertImgsToVector()
{
	for (int i = 0; i < NUM_OF_OBJECTS; i++)
		m_imgs.push_back(std::make_unique<sf::Texture>());

	m_imgs[0]->loadFromFile("OpenScreen.png");
	m_imgs[1]->loadFromFile("menu.png");
	m_imgs[2]->loadFromFile("Win.png");
	m_imgs[3]->loadFromFile("GameOver.png");
	m_imgs[4]->loadFromFile("player.png");
	m_imgs[5]->loadFromFile("monsterConstMove.png");
	m_imgs[6]->loadFromFile("monsterRandom.png");
	m_imgs[7]->loadFromFile("monsterToPlayer.png");
	m_imgs[8]->loadFromFile("money.png");
	m_imgs[9]->loadFromFile("wall.jpg");
	m_imgs[10]->loadFromFile("ladder.png");
	m_imgs[11]->loadFromFile("rod.png");
	m_imgs[12]->loadFromFile("present.png");
	m_imgs[13]->loadFromFile("clock.png");
}

//--------------------------------------------------------------------------------------------
//הכנסה לוקטור מוזיקה
void ResourcesManage::insertMusicToVector()
{
	for (int i = 0; i < NUM_OF_MUSIC; i++)
		m_music.push_back(std::make_unique<sf::SoundBuffer>());

	m_music[0]->loadFromFile("gameOverMusic.wav");
	m_music[1]->loadFromFile("moneySound.wav");
	m_music[2]->loadFromFile("monsterToPlayer.wav");
	m_music[3]->loadFromFile("winMusic.wav");
	m_music[4]->loadFromFile("presentMusic.wav");
}

//--------------------------------------------------------------------------------------------
//מחזיר פונט
sf::Font* ResourcesManage::getFont()
{
	return &m_font;
}

//--------------------------------------------------------------------------------------------
//מחזיר מנגינת רקע
sf::Music* ResourcesManage::getMusic()
{
	return &m_music_Background;
}




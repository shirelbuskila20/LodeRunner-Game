#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <SFML/Audio.hpp>
#include "Utilities.h"
using std::unique_ptr;
class ResourcesManage
{
public:

	~ResourcesManage() = default;
	static ResourcesManage& instance();
	sf::Font* getFont();
	sf::Music* getMusic();
	sf::Texture* getPtrToTexture(const int index);
	sf::SoundBuffer* getPtrToMusic(const int index);
	void insertImgsToVector();
	void insertMusicToVector();


private:
	ResourcesManage();
	ResourcesManage(const ResourcesManage&)=default;
	std::vector<unique_ptr<sf::Texture>> m_imgs;
	std::vector<unique_ptr<sf::SoundBuffer>> m_music;
	sf::Music m_music_Background;
	sf::Font m_font;

};


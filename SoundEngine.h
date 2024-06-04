#pragma once
#include <SFML/Audio.hpp>

class SoundEngine
{
private:
	sf::SoundBuffer m_clickBuffer;
	sf::Sound m_clickSound;
public:
	SoundEngine();
	static void playClick();
	static SoundEngine* m_s_soundEngineInstance;
};

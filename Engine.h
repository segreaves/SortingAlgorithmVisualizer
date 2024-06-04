#pragma once
#include <SFML/Graphics.hpp>
#include "InputHandler.h"
#include "SoundEngine.h"
#include "ScreenManager.h"
#include "SortManager.h"

class Engine
{
private:
	sf::RenderWindow m_window;
	sf::Vector2f m_resolution;

	ScreenManager m_screenManager;
	InputHandler m_inputHandler;
	SortManager m_sortManager;
	SoundEngine m_soundEngine;

	void handleInput();
	void draw();
public:
	Engine();
	void run();
};

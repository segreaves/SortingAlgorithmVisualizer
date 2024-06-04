#include "Engine.h"

Engine::Engine()
{
	m_resolution.x = sf::VideoMode::getDesktopMode().width;
	m_resolution.y = sf::VideoMode::getDesktopMode().height;
	m_window.create(sf::VideoMode(m_resolution.x, m_resolution.y), "Sorting Algorithm Visualizer", sf::Style::Fullscreen);

	m_screenManager.initialize(&m_window, sf::Vector2i(m_resolution.x, m_resolution.y));
	m_sortManager.setScreenManager(&m_screenManager);
	m_inputHandler.initialize(&m_screenManager, &m_sortManager);
}

void Engine::run()
{
	while (m_window.isOpen())
	{
		handleInput();
		draw();
	}
}

void Engine::draw()
{
	m_window.clear(sf::Color::Black);
	m_screenManager.draw(m_sortManager.getValues());
	m_window.display();
}

void Engine::handleInput()
{
	m_inputHandler.handleInput(m_window);
}

#include "InputHandler.h"
#include "SoundEngine.h"

void InputHandler::initialize(ScreenManager* screenManager, SortManager* sortManager)
{
	m_screenManager = screenManager;
	m_buttons = m_screenManager->getButtons();
	m_sortManager = sortManager;
	m_sortManager->setSorter(SortAlgorithm::quicksort);
}

void InputHandler::handleInput(sf::RenderWindow& window)
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::KeyPressed:
			handleKeyPress(event, window);
			break;
		case sf::Event::MouseButtonReleased:
			handleMouseButtonRelease(window);
			break;
		}
	}
}

void InputHandler::handleKeyPress(sf::Event& event, sf::RenderWindow& window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
}

void InputHandler::handleMouseButtonRelease(sf::RenderWindow& window)
{
	for (auto i = m_buttons.begin(),
		end = m_buttons.end(); i != end; i++)
	{
		if ((*i)->m_collider.contains(window.mapPixelToCoords(sf::Mouse::getPosition(), m_screenManager->m_selectPanelView)))
		{
			handleLeftClick((*i)->m_text, window);
			break;
		}
	}
}

void InputHandler::handleLeftClick(std::string& buttonInteractedWith, sf::RenderWindow& window)
{
	SoundEngine::playClick();
	if (buttonInteractedWith == "Sort") m_sortManager->sort();
	if (buttonInteractedWith == "Shuffle") m_sortManager->generateRandomValues();
	if (buttonInteractedWith == "Bubble Sort") m_sortManager->setSorter(SortAlgorithm::bubblesort);
	if (buttonInteractedWith == "Quicksort") m_sortManager->setSorter(SortAlgorithm::quicksort);
	if (buttonInteractedWith == "Insertion Sort") m_sortManager->setSorter(SortAlgorithm::insertionsort);
	if (buttonInteractedWith == "Merge Sort") m_sortManager->setSorter(SortAlgorithm::mergesort);
	if (buttonInteractedWith == "Exit") window.close();
}

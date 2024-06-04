#pragma once
#include "ScreenManager.h"
#include "SortManager.h"

class InputHandler
{
private:
	ScreenManager* m_screenManager;
	SortManager* m_sortManager;
	std::vector<std::shared_ptr<Button>> m_buttons;
	sf::View* m_selectPanelView;
public:
	void initialize(ScreenManager* screenManager, SortManager* sortManager);
	void handleInput(sf::RenderWindow& window);
	void handleKeyPress(sf::Event& event, sf::RenderWindow& window);
	void handleMouseButtonRelease(sf::RenderWindow& window);
	void handleLeftClick(std::string& buttonInteractedWith, sf::RenderWindow& window);
};

#pragma once
#include <SFML/Graphics.hpp>
#include "Sorter.h"
#include "SortElement.h"
#include "Button.h"

class ScreenManager
{
private:
	sf::RenderWindow* m_window;
	sf::RectangleShape m_sortPanel;
	sf::RectangleShape m_selectPanel;
	sf::Font m_font;
	sf::Text m_text;

	float m_drawWidth = 0;
	float m_drawHeight = 0;
	float m_buttonWidth = 0;
	float m_buttonHeight = 0;
	float m_buttonPadding = 0;

	std::vector<std::shared_ptr<Button>> m_buttons;

	void initializeSelectButtons();
	void addButton(float x, float y, int width, int height, sf::Color color, std::string label);
public:
	sf::View m_selectPanelView;
	sf::View m_sortPanelView;

	void initialize(sf::RenderWindow* window, sf::Vector2i res);
	void initializeSelectPanel(sf::Vector2i res, float x, float y, float width, float height, sf::Color color);
	void initializeSortPanel(sf::Vector2i res, float x, float y, float width, float height, sf::Color color);

	std::vector<std::shared_ptr<Button>> getButtons();
	void drawSortPanel(std::vector<SortElement> values);
	void drawSelectPanel();
	void clearWindow();
	void draw(std::vector<SortElement> values);
	void display();
};

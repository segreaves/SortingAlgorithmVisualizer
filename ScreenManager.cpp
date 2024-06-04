#include "ScreenManager.h"

void ScreenManager::initialize(sf::RenderWindow* window, sf::Vector2i res)
{
	m_window = window;

	float xDivision = 0.3f * res.x;
	float marginWidth = xDivision * 0.05;

	initializeSelectPanel(
		sf::Vector2i(res.x, res.y),// res
		marginWidth,// x
		marginWidth,// y
		xDivision - 2 * marginWidth,// width
		res.y - 2 * marginWidth,// height
		sf::Color(255, 255, 255, 50)// color
	);

	initializeSortPanel(
		sf::Vector2i(res.x, res.y),// res
		xDivision + marginWidth,// x
		marginWidth,// y
		res.x - xDivision - 2 * marginWidth,// width
		res.y - 2 * marginWidth,// height
		sf::Color(255, 255, 255, 25)// color
	);
}

void ScreenManager::initializeSelectPanel(sf::Vector2i res, float x, float y, float width, float height, sf::Color color)
{
	m_selectPanel.setFillColor(color);
	m_selectPanel.setSize(sf::Vector2f(width, height));
	m_selectPanelView.setSize(sf::Vector2f(width, height));
	m_selectPanelView.setCenter(width / 2, height / 2);

	float viewportStartX = 1.f / (res.x / x);
	float viewportStartY = 1.f / (res.y / y);
	float viewportSizeX = 1.f / (res.x / width);
	float viewportSizeY = 1.f / (res.y / height);

	m_selectPanelView.setViewport(
		sf::FloatRect(
			viewportStartX,
			viewportStartY,
			viewportSizeX,
			viewportSizeY
		)
	);

	m_buttonWidth = res.x / 20;
	m_buttonHeight = res.y / 20;
	m_buttonPadding = res.x / 100;

	m_text.setFillColor(sf::Color::White);
	m_text.setString("Select sorting algorithm:");
	m_font.loadFromFile("fonts/game_over.ttf");
	m_text.setFont(m_font);
	m_text.setPosition(sf::Vector2f(m_buttonPadding, m_buttonHeight));
	m_text.setCharacterSize(100);
	initializeSelectButtons();
}

void ScreenManager::initializeSortPanel(sf::Vector2i res, float x, float y, float width, float height, sf::Color color)
{
	srand((int)time(0));// for the random shuffle in generateRandomValues()
	m_sortPanel.setFillColor(color);
	m_sortPanel.setSize(sf::Vector2f(width, height));
	m_sortPanelView.setSize(sf::Vector2f(width, height));
	m_sortPanelView.setCenter(width / 2, height / 2);

	float viewportStartX = 1.f / (res.x / x);
	float viewportStartY = 1.f / (res.y / y);
	float viewportSizeX = 1.f / (res.x / width);
	float viewportSizeY = 1.f / (res.y / height);

	m_sortPanelView.setViewport(
		sf::FloatRect(
			viewportStartX,
			viewportStartY,
			viewportSizeX,
			viewportSizeY
		)
	);

	m_drawWidth = width;
	m_drawHeight = height;
}

std::vector<std::shared_ptr<Button>> ScreenManager::getButtons()
{
	return m_buttons;
}

void ScreenManager::addButton(float x, float y, int width, int height, sf::Color color, std::string label)
{
	m_buttons.push_back(std::make_shared<Button>(sf::Vector2f(x, y), width, height, color, label));
}

void ScreenManager::clearWindow()
{
	m_window->clear();
}

void ScreenManager::draw(std::vector<SortElement> values)
{
	drawSelectPanel();
	drawSortPanel(values);
}

void ScreenManager::display()
{
	m_window->display();
}

void ScreenManager::drawSelectPanel()
{
	m_window->setView(m_selectPanelView);
	m_window->draw(m_selectPanel);
	m_window->draw(m_text);
	for (auto it = m_buttons.begin(), end = m_buttons.end(); it != end; it++)
	{
		(*it)->draw(m_window);
	}
}

void ScreenManager::initializeSelectButtons()
{
	addButton(m_buttonPadding, m_buttonPadding, m_buttonWidth, m_buttonHeight, sf::Color(127, 127, 127), "Sort");
	addButton(m_buttonWidth + 2 * m_buttonPadding, m_buttonPadding, m_buttonWidth, m_buttonHeight, sf::Color(127, 127, 127), "Shuffle");
	addButton(3 * m_buttonWidth + 3 * m_buttonPadding, m_buttonPadding, m_buttonWidth, m_buttonHeight, sf::Color(127, 127, 127), "Exit");
	addButton(m_buttonPadding, (m_buttonHeight + m_buttonPadding) * 3, m_buttonWidth, m_buttonHeight, sf::Color(127, 127, 127), "Bubble Sort");
	addButton(m_buttonPadding, (m_buttonHeight + m_buttonPadding) * 4, m_buttonWidth, m_buttonHeight, sf::Color(127, 127, 127), "Quicksort");
}

void ScreenManager::drawSortPanel(std::vector<SortElement> values)
{
	// this method functions under the assumption that all input vectors will be of the type 1:values.size()
	m_window->setView(m_sortPanelView);
	m_window->draw(m_sortPanel);

	int vectorSize = values.size();
	float barWidth = m_drawWidth / vectorSize;
	float barWidthMinus1Pixel = barWidth - 1.f;
	float unitBarHeight = m_drawHeight / vectorSize;
	for (int i = 0; i < vectorSize; i++)
	{
		sf::Vector2f position = sf::Vector2f(i * barWidth, m_drawHeight - values[i].getValue() * unitBarHeight);
		sf::Vector2f size = sf::Vector2f(barWidthMinus1Pixel, values[i].getValue() * unitBarHeight);
		sf::RectangleShape rectangle = sf::RectangleShape();
		rectangle.setSize(size);
		rectangle.setPosition(position);
		rectangle.setFillColor(values[i].isHighlighted() ? sf::Color::Red : sf::Color::White);
		m_window->draw(rectangle);
	}
}

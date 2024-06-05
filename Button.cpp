#include "Button.h"

Button::Button(sf::Vector2f position, float width, float height, sf::Color color, std::string text)
{
	m_button.setPosition(position);
	m_button.setFillColor(color);
	m_button.setSize(sf::Vector2f(width, height));

	m_text = "" + text;

	float textPaddingX = width / 10;
	float textPaddingY = height / 10;

	m_buttonText.setCharacterSize(height * .25f);
	m_buttonText.setString(m_text);
	m_font.loadFromFile("fonts/DroidSans.ttf");
	m_buttonText.setFont(m_font);
	m_buttonText.setPosition(sf::Vector2f(position.x + textPaddingX, position.y + textPaddingY));

	m_collider = sf::FloatRect(position, sf::Vector2f(width, height));
}

void Button::draw(sf::RenderWindow* window)
{
	window->draw(m_button);
	window->draw(m_buttonText);
}

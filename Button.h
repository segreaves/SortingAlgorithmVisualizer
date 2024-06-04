#pragma once
#include <SFML/Graphics.hpp>

class Button
{
private:
	sf::RectangleShape m_button;
	sf::Text m_buttonText;
	sf::Font m_font;
public:
	std::string m_text;
	sf::FloatRect m_collider;

	Button(sf::Vector2f position, float width, float height, sf::Color color, std::string text);
	
	void draw(sf::RenderWindow* window);
};

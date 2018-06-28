//
// EPITECH PROJECT, 2018
//
// File description:
//
//

#include "graphics.hpp"

void Graphics::drawText(const std::string &font_name, const std::string &line,
				   const size_t &size, const sf::Color &outlineColor,
				   const sf::Color &textColor, const sf::Vector2f &position)
{
	sf::Text text;
	std::unique_ptr<sf::Font> &font = this->getFont(font_name);

	text.setFont(*font);
	text.setString(line);
	text.setCharacterSize(size);
	text.setOutlineThickness(2);
	text.setOutlineColor(outlineColor);
	text.setFillColor(textColor);
	text.setPosition(position);

	this->window.draw(text);
}
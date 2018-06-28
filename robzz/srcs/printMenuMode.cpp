//
// EPITECH PROJECT, 2018
//
// File description:
//
//

#include "graphics.hpp"

void Graphics::printMenu()
{
	this->window.draw(this->rectangle);
	this->drawText("lato", this->prompt, 20, sf::Color::Black,
			sf::Color::White, sf::Vector2f(10, 10));
	this->displayLs();
}
//
// EPITECH PROJECT, 2018
//
// File description:
//
//

#include "graphics.hpp"

void Graphics::createWindow()
{
	this->openWindow();
	this->addFont("lato", "lato.ttf");
	this->rectangle.setSize(sf::Vector2f(790, 50));
	this->rectangle.setPosition(sf::Vector2f(5, 5));
	this->rectangle.setOutlineThickness(5);
	this->rectangle.setOutlineColor(sf::Color::Blue);
}
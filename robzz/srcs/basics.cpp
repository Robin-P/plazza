//
// EPITECH PROJECT, 2018
//
// File description:
//
//

#include "graphics.hpp"

Graphics::Graphics()
{
	this->mod = MENU;
}

Graphics::~Graphics()
{
	this->closeWindow();
}

void Graphics::closeWindow()
{
	this->window.close();
}

void Graphics::openWindow()
{
	this->window.create(sf::VideoMode(800, 600), "Sfml");
	this->window.setFramerateLimit(25);
}
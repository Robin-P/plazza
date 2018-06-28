//
// EPITECH PROJECT, 2018
//
// File description:
//
//

#include "graphics.hpp"

void Graphics::eventKeyPressed(sf::Event event)
{
	if (event.key.code == sf::Keyboard::BackSpace &&
	    this->prompt.size() > 0) {
		this->prompt.erase(this->prompt.size() - 1);
	}
	else if (event.key.code == sf::Keyboard::Return)
		this->prompt.clear();
	else if (event.key.code == sf::Keyboard::Escape)
		this->closeWindow();
	else if (event.key.code == sf::Keyboard::Tab) {
		this->mod = (this->mod == Graphics::mode::MENU ?
					 Graphics::mode::GAME : Graphics::mode::MENU);
	}
}

void Graphics::eventTextEntered(sf::Event event)
{
	if (event.text.unicode > 32 && event.text.unicode < 128 &&
			 this->mod == Graphics::MENU && this->prompt.size() < 49) {
		this->prompt.push_back(static_cast<char>(event.text.unicode));
	}
}

void Graphics::getEvent(sf::Event &event)
{
	if (event.type == sf::Event::Closed)
		this->closeWindow();
	else if (event.type == sf::Event::KeyPressed)
		this->eventKeyPressed(event);
	else if (event.type == sf::Event::TextEntered)
		this->eventTextEntered(event);
}
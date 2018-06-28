//
// EPITECH PROJECT, 2018
//
// File description:
//
//

#include "graphics.hpp"

void Graphics::addFont(const std::string &key, const std::string &maccro)
{
	std::unique_ptr<sf::Font> font = std::make_unique<sf::Font>();

	font->loadFromFile(maccro);
	fonts[key] = std::move(font);
}

std::unique_ptr<sf::Font> &Graphics::getFont(const std::string &name)
{
	if (this->fonts.find(name) == this->fonts.end())
		throw std::logic_error("SFML font error");
	return this->fonts[name];
}
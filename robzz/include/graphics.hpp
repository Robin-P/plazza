//
// EPITECH PROJECT, 2018
//
// File description:
//
//

#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP

#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <memory>
#include <algorithm>
#include <iostream>
#include <sys/stat.h>
#include <cstring>

class Graphics {
public :
	Graphics();

	~Graphics();

	enum mode {
		MENU, GAME, NONE
	};

	void openWindow();
	void createWindow();
	void closeWindow();
	void displayLs();
	void getEvent(sf::Event &event);
	void eventKeyPressed(sf::Event event);
	void eventTextEntered(sf::Event event);
	void printMenu();
	std::vector<std::string> ls();
	std::unique_ptr<sf::Font> &getFont(const std::string &name);
	void addFont(const std::string &key, const std::string &path);
	void drawText(const std::string &font_name, const std::string &line,
				  const size_t &size, const sf::Color &outlineColor,
				  const sf::Color &textColor, const sf::Vector2f &position);
	std::map<const std::string, std::unique_ptr<sf::Font>> fonts;
	std::string prompt;
	sf::RenderWindow window;
	sf::RectangleShape rectangle;
	sf::CircleShape circle;
	mode mod;
	FILE *file;
};

#endif //GRAPHICS_HPP
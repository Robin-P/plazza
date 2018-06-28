//
// EPITECH PROJECT, 2018
//
// File description:
//
//

#include "graphics.hpp"

int main()
{
	Graphics graphic;

	graphic.createWindow();
	while (graphic.window.isOpen()) {
		sf::Event event{};
		while (graphic.window.pollEvent(event)) {
			graphic.getEvent(event);
		}
		if (graphic.mod == Graphics::MENU)
			graphic.printMenu();
		graphic.window.display();
		graphic.window.clear();
	}
	return (0);
}

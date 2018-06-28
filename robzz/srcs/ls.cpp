//
// EPITECH PROJECT, 2018
//
// File description:
//
//

#include "graphics.hpp"

void Graphics::displayLs()
{
	struct stat buf{};
	std::size_t y = 100, x = 30, max = 0;
	std::vector<std::string> files = this->ls();
	sf::Color color;

	for (auto &file : files) {
		max = 0;
		if (file.size() > max)
			max = file.size();
		stat(file.c_str(), &buf);
		if (S_ISDIR(buf.st_mode))
			color = sf::Color::Cyan;
		else if (buf.st_mode & S_IXUSR)
			color = sf::Color::Green;
		else
			color = sf::Color::White;
		this->drawText("lato", file, 20, sf::Color::Black, color, sf::Vector2f(x, y));
		y += 30;
		if (y > this->window.getSize().y) {
			y = 100;
			x += 10 + (10 * max);
		}
	}
}

std::vector<std::string> Graphics::ls()
{
	std::vector<std::string> result;
	char path[1024];

	this->file = popen("ls", "r");
	if (this->file == nullptr)
		return result;
	while (fgets(path, sizeof(path) - 1, this->file) != nullptr)
		result.emplace_back(strtok(path, "\n"));
	pclose(file);
	return result;
}
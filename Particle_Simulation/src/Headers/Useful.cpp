#include "Useful.hpp"
#include <iostream>

void setupfps(sf::Text* fpsText) {
	fpsText->setFont(_arial);
	fpsText->setFillColor(sf::Color::Red);
	fpsText->setCharacterSize(24);
}
void fps(sf::Text* fpsText, sf::Clock* clock, unsigned int* Frame)
{
	if (clock->getElapsedTime().asSeconds() >= 1.f)
	{
		int FPS = *Frame;
		*Frame = 0;
		clock->restart();

		fpsText->setString("FPS: " + std::to_string(FPS));
	}
	++ *Frame;
	_window->draw(*fpsText);
}

void setupWindow()
{
	_window->setPosition(_window->getPosition() - sf::Vector2i(0, 50));
	_window->setVerticalSyncEnabled(true);

	_windowSize = sf::Vector2f(_window->getSize());
	_arial.loadFromFile("C:/Windows/Fonts/arial.ttf");
}

void hideConsole()
{
	ShowWindow(GetConsoleWindow(), SW_HIDE);
}

void showConsole()
{
	ShowWindow(GetConsoleWindow(), SW_SHOW);
}

float getMagnitude(sf::Vector2f v)
{
	return std::sqrtf((v.x * v.x) + (v.y * v.y));
}

int rand50()
{
	// rand() function will generate odd or even
	// number with equal probability. If rand()
	// generates odd number, the function will
	// return 1 else it will return 0.
	return rand() & 1;
}
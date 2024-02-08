#pragma once
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include "Common.hpp"

// Set up FPS display
void setupfps(sf::Text* fpsText);
// Updates the fps text and frame number
void fps(sf::Text* fpsText, sf::Clock* clock, unsigned int* Frame);
// Setup Window
void setupWindow();
void hideConsole();
void showConsole();
// Get the length/magnitude of a vector
float getMagnitude(sf::Vector2f v);
// Generate 1 or 0
int rand50();


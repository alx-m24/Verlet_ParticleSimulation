#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <thread>
#include "Useful.hpp"
#include "Common.hpp"
#include "Particles.hpp"

class Cell {
public:
	Cell() = default;

	std::vector<int> particleIdx;
	int particleCount = 0;
};

class Grid {
private:
	void addParticle(sf::Vector2f pos, unsigned int idx);
public:
	Grid();

	unsigned int cellWidth, cellHeight, maxParticles = 4;
	sf::Vector2i cellNum;
	std::vector<std::vector<Cell*>> grid;

	void clear();
	void reset();
	void checkCollision();
};

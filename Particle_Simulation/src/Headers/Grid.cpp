#include "Grid.hpp"

Grid::Grid()
{
	cellWidth = _radius * 2;
	cellHeight = _radius * 2;


	cellNum = sf::Vector2i(_windowSize.x / cellWidth, _windowSize.y / cellHeight);
	
	grid.resize(cellNum.x);
	for (int i = 0; i < cellNum.x; ++i) {
		grid[i].resize(cellNum.y);
		for (int j = 0; j < cellNum.y; ++j) {
			grid[i][j] = new Cell();
		}
	}
}

void Grid::addParticle(sf::Vector2f pos, unsigned int idx)
{
	int col = pos.x / cellWidth, row = pos.y / cellHeight;

	if (grid[col][row]->particleCount <= maxParticles) {
		grid[col][row]->particleIdx.push_back(idx);
		grid[col][row]->particleCount += 1;
	}
}


void Grid::clear()
{
	for (std::vector<Cell*> cols : grid) {
		for (Cell* c : cols) {
			c->particleCount = 0;
		}
	}
}

void Grid::reset()
{
	clear();

	for (int i = 0; i < particles->size(); ++i) {
		addParticle((*particles)[i]->m_pos, i);
	}
}

void Grid::checkCollision()
{
	int collisions = 0;
	for (std::vector<Cell*> cols : grid) {
		for (Cell* c : cols) {
			
			if (c->particleCount > 1) {
				++collisions;
				std::cout << "Collision: " << collisions << std::endl;
			}
		}
	}

}

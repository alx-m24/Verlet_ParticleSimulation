#pragma once
#include "Common.hpp"
#include "Particles.hpp"
#include "Grid.hpp"

class Physics {
public:
	Physics();

	void updatePhysics(float dt);
	bool inBounds(Particle* p);
	Grid* grid;
};
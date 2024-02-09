#include "Physics.hpp"

Physics::Physics()
{
	grid = new Grid();
}

void Physics::updatePhysics(float dt)
{
	float sub_dt = dt / substeps;

	for (int j = 0; j < substeps; ++j) {
		grid->reset();
		grid->checkCollision();
		for (Particle* p : *particles) {

			p->physicsUpdate(sub_dt, _windowSize);
		}
	}
}

bool Physics::inBounds(Particle* p)
{
	return (p->m_pos.x > _radius && p->m_pos.y > _radius) && (p->m_pos.x < _windowSize.x - _radius && p->m_pos.y < _windowSize.y - _radius);
}

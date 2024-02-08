#include "Physics.hpp"

void updatePhysics(float dt)
{
	float sub_dt = dt / substeps;

	for (Particle* p : *particles) {
		for (int j = 0; j < substeps; ++j) {
			p->physicsUpdate(sub_dt, _windowSize);
		}
	}
}

bool inBounds(Particle* p)
{
	return (p->m_pos.x > _radius && p->m_pos.y > _radius) && (p->m_pos.x < _windowSize.x - _radius && p->m_pos.y < _windowSize.y - _radius);
}
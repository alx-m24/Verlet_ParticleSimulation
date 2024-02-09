#include "Particles.hpp"

void Particle::physicsUpdate(float dt, sf::Vector2f windowSize)
{
	wallCollision(windowSize);

	//m_acc = G + (m_force / m_mass);
	m_acc = { 0, 0 };

	// Verlet Integration
	const sf::Vector2f tempPos = m_pos;
	m_pos = m_pos + m_v + m_acc * dt * dt;
	m_prevPos = tempPos;

	m_v = m_pos - m_prevPos;

	m_force = { 0, 0 };
}

void Particle::wallCollision(sf::Vector2f _windowSize)
{
	if (m_pos.x < m_radius) {
		m_pos.x = m_radius;
		m_v.x *= -1.0f;
	}
	else if (m_pos.x > _windowSize.x - m_radius) {
		m_pos.x = _windowSize.x - m_radius;
		m_v.x *= -1.0f;
	}
	if (m_pos.y < m_radius) {
		m_pos.y = m_radius;
		m_v.y *= -1.0f;
	}
	else if (m_pos.y > _windowSize.y - m_radius) {
		m_v.y *= -1.0f;
	}
}

float Particle::getSpeed()
{
	return std::sqrtf((m_v.x * m_v.x) + (m_v.y * m_v.y));
}

float Particle::getEnergy()
{
	return 0.5f * m_mass * (getSpeed() * getSpeed());
}

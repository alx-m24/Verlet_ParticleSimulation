#pragma once
#include <SFML/Graphics.hpp>

class Particle {
public:
	Particle() = default;
	Particle(sf::Vector2f position, sf::Color Color, float r) : m_pos(position), m_prevPos(position), m_color(Color), m_radius(r) {};

	sf::Vector2f m_pos, m_force = sf::Vector2f(0, 0), m_v;
	sf::Color m_color;
	float m_mass = 10.0f, m_radius;

	void physicsUpdate(float dt, sf::Vector2f windowSize);
	void wallCollision(sf::Vector2f _windowSize);
	// Return the kinetic energy of the particle
	float getSpeed();
	float getEnergy();
private:
	sf::Vector2f m_prevPos, m_acc, G = sf::Vector2f(0, 200);
	const float m_friction = 2.0f;
};
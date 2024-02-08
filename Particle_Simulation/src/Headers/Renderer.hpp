#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "Common.hpp"
#include "Physics.hpp"

class Renderer {
public:
	Renderer() = default;
	Renderer(unsigned int particleCount);

	void update(float dt);
	void draw();
private:
	void loadTexture();

	sf::Texture m_particleTex;
	sf::Vector2f m_TexSize;
	sf::VertexArray m_displayParticles;
	std::vector<Particle*> m_particles;
};
#include "Renderer.hpp"

Renderer::Renderer(unsigned int particleCount)
{
	loadTexture();

	m_displayParticles.setPrimitiveType(sf::PrimitiveType::Quads);

	unsigned int count = 0;

	for (int i = 0; i < particleCount; ++i) {
		sf::Vector2f pos = sf::Vector2f(rand() % (int)_windowSize.x, rand() % (int)_windowSize.y);
		
		Particle* newParticle = new Particle(pos, sf::Color::Red, _radius);
		if (!inBounds(newParticle)) {
			delete newParticle;
			continue;
		}

		m_particles.push_back(newParticle);
		++count;
	}

	m_displayParticles.resize(count * 4);

	particles = &m_particles;
}

void Renderer::loadTexture()
{
	m_particleTex.loadFromFile("C:\\Users\\alexa\\OneDrive\\Coding\\C++\\Particle_Simulation\\Particle_Simulation\\Resources\\circle.png");
	m_particleTex.setSmooth(true);

	m_TexSize = sf::Vector2f(m_particleTex.getSize());
}

void Renderer::update(float dt)
{
	// -- Debugging -- //
	float T_Energy = 0;

	updatePhysics(dt);

	int count = m_particles.size();

	m_displayParticles.resize(count * 4);

	for (int i = 0; i < count; ++i) {
		Particle* curr = m_particles[i];
		
		if (!inBounds(curr)) continue;

		// -- Debugging -- //
		T_Energy += curr->getEnergy();

		int idx = i << 2;

		sf::Vector2f pos = curr->m_pos;
		m_displayParticles[idx + 0].position = pos + sf::Vector2f(-_radius, -_radius);
		m_displayParticles[idx + 1].position = pos + sf::Vector2f(-_radius, _radius);
		m_displayParticles[idx + 2].position = pos + sf::Vector2f(_radius, _radius);
		m_displayParticles[idx + 3].position = pos + sf::Vector2f(_radius, -_radius);

		sf::Color color = curr->m_color;
		m_displayParticles[idx + 0].color = color;
		m_displayParticles[idx + 1].color = color;
		m_displayParticles[idx + 2].color = color;
		m_displayParticles[idx + 3].color = color;

		m_displayParticles[idx + 0].texCoords = { 0, 0 };
		m_displayParticles[idx + 1].texCoords = { m_TexSize.x, 0 };
		m_displayParticles[idx + 2].texCoords = { m_TexSize.x, m_TexSize.y };
		m_displayParticles[idx + 3].texCoords = { 0, m_TexSize.y };
	}
	// -- Debugging -- //
	std::cout << "Total Energy in the system: " << T_Energy << std::endl;
}

void Renderer::draw()
{
	_window->draw(m_displayParticles, &m_particleTex);
}

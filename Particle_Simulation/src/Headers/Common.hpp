#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Particles.hpp"

extern sf::RenderWindow* _window;
extern sf::Vector2f _windowSize;
extern sf::Font _arial;
extern sf::Vector2i _mousePos;
// Particle radius
extern float _radius;
// Particle mass
extern float _mass;
// Particles
extern std::vector<Particle*>* particles;
// Number of substeps
extern unsigned int substeps;
// SFML
#include <SFML/Graphics.hpp>
// Other
#include <iostream>
#include <thread>
// My headers
#include "Headers/MainLoop.hpp"
#include "Headers/Common.hpp"
#include "Headers/Useful.hpp"
#include "Headers/Particles.hpp"
#include "Headers/Renderer.hpp"

sf::RenderWindow* _window;
sf::Vector2f _windowSize;
sf::Font _arial;
sf::Vector2i _mousePos;
// Particle radius
float _radius = 5.0f;
// Particle mass
float _mass = 10.0f;
// Pointer to particles
std::vector<Particle*>* particles;
// Frequency of simulation/number of substeps per frame
unsigned int substeps = 4;

int main() {
	// window settings
	sf::ContextSettings settings;
	settings.antialiasingLevel = 4;

	// creating window
	sf::RenderWindow Mainwindow(sf::VideoMode(800, 600), "Particle Simulation", sf::Style::Default, settings);
	_window = &Mainwindow;
	setupWindow();
	hideConsole();

	// Getting random seed
	srand(time(0));

	// my main loop class
	Loop loop;

	// Renderer
	Renderer renderer(10);

	sf::Text fpsText;
	setupfps(&fpsText);

	sf::Clock FPSclock, clock;
	unsigned int Frame = 0;
	// main loop
	while (Mainwindow.isOpen())
	{
		// processing inputs
		loop.Input();

		// updating window
		loop.Update();
		renderer.update(clock.restart().asSeconds());

		// rendering all objects
		//g.draw();
		fps(&fpsText, &FPSclock, &Frame);
		renderer.draw();
		loop.Render();
	}
	return 0;
}

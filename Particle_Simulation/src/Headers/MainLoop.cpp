#include "MainLoop.hpp"

void Loop::Input() {
	sf::Event event;
	// processing sfml events
	while (_window->pollEvent(event)) {
		switch (event.type) {
		case sf::Event::Closed: {
			_window->close();
			break;
		}
		case sf::Event::MouseMoved: {
			_mousePos = sf::Mouse::getPosition(*_window);
			break;
		}
		case sf::Event::Resized: {
			sf::View view = sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height));
			_window->setView(view);
			_windowSize = sf::Vector2f(_window->getSize());
			break;
		}
		default:
			break;
		}
	}
}

void Loop::Update()
{
	_window->clear(sf::Color::Black);
}

void Loop::Render()
{
	_window->display();
}
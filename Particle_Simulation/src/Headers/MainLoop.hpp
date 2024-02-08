#pragma once
#include <SFML/Graphics.hpp>
#include "Common.hpp"
#include "Renderer.hpp"

class Loop {
private:
public:
	// contruct
	Loop() = default;

	void Input();
	void Update();
	void Render();
};
#pragma once
#include "SFML\Graphics.hpp"

class Background
{
public:
	// Constructors //
	Background(std::string file, sf::RenderWindow & wnd);

	// Public Functions //
	void Draw(sf::RenderWindow & wnd) const;
	void Update(sf::RenderWindow & wnd, sf::Vector2f ship_position);
private:
	// Private Objects //
	sf::Sprite background;
	sf::Texture backgroundtexture;

	// Private Variables //
	double rotation = 0;

	// Private Vectors //
	sf::Vector2f pos;
};
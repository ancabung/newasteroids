#pragma once
#include "Ship.h"
#include "Laser.h"
#include "Asteroid.h"
#include "SFML\Graphics.hpp"

class Game
{
public:
	// Constructors //
	Game();

	// Public Functions //
	void UpdateGame(sf::RenderWindow & wnd); // updates, then draws to screen
	sf::Vector2f getShipPosition();

private:
	//Private Variables
	static constexpr int laser_amount = 20;
	static constexpr int asteroid_amount = 10;
	int current_laser = 0;

	// Private Objects //
	Ship ship;
	FrameTimer ft;
	Laser laser[laser_amount];
	Asteroid asteroid[asteroid_amount];

	// Private Functions //
	void UpdateModel(sf::RenderWindow & wnd); // update screen models
	void DrawModel(sf::RenderWindow & wnd); // draw them to screen

	// Asteroid Functions //
	void UpdateAsteroids(sf::RenderWindow & wnd, float & dt);
	void DrawAsteroids(sf::RenderWindow & wnd);

	// Laser Functions //
	void CycleLasers(); 
	void UpdateLasers(sf::RenderWindow & wnd, float dt);
	void DrawLasers(sf::RenderWindow & wnd);

		// Collision Functions //
	void HandleCollisionForLasersOnAsteroids();
	bool areColliding(sf::Sprite & sprite0, sf::Sprite & sprite1);

	sf::Font		m_font;
	sf::Text		m_text;
};
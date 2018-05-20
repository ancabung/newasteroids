#pragma once
#include <SFML\Graphics.hpp>
#include <memory>

class LaserTextureCodex // TODO: Fix so lasers don't overload
{
public:
	// Constructors //
	LaserTextureCodex();

	// Public Functions //
	sf::Texture* getTexture();
private:
	// Private Functions //
	void loadFiles();

	// Private Objects //
	sf::Texture laser_texture;
};

class Laser
{
public:
	// Constructors //
	Laser();

	// Public Functions //
	void Update(sf::RenderWindow & wnd, float dt);
	void ShootFrom(sf::Sprite sprite, sf::RenderWindow & wnd);
	sf::Sprite * getSprite();

	//Public Variables
	bool isShot = false;

private:
	//Private Objects
	sf::Sprite laser_sprite;
	LaserTextureCodex ltc;

	//Private Functions
	void init();
	void setTexture();
	void keepInBounds(sf::RenderWindow & wnd);

	//Private Variables
	float direction;
	const float speed = 650.0f;
	float deltatime = 0.0f;

	//Private Vectors
	sf::Vector2f pos;
	sf::Vector2f vel;

	//Private Vector Functions
	sf::Vector2f DegreesToNormalVector(float degrees);

	//Vector Variables
	double radianconverter = 0.0174533;
};
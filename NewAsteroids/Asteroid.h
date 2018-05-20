#pragma once
#include <SFML\Graphics.hpp>
#include <random>

class Asteroid
{
public:
	Asteroid();

	//Public Functions
	void Update(sf::RenderWindow & wnd, float dt);
	sf::Sprite * getSprite();

	//Public Variables
	bool isDestroyed = false;

private:
	enum class Type
	{
		Tiny,
		Small,
		Medium,
		Big,
		Huge,
		Count
	};
	//Private Objects
	sf::Sprite asteroid_sprite;
	sf::Texture asteroid_texture;

	//Random Number Generation
	std::random_device rd;
	std::mt19937 rng;
	std::uniform_real_distribution<float> xDist;
	std::uniform_real_distribution<float> yDist;
	std::uniform_real_distribution<float> xVelDist;
	std::uniform_real_distribution<float> yVelDist;
	std::uniform_int_distribution<int> typeDist;
	std::uniform_int_distribution<int> textureDist;

	//Private Vectors
	sf::Vector2f pos;
	sf::Vector2f vel;

	//Priavte Functions
	void setSizeAccordingToType();
	void setTextureAccordingToRNG();
	void KeepOnScreen(sf::RenderWindow & wnd);
	void wrapX(sf::RenderWindow & wnd);
	void wrapY(sf::RenderWindow & wnd);

	//Private Variables
	float speed = 15.0f;
	const int type; // keep constant if not changing sizes
	const int textureNum; // keep constant, decides which texture number upon initialization

};
#pragma once
#include <SFML\Graphics.hpp>
#include "FrameTimer.h"
#include "Laser.h"

class Ship
{
public:
	//Constructors
	Ship(float x, float y);
	
	//Update
	void Update(sf::RenderWindow & wnd, float dt, Laser & laser);

	//Get Functions
	sf::Sprite *getSprite();
	sf::Texture *getTexture();

private:
	//Private Functions
	void init();

	void LoadFiles();
	void SetTexture();

	void HandleLasers(Laser & laser, sf::RenderWindow & wnd);
	void HandleInput(Laser & laser, sf::RenderWindow & wnd);
	void HandleThrusters();
	void HandleMovement(sf::RenderWindow & wnd);
	void RegulateSpeed();

	void wrapScreen(sf::RenderWindow & wnd);
	void wrapX(sf::RenderWindow & wnd);
	void wrapY(sf::RenderWindow & wnd);

	//Private Objects
	sf::Sprite ship_sprite;
	sf::Texture ship_texture;
	FrameTimer ft;

	//Private Variables
	float rotateamount = 200.0f; // degrees/second
	float speed = 5.0f;
	float speedlimit = 40.0f;
	float deltatime = 0.0f;
	float time = 0.0f;
	float laserwaittime = 0.25f;

	//Private Vectors
	sf::Vector2f pos;
	sf::Vector2f vel;

	//Vector Functions
	sf::Vector2f DegreesToNormalVector(float degrees);

	//Vector Variables
	double radianconverter = 0.0174533;
};
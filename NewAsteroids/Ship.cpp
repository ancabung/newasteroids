#include "Ship.h"
#include <iostream>

// Constructors //

Ship::Ship(float x, float y)
	:
	pos(x,y)
{
	init();
}

void Ship::init()
{
	LoadFiles(); // opens and sets ship_texture to texture
	SetTexture(); // has to come after load files, sets origin/scale + stuff
}

// Public Functions //

void Ship::Update(sf::RenderWindow & wnd, float dt, Laser & laser)
{
	deltatime = dt; // mark time here
	time += dt;
	HandleInput(laser,wnd);
	HandleMovement(wnd);
	ship_sprite.setPosition(pos.x, pos.y);
}

sf::Texture* Ship::getTexture()
{
	return &ship_texture;
}

sf::Sprite* Ship::getSprite()
{
	return &ship_sprite;
}

// Private Functions //

void Ship::LoadFiles()
{
	if (!ship_texture.loadFromFile("../textures/PNG/playerShip2_red.png"))
	{
		printf("Ship Texture Failure.\n");
	}
}

void Ship::SetTexture()
{
	ship_sprite.setTexture(ship_texture);
	ship_sprite.setScale(0.6f,0.6f);
	ship_sprite.setOrigin((float)ship_texture.getSize().x/2,(float)ship_texture.getSize().y/2);
}

sf::Vector2f Ship::DegreesToNormalVector(float degrees)
{
	// offset by 90 degrees (3.1415/2) to compensate for ship texture orientation
	return sf::Vector2f(cos(float((double(degrees)*radianconverter) - 3.1415 / 2)), sin(float((double(degrees)*radianconverter) - 3.1415 / 2)));
}

// Handle Functions //

void Ship::HandleLasers(Laser & laser, sf::RenderWindow & wnd)
{
	if (!laser.isShot)
	{
		if (time >= laserwaittime)
		{
			laser.ShootFrom(ship_sprite, wnd);
			time = 0.0f;
		} 
	}
}

void Ship::HandleInput(Laser & laser, sf::RenderWindow & wnd)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		HandleLasers(laser,wnd);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		HandleThrusters();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		ship_sprite.rotate(rotateamount*deltatime);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		ship_sprite.rotate(-(rotateamount*deltatime));
	}
}

void Ship::HandleThrusters()
{
	float direction = ship_sprite.getRotation();
	vel += DegreesToNormalVector(direction)*speed*deltatime;
	RegulateSpeed();
}

void Ship::HandleMovement(sf::RenderWindow & wnd)
{
	pos += vel;
	vel *= 0.99f;
	wrapScreen(wnd);
}

void Ship::RegulateSpeed()
{
	if (vel.x > speedlimit)
	{
		vel.x = speedlimit;
	}
	else if (vel.x < -speedlimit)
	{
		vel.x = speedlimit;
	}

	if (vel.y > speedlimit)
	{
		vel.y = speedlimit;
	}
	else if (vel.y < -speedlimit)
	{
		vel.y = speedlimit;
	}
}

void Ship::wrapScreen(sf::RenderWindow & wnd)
{
	wrapX(wnd);
	wrapY(wnd);
}

void Ship::wrapX(sf::RenderWindow & wnd)
{
	if (ship_sprite.getPosition().x-ship_texture.getSize().x/2 > wnd.getSize().x) // right
	{
		pos.x = 0.0f-ship_texture.getSize().x / 2;
	}

	if (ship_sprite.getPosition().x + ship_texture.getSize().x / 2 < 0.0f) // left
	{
		pos.x = float(wnd.getSize().x + ship_texture.getSize().x / 2);
	}
}

void Ship::wrapY(sf::RenderWindow & wnd)
{
	if (ship_sprite.getPosition().y - ship_texture.getSize().y / 2 > wnd.getSize().y) // bottom
	{
		pos.y = 0.0f - ship_texture.getSize().y / 2;
	}

	if (ship_sprite.getPosition().y + ship_texture.getSize().y / 2 < 0.0f) // top
	{
		pos.y = float(wnd.getSize().y + ship_texture.getSize().y / 2);
	}
}

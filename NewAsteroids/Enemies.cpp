#include "Asteroid.h"


// Constructors //

Asteroid::Asteroid() //TODO: Finish random generation of asteroid position and velocity 
	:
	rng(rd()),
	xDist(0.0f, 1280.0f),
	yDist(0.0f, 720.0f),
	xVelDist(-10.0f, 10.0f),
	yVelDist(-10.0f, 10.0f),
	typeDist(0, 4), // number of types - 2 (starts from 0)
	textureDist(1,8),
	pos(xDist(rng),yDist(rng)),
	vel(xVelDist(rng),yVelDist(rng)),
	type(typeDist(rng)),
	textureNum(textureDist(rng))
{
	setTextureAccordingToRNG();
	setSizeAccordingToType();
}

// Public Functions //

void Asteroid::Update(sf::RenderWindow & wnd, float dt)
{
	if (!isDestroyed)
	{
		KeepOnScreen(wnd);
		pos += vel*dt*speed;
		asteroid_sprite.setPosition(pos);
	}
}

sf::Sprite * Asteroid::getSprite()
{
	return &asteroid_sprite;
}

// Randomizing Functions //

void Asteroid::setSizeAccordingToType()
{
	switch (type)
	{
	case 0:
		asteroid_sprite.setScale(0.25f, 0.25f);
		break;
	case 2:
		asteroid_sprite.setScale(0.50f, 0.50f);
		break;
	case 3:
		asteroid_sprite.setScale(0.75f, 0.75f);
		break;
	case 4:
		asteroid_sprite.setScale(1.0f, 1.0f);
		break;
	}
}

void Asteroid::setTextureAccordingToRNG()
{
	switch (textureNum)
	{
	case 1:
		if (!asteroid_texture.loadFromFile("../textures/PNG/Enemies/enemyBlack1.png"))
		{
			printf("Asteroid Texture 1 Loading Error\n");
		}
		else printf("Asteroid Texture 1 Loading Success\n");		
		break;
	case 2:
		if (!asteroid_texture.loadFromFile("../textures/PNG/Enemies/enemyBlack2.png"))
		{
			printf("Asteroid Texture 2 Loading Error\n");
		}
		else printf("Asteroid Texture 2 Loading Success\n");
		break;
	case 3:
		if (!asteroid_texture.loadFromFile("../textures/PNG/Effects/star3.png"))
		{
			printf("Asteroid Texture 3 Loading Error\n");
		}
		else printf("Asteroid Texture 3 Loading Success\n");
		break;
	case 4:
		if (!asteroid_texture.loadFromFile("../textures/PNG/Meteors/meteorBrown_big4.png"))
		{
			printf("Asteroid Texture 4 Loading Error\n");
		}
		else printf("Asteroid Texture 4 Loading Success\n");
		break;
	case 5:
		if (!asteroid_texture.loadFromFile("../textures/PNG/Meteors/meteorGrey_big1.png"))
		{
			printf("Asteroid Texture 5 Loading Error\n");
		}
		else printf("Asteroid Texture 5 Loading Success\n");
		break;
	case 6:
		if (!asteroid_texture.loadFromFile("../textures/PNG/Meteors/meteorGrey_big2.png"))
		{
			printf("Asteroid Texture 6 Loading Error\n");
		}
		else printf("Asteroid Texture 6 Loading Success\n");
		break;
	case 7:
		if (!asteroid_texture.loadFromFile("../textures/PNG/Meteors/meteorGrey_big3.png"))
		{
			printf("Asteroid Texture 7 Loading Error\n");
		}
		else printf("Asteroid Texture 7 Loading Success\n");
		break;
	case 8:
		if (!asteroid_texture.loadFromFile("../textures/PNG/Meteors/meteorGrey_big4.png"))
		{
			printf("Asteroid Texture 8 Loading Error\n");
		}
		else printf("Asteroid Texture 8 Loading Success\n");
		break;
	}
	asteroid_sprite.setTexture(asteroid_texture);
}

// Wrapping Functions //

void Asteroid::KeepOnScreen(sf::RenderWindow & wnd)
{
	wrapX(wnd);
	wrapY(wnd);
}

void Asteroid::wrapX(sf::RenderWindow & wnd)
{
	if (pos.x - asteroid_texture.getSize().x > wnd.getSize().x) // left side ast, right side screen
	{
		pos.x = 0.0f - asteroid_texture.getSize().x;
	}

	if (pos.x + asteroid_texture.getSize().x< 0.0f) //
	{
		pos.x = float(wnd.getSize().x + asteroid_texture.getSize().x); // right side ast, left side screen
	}
}

void Asteroid::wrapY(sf::RenderWindow & wnd)
{
	if (asteroid_sprite.getPosition().y - asteroid_texture.getSize().y / 2 > wnd.getSize().y) // bottom
	{
		pos.y = 0.0f - asteroid_texture.getSize().y;
	}

	if (asteroid_sprite.getPosition().y + asteroid_texture.getSize().y < 0.0f) // top
	{
		pos.y = float(wnd.getSize().y + asteroid_texture.getSize().y / 2);
	}
}

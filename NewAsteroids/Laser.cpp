#include "Laser.h"

// Constructors //

Laser::Laser()
	:
	ltc()
{
	init();
}
void Laser::init()
{
	setTexture();

	vel = { 0.0f,0.0f };
	pos = { 9999.0f, 9999.0f };
	direction = 0.0f;
}

// Public Functions //

void Laser::Update(sf::RenderWindow & wnd, float dt)
{
	if (isShot)
	{
		keepInBounds(wnd);
		deltatime = dt;
		pos += vel*deltatime;
		laser_sprite.setPosition(pos);
	}
}

void Laser::ShootFrom(sf::Sprite sprite, sf::RenderWindow & wnd)
{
	printf("[SHOT]\n");
	isShot = true;
	pos = sprite.getPosition();
	direction = sprite.getRotation();
	laser_sprite.setRotation(direction);
	vel = DegreesToNormalVector(direction)*speed;
}

sf::Sprite * Laser::getSprite()
{
	return &laser_sprite;
}

// Private Functions //

void Laser::setTexture()
{
	laser_sprite.setTexture(*ltc.getTexture());
	laser_sprite.setOrigin(float(ltc.getTexture()->getSize().x/2), float(ltc.getTexture()->getSize().y / 2));
	laser_sprite.setScale(0.5f,0.5f);
}

void Laser::keepInBounds(sf::RenderWindow & wnd)
{
	if (pos.x + laser_sprite.getTexture()->getSize().y / 2 < 0.0f ||
		pos.x - laser_sprite.getTexture()->getSize().y / 2 > wnd.getSize().x ||
		pos.y + laser_sprite.getTexture()->getSize().y / 2 < 0.0f ||
		pos.y - laser_sprite.getTexture()->getSize().y / 2 > wnd.getSize().y)
	{
		printf("[NOT-SHOT]");
		isShot = false;
	}
}

sf::Vector2f Laser::DegreesToNormalVector(float degrees)
{
	// offset by 90 degrees (3.1415/2) to compensate for ship texture orientation
	return sf::Vector2f(cos(float((double(degrees)*radianconverter) - 3.1415 / 2)), sin(float((double(degrees)*radianconverter) - 3.1415 / 2)));
}

// Laser Texture Codex Functions //

LaserTextureCodex::LaserTextureCodex()
{
	loadFiles();
}

sf::Texture * LaserTextureCodex::getTexture()
{
	return &laser_texture;
}

void LaserTextureCodex::loadFiles()
{
	if (!laser_texture.loadFromFile("../textures/PNG/Lasers/laserRed13.png"))
	{
		printf("Laser Texture Failure.\n");
	} // TODO: Fix laser from overloading
}

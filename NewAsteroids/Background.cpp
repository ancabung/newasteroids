#include "Background.h"

// Constructors //

Background::Background(std::string file, sf::RenderWindow & wnd)
{
	if (!backgroundtexture.loadFromFile(file))
	{
		printf("Background Texture Load Failure.\n");
	}
	backgroundtexture.setRepeated(true);
	background.setTexture(backgroundtexture);
	background.setOrigin((float)backgroundtexture.getSize().x / 2, (float)backgroundtexture.getSize().y / 2);
	background.setPosition(0.0f,0.0f);
	background.setScale(5.0f,5.0f);
	background.setTextureRect(sf::IntRect(0, backgroundtexture.getSize().y, wnd.getSize().x*10, wnd.getSize().y*10));
}

// Public Functions //

void Background::Draw(sf::RenderWindow & wnd) const
{
	wnd.draw(background);
}

void Background::Update(sf::RenderWindow & wnd, sf::Vector2f ship_position)
{
	background.setPosition(int(-ship_position.x + float(wnd.getSize().x)), int(-ship_position.y + float( wnd.getSize().y)));
	background.setRotation(float(rotation));
	rotation+=0.05;
}

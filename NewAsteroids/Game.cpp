#include "Game.h"

// Constructors //

Game::Game()
	:
	ship(500.0f, 500.0f)
{
	this->m_font.loadFromFile("MarkerFelt.ttf");
	this->m_text.setFont(this->m_font);
	this->m_text.setString("Score: ");
	this->m_text.setCharacterSize(15);
	this->m_text.setPosition(200, 0);
}

// Public Functions //

sf::Vector2f Game::getShipPosition()
{
	return ship.getSprite()->getPosition();
}

// Private Functions //

void Game::UpdateGame(sf::RenderWindow & wnd)
{
	UpdateModel(wnd);
	DrawModel(wnd);
}

void Game::UpdateModel(sf::RenderWindow & wnd)
{
	HandleCollisionForLasersOnAsteroids();
	CycleLasers();
	float dt = ft.Mark();
	UpdateAsteroids(wnd, dt);
	ship.Update(wnd, dt, laser[current_laser]);
	UpdateLasers(wnd, dt);
}

void Game::DrawModel(sf::RenderWindow & wnd)
{
	DrawLasers(wnd);
	wnd.draw(*ship.getSprite());
	DrawAsteroids(wnd);
}

// Laser Functions //

void Game::CycleLasers()
{
	if (laser[current_laser].isShot)
	{
		if (current_laser <= laser_amount)
		{
			current_laser++;
		}
		else current_laser = 0;
	}
}

void Game::UpdateLasers(sf::RenderWindow & wnd, float dt)
{
	for (int i = 0; i<=laser_amount; i++)
	{
		laser[i].Update(wnd, dt);
	}
}

void Game::DrawLasers(sf::RenderWindow & wnd)
{
	for (int i = 0; i <= laser_amount; i++)
	{
		if (laser[i].isShot)
		{
			wnd.draw(*laser[i].getSprite());
		}
	}
}

// Asteroid Functions //

void Game::UpdateAsteroids(sf::RenderWindow & wnd, float & dt)
{
	for (int i = 0; i <= asteroid_amount; i++)
	{
		asteroid[i].Update(wnd, dt);
	}
}

void Game::DrawAsteroids(sf::RenderWindow & wnd) 
{
	for (int i = 0; i <= asteroid_amount; i++)
	{
		if (!asteroid[i].isDestroyed)
		{
			wnd.draw(*asteroid[i].getSprite());
		}
	}
}

// Collision Detection Functions //

void Game::HandleCollisionForLasersOnAsteroids()
{
	for (int i = 0; i <= asteroid_amount-1; i++)
	{
		for(int j = 0; j<=laser_amount-1; j++)
		{
			if(laser[j].isShot && !asteroid[i].isDestroyed)
			{
				if (areColliding(*laser[j].getSprite(), *asteroid[i].getSprite()))
				{
					asteroid[i].isDestroyed = true;
					laser[j].isShot = false;
				}
			}
		}
	}
}

bool Game::areColliding(sf::Sprite & sprite0, sf::Sprite & sprite1)
{
	sf::FloatRect sprite0_rect = sprite0.getGlobalBounds();
	sf::FloatRect sprite1_rect = sprite1.getGlobalBounds();
	return sprite0_rect.intersects(sprite1_rect);
}

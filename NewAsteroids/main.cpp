#include <SFML/Graphics.hpp>
#include "main.h"

int main()
{
	MainWindow main;
	Game game;

	main.GameLoop( game );
}

// Main Window Initialization //

MainWindow::MainWindow()
	:
	wnd(sf::VideoMode(1280, 720), "Asteroids"),
	background("../textures/Backgrounds/space3.png", wnd)
{
	wnd.setFramerateLimit(60);
}

// Main Game Loop //

void MainWindow::GameLoop(Game & game)
{
	while (wnd.isOpen())
	{
		wnd.clear();

		HandleBackground(wnd, game);

		HandleEvents();


		game.UpdateGame(wnd);

		wnd.display();
	}
}

// Handle Functions //

void MainWindow::HandleEvents()
{
	sf::Event e;
	while (wnd.pollEvent(e))
	{
		if (e.type == sf::Event::Closed)
		{
			wnd.close();
		}
	}
}

void MainWindow::HandleBackground(sf::RenderWindow & wnd, Game & game)
{
	UpdateBackground(wnd, game);
	DrawBackground(wnd);
}

void MainWindow::DrawBackground(sf::RenderWindow & wnd)
{
	background.Draw(wnd);
}

void MainWindow::UpdateBackground(sf::RenderWindow & wnd, Game & game)
{
	background.Update(wnd,game.getShipPosition());
}


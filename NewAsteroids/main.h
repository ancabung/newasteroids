#pragma once
#include "Game.h"
#include "Background.h"

class MainWindow
{
public:
	MainWindow();

	//Objects
	sf::RenderWindow wnd;
	Background background;

	//Functions
	void HandleEvents();
	void GameLoop(Game & game);
	void DrawBackground(sf::RenderWindow & wnd);
	void UpdateBackground(sf::RenderWindow & wnd, Game & game);
	void HandleBackground(sf::RenderWindow & wnd, Game & game);
	
};
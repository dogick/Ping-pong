#include "stdafx.h"
#include "Const.h"
#include "Game.h"
#include <iostream>

void Render(sf::RenderWindow & window, Game* game)
{
	window.clear();
	for (auto wall : game->scene.walls)
	{
		window.draw(wall->rectangle);
	}
	window.draw(game->enemy.shape);
	window.draw(game->scene.centerLines);
	window.draw(game->ball.shape);
	window.draw(game->player.playerShape);
	window.display();
}

void HandleEvents(sf::RenderWindow & window)
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window.close();
		}
	}
}

void Update(sf::Clock &clock, Game* game)
{
	const float elapsedTime = clock.getElapsedTime().asSeconds();
	clock.restart();
	UpdateGame(game, elapsedTime);
}

void EnterMainLoop(sf::RenderWindow & window, Game* game, sf::Clock &clock)
{
	while (window.isOpen())
	{
		HandleEvents(window);
		Update(clock, game);
		Render(window, game);
	}
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), TITLE);
	Game* game = new Game;
	game->InitializeGame();
	sf::Clock clock;
	EnterMainLoop(window, game, clock);
	return 0;
}
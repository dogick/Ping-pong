#include "stdafx.h"
#include "Const.h"
#include "Game.h"


void Game::InitializeGame()
{
	InitializeScene(scene);
	StartBall(ball);
}

void UpdateGame(Game* game, float elapsedTime)
{
	UpdatePlayer(game->player, elapsedTime, game->scene.walls);
	sf::FloatRect oldBoundsPlayer = game->player.playerShape.getGlobalBounds();
	sf::FloatRect oldBoundsEnemy = game->enemy.shape.getGlobalBounds();
	UpdateBall(game->ball, elapsedTime, game->scene.walls, oldBoundsPlayer, oldBoundsEnemy, game->score);
	UpdateEnemy(game->enemy, elapsedTime, game->scene.walls, game->ball);
}

void ResetGame(Ball & ball)
{
	ball.shape.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	StartBall(ball);
}
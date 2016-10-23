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
	UpdateBall(game->ball, elapsedTime, game->scene.walls, game->player.playerShape.getGlobalBounds());
	//game->ball.shape.move(game->ball.direction.x * elapsedTime * BALL_SPEED, game->ball.direction.y * elapsedTime * BALL_SPEED);
}
#pragma once
#include "stdafx.h"
#include "Scene.h"
#include "Player.h"
#include "Ball.h"
#include "Enemy.h"

struct Game
{
	Scene scene;
	Player player;
	Ball ball;
	Enemy enemy;
	void InitializeGame();
};

void UpdateGame(Game* game, float elapsedTime);
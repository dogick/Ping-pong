#pragma once
#include "stdafx.h"
#include "Scene.h"
#include "Ball.h"
struct Enemy
{
	Enemy();
	sf::RectangleShape shape;
};

void UpdateEnemy(Enemy &enemy, float elapsedTime, std::vector<Wall*> & walls, Ball & ball);
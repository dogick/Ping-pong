#pragma once
#include "stdafx.h"
#include "Const.h"
#include "Scene.h"

struct Ball
{
	Ball();
	sf::CircleShape shape;
	sf::Vector2f direction;
};

void StartBall(Ball & ball);
void UpdateBall(Ball & ball, float elapsedTime, std::vector<Wall*> & walls, sf::FloatRect & oldBoundsPlayer);
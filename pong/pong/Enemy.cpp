#include "stdafx.h"
#include "Enemy.h"
#include "Const.h"

Enemy::Enemy()
{
	shape.setSize(ENEMY_SIZE);
	shape.setPosition(970, 100);
	shape.setFillColor(sf::Color::Red);
}
#include "stdafx.h"
#include "Enemy.h"
#include "Const.h"

Enemy::Enemy()
{
	shape.setSize(ENEMY_SIZE);
	shape.setPosition(970, 100);
	shape.setFillColor(sf::Color::Red);
}

void UpdateEnemy(Enemy &enemy, float elapsedTime, std::vector<Wall*> & walls, Ball & ball)
{
	const float speed = ENEMY_SPEED * elapsedTime;
	sf::Vector2f movement(0.f, 0.f);
	if (enemy.shape.getPosition().y + enemy.shape.getGlobalBounds().height / 2 < ball.shape.getPosition().y)
	{
		movement.y = speed;
	}
	if (enemy.shape.getPosition().y + enemy.shape.getGlobalBounds().height / 2 > ball.shape.getPosition().y)
	{
		movement.y = -speed;
	}
	CheckFieldWallsCollision(enemy.shape.getGlobalBounds(), movement, walls);
	enemy.shape.move(movement);
}
#include "stdafx.h"
#include "Ball.h"
#include <random>
#include <iostream>

Ball::Ball()
{
	shape.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	shape.setOrigin(BALL_RADIUS, BALL_RADIUS);
	shape.setRadius(BALL_RADIUS);
	shape.setFillColor(sf::Color::Blue);
}

float GetRandomDirection()
{
	std::random_device random_device;
	std::mt19937 generator(random_device());
	std::uniform_int_distribution<> distribution(1, 2);
	return distribution(generator) == 1 ? -1 : 1;
}

void StartBall(Ball & ball)
{
	ball.direction = sf::Vector2f(GetRandomDirection(), GetRandomDirection());
	ball.shape.move(ball.direction);
}

void CheckBallCollision(Ball & ball, std::vector<Wall*> & walls, sf::FloatRect & oldBoundsPlayer)
{
	sf::FloatRect oldBounds = ball.shape.getGlobalBounds();
	for (auto wall : walls)
	{
		bool isCollision = wall->rectangle.getGlobalBounds().intersects(oldBounds);
		if (isCollision && (wall->wallPosition == WallPosition::TOP || wall->wallPosition == WallPosition::BOTTOM))
		{
			ball.direction.y *= -1;
		}
		else if (isCollision && (wall->wallPosition == WallPosition::LEFT || wall->wallPosition == WallPosition::RIGHT))
		{
			ball.direction.x *= -1;
		}
	}

	if (oldBounds.intersects(oldBoundsPlayer))
	{
		ball.direction.x *= -1;
	}
}

void UpdateBall(Ball & ball, float elapsedTime, std::vector<Wall*> & walls, sf::FloatRect & oldBoundsPlayer)
{
	CheckBallCollision(ball, walls, oldBoundsPlayer);
	sf::Vector2f movement(ball.direction.x * elapsedTime * BALL_SPEED, ball.direction.y * elapsedTime * BALL_SPEED);
	ball.shape.move(movement);
}
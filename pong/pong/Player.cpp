#include "stdafx.h"
#include "Player.h"
#include "Const.h"


Player::Player()
{
	playerShape.setSize(PLAYER_SIZE);
	playerShape.setPosition(10, 100);
	playerShape.setFillColor(sf::Color::Red);
}

void UpdatePlayerDirection(Player &player)
{
	player.direction = Direction::NONE;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		player.direction = Direction::UP;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		player.direction = Direction::DOWN;
	}
}


void UpdatePlayer(Player &player, float elapsedTime, std::vector<Wall*> & walls)
{
	const float step = PLAYER_SPEED * elapsedTime;

	UpdatePlayerDirection(player);

	sf::Vector2f movement(0.f, 0.f);
	switch (player.direction)
	{
	case Direction::UP:
		movement.y -= step;
		break;
	case Direction::DOWN:
		movement.y += step;
		break;
	case Direction::NONE:
		break;
	}
	if (CheckFieldWallsCollision(player.playerShape.getGlobalBounds(), movement, walls))
	{
		// Останавливаем пакмана при столкновении
		player.direction = Direction::NONE;
	}
	player.playerShape.move(movement);
}
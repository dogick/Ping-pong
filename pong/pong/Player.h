#pragma once
#include "stdafx.h"
#include "Scene.h"

enum struct Direction
{
	NONE,
	UP,
	DOWN,
};

struct Player
{
	Player();
	sf::RectangleShape playerShape;
	Direction direction;
};

void UpdatePlayer(Player &player, float elapsedTime, std::vector<Wall*> & walls);
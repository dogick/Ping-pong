#include "stdafx.h"
#include "Const.h"
#include "Scene.h"

#include <iostream>

void InitializeScene(Scene & scene)
{
	InitializeWall(scene.walls);
	InitializeCenterLine(scene.centerLines);
}

void InitializeCenterLine(sf::RectangleShape & line)
{
	line.setSize(sf::Vector2f(WINDOW_HEIGHT, 2));
	line.rotate(90);
	line.setPosition(WINDOW_WIDTH / 2, 0);
}

Wall::Wall(sf::Vector2f const& position, sf::Vector2f const& size, sf::Vector3i const& color, WallPosition const& wallPos)
{
	wallPosition = wallPos;
	rectangle.setPosition(position);
	rectangle.setSize(size);
	rectangle.setFillColor(sf::Color(color.x, color.x, color.z));
	rectangle.setOutlineThickness(2);
}

void InitializeWall(std::vector<Wall*> & walls)
{
	walls.push_back(new Wall({ 0, 0 }, { float(WINDOW_WIDTH), 50 }, { 24, 56,177 }, WallPosition::TOP));
	walls.push_back(new Wall({ 0, 0 }, { 8, float(WINDOW_HEIGHT) }, { 24, 56,177 }, WallPosition::LEFT));
	walls.push_back(new Wall({ float(WINDOW_WIDTH - 8), 0 }, { 8, float(WINDOW_HEIGHT) }, { 24, 56,177 }, WallPosition::RIGHT));
	walls.push_back(new Wall({ 0, float(WINDOW_HEIGHT - 8) }, { float(WINDOW_WIDTH), 8 }, { 24, 56,177 }, WallPosition::BOTTOM));
}

bool CheckFieldWallsCollision(const sf::FloatRect &oldBounds, sf::Vector2f & movement, std::vector<Wall*> & walls)
{
	for (auto wall : walls)
	{
		if (wall->rectangle.getGlobalBounds().intersects(oldBounds))
		{
			switch (wall->wallPosition)
			{
			case WallPosition::TOP:
				movement = { 0, 0.5f };
				break;
			case WallPosition::BOTTOM:
				movement = { 0, -0.5f };
			default:
				break;
			}
			return true;
		}
	}
	return false;
}
#pragma once

enum class WallPosition
{
	TOP,
	BOTTOM,
	LEFT,
	RIGHT,
};

struct Wall
{
	Wall::Wall(sf::Vector2f const& position, sf::Vector2f const& size, sf::Vector3i const& color, WallPosition const& wallPos);
	sf::RectangleShape rectangle;
	sf::Vector2f size;
	sf::Vector2f position;
	WallPosition wallPosition;
};

struct Scene
{
	std::vector<Wall*> walls;
    sf::RectangleShape centerLines;
};

void InitializeWall(std::vector<Wall*> & walls);
void InitializeScene(Scene & scene);
void InitializeCenterLine(sf::RectangleShape & line);
bool CheckFieldWallsCollision(const sf::FloatRect &oldBounds, sf::Vector2f & movement, std::vector<Wall*> & walls);
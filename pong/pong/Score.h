#pragma once
#include "stdafx.h"

struct Score
{
	Score();
	sf::Font font;
	sf::Text text[2];
	int scorePlayer;
	int scoreEnemy;
};


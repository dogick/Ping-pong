#include "stdafx.h"
#include "Score.h"

Score::Score()
{
	if (!font.loadFromFile("resources/font/Rotonda.ttf"))
	{
		exit(EXIT_FAILURE);
	}

	for (auto & scoreText : text)
	{
		scoreText.setFont(font);
		scoreText.setCharacterSize(35);
		scoreText.setString(std::to_string(0));
	}
	text[0].setPosition(450, 8);
	text[1].setPosition(530, 8);
	scorePlayer = 0;
	scoreEnemy = 0;
}
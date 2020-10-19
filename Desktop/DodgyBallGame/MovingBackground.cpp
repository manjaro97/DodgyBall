/*
 * File:   MovingBackground.cpp
 * Author: Jonas Carlsson
 *
 * Created on Mars 21, 2019, 14:15 PM
 */
#include "MovingBackground.h"


MovableBackground::MovableBackground()
{
	bgSpeed = 0.3;

	bgTex.loadFromFile("background.jpg");
	bgTex.setSmooth(false);
	bgTex.setRepeated(true);

	bgY = 0;
	bgSize.x = 1366;
	bgSize.y = 768;

	bgShape.setTexture(&bgTex);
	bgShape.setSize(bgSize);
}


void MovableBackground::Update(sf::RenderWindow &window, float elapsedTime)
{
	if (bgY < 600)
	{
		bgY += bgSpeed * elapsedTime;
	}
	else
	{
		bgY = 0;
	}
	bgShape.setPosition(0, bgY);
}
void MovableBackground::Render(sf::RenderWindow &window)
{
	window.draw(bgShape);
}
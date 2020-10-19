/*
 * File:   MovingBackground.h
 * Author: Jonas Carlsson
 *
 * Created on Mars 21, 2019, 14:15 PM
 */
#ifndef MOVINGBACKGROUND_H
#define MOVINGBACKGROUND_H

#include <SFML\Graphics.hpp>

class MovableBackground
{
public:
	MovableBackground();
	void Update(sf::RenderWindow &window, float elapsedTime);
	void Render(sf::RenderWindow &window);

private:
	sf::Texture bgTex;
	sf::Texture bg2Tex;

	sf::RectangleShape bgShape;
	sf::Vector2f bgSize;

	sf::Sprite      bgSprite;
	sf::Sprite      bg2Sprite;

	float bgSpeed;
	float bgY;
	float bg2Y;
	float windowbg1diff;
};
#endif
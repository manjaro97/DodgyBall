/*
 * File:   Engine.h
 * Author: Jonas Carlsson
 *
 * Created on Mars 21, 2019, 14:15 PM
 */
#ifndef ENGINE_H
#define ENGINE_H

#include <SFML/Graphics.hpp>
#include "Ball.h"
#include "Wall.h"
#include "Counter.h"
#include "MovingBackground.h"

class Engine
{
public:
	// The Engine constructor
	Engine();

	// start will call all the private functions
	void start();
private:
	// A regular RenderWindow
	sf::RenderWindow m_Window;

	// Declare a sprite and a Texture for the background
	sf::Sprite m_BackgroundSprite;
	sf::Texture m_BackgroundTexture;
	
	// An instance of Ball, Wall and DeathCounter
	Ball m_Ball;
	Wall m_Wall;
	DeathCounter m_deaths;

	// Private functions for internal use only
	void input();
	void update(float dtAsSeconds);
	void draw();
};

#endif
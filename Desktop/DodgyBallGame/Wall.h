/*
 * File:   Wall.h
 * Author: Jonas Carlsson
 *
 * Created on Mars 21, 2019, 14:15 PM
 */
#ifndef WALL_H
#define WALL_H

#include <SFML/Graphics.hpp>

class Wall
{
	// Public functions
public:
	Wall();

	// Send a copy of the sprite to main
	sf::Sprite getSprite();

	//Returns position of Wall
	sf::Vector2f getWallPosition();

	// Resets speed of Wall
	void reset();

	// Returns speed of Wall
	int getSpeed();

	// We will call this function once every frame
	void update(float elapsedTime);

	// All the private variables can only be accessed internally
private:
	// Wall's position
	sf::Vector2f m_Position;

	// Sprite
	sf::Sprite m_Sprite;

	// Texture
	sf::Texture m_Texture;

	// Wall's speed in pixels per second
	float m_Speed;
};
#endif
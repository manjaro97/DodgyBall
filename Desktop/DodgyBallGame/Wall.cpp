/*
 * File:   Wall.cpp
 * Author: Jonas Carlsson
 *
 * Created on Mars 21, 2019, 14:15 PM
 */
#include "Wall.h"

Wall::Wall()
{
	// How fast does Ball move?
	m_Speed = 300;

	// Associate a texture with the sprite
	m_Texture.loadFromFile("wall.png");
	m_Sprite.setTexture(m_Texture);

	// Set the Ball's starting position
	m_Position.x = 1366; // 0 -> 146
	m_Position.y = -1100; // 0 -> 1330, 1550 -> 2880
}

/// <summary>
/// Make the private spite available to the draw() function
/// <summary>
sf::Sprite Wall::getSprite()
{
	return m_Sprite;
}

/// <summary>
/// returns position of Wall
/// <summary>
sf::Vector2f Wall::getWallPosition() {
	return m_Position;
}

// Variable definitions
int VerticalMovement = 0;
int HorizontalMovement = 0;

/// <summary>
/// resets position and speed of Wall and makes sure it travels in the right diretion
/// <summary>
void Wall::reset() {
	m_Position.x = 1366;
	m_Position.y = -1100;
	m_Speed = 300;
	VerticalMovement = 0;
}

/// <summary>
/// Returns speed of Wall
/// <summary>
int Wall::getSpeed() {
	return m_Speed;
}

/// <summary>
/// Move Wall based on the input this frame, the time elapsed, and the speed
/// <summary>
void Wall::update(float elapsedTime)
{
	// if moving left
	if (VerticalMovement == 0)
	{
		// If not at end of screen: move, else: change direction
		if (m_Position.x > -150) {
			m_Position.x -= m_Speed * elapsedTime;
		}
		else {
			VerticalMovement = 1;
		}
	}
	// if moving right
	if (VerticalMovement == 1)
	{
		// If not at end of screen: move, else: change direction
		if (m_Position.x < 1366) {
			m_Position.x += m_Speed * elapsedTime;
		}
		else {
			VerticalMovement = 0;
			m_Speed += 10;
		}
	}
	// if moving up
	if (HorizontalMovement == 0)
	{
		// If not at end of screen: move, else: change direction
		if (m_Position.y > -1320) {
			m_Position.y -= 0.4 * m_Speed * elapsedTime;
		}
		else {
			HorizontalMovement = 1;
		}
	}
	// if moving down
	if (HorizontalMovement == 1)
	{
		// If not at end of screen: move, else: change direction
		if (m_Position.y < -800) {
			m_Position.y += 0.2 * m_Speed * elapsedTime;
		}
		else {
			HorizontalMovement = 0;
		}
	}

	// Now move the sprite to its new position
	m_Sprite.setPosition(m_Position);
}
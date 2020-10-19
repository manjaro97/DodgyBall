/*
 * File:   Ball.cpp
 * Author: Jonas Carlsson
 *
 * Created on Mars 21, 2019, 14:15 PM
 */
#include "Ball.h"

 /// <summary>
 /// Class of Ball
 /// <summary>
Ball::Ball()
{
	// How fast does Ball move?
	m_Speed = 400;

	// Associate a texture with the sprite
	m_Texture.loadFromFile("ball.png");
	m_Sprite.setTexture(m_Texture);

	// Set the Ball's starting position
	m_Position.x = 0;
	m_Position.y = 576;
}

/// <summary>
/// Make the private sprite available to the draw() function
/// <summary>
sf::Sprite Ball::getSprite()
{
	return m_Sprite;
}


/// <summary>
/// Returns position of Ball
/// <summary>
sf::Vector2f Ball::getBobPosition() {
	return m_Position;
}

/// <summary>
/// Resets position of Ball
/// <summary>
void Ball::reset() {
	m_Position.x = 0;
	m_Position.y = 576;
}

/// <summary>
/// Move Ball in a specific direction
/// <summary>
void Ball::moveLeft()
{
	m_LeftPressed = true;
}

void Ball::moveRight()
{
	m_RightPressed = true;
}

/// <summary>
/// Stops Ball in a specific direction
/// <summary>
void Ball::stopLeft()
{
	m_LeftPressed = false;
}

void Ball::stopRight()
{
	m_RightPressed = false;
}


//Temporary move up and down-----------
void Ball::moveUp()
{
	m_UpPressed = true;
}

void Ball::moveDown()
{
	m_DownPressed = true;
}

void Ball::stopUp()
{
	m_UpPressed = false;
}

void Ball::stopDown()
{
	m_DownPressed = false;
}
//-------------------------------------


/// <summary>
/// Move Ball based on the input this frame, the time elapsed, and the speed
/// <summary>
void Ball::update(float elapsedTime)
{
	if (m_RightPressed)
	{
		if (m_Position.x < 1218) {
			m_Position.x += m_Speed * elapsedTime;
		}
	}

	if (m_LeftPressed)
	{
		if (m_Position.x > 0) {
			m_Position.x -= m_Speed * elapsedTime;
		}
	}

	//Temporary move up and down-----------
	if (m_UpPressed)
	{
		if (m_Position.y > 0) {
			m_Position.y -= m_Speed * elapsedTime;
		}
	}

	if (m_DownPressed)
	{
		if (m_Position.y < 616) {
			m_Position.y += m_Speed * elapsedTime;
		}
	}
	//-------------------------------------

	// Now move the sprite to its new position
	m_Sprite.setPosition(m_Position);
}

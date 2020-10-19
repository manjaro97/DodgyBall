/*
 * File:   Ball.h
 * Author: Jonas Carlsson
 *
 * Created on Mars 21, 2019, 14:15 PM
 */
#ifndef BOB_H
#define BOB_H

#include <SFML/Graphics.hpp>

class Ball
{
// Public functions
public:
	Ball();

	// Send a copy of the sprite to main
	sf::Sprite getSprite();

	sf::Vector2f getBobPosition();

	void reset();

	// Move Ball in a specific direction
	void moveLeft();

	void moveRight();

	// Stop Ball moving in a specific direction
	void stopLeft();

	void stopRight();

	//Temporary move up and down-----------
	// Move Ball in a specific direction
	void moveUp();

	void moveDown();

	// Stop Ball moving in a specific direction
	void stopUp();

	void stopDown();
	//-------------------------------------

	// We will call this function once every frame
	void update(float elapsedTime);

	// All the private variables can only be accessed internally
private:

	// Where is Ball
	sf::Vector2f m_Position;

	// Of course we will need a sprite
	sf::Sprite m_Sprite;

	// And a texture
	// Ball has been working out and he is now a bit more muscular than before
	// Furthermore, he fancies himself in lumberjack attire
	sf::Texture m_Texture;

	// Which direction(s) is the player currently moving in
	bool m_LeftPressed;
	bool m_RightPressed;

	//Temporary move up and down-----------
	bool m_UpPressed;
	bool m_DownPressed;
	//-------------------------------------

	// Ball's speed in pixels per second
	float m_Speed;
};


#endif
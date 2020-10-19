/*
 * File:   Input.cpp
 * Author: Jonas Carlsson
 *
 * Created on Mars 21, 2019, 14:15 PM
 */
#include "Engine.h"

 /// <summary>
 /// Keeps track of input from keyboard to move Character
 /// <summary>
void Engine::input()
{
	// Handle the player quitting
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		m_Window.close();
	}

	// Handle the player moving
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		m_Ball.moveLeft();
	}
	else
	{
		m_Ball.stopLeft();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		m_Ball.moveRight();
	}
	else
	{
		m_Ball.stopRight();
	}

	//Temporary move up and down-----------
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		m_Ball.moveUp();
	}
	else
	{
		m_Ball.stopUp();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		m_Ball.moveDown();
	}
	else
	{
		m_Ball.stopDown();
	}
	//-------------------------------------
}

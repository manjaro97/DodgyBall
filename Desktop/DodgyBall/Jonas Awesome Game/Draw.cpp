/*
 * File:   Draw.cpp
 * Author: Jonas Carlsson
 *
 * Created on Mars 21, 2019, 14:15 PM
 */
#include "Engine.h"
#include "Counter.h"
#include "string"
#include "iostream"
#include "sstream"

// Sets Highscore at start of game to 0;
int Highscore = 0;

/// <summary>
/// Draws on screen, layers based on order of execution
/// <summary>
void Engine::draw()
{
	// Rub out the last frame
	m_Window.clear(sf::Color::White);

	// Draw the background, Wall and Ball
	m_Window.draw(m_BackgroundSprite);
	m_Window.draw(m_Wall.getSprite());
	m_Window.draw(m_Ball.getSprite());
	
	// Prepares message with font
	sf::Text message;
	sf::Font font;
	if (!font.loadFromFile("28 Days Later.ttf"))
	{
		m_Window.close();
	}
	message.setFont(font);

	// Fetches amount of Deaths and converts to string
	int IntDeath = m_deaths.getCounter(); 
	std::stringstream StrDeath;
	StrDeath << IntDeath;

	std::string str = "  Deaths " + StrDeath.str();

	// Sets message with string, size and colour
	message.setString(str);
	message.setCharacterSize(70);
	message.setFillColor(sf::Color::Red);
	//Draw the message on screen
	m_Window.draw(message);

	////////////////////////////////////////
	// Fetches level by checking amount of times speed was changed
	int IntLevel = (m_Wall.getSpeed() / 10) - 30;
	std::stringstream StrLevel;
	StrLevel << IntLevel;

	str = "                                                                 Level " + StrLevel.str();

	// Sets message with string and colour
	message.setString(str);
	message.setFillColor(sf::Color::Blue);
	//Draw the message on screen
	m_Window.draw(message);

	////////////////////////////////////////
	// Fetches Highscore from level if Level goes beyond previous highscore
	if (Highscore < IntLevel) {
		Highscore = IntLevel;
	}
	std::stringstream StrHighscore;
	StrHighscore << Highscore;
	str = "                             Highscore " + StrHighscore.str();

	// Sets message with string and colour
	message.setString(str);
	message.setFillColor(sf::Color::Green);
	//Draw the message on screen
	m_Window.draw(message);
	
	// Show everything we have just drawn
	m_Window.display();
} 
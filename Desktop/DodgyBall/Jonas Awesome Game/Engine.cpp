/*
 * File:   Engine.cpp
 * Author: Jonas Carlsson
 *
 * Created on Mars 21, 2019, 14:15 PM
 */
#include "Engine.h"
bool isInside(int circle_x, int circle_y, int rad, int x, int y);

Engine::Engine()
{
	// Get the screen resolution and create an SFML window and View
	sf::Vector2f resolution;
	resolution.x = sf::VideoMode::getDesktopMode().width;
	resolution.y = sf::VideoMode::getDesktopMode().height;

	m_Window.create(sf::VideoMode(resolution.x, resolution.y),
		"Simple Game Engine",
		sf::Style::Fullscreen);

	// Load the background into the texture
	// Be sure to scale this image to your screen size
	m_BackgroundTexture.loadFromFile("background.jpg");

	// Associate the sprite with the texture
	m_BackgroundSprite.setTexture(m_BackgroundTexture);

}

/// <summary>
/// Function that keeps track of time and execution of input, updates draw to screen
/// <summary>
void Engine::start()
{
	// Timing
	sf::Clock clock;

	while (m_Window.isOpen())
	{
		// Restart the clock and save the elapsed time into dt
		sf::Time dt = clock.restart();

		// Make a fraction from the delta time
		float dtAsSeconds = dt.asSeconds();

		// Fetches position of Ball and Wall
		sf::Vector2f Ballpos = m_Ball.getBobPosition();
		sf::Vector2f Wallpos = m_Wall.getWallPosition();
		
		// for every "Ball radius" lenght checks points on Walls edges for collission
		//Upper part of Wall
		for (int i = Wallpos.x; i <= Wallpos.x + 146; i += 73)
		{
			for (int i2 = Wallpos.y + 1330; i2 >= Wallpos.y; i2 -= 73)
			{
				if (isInside(Ballpos.x + 73, Ballpos.y + 73, 73, i, i2)) {
					// On collission: resets position of Wall and Ball while also reseting speed of Wall and deaths. 
					// Level is also reset since it is based on speed of Wall
					m_deaths.death();
					m_Wall.reset();
					m_Ball.reset();
				}
			}
		}
		//Lower part of Wall
		for (int i = Wallpos.x; i <= Wallpos.x + 146; i += 73)
		{
			for (int i2 = Wallpos.y + 1550; i2 <= Wallpos.y + 2660; i2 += 73)
			{
				if (isInside(Ballpos.x + 73, Ballpos.y + 73, 73, i, i2)) {
					m_deaths.death();
					m_Wall.reset();
					m_Ball.reset();
				}
			}
		}
		
		//Keeps game updated on whats happening
		input();
		update(dtAsSeconds);
		draw();
	}
}

/// <summary>
/// Checks if Circle collides with given point
/// <summary>
bool isInside(int circle_x, int circle_y,
	int rad, int x, int y)
{
	// Compare radius of circle with distance  
	// of its center from given point 
	if ((x - circle_x) * (x - circle_x) +
		(y - circle_y) * (y - circle_y) <= rad * rad)
		return true;
	else
		return false;
}
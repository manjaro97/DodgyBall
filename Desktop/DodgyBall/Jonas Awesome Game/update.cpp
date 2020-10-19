/*
 * File:   update.cpp
 * Author: Jonas Carlsson
 *
 * Created on Mars 21, 2019, 14:15 PM
 */
#include "Engine.h"

// update for position of Wall and Ball
void Engine::update(float dtAsSeconds)
{
	m_Ball.update(dtAsSeconds);
	m_Wall.update(dtAsSeconds);
}
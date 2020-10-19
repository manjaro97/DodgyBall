/*
 * File:   Counter.cpp
 * Author: Jonas Carlsson
 *
 * Created on Mars 21, 2019, 14:15 PM
 */
#include "Counter.h"

 /// <summary>
 /// Class for Death Counter
 /// <summary>
DeathCounter::DeathCounter()
{
	//Amount of Deaths at start of game
	int counter = 0;
}

/// <summary>
/// Returns amount of Deaths
/// <summary>
int DeathCounter::getCounter() {
	return counter;
}

/// <summary>
/// Adds 1 to Death count
/// <summary>
//Adds to death by one
void DeathCounter::death() {
	counter++;
}

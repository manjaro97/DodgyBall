/*
 * File:   Counter.h
 * Author: Jonas Carlsson
 *
 * Created on Mars 21, 2019, 14:15 PM
 */
#ifndef COUNTER
#define COUNTER

//Class for DeathCounter
class DeathCounter
{
public:
	DeathCounter();

	//Returns amount of Deaths
	int getCounter();
	//Adds to death by one
	void death();
private: 
	int counter = 0;
};

#endif
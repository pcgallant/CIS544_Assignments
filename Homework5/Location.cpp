///////////////////////////////////////////////////////////
// CIS554 Object Oriented Programming in C++
// Homework 5 - Location class definition
// Patricia Gallant
///////////////////////////////////////////////////////////

#include "Location.h"
Location::Location()
{
}

Location::~Location()
{
}

Location::LOCATION Location::GetLocation(Point & p)
{
	//Check combinations of x & y coordinates to determine location
	if (p.GetX >= 0 && p.GetX <= 5 && p.GetY >= 0 && p.GetY <= 5)
	{
		return LOCATION::NEWYORK;
	}
	else if (p.GetX >= 6 && p.GetX <= 10 && p.GetY >= 6 && p.GetY <= 10)
	{
		return LOCATION::SANFRANSISCO;
	}
	else if (p.GetX >= 11 && p.GetX <= 15 && p.GetY >= 11 && p.GetY <= 15)
	{
		return LOCATION::LOSANGELES;
	}
	else if (p.GetX >= 16 && p.GetX <= 20 && p.GetY >= 16 && p.GetY <= 20)
	{
		return LOCATION::CHICAGO;
	}
	else
	{
		return LOCATION::NOT_FOUND;
	}
}

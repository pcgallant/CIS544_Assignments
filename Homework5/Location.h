///////////////////////////////////////////////////////////
// CIS554 Object Oriented Programming in C++
// Homework 5 - Location class interface
// Patricia Gallant
///////////////////////////////////////////////////////////

#include "Point.h"
#include "Set.h"
class Location
{
public:
	Location();
	~Location();
	enum class LOCATION { NOT_FOUND, NEWYORK, SANFRANSISCO, LOSANGELES, CHICAGO };

	LOCATION GetLocation(Point &p);

private:
	Set xNewYork;
	Set yNewYork;
	Set xSanFransicso;
	Set ySanFransicso;
	Set xLosAngeles;
	Set yLosAngeles;
	Set xChicago;
	Set yChicago;
};
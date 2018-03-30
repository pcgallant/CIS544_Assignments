///////////////////////////////////////////////////////////
// CIS554 Object Oriented Programming in C++
// Homework 5 - Employee class definition
// Patricia Gallant
///////////////////////////////////////////////////////////
#include "stdafx.h"
#include "Employee.h"


Employee::Employee()
{
}

Employee::Employee(string name, int xVal, int yVal)
{
	Point tempPoint(xVal, yVal);

	this->SetName(name);
	this->SetCoordinates(tempPoint);
	return;

}


Employee::~Employee()
{
}

void Employee::SetCoordinates(Point empCoord)
{
	this->empCoordinates = empCoord;
	return;
}

Point Employee::GetCoordinates()
{
	return this->empCoordinates;
}

void Employee::SetName(string name)
{
	empName = name;
	return;
}

string Employee::GetName()
{
	return empName;
}

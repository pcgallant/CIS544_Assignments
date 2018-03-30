///////////////////////////////////////////////////////////
// CIS554 Object Oriented Programming in C++
// Homework 5 - Employee class interface
// Patricia Gallant
///////////////////////////////////////////////////////////
#include <string>
using std::string;
#include "Point.h"

class Employee
{
public:
	Employee();    //default constructor
	Employee(string name, int xVal, int yVal);   // initializer constructor

	~Employee();

	void SetCoordinates(Point empCoord);
	Point GetCoordinates();

	void SetName(string name);
	string GetName();


private:
	string empName;
	Point empCoordinates;

};


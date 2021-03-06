///////////////////////////////////////////////////////////
// CIS554 Object Oriented Programming in C++
// Exercise 5_3 - Function overloading
// Patricia Gallant
///////////////////////////////////////////////////////////

#include <iostream>
#include "maximum.h"
using namespace std;


int main()
{
	// demonstrate maximum with int values
	int int1, int2, int3, int4;

	cout << "Input four integer values: ";
	cin >> int1 >> int2 >> int3 >> int4;

	// invoke int version of maximum
	cout << "The maximum integer value is: "
		<< maximum(int1, int2, int3, int4);

	// demonstrate maximum with double values
	double double1, double2, double3, double4;

	cout << "\n\nInput four double values: ";
		cin >> double1 >> double2 >> double3 >> double4;

	// invoke double version of maximum
		cout << "The maximum double value is: "
			<< maximum(double1, double2, double3, double4);

	// demonstrate maximum with char values
		char char1, char2, char3, char4;

		cout << "\n\nInput four characters: ";
		cin >> char1 >> char2 >> char3 >> char4;

		// invoke char version of maximum
		cout << "The maximum character value is: "
			<< maximum(char1, char2, char3, char4) << endl;

    return 0;
} // end main


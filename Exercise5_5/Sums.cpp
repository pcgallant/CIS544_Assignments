///////////////////////////////////////////////////////////
// CIS554 Object Oriented Programming in C++
// Exercise 5_3 - Function overloading
// Patricia Gallant
///////////////////////////////////////////////////////////
#include <iostream>
#include "Sums.h"
using namespace std;

Sums::Sums()
	:endInt(0)
{
	//default constructor
}
int Sums::SumAllInt(int n)
{
	// Base case
	if (n <= 1)
	{
		return 1;
	}
	else
	{
		// call recursivley with n-1
		return n + SumAllInt(n - 1);
	}
}
bool Sums::SetEndInt(int n)
{
	if (n < 0)
	{
		cout << "Invalid entry. Must be a positive integer." << endl;
		return false;
	}
	else
	{
		endInt = n;
		return true;
	}


}
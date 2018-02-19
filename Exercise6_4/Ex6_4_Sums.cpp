///////////////////////////////////////////////////////////
// CIS554 Object Oriented Programming in C++
// Exercise 6_4 - Pass by reference with pointers
// Patricia Gallant
///////////////////////////////////////////////////////////
#include <iostream>
#include "Ex6_4_Sums.h"
using namespace std;

Ex6_4_Sums::Ex6_4_Sums()
	:endInt(0)
{
	//default constructor
}
int Ex6_4_Sums::SumAllInt(int * nPtr)
{
	int nextN = *nPtr -1;  // dereference the pointer and subtract 1 for use in recursive call
	int * nextNptr = &nextN;  // initialize pointer to the address location for nextN

	// Base case
	if (*nPtr <= 1)
	{
		return 1;
	}
	else
	{
		// call recursivley with n-1
		return *nPtr + SumAllInt( nextNptr);
	}
}
bool Ex6_4_Sums::SetEndInt(int  *nPtr)
{
	if (*nPtr <= 0)
	{
		cout << "Invalid entry. Must be an integer greater than 0." << endl;
		return false;
	}
	else
	{
		endInt = *nPtr;
		return true;
	}


}
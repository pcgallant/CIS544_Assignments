///////////////////////////////////////////////////////////
// CIS554 Object Oriented Programming in C++
// Exercise 6_4 - Pass by reference with pointers
// Patricia Gallant
///////////////////////////////////////////////////////////

#include <iostream>
#include "Ex6_4_Sums.h"
using namespace std;

int main()
{
	int startInt = 1;
	char cont = 'y';
	int input = 0;

	Ex6_4_Sums mySums;

	while (cont == 'y' || cont == 'Y')
	{
		cout << "Enter a positive integer: ";
		cin >> input;

		if (mySums.SetEndInt(&input) == true)
		{
			cout << "The sum of all positive integers from 1 to " << input << " is " << mySums.SumAllInt(&input) << endl;
		}

		cout << "\nAnother sum?";
		cin >> cont;
	}
	return 0;
}


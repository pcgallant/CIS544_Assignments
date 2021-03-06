//////////////////////////////////////////////
// CIS 554 Object Oriented Programming C++
// Patricia Gallant
// Homework 1
/////////////////////////////////////////////

#include <iostream>
#include "Convert.h"

using namespace std;

int main()
{
	Convert reqConvert;
	char cont = ' '; // sentinal flag to stop requesting numbers to convert
	bool success = true;

	while (cont != 'N' && cont != 'n' && cont != 'No' && cont != 'nO' && cont!= 'no' )
	{
		success = reqConvert.setInput();
		if (success == true)
		{
			cout << "The decimal value of " << reqConvert.getNumber() << " base "
				<< reqConvert.getBase() << " is " << reqConvert.getDecimalValue() << endl << endl;
		}
		else
		{
			cout << "Validation error on input." << endl;
		}
		cout << "Do you want to try again?" << endl;
		cin >> cont;

	}
    return 0;
}


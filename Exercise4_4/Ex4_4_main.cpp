/////////////////////////////////////////////////////
// CIS554 Object Oriented Programming in C++
// Exercise 4_4 - Functions
// Patricia Gallant
/////////////////////////////////////////////////////

#include <iostream>
#include "TimeDiff.h"

using namespace std;
int main()
{
	TimeDiff myTimeDiff;
	int hour = 0;
	int minute = 0;
	int second = 0;
	char cont = 'Y';

	while (cont == 'Y' || cont == 'y')
	{
		cout << "Enter hour: ";
		cin >> hour;
		cout << endl << "Enter minute: ";
		cin >> minute;
		cout << endl << "Enter second: ";
		cin >> second;
		cout << endl;

		if (myTimeDiff.ValidateTime(hour, minute, second) == true)
		{
			cout << "Seconds since previous noon = " << myTimeDiff.SecondsSinceNoon(hour, minute, second) << endl;
		}
		else
		{
			cout << "Invalid time format, try again" << endl;
		}
		cout << "Another? (Enter Y to continue, any other key to exit)";
		cin >> cont;
	}
	return 0;
}
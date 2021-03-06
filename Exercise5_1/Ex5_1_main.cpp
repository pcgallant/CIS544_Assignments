/////////////////////////////////////////////////////
// CIS554 Object Oriented Programming in C++
// Exercise 5_1 Reference Parameters
// Patricia Gallant
/////////////////////////////////////////////////////

#include <iostream>
#include "Ex5_1_TimeDiff.h"

using namespace std;
int main()
{
	Ex5_1_TimeDiff myTimeDiff;
	int hour = 0;
	int minute = 0;
	int second = 0;
	char cont = 'Y';

	while (cont == 'Y' || cont == 'y')
	{
		cout << "Enter hour: ";
		cin >> hour;
		cout  << "Enter minute: ";
		cin >> minute;
		cout << "Enter second: ";
		cin >> second;

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
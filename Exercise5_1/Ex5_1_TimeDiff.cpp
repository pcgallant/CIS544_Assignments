#include "Ex5_1_TimeDiff.h"
using namespace std;

Ex5_1_TimeDiff::Ex5_1_TimeDiff()
{
	//default constructor
}

int Ex5_1_TimeDiff::SecondsSinceNoon(int &hour, int &min, int &sec)
{
	int totSeconds = 0;

	//Validate that the entered values are a valid time
	if (ValidateTime(hour, min, sec) == false)
	{
		cout << "/nLOGIC ERROR: Invalid time received in SecondsSinceNoon" << endl;
	}
	else
	{
		//Calculate the number seconds since the last noon 
		if (hour == 12) {
			// this is the noon hour so no seconds within the hour
			totSeconds = 0;
		}
		else if (hour > 12)
		{
			//the last noon was earlier today so calc seconds from this hour- 12 value
			totSeconds = (hour - 12) * 3600;
		}
		else
		{
			//the last noon was yesterday so you need to add 12 hours before calculating the # of seconds for this hour value
			totSeconds = (12 + hour) * 3600;
		}

		if (hour == 12)
		{
		}
		else
		{// 
		}
		// now add the seconds for the minutes and seconds of the entered time
		totSeconds = totSeconds + (min * 60) + sec;
		return totSeconds;
	}
}


bool Ex5_1_TimeDiff::ValidateTime(int &hour, int &min, int &sec)
{
	//Hour must be >= 0 and <=23, min must be >=0 and <=59, sec must be >=0 and <=59
	if (hour >= 0 && hour <= 23 && min >= 0 && min <= 59 && sec >= 0 && sec <= 59)
	{
		return true;
	}
	else
	{
		return false;
	}
}
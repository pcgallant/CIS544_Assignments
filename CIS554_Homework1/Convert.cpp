//////////////////////////////////////////////
// CIS 554 Object Oriented Programming C++
// Patricia Gallant
// Homework 1
/////////////////////////////////////////////

#include <iostream>
#include "Convert.h"

// constructor will initialize all the member data to zero upon creation
Convert::Convert()
	: number(0), base(0), result(0), numDigits(0)
{
	//empty body
}


int Convert::getNumber()
{
	return number;
}

int Convert::getBase()
{
	return base;
}

bool Convert::setInput()
{
	bool success = true;
	int inBase = 0;
	int inNum = 0;
	int currNum = 0;
	int digit = 0;
	int count = 0;

	//prompt for base
	cout << "What base is the number you want converted? (max base 10) " << endl;
	cin >> inBase;
	// Validate the base value entered
	if (cin.fail() || inBase < 2 || inBase > 10)
	{
		cout << "Invalid, base must be a positive integer between 2 and 10" << endl;
		cin.clear();
		return false;
	}
	else 
	{
		//valid range for base, ask for number
		cout << "Enter the positive number to convert: " << endl;
		cin >> inNum;
		//validation that entry is numeric
		if (cin.fail())
		{
			cout << "Number to convert is invalid, must be an integer" << endl;
			cin.clear();
			return false;
		}
		else if (inNum < 0)
		{// invalid entry
			cout << "Number to convert " << inNum << " is invalid (negative number), must be positive.  " << endl;
			cin.clear();
			return false;  // return false (unsuccesful) - do not update variables
		} //end negative entry
		else
		{//make sure no digit is greater than the base and count total digits
			currNum = inNum;
			while (currNum > 0)
			{
				count++;
				digit = currNum % 10;
				if (digit > inBase-1)
				{
					cout << inNum << " is invalid: Base " << inBase << " numbers cannot have " << digit << " ( found at pos #  " << count << ")"
						<< endl;
					return false; //return false (unsuccessful) - do not update variables
				}  // end check invalid digit for base
				currNum = currNum / 10;
			}

			{// set the class variables
				base = inBase;
				number = inNum;
				numDigits = count;
				return true;
			}
		}
	}
}

		//function will convert the number to decimal 
		int Convert::getDecimalValue()
		{
			int currNum = number;	// holding area for processing the number to find the individual digits
			int currPlace =0;  // holds the current place value
			int digit = 0;		// holds the digit at the current place value
			int result = 0;    // will accumulate the total value in decimal to return
			int placeValue = 0;  // will hold the value for the digit in it's place 
			
			for(currPlace = 0; currPlace <= numDigits; currPlace++)
			{
				digit = currNum % 10; //remainder represents the digit for this place value
				currNum = currNum / 10;
				int temp = pow(base, currPlace);
				placeValue = digit * pow(base, currPlace);
				result = result + placeValue;
			}
			return result;
		}
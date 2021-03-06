///////////////////////////////////////////////////////////
// CIS554 Object Oriented Programming in C++
// Exercise 5_3 - Function overloading
// Patricia Gallant
///////////////////////////////////////////////////////////

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class Maximum
{
public:
	int GetMaximumValue(int num1, int num2, int num3)
	{
		cout << "GetMaximumValue with 3 parameters was called" << endl;
		int maxValue = num1;
		if (num2 > maxValue)
			maxValue = num2;
		if (num3 > maxValue)
			maxValue = num3;

		return maxValue;
	}
	// four parameter function
	int GetMaximumValue(int num1, int num2, int num3, int num4)
	{
		cout << "GetMaximumValue with 4 parameters was called" << endl;
		int maxValue = num1;
		if (num2 > maxValue)
			maxValue = num2;
		if (num3 > maxValue)
			maxValue = num3;
		if (num4 > maxValue)
			maxValue = num4;

		return maxValue;
	}
};

int main()
{
	int num1;
	int num2;
	int num3;
	int num4;
	char response = 'n';
	char cont = 'y';

	Maximum max;

	while (cont == 'y' || cont == 'Y')
	{
		cout << "Enter first number: ";
		cin >> num1;
		cout << "Enter second number: ";
		cin >> num2;
		cout << "Enter third number: ";
		cin >> num3;
		cout << "Do you have a fourth number? (y or n)";
		cin >> response;
		if (response == 'Y' || response == 'y')
		{
			cout << "Enter fourth number: ";
			cin >> num4;
			cout << "Max Value = " << max.GetMaximumValue(num1, num2, num3, num4) << endl;
		}
		else
		{
			cout << "Max Value = " << max.GetMaximumValue(num1, num2, num3) << endl;
		}

		cout << "Would you like to try again? (y to continue, any other key to quit)" << endl;
		cin >> cont;
	}

	return 0;
}

/////////////////////////////////////////////////////
// CIS554 Object Oriented Programming in C++
// Exercise 7_1 - Exception Handling  MAIN
// Patricia Gallant
/////////////////////////////////////////////////////
#include <iostream>
#include "DivideByZeroException.h" // DivideByZeroException class 
#include "NumberTooLargeException.h" //NumberTooLargeException class
using namespace std;

// perform division and throw DivideByZeroException object if 
// divide-by-zero exception occurs
double quotient(int numerator, int denominator) {
	// throw DivideByZeroException if trying to divide by zero
	if (denominator == 0) {
		throw DivideByZeroException{}; // terminate function
	}

	// return division result
	return static_cast<double>(numerator) / denominator;
}

double multiplication(int multiplicand, int multiplier)
{
	//throw number too large exception if result is > 1,000,000
	if (multiplicand * multiplier > 1000000)
	{
		throw NumberTooLargeException{}; // terminate function
	}
	return multiplicand * multiplier;
}//end multiplication function

int main() {
	int number1; // user-specified numerator
	int number2; // user-specified denominator

	cout << "Enter two integers (end-of-file to end): ";

	// enable user to enter two integers to divide
	while (cin >> number1 >> number2) {
		// try block contains code that might throw exception     
		// and code that will not execute if an exception occurs
		try {
			double result{ quotient(number1, number2) };
			cout << "The quotient is: " << result << endl;
		}
		catch (const DivideByZeroException& divideByZeroException) {
			cout << "Exception occurred: "
				<< divideByZeroException.what() << endl;
		}
		try {
			double result{ multiplication(number1, number2) };
			cout << "The product is: " << result << endl;
		}
		catch (const NumberTooLargeException& numberTooLargeException) {
			cout << "Exception occurred: "
				<< numberTooLargeException.what() << endl;
		}

		cout << "\nEnter two integers (end-of-file to end): ";
	} //end division while
	cout << endl;

}

//////////////////////////////////////////////
// CIS 554 Object Oriented Programming C++
// Patricia Gallant
// Homework 1
/////////////////////////////////////////////

#include <iostream>
using namespace std;

class Convert
{
public:
	explicit Convert();   // default constructor for the Convert class
	int getNumber();   // getter for the number being converted
	int getBase();     // getter for the base of the number being converted
	bool setInput();     // combined setter for the number and base 
	int getDecimalValue();   // method to convert the number and base provided by user to decimal value
		
private:
	int number;   //the number to convert
	int base;     //the base of the number being converted
	int result;     // the decimal value of the number
	int numDigits;  // the number of digits of the number being converted
	
};


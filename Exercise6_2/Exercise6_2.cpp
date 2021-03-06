///////////////////////////////////////////////////////////
// CIS554 Object Oriented Programming in C++
// Exercise 6_2 - Mulit-dimensional array objects
// Patricia Gallant
///////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
#include <array>
using namespace std;

size_t const rows{ 10 };
size_t const columns{ 10 };
void printArray(const array<array<int, columns>, rows>&);

int main()
{
	array< array<int, columns>, rows> n; // n is an 2D array of 10 columns and 10 rows holding int values
	int average = 0;  // average value of the elements of the array


	srand(static_cast<unsigned int>(time(0)));

	// initialize elements of array n to random numbers
	for (size_t row{ 0 }; row < rows; ++row)  // loop through array's rows
	{
		for (size_t column{ 0 }; column < columns; ++column)
		{
			n[row][column] = rand() % 100; // set element at location row, column to a random number from 1 to 99
			average = average + n[row][column];
		}
	}

	average = average / (rows * columns);  //complete average calculation

	printArray(n);
	cout << "\nAverage of values in array is: " << average << endl;

	return 0;
} //end main

void printArray(const array<array<int, columns>, rows>& a)
{
	int j = 0;  // will be column index for display
	int i = 0;  //will be row index for display

/*	cout << "Row" ;
	for (i=0; i < columns; i++)
	{ 
		cout << setw(7) << i;
	}
	cout << endl;
	cout << "---";
	for (i = 0; i < columns; i++)
	{
		cout << setw(7) << "---";
	}
	cout << endl;
*/

	//loop through array's rows
	for (auto const& row : a)
	{
		// loop through columns of current row, print row index
//		cout << j ;
		for (auto const& element : row)
		{
			cout << setw(7) << element;
			j++;
		} // end column loop
		cout << endl; // end of row, start new line of output
	j++;
	} // end row loop
} //end printArray




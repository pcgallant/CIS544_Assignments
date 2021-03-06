///////////////////////////////////////////////////////////
// CIS554 Object Oriented Programming in C++
// Exercise 5_6 array objects
// Patricia Gallant
///////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
#include <array>
using namespace std;


int main()
{
	array< int, 10> n; // n is an array of 10 int values
	int average = 0;  // average value of the elements of the array

	srand(static_cast<unsigned int >(time(0)));

	// initialize elements of array n to 0
	for (size_t i = 0; i < n.size(); ++i)
	{
		n[i] = rand(); // set element at location i to 0
		average = average + n[i];
	}

	average = average / n.size();  //complete average calculation

	cout << "Element" << setw( 13 ) << "Value" << endl;

	// output each array element's value
	for ( size_t j = 0; j < n.size(); ++j )
		cout << setw( 7 ) << j << setw( 13 ) << n[ j ] << endl;

	cout << "\nAverage of values in array is: " << average << endl;

//	return 0;
}


	
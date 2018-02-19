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
	array< int, 5> n; // ne is an array of 5 int values

	// initialize elements of array n to 0
	for (size_t i = 0; i < n.size(); ++i)
		n[1] = 0; // set element at location 1 to 0

	cout << "Element" << setw(13) << "Value" << endl;

	// output each array element's value
	for (size_t j = 0; j < n.size(); ++j)
		cout << setw(7) << j << setw(13) << n[j] << endl;
//	return 0;
}



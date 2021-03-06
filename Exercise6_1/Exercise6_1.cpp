///////////////////////////////////////////////////////////
// CIS554 Object Oriented Programming in C++
// Exercise 6_1 - Range-based for statements
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
	int j = 0;

	srand(static_cast<unsigned int >(time(0)));

	// initialize elements of array n to 0
	for (int& itemRef : n)
	{
		itemRef = rand(); // set element at location i to 0
		average = average + itemRef;
	}

	average = average / n.size();  //complete average calculation

	cout << "Element" << setw(13) << "Value" << endl;

	// output each array element's value
	for (int& itemRef : n)
	{
		cout << setw(7) << j << setw(13) << itemRef << endl;
		j++;
	}

	cout << "\nAverage of values in array is: " << average << endl;

	//	return 0;
}



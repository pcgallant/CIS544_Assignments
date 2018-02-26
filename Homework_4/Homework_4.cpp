/////////////////////////////////////////////////////
// CIS554 Object Oriented Programming in C++
// Homework 4 - main
// Patricia Gallant
///////////////////////////////////////////////////////

#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::endl;

#include <iomanip>
using std::setw;
using std::right;


class MultiDem
{
public:
	MultiDem();
	void PrintMultiDem();

private:
	// vector declaration
	vector<vector<int>> myMultiVector;
};

MultiDem::MultiDem()
// using the class initialization list to 
// construct vector as a [10][5] mulitdemensional vector, initialized to all 0
	: myMultiVector(10, vector<int>(5, 0))
{

	// iterate through the vector and put some data in it
	for (int rows = 0; rows<myMultiVector.size(); rows++)
	{
		for (int cols = 0; cols<myMultiVector.at(0).size(); cols++)
		{
			// put some data in each row and column using the vector.at() method
			myMultiVector.at(rows).at(cols) = rows + cols;

			// alternatively, this would work as well, and be acceptable
			// myMultiVector[rows][cols] = rows + cols;
		}
	}
}

void MultiDem::PrintMultiDem()
{
	for (int rows = 0; rows<myMultiVector.size(); rows++)
	{
		for (int cols = 0; cols<myMultiVector.at(0).size(); cols++)
		{
			// put some data in each row and column, using subscript notation
			cout << setw(4) << right << myMultiVector[rows][cols];

			// alternatively, this would work as well, and be acceptable
			// cout << myMultiVector.at(rows).at(cols);
		}

		// put a new line before printing the next row of data
		cout << endl;
	}
}

int main()
{
	MultiDem md;
	md.PrintMultiDem();
}

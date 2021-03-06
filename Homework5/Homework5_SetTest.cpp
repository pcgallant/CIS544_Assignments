///////////////////////////////////////////////////////////
// CIS554 Object Oriented Programming in C++
// Homework 5 - Set Test Driver (main)
// Patricia Gallant
///////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

#include "Set.h"


int main()
{
	vector<bool> test1{ false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false };
	vector<bool> test2{ true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true };
	vector<bool> test3{ true, true, true, true, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false };
	vector<bool> test4{ true, true, true, true, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false };
	int inInteger = 0;



	Set testSet1(test1);
	Set testSet2(test2);
	Set testSet3(test3);
	Set testSet4(test4);

	cout << "Test Set 1" << endl;
	testSet1.Print();

	cout << "Test Set 2" << endl;
	testSet2.Print();

	cout << "Test Set 3" << endl;
	testSet3.Print();

	cout << "Test Set 4" << endl;
	testSet4.Print();

	cout << "Enter integer to find in each set";
	cin >> inInteger;
	if (cin.fail()) {
		cout << "Invalid input, please enter an integer" << endl;
		cin.clear();

	}

	return 0;
}


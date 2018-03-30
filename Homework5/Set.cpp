///////////////////////////////////////////////////////////
// CIS554 Object Oriented Programming in C++
// Homework 5 - Set class definition
// Patricia Gallant
///////////////////////////////////////////////////////////
#include <iostream>
#include <iomanip>
using namespace std;

#include "Set.h"


Set::Set()
	:setVector{ true }
{
}

Set::Set(vector<bool> v)
{
	setVector.push_back(v);
}


Set::~Set()
{
}

bool Set::IsMember(int x)
{
	return this->setVector[x];   // return the bool value of the appropriate index from the set vector
}

Set Set::Union(Set & s)
{
	Set unionSet;

	//loop through this classes vector set and the passed set to build a return set that is union of all true values from both sets
	for (size_t myIndex = 0; myIndex < this->setVector.size(); myIndex++) {
		for (size_t inIndex = 0; inIndex < s.setVector.size(); inIndex++)
		{
			if (this->setVector.at(myIndex) == true || s.setVector.at(inIndex) == true)
			{
				unionSet.setVector.push_back(true);
			}
			else
			{
				unionSet.setVector.push_back(false);
			}
		}
	}
	return unionSet;
}

Set Set::Intersection(Set & s)
{
	Set interSection;

	//loop through this classes vector set and the passed set to build a return set that is union of all true values from both sets
	for (size_t myIndex = 0; myIndex < this->setVector.size(); myIndex++) {
		for (size_t inIndex = 0; inIndex < s.setVector.size(); inIndex++)
		{
			if (this->setVector.at(myIndex) == true && *s.setVector.at(inIndex) == true)
			{
				interSection.setVector.push_back(true);
			}
			else
			{
				interSection.setVector.push_back(false);
			}
		}
	}
	return interSection;
}

void Set::Print()
{
	for (size_t i = 0; i < this->setVector.size(); i++)
	{
		cout << setw(4) << this->setVector.at(i) << endl;
	}
}
///////////////////////////////////////////////////////////
// CIS554 Object Oriented Programming in C++
// Homework 5 - Set class interface
// Patricia Gallant
///////////////////////////////////////////////////////////
#include <vector>
using std::vector;
class Set
{
public:
	Set();				// default constructor
	Set(vector<bool> v);		// initializer constructor
	~Set();

	bool IsMember(int x);
	Set Union(Set &s);  //returns a set that represents the union of this set and S
	Set Intersection(Set & s);  // retruns a Set that represents the intersection of this set and S
	void Print();  // prints the members of this Set

private:
	vector<bool> setVector;


};
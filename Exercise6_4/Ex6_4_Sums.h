///////////////////////////////////////////////////////////
// CIS554 Object Oriented Programming in C++
// Exercise 6_4 - Pass by reference with pointers
// Patricia Gallant
///////////////////////////////////////////////////////////
class Ex6_4_Sums
{
public:
	Ex6_4_Sums();
	bool SetEndInt(int * nPtr);
	int SumAllInt(int * nPtr);
private:
	int endInt;
};


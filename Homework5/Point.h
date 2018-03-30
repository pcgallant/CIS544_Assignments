///////////////////////////////////////////////////////////
// CIS554 Object Oriented Programming in C++
// Homework 5 - Point class interface
// Patricia Gallant
///////////////////////////////////////////////////////////

class Point
{
public:
	Point();  // default constructor
	~Point();
	Point(int xVal, int yVal);  // initializer constructor

	void SetY(int yVal);
	int GetY();
	void SetX(int xVal);
	int GetX();

private:
	int xCoord;
	int yCoord;
};
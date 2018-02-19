#include <iostream>
using namespace std;
class Ex5_1_TimeDiff
{
public:
	Ex5_1_TimeDiff();
	int SecondsSinceNoon(int &hour, int& min, int &sec);
	bool ValidateTime(int &hour, int  & min, int & sec);

private:

	int secSinceNoon;
};


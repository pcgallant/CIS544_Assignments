#include <iostream>
using namespace std;
class TimeDiff
{
public:
	TimeDiff();
	int SecondsSinceNoon(int hour, int min, int sec);
	bool ValidateTime(int hour, int min, int sec);
	 
private:

	int secSinceNoon;
};


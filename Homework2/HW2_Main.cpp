/////////////////////////////////////////////////////
// CIS554 Object Oriented Programming in C++
// Homework 2 - main
// Patricia Gallant
///////////////////////////////////////////////////////
//
#include <iostream>
#include "Worker.h"
using namespace std;

int main()
{
	int inputCode = 0;
	Worker indivWorker;


	//cout << "Enter paycode (-1 to end):";
	//cin >> inputCode;
	

	while (inputCode != -1)
	{ 
		cout << "\nEnter paycode (-1 to end):";
		cin >> inputCode;
	//	cin.clear();
	//	cin.ignore(256, '\n');

		switch (inputCode)
		{
		case 1: // manager
			indivWorker.CalcManagerPay();
			break;
		case 2: //Hourly
			indivWorker.CalcHourlyPay();
			break;
		case 3: //Commission
			indivWorker.CalcCommissionPay();
			break;
		case 4: //Piece worker
			indivWorker.CalcPieceworkPay();
			break;
		case -1: // Quit
			cout << "\n\n";
			break;
		default: //invalid
			cout << "\nInvalid entry. worker type must be 1, 2, 3, or 4 (or -1 to end).\n";
			break;
		}
	}

	indivWorker.DisplaySummary();
    return 0;
}


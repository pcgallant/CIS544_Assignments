/////////////////////////////////////////////////////
// CIS554 Object Oriented Programming in C++
// Homework 2 - Worker class definition
// Patricia Gallant
///////////////////////////////////////////////////////
#include <iostream>
#include <iomanip>
#include "Worker.h"
using std::cout;
using std::cin;
using std::setprecision;
using std::fixed;


Worker::Worker()
	:typeCode (0), totalMgrPay(0.0), totalHrlPay(0.0), totalCommPay(0.0), totalPiecePay(0.0)
{
	//default constructor 
}

void Worker::CalcManagerPay()
{
	double weeklySal = 0.0;
	cout << "\nManager was selected.";
	cout << "\nEnter weekly salary: ";
	cin >> weeklySal;
	//Manager pay is a fixed weekly salary
	cout << "Worker's pay is $" << weeklySal << setprecision(2) << fixed << endl;
	totalMgrPay = totalMgrPay + weeklySal;
	return ;
}

void Worker::CalcHourlyPay()
{
	int hoursWorked;  //the number of hours worked
	int const standardWeek = 40;
	int otHours;
	double hrlyRate = 0;
	double sal = 0;
	cout << "\nHourly worker was selected.";
	cout << "\nEnter hourly salary: ";
	cin >> hrlyRate;
	cout << endl << "Enter the total hours worked: ";
	cin >> hoursWorked;

	if (hoursWorked > 40)
	{
		otHours = hoursWorked - standardWeek;
		sal = (otHours * hrlyRate * 1.5) + (standardWeek * hrlyRate);
	}
	else
	{
		sal = hoursWorked * hrlyRate;
	}
	totalHrlPay = totalHrlPay + sal;
	cout << "Worker's pay is $" << sal << setprecision(2) << fixed << endl;
	return ;
}

void Worker::CalcCommissionPay()
{
	double const baseCommPay = 250.00;
	double const commPct = 0.057;
	double grossSales = 0;
	double sal = 0;
	cout << "\nCommission worker was selected.";
	cout << "\nEnter gross weekly sales: ";
	cin >> grossSales;
	
	sal = baseCommPay + (grossSales * commPct);
	totalCommPay = totalCommPay + sal;
	cout << "Worker's pay is $" << sal << setprecision(2) << fixed << endl;

	return ;

}

void Worker::CalcPieceworkPay()
{
	double pieceRate = 0;
	int pieceCnt = 0;
	double sal = 0;

	cout << "\nPiece worker was selected.";
	cout << "\nEnter number of pieces: ";
	cin >> pieceCnt;
	cout << "Enter wage per piece: ";
	cin >> pieceRate;

	sal = pieceCnt * pieceRate;
	cout << "Worker pay is $" << sal << setprecision(2) << fixed;
	totalPiecePay = totalPiecePay + sal;
	cout << "Worker's pay is $" << sal << setprecision(2) << fixed << endl;

	return ;

}


void Worker::CreateBarChart()
{
	/*TODO Create a bar chart (using a private utility function in the Worker class) that indicates how much money
	was earned by each type of employee, rounded to 100’s of dollars. E.g., if $1232 was earned, there would be 12 asterix characters.
	The bar chart should look something like this:

	Managers 	**********
	Hourly    	*****
	Commission  ************
	Pieceworker	*******
	*/

	int numStars = 0;
	//TODO create asterisk bar for each worker type's total pay
	cout << "\n\nSummary Chart";
	cout << "\nManagers:   ";
	numStars = static_cast<int>(totalMgrPay / 100);
	for(int i=0; i < numStars; i++)
	{ 
		cout << "*";
	}
	
	cout << "\nHourly:     ";
	numStars = static_cast<int>(totalHrlPay / 100);
	for (int i = 0; i < numStars; i++)
	{
		cout << "*";
	}
	cout << "\nCommission: ";
	numStars = static_cast<int>(totalCommPay / 100);
	for (int i = 0; i < numStars; i++)
	{
		cout << "*";
	}
	cout << "\nPiece Work: ";
	numStars = static_cast<int>(totalPiecePay / 100);
	for (int i = 0; i < numStars; i++)
	{
		cout << "*";
	}
	cout << "\n\nGoodbye!\n\n";
/*		cout << "\nDisplay Summary:  "
		<< "\nManagers:   " << fixed << setprecision(2) << totalMgrPay
		<< "\nHourly:     " << fixed << setprecision(2) << totalHrlPay
		<< "\nCommission: " << fixed << setprecision(2) << totalCommPay
		<< "\nPiece Work: " << fixed << setprecision(2) << totalPiecePay << "\n";
*/
}


void Worker::DisplaySummary()
{
	CreateBarChart();

}


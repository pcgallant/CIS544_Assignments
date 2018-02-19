/////////////////////////////////////////////////////
// CIS554 Object Oriented Programming in C++
// Homework 2 - worker class interface
// Patricia Gallant
///////////////////////////////////////////////////////

#include <iostream>
using namespace std;

class Worker
{  
public:
	Worker();
	void CalcManagerPay();
	void CalcHourlyPay();
	void CalcCommissionPay();
	void CalcPieceworkPay();
	
	void DisplaySummary();

private:
	int typeCode;  //the type of worker
	double totalMgrPay = 0;
	double totalHrlPay = 0;
	double totalCommPay = 0;
	double totalPiecePay = 0;
	void CreateBarChart();
	
	

};


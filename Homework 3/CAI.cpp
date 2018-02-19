/////////////////////////////////////////////////////
// CIS554 Object Oriented Programming in C++
// Homework 3 - CAI class definition
// Patricia Gallant
///////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <iomanip>
#include "CAI.h"
using namespace std;

CAI::CAI()
	: number1(1), number2(1), firstRightCnt(0), mult1stRight(0), wrongAnsCnt(0), nbrProbs(0), 
		divProbsAsked(0), multProbsAsked(0), currProbType('M')
{
	//default constructor
	setNbrProbs();

	// seed random number generator with current time
	srand(static_cast<unsigned int>(time(0)));
}

void CAI::genNextMult()
{ 
	number1 = rand() % 10;  // get random number from 0 - 9 for multiplicand
	number2 = rand() % 10;  // get random number from 0 - 9 for multiplier
	multProbsAsked++;  //increment count of multiplication problems generated
	currProbType = 'M'; 
	operStr = " times ";
	return;
}

void CAI::genNextDiv()
{// 
	number1 = rand() % 10;  // get random number from 0 - 9 for dividend
	number2 = 1 + rand() % 9;  // get random number from 1 - 9 for divisor
	divProbsAsked++;  //increment count of division problems generated
	currProbType = 'D';
	operStr = " divided by ";
	return;
}

bool CAI::checkAnswer(int answer)
{
	int responseNbr = 0; 
	bool check = true;
	responseNbr = rand() % 4;  // generate random number to provide differentiated responses to reduce student fatigue

	//Compare student's answer to the correct answer and respond
	switch (currProbType)
	{
	case 'D':
			check = (answer == number1 / number2);
			break;
	case 'M':
		check = (answer == number1 * number2);
		break;
	}

	//Determine random response code -- create switch statement for the code
	if (check == true)
	{  // cycle through correct answer responses
		switch (responseNbr)
		{
		case 0: 
			cout << " Very good!\n";
			break;
		case 1:
			cout << " Excellent!\n";
			break;
		case 2:
			cout << " Nice work!\n";
			break;
		case 3:
			cout << " You're rocking this stuff!\n";
			break;
		default:
			cout << " Correct!\n";
			break;
		}
	}
	else
	{
		setWrongAnsCnt();

		switch (responseNbr)
		{
		case 0:
			cout << " No.  Please try again.\n";
			break;
		case 1:
			cout << " Wrong.  Try once more.\n";
			break;
		case 2:
			cout << " Don't give up!\n";
			break;
		case 3:
			cout << " No.  Take a breath and keep trying. You can do this!";
			break;
		default:
			cout << " Wrong answer.  Try again.\n";
			break;
		}
	}
	
	return check;
}

void CAI::askNewQuestion()
{
	int randInt = 0;

	//error check that there are still questions to ask
	if ((multProbsAsked + divProbsAsked) == nbrProbs)
	{ //total number of problems have been asked, exit with error, should never get here!
		cout << "LOGIC ERROR!  Check looping rules have exceeded max number of questions to ask.  /nmultProbsAsked = " << multProbsAsked
			<< "  divProbsAsked = " << divProbsAsked << " nbrProbs = " << nbrProbs << endl;
	}
	//TODO generate random math problem alternating randomly between multiplication and division
	if (multProbsAsked >= nbrProbs / 2)
	{
		//have asked all the multiplication problems, so generate the next division problem
		genNextDiv();
	}
	else if (divProbsAsked >= nbrProbs / 2)
	{
		//have asked all the division problems already, so set the problem to multiplication
		
		genNextMult();
	}
	else
	{
		randInt = rand() % 2;
		switch (randInt)
		{
		case 0:
			currProbType = 'M';
			genNextMult();
			break;
		case 1:
			currProbType = 'D';
			genNextDiv();
			break;
		}
	}
	//Display question
	displayQuestion();
	return;
}

bool CAI::getAnswer()
{
	int answer = 0;

	cin >> answer;
	//TODO is there are way to add a timer to re-prompt?

	return checkAnswer(answer);
}

void CAI::setNbrProbs()
{
	nbrProbs = 10;
	return;
}

void CAI::setNbrProbs(int setSize)
{
	// allow extension to override the total # of practice problems
	if (setSize % 2 != 0)
	{ //require even number of problems, so add one to integer
		nbrProbs = setSize + 1;
	}
	else
	{
		nbrProbs = setSize;
	}
	return;
}

void CAI::setfirstRightCnt()
{
	firstRightCnt++;
	return;
}

void CAI::setWrongAnsCnt()
{
	wrongAnsCnt++;
	return;
}

int CAI::getNbrProbs()
{
	return nbrProbs;
}

void CAI::displayQuestion()
{
	cout << "\n" << divProbsAsked + multProbsAsked << ") What is " << number1 << operStr << number2 << " ? ";
	return;
}



void CAI::displayResults()
{//TODO provide summary of how student did
	int avgGuesses = wrongAnsCnt / (nbrProbs - firstRightCnt);   // calculated average of guesses on problems not answered right on the first try

	//TODO improve if you have time by having the wrap-up comments cycle through random responses
	cout << "**************************************************************************" << endl;
	cout << "* Great job! A little more practice and you could do this in your sleep. *" << endl;
	cout << "* Check out your results!                                                *" << endl;
	cout << "**************************************************************************" << endl;
	cout << "            Problems answered right on FIRST try: " << firstRightCnt << endl;
	cout << "            Average # of wrong answers tried:     " << avgGuesses <<  endl;
	cout << "**************************************************************************" << endl << endl;
	cout << " See you again soon!" << endl << endl;


	return;
}

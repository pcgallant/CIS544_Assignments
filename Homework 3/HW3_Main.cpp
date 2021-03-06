/////////////////////////////////////////////////////
// CIS554 Object Oriented Programming in C++
// Homework 3 - main
// Patricia Gallant
///////////////////////////////////////////////////////

#include <iostream>
#include "CAI.h"
using namespace std;


int main()
{
	CAI practice;
	int attempts = 0; // track the number of attempts on any particular question
	cout << "Hi there!  I'm Noggin, your Math Study Buddy. ";
		cout << "\nI'm thrilled to help you practice multiplication and division.   \n\n Ready....Set....GO!\n\n" ;
	
	//set the total number of problems attribute
	practice.setNbrProbs();

	//TODO loop to ask questions & process answers
	for (int i = 0; i < practice.getNbrProbs(); i++)
	{
		attempts = 0;  //reinitialize attempts for this question
		practice.askNewQuestion();
			while (practice.getAnswer() == false )  // continue to get new answers until they get it right
			{
				attempts++;  //increment the # of attempted answer
				practice.displayQuestion();
			}

			attempts++;  // increment the # of attempted answers, will only do this if answer is correct

			if (attempts == 1)
			{
				//student got the question right the first time
				practice.setfirstRightCnt();
			}
			continue;  // Student has answered correctly, so ask the next question
	}
	// all questions completed, display the results
	practice.displayResults();
    return 0;
}


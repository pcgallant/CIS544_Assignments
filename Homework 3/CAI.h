/////////////////////////////////////////////////////
// CIS554 Object Oriented Programming in C++
// Homework 3 - CAI class interface header
// Patricia Gallant
///////////////////////////////////////////////////////
class CAI
{
public:
	CAI();

	void askNewQuestion();  //will return a random multiplication or division problem.  Will choose randomly but will always be half of each type
	bool getAnswer(); // will receive and check the students answer and respond.  Will return true if correct and false if incorrect
	void setNbrProbs();  // default set
	void setNbrProbs(int setSize); //allow override of default # of problems: 10 total, 5 mult and 5 div
	void setfirstRightCnt();  //set value of # of questions answered correctly on the first try
	void setWrongAnsCnt();  //set value of # of wrong answers
	int getNbrProbs(); // return the # of problems to be solved
	void displayQuestion();  //will re-display the current question for new tries
	void displayResults(); //will provide summary information about the practice session

private:
	int number1;   // random single digit integer - multiplicand or dividend
	int number2;   // random single digit integer -  multiplier or divisor (will not allow zero)
	
	int firstRightCnt;  // total number of problems answered right on first attempt
	int mult1stRight; // number of mulitplication problems right on first attempt
	int wrongAnsCnt;  // total number of answers wrong
	
	int nbrProbs;     // the number of problems for the session -- default is 10
	
	int divProbsAsked;  //will count the number of division problems that have been asked so far
	int multProbsAsked; //will keep count of the number of multiplication problems that have been asked

	char currProbType;  //indicates the current math problem being asked: "M"= mulitplication; "D" = division
	std::string operStr;  // the text for the current operator to use in the question

	void genNextMult(); // will generate  random multiplication integer set and update class integer1, integer2
	void genNextDiv();  // will generate randome division problem integer set and update class integer1, integer2
	bool checkAnswer(int answer); // will check and provide response to answer provided and return result
};


/////////////////////////////////////////////////////
// CIS554 Object Oriented Programming in C++
// Homework 4 - main
// Patricia Gallant
///////////////////////////////////////////////////////

#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <iomanip>
using std::setw;
using std::right;

#include "WordFont.h"

int main()
{
	string inputWord;
	char inputCode = 'y';
	int inputNum = 0;
	char inputWeight = ' ';
	int inputSize = 0;
	char inputSame = ' ';
	char inputPixel = ' ';

	
	WordFont myWord;
	cout << "This program will display any word (up to 6 letters) you enter using the requested character, fontsize and weight you would like. " << endl;
	cout << "At this time, the program is limited to words with only the following letters : \n" << myWord.getImplementedLetters() << endl;

	//Loop through the prompts until user decides to quit
	while (inputCode != 'N' && inputCode != 'n')
	{
		inputPixel = ' ';
		cout << "\n\nEnter the word you want to print: " ;
		cin >> inputWord;
		if (myWord.validateWordLength(inputWord) == false)
		{
			cout << "Must limmit word to  6 letters, because that is all that will fit across the screen" << endl;
			continue;
		}
		if (cin.fail())
		{
			cin.clear();
		}
		cout << "\nWhat size font? (8 -12):";
		cin >> inputSize;
		if (cin.fail())
		{
			cin.clear();
		}
		myWord.setFontSize(inputSize);
		cout << "\nWhat weight font? (N = normal, B = bold):";
		cin >> inputWeight;
		if (cin.fail())
		{
			cin.clear();
		}
		myWord.setFontWeight(inputWeight);
		cout << "Do you want each letter drawn with the same pixel character (Y or N)?";
		cin >> inputSame;
		if (cin.fail())
		{
			cin.clear();
		}
		else if (inputSame == 'Y' || inputSame == 'y') {
			cout << "Enter the pixel character you want to use to draw the letters: ";
			cin >> inputPixel;
			if (cin.fail())
			{
				cin.clear();
			}
		}
		else {
			cout << "Ok, each letter will be drawn using the letter as the pixel character." << endl;
			inputPixel = ' ';
		}

		myWord.printWord(inputSize, inputPixel, inputWeight, inputWord);

		cout << "\nAgain? (N to quit.  Any other value to continue): ";
		cin >> inputCode;
		if (cin.fail())
		{
			cin.clear();
		}
	}
	return 0;
}

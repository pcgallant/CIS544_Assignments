#include <iostream>
using std::cout;
using std::endl;
#include <iomanip>
using std::setw;
#include <vector>
#include <stdexcept>
using namespace std;
#include "WordFont.h"

WordFont::WordFont()
	:minFontSize(8), maxFontSize(12), maxWordLength(6), pixelChar(' '), fontSize(8), weightTyp('N'), boldFont('B'), normalFont('N'),
	implementedLetters("A, B, C, D, E, H, I, L, M, N, O, R, S, T, U")
{
};

void WordFont::setFontSize(int fSize)
{
	if (validateFontSize(fSize) == true)
	{
		fontSize = fSize;
		return;
	}
	else if (fSize < minFontSize)
	{
		cout << "Font size " << fSize << " too small.  Using the min font size of " << minFontSize << endl;
		fontSize = 8;
		return;
	}
	else
	{//fSize > 12
		cout << "Font size  " << fSize << " too large. Using the max font size of " << maxFontSize << endl;
		fontSize = maxFontSize;
		return;
	}
}

int WordFont::getFontSize()
{
	return fontSize;
}

void WordFont::setFontWeight(char weight)
{
	if (validateFontWeight(weight) == true)
	{
		if (weight == 'b' || weight == 'B')
		{
			weightTyp = boldFont;
		}
		else
		{
			weightTyp = normalFont;
		}
	}
	else
	{
		cout << "Invalid weight type, will use Normal weight" << endl;
		weightTyp = normalFont;
	}
	return;
}

char WordFont::getFontWeight()
{
	return weightTyp;
}

void WordFont::setPixelChar(char inputC)
{
	if (inputC == ' ' || inputC == NULL)
	{
		cout << "You either entered blank or nothing as your pixel character.  Will use each letter as the pixel char for that letter. " << endl;
	}
	pixelChar = inputC;
}

char WordFont::getPixelChar()
{
	return pixelChar;
}

int const WordFont::getMaxFontSize()
{
	return maxFontSize;
}

int const WordFont::getMinFontSize()
{
	return minFontSize;
}

size_t const WordFont::getMaxWordLength()
{
	return maxWordLength;
}

string WordFont::getImplementedLetters()
{
	return implementedLetters;
}

bool WordFont::validateFontSize(int fSize)
{
	if (fSize >= minFontSize && fSize <= maxFontSize)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool WordFont::validateFontWeight(char fWeight)
{
	if (fWeight == 'n' || fWeight == 'N' || fWeight == 'B' || fWeight == 'b')
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool WordFont::validateWordLength(string inWord)
{
	if (inWord.length() <= maxWordLength)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void WordFont::printWord(int fSize, char pChar, char fWeight, string inWord)
{
	//set the font characteristics in the class member data
	setFontSize(fSize);
	setPixelChar(pChar);
	setFontWeight(fWeight);
	static const string kernStr = " ";   // blank to separate each letter
//	int kernAmt = fontSize % minFontSize + 1;  // put 1 - 4 spaces between letters depending on font size
	int kernAmt = 1;  // always use 1
// clear the formattedWord vector 
	formattedWord.clear();

	// Format the multi-dimensional vector for each letter in the word also validated the letters used are supported
	if (setFormattedWord(inWord) != true)
	{  //Input word encountered errors processing this letter, stop processing
		cout << "In printWord LN119: error processing letter!" << endl;
		return;
	}

	//   PRINT THE WORD from the MultiDimensional Vector
	for (size_t rows = 0; rows < formattedWord.at(0).size(); rows++)
	{// loop through the rows of the letters
		for (size_t ltrIdx = 0; ltrIdx < inWord.length(); ltrIdx++)
		{ // loop through the letters, row by row
			for (int cols = 0; cols < fontSize; cols++)
			{  // print the character in the column
				cout << formattedWord.at(ltrIdx).at(rows).at(cols);

			} // end of all columns for the letter
			// put separator between the letter
			for (int i = 0; i < kernAmt; i++)
			{
				cout << kernStr;
			}
		} // end of letter
		cout << endl;   // end of line after the last letter's row is printed
	} // end of row
	cout << endl;
	return;
}

bool WordFont::setFormattedWord(string word)
{
	int rc = 0;  // return code from format routine
	char currLett = ' ';  // holds the uppercase value of the letter being processed
//	cout << "In setFormmattedWord for word: " << word << endl;
	//Loop through the input word and insert the correct 2-D vector into the formated word vector
	for (size_t ltrIdx = 0; ltrIdx < word.length(); ltrIdx++)
	{
		//		cout << "LN162: the letter is: " << word.at(ltrIdx);
		switch (word.at(ltrIdx))
		{
		case 'a':
		case 'A':
			currLett = 'A';
			rc = formatA(ltrIdx);
			break;
		case 'b':
		case 'B':
			currLett = 'B';
			rc = formatB(ltrIdx);
			break;
		case 'c':
		case 'C':
			currLett = 'C';
			rc = formatC(ltrIdx);
			break;
		case 'd':
		case 'D':
			currLett = 'D';
			rc = formatD(ltrIdx);
			break;
		case 'e':
		case 'E':
			currLett = 'E';
			rc = formatE(ltrIdx);
			break;
/*
		case 'f':
			
					case 'F':
					currLett = 'F';
						formatF(ltrIdx);
						break;
					case 'g':
					case 'G':
						formatG(ltrIdx);
						break;
			*/
		case 'h':
		case 'H':
			currLett = 'H';
			rc = formatH(ltrIdx);
			break;
		case 'i':
		case 'I':
			currLett = 'I';
			rc = formatI(ltrIdx);
			break;
			/*
					case 'j':
					case 'J':
						rc = formatJ(ltrIdx);
						break;
					case 'k':
					case 'K':
						rc = formatK(ltrIdx);
						break;
			*/
		case 'l':
		case 'L':
			currLett = 'L';
			rc = formatL(ltrIdx);
			break;
		case 'm':
		case 'M':
			currLett = 'M';
			rc = formatM(ltrIdx);
			break;
		case 'n':
		case 'N':
			currLett = 'N';
			rc = formatN(ltrIdx);
			break;
		case 'o':
		case 'O':
			currLett = 'O';
			rc = formatO(ltrIdx);
			break;
			/*
					case 'p':
					case 'P':
						rc = formatP(ltrIdx);
						break;
					case 'q':
					case 'Q':
						rc = formatQ(ltrIdx);
						break;
			*/
		case 'r':
		case 'R':
			currLett = 'R';
			rc = formatR(ltrIdx);
			break;
		case 's':
		case 'S':
			currLett = 'S';
			rc = formatS(ltrIdx);
			break;
		case 't':
		case 'T':
			currLett = 'T';
			rc = formatT(ltrIdx);
			break;
		case 'u':
		case 'U':
			currLett = 'U';
			rc = formatU(ltrIdx);
			break;
			/*
		case 'v':
					case 'V':
						rc = formatV(ltrIdx);
						break;
					case 'w':
					case 'W':
						rc = formatW(ltrIdx);
						break;
					case 'x':
					case 'X':
						rc = formatX(ltrIdx);
						break;
					case 'y':
					case 'Y':
						rc = formatY(ltrIdx);
						break;
					case 'z':
					case 'Z':
						rc = formatZ(ltrIdx);
						break;
			*/
		default:
			cout << "Letter " << word.at(ltrIdx) << " is not supported" << endl;
			return false;
		}

		//configuration error checking
		if (fontSize != formattedWord.at(ltrIdx).size())
		{
			cout << "LOGIC ERROR:  bad data, the loaded letter vector is not the correct font size!" << endl;
			cout << "Letter: " << word.at(ltrIdx) << " fontSize= " << fontSize << " loaded vector size = " << formattedWord.at(ltrIdx).size() << endl;
			return false;
		}
		if (currLett != pixelChar && pixelChar != ' ')
		{ // Replace all instances of this letter in the vector with the requested pixel character 
			maskLetter(ltrIdx, currLett);
		}
	}
	if (rc == 0)
	{
		return true;
	}
	else {
		return false;
	}

}

int WordFont::formatA(int letIdx)  // pass in the index value for the location in the formatted word vector to place the formatted letter
{
	int error = 0;
	static const char thisLetter = 'A';
	//NORMAL font definitions
	static const vector<vector<char>> aN8 = //definition of 8-pixel normal A font
	{
	{' ',' ',' ','A','A',' ',' ',' '},
	{' ',' ','A',' ',' ','A',' ',' '},
	{' ','A',' ',' ',' ',' ','A',' '},
	{' ','A',' ',' ',' ',' ','A',' '},
	{' ','A','A','A','A','A','A',' '},
	{' ','A',' ',' ',' ',' ','A',' '},
	{' ','A',' ',' ',' ',' ','A',' '},
	{' ','A',' ',' ',' ',' ','A',' '} };
	static const vector<vector<char>> aN9 =   // definition of 9-pixel normal A font
	{
	{' ',' ',' ','A','A','A',' ',' ',' '},
	{' ',' ','A',' ',' ',' ','A',' ',' '},
	{' ','A',' ',' ',' ',' ',' ','A',' '},
	{' ','A',' ',' ',' ',' ',' ','A',' '},
	{' ','A',' ',' ',' ',' ',' ','A',' '},
	{' ','A','A','A','A','A','A','A',' '},
	{' ','A',' ',' ',' ',' ',' ','A',' '},
	{' ','A',' ',' ',' ',' ',' ','A',' '},
	{' ','A',' ',' ',' ',' ',' ','A',' '} };
	static const vector<vector<char>> aN10 = // definition of 10-pixel normal A font
	{
	{' ',' ',' ','A','A','A','A',' ',' ',' '},
	{' ',' ','A',' ',' ',' ',' ','A',' ',' '},
	{' ','A',' ',' ',' ',' ',' ',' ','A',' '},
	{' ','A',' ',' ',' ',' ',' ',' ','A',' '},
	{' ','A',' ',' ',' ',' ',' ',' ','A',' '},
	{' ','A','A','A','A','A','A','A','A',' '},
	{' ','A',' ',' ',' ',' ',' ',' ','A',' '},
	{' ','A',' ',' ',' ',' ',' ',' ','A',' '},
	{' ','A',' ',' ',' ',' ',' ',' ','A',' '},
	{' ','A',' ',' ',' ',' ',' ',' ','A',' '} };
	static const vector<vector<char>> aN11 = // definition of 11-pixel normal A font
	{
	{' ',' ',' ',' ','A','A','A',' ',' ',' ',' '},
	{' ',' ',' ','A',' ',' ',' ','A',' ',' ',' '},
	{' ',' ','A',' ',' ',' ',' ',' ','A',' ',' '},
	{' ','A',' ',' ',' ',' ',' ',' ',' ','A',' '},
	{' ','A',' ',' ',' ',' ',' ',' ',' ','A',' '},
	{' ','A',' ',' ',' ',' ',' ',' ',' ','A',' '},
	{' ','A','A','A','A','A','A','A','A','A',' '},
	{' ','A',' ',' ',' ',' ',' ',' ',' ','A',' '},
	{' ','A',' ',' ',' ',' ',' ',' ',' ','A',' '},
	{' ','A',' ',' ',' ',' ',' ',' ',' ','A',' '},
	{' ','A',' ',' ',' ',' ',' ',' ',' ','A',' '} };
	static const vector<vector<char>> aN12 = // definition of 12-pixel normal A font
	{
	{' ',' ',' ',' ','A','A','A','A',' ',' ',' ',' '},
	{' ',' ',' ','A',' ',' ',' ',' ','A',' ',' ',' '},
	{' ',' ','A',' ',' ',' ',' ',' ',' ','A',' ',' '},
	{' ','A',' ',' ',' ',' ',' ',' ',' ',' ','A',' '},
	{' ','A',' ',' ',' ',' ',' ',' ',' ',' ','A',' '},
	{' ','A',' ',' ',' ',' ',' ',' ',' ',' ','A',' '},
	{' ','A','A','A','A','A','A','A','A','A','A',' '},
	{' ','A',' ',' ',' ',' ',' ',' ',' ',' ','A',' '},
	{' ','A',' ',' ',' ',' ',' ',' ',' ',' ','A',' '},
	{' ','A',' ',' ',' ',' ',' ',' ',' ',' ','A',' '},
	{' ','A',' ',' ',' ',' ',' ',' ',' ',' ','A',' '},
	{' ','A',' ',' ',' ',' ',' ',' ',' ',' ','A',' '}
	};

	//BOLD font definitions
	static const vector<vector<char>> aB8 =		//definition of 8-pixel bold A font
	{
	{ ' ',' ','A','A','A','A',' ',' ' },
	{ ' ','A','A','A','A','A','A',' ' },
	{ 'A','A',' ',' ',' ',' ','A','A' },
	{ 'A','A','A','A','A','A','A','A' },
	{ 'A','A','A','A','A','A','A','A' },
	{ 'A','A',' ',' ',' ',' ','A','A' },
	{ 'A','A',' ',' ',' ',' ','A','A' },
	{ 'A','A',' ',' ',' ',' ','A','A' } };
	static const vector<vector<char>> aB9 =		// definition of 9-pixel bold A font
	{
	{ ' ',' ','A','A','A','A','A',' ',' ' },
	{ ' ','A','A','A','A','A','A','A',' ' },
	{ 'A','A',' ',' ',' ',' ',' ','A','A' },
	{ 'A','A',' ',' ',' ',' ',' ','A','A' },
	{ 'A','A','A','A','A','A','A','A','A' },
	{ 'A','A','A','A','A','A','A','A','A' },
	{ 'A','A',' ',' ',' ',' ',' ','A','A' },
	{ 'A','A',' ',' ',' ',' ',' ','A','A' },
	{ 'A','A',' ',' ',' ',' ',' ','A','A' } };
	static const vector<vector<char>> aB10	// definitionof 10-pixel bold A font
	{
	{ ' ',' ','A','A','A','A','A','A',' ',' ' },
	{ ' ','A','A','A','A','A','A','A','A',' ' },
	{ 'A','A',' ',' ',' ',' ',' ',' ','A','A' },
	{ 'A','A',' ',' ',' ',' ',' ',' ','A','A' },
	{ 'A','A','A','A','A','A','A','A','A','A' },
	{ 'A','A','A','A','A','A','A','A','A','A' },
	{ 'A','A',' ',' ',' ',' ',' ',' ','A','A' },
	{ 'A','A',' ',' ',' ',' ',' ',' ','A','A' },
	{ 'A','A',' ',' ',' ',' ',' ',' ','A','A' },
	{ 'A','A',' ',' ',' ',' ',' ',' ','A','A' } };
	static const vector<vector<char>> aB11 =	// definition of 11-pixel bold A font
	{
	{ ' ',' ',' ','A','A','A','A','A',' ',' ',' ' },
	{ ' ',' ','A','A','A','A','A','A','A',' ',' ' },
	{ ' ','A','A',' ',' ',' ',' ',' ','A','A',' ' },
	{ 'A','A',' ',' ',' ',' ',' ',' ',' ','A','A' },
	{ 'A','A',' ',' ',' ',' ',' ',' ',' ','A','A' },
	{ 'A','A','A','A','A','A','A','A','A','A','A' },
	{ 'A','A','A','A','A','A','A','A','A','A','A' },
	{ 'A','A',' ',' ',' ',' ',' ',' ',' ','A','A' },
	{ 'A','A',' ',' ',' ',' ',' ',' ',' ','A','A' },
	{ 'A','A',' ',' ',' ',' ',' ',' ',' ','A','A' },
	{ 'A','A',' ',' ',' ',' ',' ',' ',' ','A','A' } };

	static const vector<vector<char>> aB12 =		// definition of 12-pixel bold A font
	{
	{ ' ',' ',' ','A','A','A','A','A','A',' ',' ',' ' },
	{ ' ',' ','A','A','A','A','A','A','A','A',' ',' ' },
	{ ' ','A','A',' ',' ',' ',' ',' ',' ','A','A',' ' },
	{ 'A','A',' ',' ',' ',' ',' ',' ',' ',' ','A','A' },
	{ 'A','A',' ',' ',' ',' ',' ',' ',' ',' ','A','A' },
	{ 'A','A','A','A','A','A','A','A','A','A','A','A' },
	{ 'A','A','A','A','A','A','A','A','A','A','A','A' },
	{ 'A','A',' ',' ',' ',' ',' ',' ',' ',' ','A','A' },
	{ 'A','A',' ',' ',' ',' ',' ',' ',' ',' ','A','A' },
	{ 'A','A',' ',' ',' ',' ',' ',' ',' ',' ','A','A' },
	{ 'A','A',' ',' ',' ',' ',' ',' ',' ',' ','A','A' },
	{ 'A','A',' ',' ',' ',' ',' ',' ',' ',' ','A','A' } };

	// insert a vector of the correct size for the requested font
	switch (fontSize)
	{
	case 8:
		if (weightTyp == boldFont)
		{
			formattedWord.push_back(aB8);
		}
		else
		{
			formattedWord.push_back(aN8);
		}
		break;
	case 9:
		if (weightTyp == boldFont)
		{
			formattedWord.push_back(aB9);
		}
		else
		{
			formattedWord.push_back(aN9);
		}
		break;
	case 10:
		if (weightTyp == boldFont)
		{
			formattedWord.push_back(aB10);
		}
		else
		{
			formattedWord.push_back(aN10);
		}
		break;
	case 11:
		if (weightTyp == boldFont)
		{
			formattedWord.push_back(aB11);
		}
		else
		{
			formattedWord.push_back(aN11);
		}
		break;
	case 12:
		if (weightTyp == boldFont)
		{
			formattedWord.push_back(aB12);
		}
		else
		{
			formattedWord.push_back(aN12);
		}
		break;
	default:
		cout << "LOGIC ERROR: invalid font size encountered: " << fontSize;
		error++;
		break;
	}
	return error;
} // end formatA

int WordFont::formatB(int letIdx)
{//Format the letter B in the 2D vector based on the requested size and weight
	int error = 0;
	static const char thisLetter = 'B';
	//NORMAL font definitions
	static const vector<vector<char>> bN8 = //definition of 8-pixel normal B font
	{ { ' ','B','B','B','B','B',' ',' ' },
	{ ' ','B',' ',' ',' ',' ','B',' ' },
	{ ' ','B',' ',' ',' ',' ','B',' ' },
	{ ' ','B',' ',' ',' ',' ','B',' ' },
	{ ' ','B','B','B','B','B',' ',' ' },
	{ ' ','B',' ',' ',' ',' ','B',' ' },
	{ ' ','B',' ',' ',' ',' ','B',' ' },
	{ ' ','B','B','B','B','B','B',' ' } };
	static const vector<vector<char>> bN9 =   // definition of 9-pixel normal B font
	{
	{ ' ','B','B','B','B','B','B',' ',' ' },
	{ ' ','B',' ',' ',' ',' ',' ','B',' ' },
	{ ' ','B',' ',' ',' ',' ',' ','B',' ' },
	{ ' ','B',' ',' ',' ',' ',' ','B',' ' },
	{ ' ','B','B','B','B','B','B',' ',' ' },
	{ ' ','B',' ',' ',' ',' ',' ','B',' ' },
	{ ' ','B',' ',' ',' ',' ',' ','B',' ' },
	{ ' ','B',' ',' ',' ',' ',' ','B',' ' },
	{ ' ','B','B','B','B','B','B',' ',' ' } };
	static const vector<vector<char>> bN10 = // definition of 10-pixel normal B font
	{
	{ ' ','B','B','B','B','B','B','B',' ',' ' },
	{ ' ','B',' ',' ',' ',' ',' ',' ','B',' ' },
	{ ' ','B',' ',' ',' ',' ',' ',' ','B',' ' },
	{ ' ','B',' ',' ',' ',' ',' ',' ','B',' ' },
	{ ' ','B',' ',' ',' ',' ',' ',' ','B',' ' },
	{ ' ','B','B','B','B','B','B','B',' ',' ' },
	{ ' ','B',' ',' ',' ',' ',' ',' ','B',' ' },
	{ ' ','B',' ',' ',' ',' ',' ',' ','B',' ' },
	{ ' ','B',' ',' ',' ',' ',' ',' ','B',' ' },
	{ ' ','B','B','B','B','B','B','B',' ',' ' } };
	static const vector<vector<char>> bN11 = // definition of 11-pixel normal B font
	{
	{ 'B','B','B','B','B','B','B','B','B','B',' ' },
	{ 'B','B','B','B','B','B','B','B','B','B','B' },
	{ 'B','B',' ',' ',' ',' ',' ',' ',' ','B','B' },
	{ 'B','B',' ',' ',' ',' ',' ',' ',' ','B','B' },
	{ 'B','B',' ',' ',' ',' ',' ',' ',' ','B','B' },
	{ 'B','B','B','B','B','B','B','B','B','B',' ' },
	{ 'B','B','B','B','B','B','B','B','B','B','B' },
	{ 'B','B',' ',' ',' ',' ',' ',' ',' ','B','B' },
	{ 'B','B',' ',' ',' ',' ',' ',' ',' ','B','B' },
	{ 'B','B',' ',' ',' ',' ',' ',' ',' ','B','B' },
	{ 'B','B','B','B','B','B','B','B','B','B',' ' } };
	static const vector<vector<char>> bN12 = // definition of 12-pixel normal B font
	{
	{ ' ','B','B','B','B','B','B','B','B','B',' ',' ' },
	{ ' ','B',' ',' ',' ',' ',' ',' ',' ',' ','B',' ' },
	{ ' ','B',' ',' ',' ',' ',' ',' ',' ',' ','B',' ' },
	{ ' ','B',' ',' ',' ',' ',' ',' ',' ',' ','B',' ' },
	{ ' ','B',' ',' ',' ',' ',' ',' ',' ',' ','B',' ' },
	{ ' ','B',' ',' ',' ',' ',' ',' ',' ',' ','B',' ' },
	{ ' ','B','B','B','B','B','B','B','B','B',' ',' ' },
	{ ' ','B',' ',' ',' ',' ',' ',' ',' ',' ','B',' ' },
	{ ' ','B',' ',' ',' ',' ',' ',' ',' ',' ','B',' ' },
	{ ' ','B',' ',' ',' ',' ',' ',' ',' ',' ','B',' ' },
	{ ' ','B',' ',' ',' ',' ',' ',' ',' ',' ','B',' ' },
	{ ' ','B','B','B','B','B','B','B','B','B',' ',' ' } };

	//BOLD font definitions
	static const vector<vector<char>> bB8 =		//definition of 8-pixel bold B font
	{
	{ 'B','B','B','B','B','B','B',' ' },
	{ 'B','B','B','B','B','B','B','B' },
	{ 'B','B',' ',' ',' ',' ','B','B' },
	{ 'B','B','B','B','B','B','B','B' },
	{ 'B','B','B','B','B','B','B',' ' },
	{ 'B','B',' ',' ',' ',' ','B','B' },
	{ 'B','B','B','B','B','B','B','B' },
	{ 'B','B','B','B','B','B','B',' ' } };
	static const vector<vector<char>> bB9 =		// definition of 9-pixel bold B font
	{
	{ 'B','B','B','B','B','B','B','B',' ' },
	{ 'B','B','B','B','B','B','B','B','B' },
	{ 'B','B',' ',' ',' ',' ',' ','B','B' },
	{ 'B','B',' ',' ',' ',' ',' ','B','B' },
	{ 'B','B','B','B','B','B','B','B',' ' },
	{ 'B','B','B','B','B','B','B','B','B' },
	{ 'B','B',' ',' ',' ',' ',' ','B','B' },
	{ 'B','B',' ',' ',' ',' ',' ','B','B' },
	{ 'B','B','B','B','B','B','B','B',' ' } };
	static const vector<vector<char>> bB10	// definitionof 10-pixel bold B font
	{
	{ 'B','B','B','B','B','B','B','B','B',' ' },
	{ 'B','B','B','B','B','B','B','B','B','B' },
	{ 'B','B',' ',' ',' ',' ',' ',' ','B','B' },
	{ 'B','B',' ',' ',' ',' ',' ',' ','B','B' },
	{ 'B','B','B','B','B','B','B','B','B','B' },
	{ 'B','B','B','B','B','B','B','B','B',' ' },
	{ 'B','B',' ',' ',' ',' ',' ',' ','B','B' },
	{ 'B','B',' ',' ',' ',' ',' ',' ','B','B' },
	{ 'B','B','B','B','B','B','B','B','B','B' },
	{ 'B','B','B','B','B','B','B','B','B',' ' } };
	static const vector<vector<char>> bB11 =	// definition of 11-pixel bold B font
	{
	{ 'B','B','B','B','B','B','B','B','B','B',' ' },
	{ 'B','B','B','B','B','B','B','B','B','B','B' },
	{ 'B','B',' ',' ',' ',' ',' ',' ',' ','B','B' },
	{ 'B','B',' ',' ',' ',' ',' ',' ',' ','B','B' },
	{ 'B','B',' ',' ',' ',' ',' ',' ',' ','B','B' },
	{ 'B','B','B','B','B','B','B','B','B','B',' ' },
	{ 'B','B','B','B','B','B','B','B','B','B','B' },
	{ 'B','B',' ',' ',' ',' ',' ',' ',' ','B','B' },
	{ 'B','B',' ',' ',' ',' ',' ',' ',' ','B','B' },
	{ 'B','B',' ',' ',' ',' ',' ',' ',' ','B','B' },
	{ 'B','B','B','B','B','B','B','B','B','B',' ' } };

	static const vector<vector<char>> bB12 =		// definition of 12-pixel bold B font
	{
	{ 'B','B','B','B','B','B','B','B','B','B','B',' ' },
	{ 'B','B','B','B','B','B','B','B','B','B','B','B' },
	{ 'B','B',' ',' ',' ',' ',' ',' ',' ',' ','B','B' },
	{ 'B','B',' ',' ',' ',' ',' ',' ',' ',' ','B','B' },
	{ 'B','B',' ',' ',' ',' ',' ',' ',' ',' ','B','B' },
	{ 'B','B','B','B','B','B','B','B','B','B','B','B' },
	{ 'B','B','B','B','B','B','B','B','B','B','B',' ' },
	{ 'B','B',' ',' ',' ',' ',' ',' ',' ',' ','B','B' },
	{ 'B','B',' ',' ',' ',' ',' ',' ',' ',' ','B','B' },
	{ 'B','B',' ',' ',' ',' ',' ',' ',' ',' ','B','B' },
	{ 'B','B','B','B','B','B','B','B','B','B','B','B' },
	{ 'B','B','B','B','B','B','B','B','B','B','B',' ' } };

	// insert a vector of the correct size for the requested font
	switch (fontSize)
	{
	case 8:
		if (weightTyp == boldFont)
		{
			formattedWord.push_back(bB8);
		}
		else
		{
			formattedWord.push_back(bN8);
		}
		break;
	case 9:
		if (weightTyp == boldFont)
		{
			formattedWord.push_back(bB9);
		}
		else
		{
			formattedWord.push_back(bN9);
		}
		break;
	case 10:
		if (weightTyp == boldFont)
		{
			formattedWord.push_back(bB10);
		}
		else
		{
			formattedWord.push_back(bN10);
		}
		break;
	case 11:
		if (weightTyp == boldFont)
		{
			formattedWord.push_back(bB11);
		}
		else
		{
			formattedWord.push_back(bN11);
		}
		break;
	case 12:
		if (weightTyp == boldFont)
		{
			formattedWord.push_back(bB12);
		}
		else
		{
			formattedWord.push_back(bN12);
		}
		break;
	default:
		cout << "LOGIC ERROR: invalid font size encountered: " << fontSize;
		error++;
		break;
	}

	return error;
} // end formatB

int WordFont::formatC(int letIdx)
{//Format the letter C in the 2D vector based on the requested size and weight
	int error = 0;
	static const char thisLetter = 'C';
	//NORMAL font definitions
	static const vector<vector<char>> cN8 = //definition of 8-pixel normal C font
	{
	{ ' ',' ','C','C','C','C',' ',' ' },
	{ ' ','C',' ',' ',' ',' ','C',' ' },
	{ ' ','C',' ',' ',' ',' ','C',' ' },
	{ ' ','C',' ',' ',' ',' ',' ',' ' },
	{ ' ','C',' ',' ',' ',' ',' ',' ' },
	{ ' ','C',' ',' ',' ',' ','C',' ' },
	{ ' ','C',' ',' ',' ',' ','C',' ' },
	{ ' ',' ','C','C','C','C',' ',' ' } };
	static const vector<vector<char>> cN9 =   // definition of 9-pixel normal C font
	{
	{ ' ',' ','C','C','C','C','C',' ',' ' },
	{ ' ','C',' ',' ',' ',' ',' ','C',' ' },
	{ ' ','C',' ',' ',' ',' ',' ','C',' ' },
	{ ' ','C',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','C',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','C',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','C',' ',' ',' ',' ',' ','C',' ' },
	{ ' ','C',' ',' ',' ',' ',' ','C',' ' },
	{ ' ',' ','C','C','C','C','C',' ',' ' } };
	static const vector<vector<char>> cN10 = // definition of 10-pixel normal C font
	{
	{ ' ',' ','C','C','C','C','C','C',' ',' ' },
	{ ' ','C',' ',' ',' ',' ',' ',' ','C',' ' },
	{ ' ','C',' ',' ',' ',' ',' ',' ','C',' ' },
	{ ' ','C',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','C',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','C',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','C',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','C',' ',' ',' ',' ',' ',' ','C',' ' },
	{ ' ','C',' ',' ',' ',' ',' ',' ','C',' ' },
	{ ' ',' ','C','C','C','C','C','C',' ',' ' } };
	static const vector<vector<char>> cN11 = // definition of 11-pixel normal C font
	{
	{ ' ',' ','C','C','C','C','C','C','C',' ',' ' },
	{ ' ','C',' ',' ',' ',' ',' ',' ',' ','C',' ' },
	{ ' ','C',' ',' ',' ',' ',' ',' ',' ','C',' ' },
	{ ' ','C',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','C',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','C',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','C',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','C',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','C',' ',' ',' ',' ',' ',' ',' ','C',' ' },
	{ ' ','C',' ',' ',' ',' ',' ',' ',' ','C',' ' },
	{ ' ',' ','C','C','C','C','C','C','C',' ',' ' } };
	static const vector<vector<char>> cN12 = // definition of 12-pixel normal C font
	{
	{ ' ',' ','C','C','C','C','C','C','C','C',' ',' ' },
	{ ' ','C',' ',' ',' ',' ',' ',' ',' ',' ','C',' ' },
	{ ' ','C',' ',' ',' ',' ',' ',' ',' ',' ','C',' ' },
	{ ' ','C',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','C',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','C',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','C',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','C',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','C',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','C',' ',' ',' ',' ',' ',' ',' ',' ','C',' ' },
	{ ' ','C',' ',' ',' ',' ',' ',' ',' ',' ','C',' ' },
	{ ' ',' ','C','C','C','C','C','C','C','C',' ',' ' } };

	//BOLD font definitions
	static const vector<vector<char>> cB8 =		//definition of 8-pixel bold C font
	{
	{ ' ','C','C','C','C','C','C',' ' },
	{ 'C','C','C','C','C','C','C','C' },
	{ 'C','C',' ',' ',' ',' ','C','C' },
	{ 'C','C',' ',' ',' ',' ',' ',' ' },
	{ 'C','C',' ',' ',' ',' ',' ',' ' },
	{ 'C','C',' ',' ',' ',' ','C','C' },
	{ 'C','C','C','C','C','C','C','C' },
	{ ' ','C','C','C','C','C','C',' ' } };
	static const vector<vector<char>> cB9 =		// definition of 9-pixel bold C font
	{
	{ ' ','C','C','C','C','C','C','C',' ' },
	{ 'C','C','C','C','C','C','C','C','C' },
	{ 'C','C',' ',' ',' ',' ',' ','C','C' },
	{ 'C','C',' ',' ',' ',' ',' ',' ',' ' },
	{ 'C','C',' ',' ',' ',' ',' ',' ',' ' },
	{ 'C','C',' ',' ',' ',' ',' ',' ',' ' },
	{ 'C','C',' ',' ',' ',' ',' ','C','C' },
	{ 'C','C','C','C','C','C','C','C','C' },
	{ ' ','C','C','C','C','C','C','C',' ' } };
	static const vector<vector<char>> cB10	// definitionof 10-pixel bold C font
	{
	{ ' ','C','C','C','C','C','C','C','C',' ' },
	{ 'C','C','C','C','C','C','C','C','C','C' },
	{ 'C','C',' ',' ',' ',' ',' ',' ','C','C' },
	{ 'C','C',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ 'C','C',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ 'C','C',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ 'C','C',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ 'C','C',' ',' ',' ',' ',' ',' ','C','C' },
	{ 'C','C','C','C','C','C','C','C','C','C' },
	{ ' ','C','C','C','C','C','C','C','C',' ' } };
	static const vector<vector<char>> cB11 =	// definition of 11-pixel bold C font
	{
	{ ' ','C','C','C','C','C','C','C','C','C',' ' },
	{ 'C','C','C','C','C','C','C','C','C','C','C' },
	{ 'C','C',' ',' ',' ',' ',' ',' ',' ','C','C' },
	{ 'C','C',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ 'C','C',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ 'C','C',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ 'C','C',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ 'C','C',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ 'C','C',' ',' ',' ',' ',' ',' ',' ','C','C' },
	{ 'C','C','C','C','C','C','C','C','C','C','C' },
	{ ' ','C','C','C','C','C','C','C','C','C',' ' } };

	static const vector<vector<char>> cB12 =		// definition of 12-pixel bold C font
	{
	{ ' ','C','C','C','C','C','C','C','C','C','C',' ' },
	{ 'C','C','C','C','C','C','C','C','C','C','C','C' },
	{ 'C','C',' ',' ',' ',' ',' ',' ',' ',' ','C','C' },
	{ 'C','C',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ 'C','C',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ 'C','C',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ 'C','C',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ 'C','C',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ 'C','C',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ 'C','C',' ',' ',' ',' ',' ',' ',' ',' ','C','C' },
	{ 'C','C','C','C','C','C','C','C','C','C','C','C' },
	{ ' ','C','C','C','C','C','C','C','C','C','C',' ' } };

	// insert a vector of the correct size for the requested font
	switch (fontSize)
	{
	case 8:
		if (weightTyp == boldFont)
		{
			formattedWord.push_back(cB8);
		}
		else
		{
			formattedWord.push_back(cN8);
		}
		break;
	case 9:
		if (weightTyp == boldFont)
		{
			formattedWord.push_back(cB9);
		}
		else
		{
			formattedWord.push_back(cN9);
		}
		break;
	case 10:
		if (weightTyp == boldFont)
		{
			formattedWord.push_back(cB10);
		}
		else
		{
			formattedWord.push_back(cN10);
		}
		break;
	case 11:
		if (weightTyp == boldFont)
		{
			formattedWord.push_back(cB11);
		}
		else
		{
			formattedWord.push_back(cN11);
		}
		break;
	case 12:
		if (weightTyp == boldFont)
		{
			formattedWord.push_back(cB12);
		}
		else
		{
			formattedWord.push_back(cN12);
		}
		break;
	default:
		cout << "LOGIC ERROR: invalid font size encountered: " << fontSize;
		error++;
		break;
	}

	return error;
} // end formatC

int WordFont::formatD(int letIdx)
{//Format the letter D in the 2D vector based on the requested size and weight
	int error = 0;
	static const char thisLetter = 'D';
	//NORMAL font definitions
	static const vector<vector<char>> dN8 = //definition of 8-pixel normal D font
	{
	{ ' ','D','D','D','D','D',' ',' ' },
	{ ' ','D',' ',' ',' ',' ','D',' ' },
	{ ' ','D',' ',' ',' ',' ','D',' ' },
	{ ' ','D',' ',' ',' ',' ','D',' ' },
	{ ' ','D',' ',' ',' ',' ','D',' ' },
	{ ' ','D',' ',' ',' ',' ','D',' ' },
	{ ' ','D',' ',' ',' ',' ','D',' ' },
	{ ' ','D','D','D','D','D',' ',' ' } };
	static const vector<vector<char>> dN9 =   // definition of 9-pixel normal D font
	{
	{ ' ','D','D','D','D','D','D',' ',' ' },
	{ ' ','D',' ',' ',' ',' ',' ','D',' ' },
	{ ' ','D',' ',' ',' ',' ',' ','D',' ' },
	{ ' ','D',' ',' ',' ',' ',' ','D',' ' },
	{ ' ','D',' ',' ',' ',' ',' ','D',' ' },
	{ ' ','D',' ',' ',' ',' ',' ','D',' ' },
	{ ' ','D',' ',' ',' ',' ',' ','D',' ' },
	{ ' ','D',' ',' ',' ',' ',' ','D',' ' },
	{ ' ','D','D','D','D','D','D',' ',' ' } };
	static const vector<vector<char>> dN10 = // definition of 10-pixel normal D font
	{
	{ ' ','D','D','D','D','D','D','D',' ',' ' },
	{ ' ','D',' ',' ',' ',' ',' ',' ','D',' ' },
	{ ' ','D',' ',' ',' ',' ',' ',' ','D',' ' },
	{ ' ','D',' ',' ',' ',' ',' ',' ','D',' ' },
	{ ' ','D',' ',' ',' ',' ',' ',' ','D',' ' },
	{ ' ','D',' ',' ',' ',' ',' ',' ','D',' ' },
	{ ' ','D',' ',' ',' ',' ',' ',' ','D',' ' },
	{ ' ','D',' ',' ',' ',' ',' ',' ','D',' ' },
	{ ' ','D',' ',' ',' ',' ',' ',' ','D',' ' },
	{ ' ','D','D','D','D','D','D','D',' ',' ' } };
	static const vector<vector<char>> dN11 = // definition of 11-pixel normal D font
	{
	{ ' ','D','D','D','D','D','D','D','D',' ',' ' },
	{ ' ','D',' ',' ',' ',' ',' ',' ',' ','D',' ' },
	{ ' ','D',' ',' ',' ',' ',' ',' ',' ','D',' ' },
	{ ' ','D',' ',' ',' ',' ',' ',' ',' ','D',' ' },
	{ ' ','D',' ',' ',' ',' ',' ',' ',' ','D',' ' },
	{ ' ','D',' ',' ',' ',' ',' ',' ',' ','D',' ' },
	{ ' ','D',' ',' ',' ',' ',' ',' ',' ','D',' ' },
	{ ' ','D',' ',' ',' ',' ',' ',' ',' ','D',' ' },
	{ ' ','D',' ',' ',' ',' ',' ',' ',' ','D',' ' },
	{ ' ','D',' ',' ',' ',' ',' ',' ',' ','D',' ' },
	{ ' ','D','D','D','D','D','D','D','D',' ',' ' } };
	static const vector<vector<char>> dN12 = // definition of 12-pixel normal D font
	{
	{ ' ','D','D','D','D','D','D','D','D','D',' ',' ' },
	{ ' ','D',' ',' ',' ',' ',' ',' ',' ',' ','D',' ' },
	{ ' ','D',' ',' ',' ',' ',' ',' ',' ',' ','D',' ' },
	{ ' ','D',' ',' ',' ',' ',' ',' ',' ',' ','D',' ' },
	{ ' ','D',' ',' ',' ',' ',' ',' ',' ',' ','D',' ' },
	{ ' ','D',' ',' ',' ',' ',' ',' ',' ',' ','D',' ' },
	{ ' ','D',' ',' ',' ',' ',' ',' ',' ',' ','D',' ' },
	{ ' ','D',' ',' ',' ',' ',' ',' ',' ',' ','D',' ' },
	{ ' ','D',' ',' ',' ',' ',' ',' ',' ',' ','D',' ' },
	{ ' ','D',' ',' ',' ',' ',' ',' ',' ',' ','D',' ' },
	{ ' ','D',' ',' ',' ',' ',' ',' ',' ',' ','D',' ' },
	{ ' ','D','D','D','D','D','D','D','D','D',' ',' ' } };

	//BOLD font definitions
	static const vector<vector<char>> dB8 =		//definition of 8-pixel bold D font
	{
	{ 'D','D','D','D','D','D','D',' ' },
	{ 'D','D','D','D','D','D','D','D' },
	{ 'D','D',' ',' ',' ',' ','D','D' },
	{ 'D','D',' ',' ',' ',' ','D','D' },
	{ 'D','D',' ',' ',' ',' ','D','D' },
	{ 'D','D',' ',' ',' ',' ','D','D' },
	{ 'D','D','D','D','D','D','D','D' },
	{ 'D','D','D','D','D','D','D',' ' } };
	static const vector<vector<char>> dB9 =		// definition of 9-pixel bold D font
	{
	{ 'D','D','D','D','D','D','D','D',' ' },
	{ 'D','D','D','D','D','D','D','D','D' },
	{ 'D','D',' ',' ',' ',' ',' ','D','D' },
	{ 'D','D',' ',' ',' ',' ',' ','D','D' },
	{ 'D','D',' ',' ',' ',' ',' ','D','D' },
	{ 'D','D',' ',' ',' ',' ',' ','D','D' },
	{ 'D','D',' ',' ',' ',' ',' ','D','D' },
	{ 'D','D','D','D','D','D','D','D','D' },
	{ 'D','D','D','D','D','D','D','D',' ' } };
	static const vector<vector<char>> dB10	// definitionof 10-pixel bold D font
	{
	{ 'D','D','D','D','D','D','D','D','D',' ' },
	{ 'D','D','D','D','D','D','D','D','D','D' },
	{ 'D','D',' ',' ',' ',' ',' ',' ','D','D' },
	{ 'D','D',' ',' ',' ',' ',' ',' ','D','D' },
	{ 'D','D',' ',' ',' ',' ',' ',' ','D','D' },
	{ 'D','D',' ',' ',' ',' ',' ',' ','D','D' },
	{ 'D','D',' ',' ',' ',' ',' ',' ','D','D' },
	{ 'D','D',' ',' ',' ',' ',' ',' ','D','D' },
	{ 'D','D','D','D','D','D','D','D','D','D' },
	{ 'D','D','D','D','D','D','D','D','D',' ' } };
	static const vector<vector<char>> dB11 =	// definition of 11-pixel bold D font
	{
	{ 'D','D','D','D','D','D','D','D','D','D',' ' },
	{ 'D','D','D','D','D','D','D','D','D','D','D' },
	{ 'D','D',' ',' ',' ',' ',' ',' ',' ','D','D' },
	{ 'D','D',' ',' ',' ',' ',' ',' ',' ','D','D' },
	{ 'D','D',' ',' ',' ',' ',' ',' ',' ','D','D' },
	{ 'D','D',' ',' ',' ',' ',' ',' ',' ','D','D' },
	{ 'D','D',' ',' ',' ',' ',' ',' ',' ','D','D' },
	{ 'D','D',' ',' ',' ',' ',' ',' ',' ','D','D' },
	{ 'D','D',' ',' ',' ',' ',' ',' ',' ','D','D' },
	{ 'D','D','D','D','D','D','D','D','D','D','D' },
	{ 'D','D','D','D','D','D','D','D','D','D',' ' } };

	static const vector<vector<char>> dB12 =		// definition of 12-pixel bold D font
	{
	{ 'D','D','D','D','D','D','D','D','D','D','D',' ' },
	{ 'D','D','D','D','D','D','D','D','D','D','D','D' },
	{ 'D','D',' ',' ',' ',' ',' ',' ',' ',' ','D','D' },
	{ 'D','D',' ',' ',' ',' ',' ',' ',' ',' ','D','D' },
	{ 'D','D',' ',' ',' ',' ',' ',' ',' ',' ','D','D' },
	{ 'D','D',' ',' ',' ',' ',' ',' ',' ',' ','D','D' },
	{ 'D','D',' ',' ',' ',' ',' ',' ',' ',' ','D','D' },
	{ 'D','D',' ',' ',' ',' ',' ',' ',' ',' ','D','D' },
	{ 'D','D',' ',' ',' ',' ',' ',' ',' ',' ','D','D' },
	{ 'D','D',' ',' ',' ',' ',' ',' ',' ',' ','D','D' },
	{ 'D','D','D','D','D','D','D','D','D','D','D','D' },
	{ 'D','D','D','D','D','D','D','D','D','D','D',' ' }};

	// insert a vector of the correct size for the requested font
	switch (fontSize)
	{
	case 8:
		if (weightTyp == boldFont)
		{
			formattedWord.push_back(dB8);
		}
		else
		{
			formattedWord.push_back(dN8);
		}
		break;
	case 9:
		if (weightTyp == boldFont)
		{
			formattedWord.push_back(dB9);
		}
		else
		{
			formattedWord.push_back(dN9);
		}
		break;
	case 10:
		if (weightTyp == boldFont)
		{
			formattedWord.push_back(dB10);
		}
		else
		{
			formattedWord.push_back(dN10);
		}
		break;
	case 11:
		if (weightTyp == boldFont)
		{
			formattedWord.push_back(dB11);
		}
		else
		{
			formattedWord.push_back(dN11);
		}
		break;
	case 12:
		if (weightTyp == boldFont)
		{
			formattedWord.push_back(dB12);
		}
		else
		{
			formattedWord.push_back(dN12);
		}
		break;
	default:
		cout << "LOGIC ERROR: invalid font size encountered: " << fontSize;
		error++;
		break;
	}

	return error;
} // end formatD

int WordFont::formatE(int letIdx)
{//Format the letter E in the 2D vector based on the requested size and weight
	int error = 0;
	static const char thisLetter = 'E';
	//NORMAL font definitions
	static const vector<vector<char>> eN8 = //definition of 8-pixel normal E font
	{
	{ ' ','E','E','E','E','E','E',' ' },
	{ ' ','E',' ',' ',' ',' ',' ',' ' },
	{ ' ','E',' ',' ',' ',' ',' ',' ' },
	{ ' ','E','E','E','E',' ',' ',' ' },
	{ ' ','E',' ',' ',' ',' ',' ',' ' },
	{ ' ','E',' ',' ',' ',' ',' ',' ' },
	{ ' ','E',' ',' ',' ',' ',' ',' ' },
	{ ' ','E','E','E','E','E','E',' ' }};
	static const vector<vector<char>> eN9 =   // definition of 9-pixel normal E font
	{
		{ ' ','E','E','E','E','E','E','E',' ' },
	{ ' ','E',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','E',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','E',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','E','E','E','E',' ',' ',' ',' ' },
	{ ' ','E',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','E',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','E',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','E','E','E','E','E','E','E',' ' }};
	static const vector<vector<char>> eN10 = // definition of 10-pixel normal E font
	{
	{ ' ','E','E','E','E','E','E','E','E',' ' },
	{ ' ','E',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','E',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','E',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','E',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','E','E','E','E','E',' ',' ',' ',' ' },
	{ ' ','E',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','E',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','E',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','E','E','E','E','E','E','E','E',' ' }};
	static const vector<vector<char>> eN11 = // definition of 11-pixel normal E font
	{
	{ ' ','E','E','E','E','E','E','E','E','E',' ' },
	{ ' ','E',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','E',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','E',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','E',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','E','E','E','E','E',' ',' ',' ',' ',' ' },
	{ ' ','E',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','E',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','E',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','E',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','E','E','E','E','E','E','E','E','E',' ' }};
	static const vector<vector<char>> eN12 = // definition of 12-pixel normal E font
	{
	{ ' ','E','E','E','E','E','E','E','E','E','E',' ' },
	{ ' ','E',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','E',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','E',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','E',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','E','E','E','E','E','E',' ',' ',' ',' ',' ' },
	{ ' ','E',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','E',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','E',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','E',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','E',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','E','E','E','E','E','E','E','E','E','E',' ' }};

	//BOLD font definitions
	static const vector<vector<char>> eB8 =		//definition of 8-pixel bold E font
	{
	{ 'E','E','E','E','E','E','E','E' },
	{ 'E','E','E','E','E','E','E','E' },
	{ 'E','E',' ',' ',' ',' ',' ',' ' },
	{ 'E','E','E','E','E',' ',' ',' ' },
	{ 'E','E','E','E','E',' ',' ',' ' },
	{ 'E','E',' ',' ',' ',' ',' ',' ' },
	{ 'E','E','E','E','E','E','E','E' },
	{ 'E','E','E','E','E','E','E','E' } };
	static const vector<vector<char>> eB9 =		// definition of 9-pixel bold E font
	{
	{ 'E','E','E','E','E','E','E','E','E' },
	{ 'E','E','E','E','E','E','E','E','E' },
	{ 'E','E',' ',' ',' ',' ',' ',' ',' ' },
	{ 'E','E','E','E','E','E',' ',' ',' ' },
	{ 'E','E','E','E','E','E',' ',' ',' ' },
	{ 'E','E',' ',' ',' ',' ',' ',' ',' ' },
	{ 'E','E',' ',' ',' ',' ',' ',' ',' ' },
	{ 'E','E','E','E','E','E','E','E','E' },
	{ 'E','E','E','E','E','E','E','E','E' }};
	static const vector<vector<char>> eB10	// definitionof 10-pixel bold E font
	{
	{ 'E','E','E','E','E','E','E','E','E','E' },
	{ 'E','E','E','E','E','E','E','E','E','E' },
	{ 'E','E',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ 'E','E',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ 'E','E','E','E','E','E','E',' ',' ',' ' },
	{ 'E','E','E','E','E','E','E',' ',' ',' ' },
	{ 'E','E',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ 'E','E',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ 'E','E','E','E','E','E','E','E','E','E' },
	{ 'E','E','E','E','E','E','E','E','E','E' }};
	static const vector<vector<char>> eB11 =	// definition of 11-pixel bold E font
	{
	{ 'E','E','E','E','E','E','E','E','E','E','E' },
	{ 'E','E','E','E','E','E','E','E','E','E','E' },
	{ 'E','E',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ 'E','E',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ 'E','E','E','E','E','E','E',' ',' ',' ',' ' },
	{ 'E','E','E','E','E','E','E',' ',' ',' ',' ' },
	{ 'E','E',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ 'E','E',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ 'E','E',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ 'E','E','E','E','E','E','E','E','E','E','E' },
	{ 'E','E','E','E','E','E','E','E','E','E','E' }};

	static const vector<vector<char>> eB12 =		// definition of 12-pixel bold E font
	{
	{ 'E','E','E','E','E','E','E','E','E','E','E','E' },
	{ 'E','E','E','E','E','E','E','E','E','E','E','E' },
	{ 'E','E',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ 'E','E',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ 'E','E',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ 'E','E','E','E','E','E','E','E',' ',' ',' ',' ' },
	{ 'E','E','E','E','E','E','E','E',' ',' ',' ',' ' },
	{ 'E','E',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ 'E','E',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ 'E','E',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ 'E','E','E','E','E','E','E','E','E','E','E','E' },
	{ 'E','E','E','E','E','E','E','E','E','E','E','E' }};

	// insert a vector of the correct size for the requested font
	switch (fontSize)
	{
	case 8:
		if (weightTyp == boldFont)
		{
			formattedWord.push_back(eB8);
		}
		else
		{
			formattedWord.push_back(eN8);
		}
		break;
	case 9:
		if (weightTyp == boldFont)
		{
			formattedWord.push_back(eB9);
		}
		else
		{
			formattedWord.push_back(eN9);
		}
		break;
	case 10:
		if (weightTyp == boldFont)
		{
			formattedWord.push_back(eB10);
		}
		else
		{
			formattedWord.push_back(eN10);
		}
		break;
	case 11:
		if (weightTyp == boldFont)
		{
			formattedWord.push_back(eB11);
		}
		else
		{
			formattedWord.push_back(eN11);
		}
		break;
	case 12:
		if (weightTyp == boldFont)
		{
			formattedWord.push_back(eB12);
		}
		else
		{
			formattedWord.push_back(eN12);
		}
		break;
	default:
		cout << "LOGIC ERROR: invalid font size encountered: " << fontSize;
		error++;
		break;
	}

	return error;
} // end formatE

int WordFont::formatH(int letIdx)
{//Format the letter H in the 2D vector based on the requested size and weight
	int error = 0;
	static const char thisLetter = 'H';
	//NORMAL font definitions
	static const vector<vector<char>> hN8 = //definition of 8-pixel normal H font
	{
	{ ' ','H',' ',' ',' ',' ','H',' ' },
	{ ' ','H',' ',' ',' ',' ','H',' ' },
	{ ' ','H',' ',' ',' ',' ','H',' ' },
	{ ' ','H',' ',' ',' ',' ','H',' ' },
	{ ' ','H','H','H','H','H','H',' ' },
	{ ' ','H',' ',' ',' ',' ','H',' ' },
	{ ' ','H',' ',' ',' ',' ','H',' ' },
	{ ' ','H',' ',' ',' ',' ','H',' ' }};
	static const vector<vector<char>> hN9 =   // definition of 9-pixel normal H font
	{
	{ ' ','H',' ',' ',' ',' ',' ','H',' ' },
	{ ' ','H',' ',' ',' ',' ',' ','H',' ' },
	{ ' ','H',' ',' ',' ',' ',' ','H',' ' },
	{ ' ','H',' ',' ',' ',' ',' ','H',' ' },
	{ ' ','H','H','H','H','H','H','H',' ' },
	{ ' ','H',' ',' ',' ',' ',' ','H',' ' },
	{ ' ','H',' ',' ',' ',' ',' ','H',' ' },
	{ ' ','H',' ',' ',' ',' ',' ','H',' ' },
	{ ' ','H',' ',' ',' ',' ',' ','H',' ' }};
	static const vector<vector<char>> hN10 = // definition of 10-pixel normal H font
	{ { ' ','H',' ',' ',' ',' ',' ',' ','H',' ' },
	{ ' ','H',' ',' ',' ',' ',' ',' ','H',' ' },
	{ ' ','H',' ',' ',' ',' ',' ',' ','H',' ' },
	{ ' ','H',' ',' ',' ',' ',' ',' ','H',' ' },
	{ ' ','H',' ',' ',' ',' ',' ',' ','H',' ' },
	{ ' ','H','H','H','H','H','H','H','H',' ' },
	{ ' ','H',' ',' ',' ',' ',' ',' ','H',' ' },
	{ ' ','H',' ',' ',' ',' ',' ',' ','H',' ' },
	{ ' ','H',' ',' ',' ',' ',' ',' ','H',' ' },
	{ ' ','H',' ',' ',' ',' ',' ',' ','H',' ' }};
	static const vector<vector<char>> hN11 = // definition of 11-pixel normal H font
	{
	{ ' ','H',' ',' ',' ',' ',' ',' ',' ','H',' ' },
	{ ' ','H',' ',' ',' ',' ',' ',' ',' ','H',' ' },
	{ ' ','H',' ',' ',' ',' ',' ',' ',' ','H',' ' },
	{ ' ','H',' ',' ',' ',' ',' ',' ',' ','H',' ' },
	{ ' ','H',' ',' ',' ',' ',' ',' ',' ','H',' ' },
	{ ' ','H','H','H','H','H','H','H','H','H',' ' },
	{ ' ','H',' ',' ',' ',' ',' ',' ',' ','H',' ' },
	{ ' ','H',' ',' ',' ',' ',' ',' ',' ','H',' ' },
	{ ' ','H',' ',' ',' ',' ',' ',' ',' ','H',' ' },
	{ ' ','H',' ',' ',' ',' ',' ',' ',' ','H',' ' },
	{ ' ','H',' ',' ',' ',' ',' ',' ',' ','H',' ' }};
	static const vector<vector<char>> hN12 = // definition of 12-pixel normal H font
	{
	{ ' ','H',' ',' ',' ',' ',' ',' ',' ',' ','H',' ' },
	{ ' ','H',' ',' ',' ',' ',' ',' ',' ',' ','H',' ' },
	{ ' ','H',' ',' ',' ',' ',' ',' ',' ',' ','H',' ' },
	{ ' ','H',' ',' ',' ',' ',' ',' ',' ',' ','H',' ' },
	{ ' ','H',' ',' ',' ',' ',' ',' ',' ',' ','H',' ' },
	{ ' ','H',' ',' ',' ',' ',' ',' ',' ',' ','H',' ' },
	{ ' ','H','H','H','H','H','H','H','H','H','H',' ' },
	{ ' ','H',' ',' ',' ',' ',' ',' ',' ',' ','H',' ' },
	{ ' ','H',' ',' ',' ',' ',' ',' ',' ',' ','H',' ' },
	{ ' ','H',' ',' ',' ',' ',' ',' ',' ',' ','H',' ' },
	{ ' ','H',' ',' ',' ',' ',' ',' ',' ',' ','H',' ' },
	{ ' ','H',' ',' ',' ',' ',' ',' ',' ',' ','H',' ' }};

	//BOLD font definitions
	static const vector<vector<char>> hB8 =		//definition of 8-pixel bold H font
	{
	{ 'H','H',' ',' ',' ',' ','H','H' },
	{ 'H','H',' ',' ',' ',' ','H','H' },
	{ 'H','H',' ',' ',' ',' ','H','H' },
	{ 'H','H','H','H','H','H','H','H' },
	{ 'H','H','H','H','H','H','H','H' },
	{ 'H','H',' ',' ',' ',' ','H','H' },
	{ 'H','H',' ',' ',' ',' ','H','H' },
	{ 'H','H',' ',' ',' ',' ','H','H' }};
	static const vector<vector<char>> hB9 =		// definition of 9-pixel bold H font
	{
	{ 'H','H',' ',' ',' ',' ',' ','H','H' },
	{ 'H','H',' ',' ',' ',' ',' ','H','H' },
	{ 'H','H',' ',' ',' ',' ',' ','H','H' },
	{ 'H','H',' ',' ',' ',' ',' ','H','H' },
	{ 'H','H','H','H','H','H','H','H','H' },
	{ 'H','H','H','H','H','H','H','H','H' },
	{ 'H','H',' ',' ',' ',' ',' ','H','H' },
	{ 'H','H',' ',' ',' ',' ',' ','H','H' },
	{ 'H','H',' ',' ',' ',' ',' ','H','H' }};
	static const vector<vector<char>> hB10	// definitionof 10-pixel bold H font
	{
	{ 'H','H',' ',' ',' ',' ',' ',' ','H','H' },
	{ 'H','H',' ',' ',' ',' ',' ',' ','H','H' },
	{ 'H','H',' ',' ',' ',' ',' ',' ','H','H' },
	{ 'H','H',' ',' ',' ',' ',' ',' ','H','H' },
	{ 'H','H','H','H','H','H','H','H','H','H' },
	{ 'H','H','H','H','H','H','H','H','H','H' },
	{ 'H','H',' ',' ',' ',' ',' ',' ','H','H' },
	{ 'H','H',' ',' ',' ',' ',' ',' ','H','H' },
	{ 'H','H',' ',' ',' ',' ',' ',' ','H','H' },
	{ 'H','H',' ',' ',' ',' ',' ',' ','H','H' }};
	static const vector<vector<char>> hB11 =	// definition of 11-pixel bold H font
	{
	{ 'H','H',' ',' ',' ',' ',' ',' ',' ','H','H' },
	{ 'H','H',' ',' ',' ',' ',' ',' ',' ','H','H' },
	{ 'H','H',' ',' ',' ',' ',' ',' ',' ','H','H' },
	{ 'H','H',' ',' ',' ',' ',' ',' ',' ','H','H' },
	{ 'H','H',' ',' ',' ',' ',' ',' ',' ','H','H' },
	{ 'H','H','H','H','H','H','H','H','H','H','H' },
	{ 'H','H','H','H','H','H','H','H','H','H','H' },
	{ 'H','H',' ',' ',' ',' ',' ',' ',' ','H','H' },
	{ 'H','H',' ',' ',' ',' ',' ',' ',' ','H','H' },
	{ 'H','H',' ',' ',' ',' ',' ',' ',' ','H','H' },
	{ 'H','H',' ',' ',' ',' ',' ',' ',' ','H','H' }};

	static const vector<vector<char>> hB12 =		// definition of 12-pixel bold H font
	{
	{ 'H','H',' ',' ',' ',' ',' ',' ',' ',' ','H','H' },
	{ 'H','H',' ',' ',' ',' ',' ',' ',' ',' ','H','H' },
	{ 'H','H',' ',' ',' ',' ',' ',' ',' ',' ','H','H' },
	{ 'H','H',' ',' ',' ',' ',' ',' ',' ',' ','H','H' },
	{ 'H','H',' ',' ',' ',' ',' ',' ',' ',' ','H','H' },
	{ 'H','H','H','H','H','H','H','H','H','H','H','H' },
	{ 'H','H','H','H','H','H','H','H','H','H','H','H' },
	{ 'H','H',' ',' ',' ',' ',' ',' ',' ',' ','H','H' },
	{ 'H','H',' ',' ',' ',' ',' ',' ',' ',' ','H','H' },
	{ 'H','H',' ',' ',' ',' ',' ',' ',' ',' ','H','H' },
	{ 'H','H',' ',' ',' ',' ',' ',' ',' ',' ','H','H' },
	{ 'H','H',' ',' ',' ',' ',' ',' ',' ',' ','H','H' }};

	// insert a vector of the correct size for the requested font
	switch (fontSize)
	{
	case 8:
		if (weightTyp == boldFont)
		{
			formattedWord.push_back(hB8);
		}
		else
		{
			formattedWord.push_back(hN8);
		}
		break;
	case 9:
		if (weightTyp == boldFont)
		{
			formattedWord.push_back(hB9);
		}
		else
		{
			formattedWord.push_back(hN9);
		}
		break;
	case 10:
		if (weightTyp == boldFont)
		{
			formattedWord.push_back(hB10);
		}
		else
		{
			formattedWord.push_back(hN10);
		}
		break;
	case 11:
		if (weightTyp == boldFont)
		{
			formattedWord.push_back(hB11);
		}
		else
		{
			formattedWord.push_back(hN11);
		}
		break;
	case 12:
		if (weightTyp == boldFont)
		{
			formattedWord.push_back(hB12);
		}
		else
		{
			formattedWord.push_back(hN12);
		}
		break;
	default:
		cout << "LOGIC ERROR: invalid font size encountered: " << fontSize;
		error++;
		break;
	}

	return error;
} // end formatH

int WordFont::formatI(int letIdx)
{//Format the letter I in the 2D vector based on the requested size and weight
	int error = 0;
	static const char thisLetter = 'I';
	//NORMAL font definitions
	static const vector<vector<char>> iN8 = //definition of 8-pixel normal I font
	{
	{ ' ','I','I','I','I','I','I',' ' },
	{ ' ',' ',' ','I',' ',' ',' ',' ' },
	{ ' ',' ',' ','I',' ',' ',' ',' ' },
	{ ' ',' ',' ','I',' ',' ',' ',' ' },
	{ ' ',' ',' ','I',' ',' ',' ',' ' },
	{ ' ',' ',' ','I',' ',' ',' ',' ' },
	{ ' ',' ',' ','I',' ',' ',' ',' ' },
	{ ' ','I','I','I','I','I','I',' ' }};
	static const vector<vector<char>> iN9 =   // definition of 9-pixel normal I font
	{
	{ ' ','I','I','I','I','I','I','I',' ' },
	{ ' ',' ',' ',' ','I',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ','I',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ','I',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ','I',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ','I',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ','I',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ','I',' ',' ',' ',' ' },
	{ ' ','I','I','I','I','I','I','I',' ' }};
	static const vector<vector<char>> iN10 = // definition of 10-pixel normal I font
	{
	{ ' ','I','I','I','I','I','I','I','I',' ' },
	{ ' ',' ',' ',' ','I',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ','I',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ','I',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ','I',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ','I',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ','I',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ','I',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ','I',' ',' ',' ',' ',' ' },
	{ ' ','I','I','I','I','I','I','I','I',' ' }};
	static const vector<vector<char>> iN11 = // definition of 11-pixel normal I font
	{
	{ ' ','I','I','I','I','I','I','I','I','I',' ' },
	{ ' ',' ',' ',' ',' ','I',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ','I',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ','I',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ','I',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ','I',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ','I',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ','I',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ','I',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ','I',' ',' ',' ',' ',' ' },
	{ ' ','I','I','I','I','I','I','I','I','I',' ' }};
	static const vector<vector<char>> iN12 = // definition of 12-pixel normal I font
	{
	{ ' ','I','I','I','I','I','I','I','I','I','I',' ' },
	{ ' ',' ',' ',' ',' ','I',' ',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ','I',' ',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ','I',' ',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ','I',' ',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ','I',' ',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ','I',' ',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ','I',' ',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ','I',' ',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ','I',' ',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ','I',' ',' ',' ',' ',' ',' ' },
	{ ' ','I','I','I','I','I','I','I','I','I','I',' ' }};

	//BOLD font definitions
	static const vector<vector<char>> iB8 =		//definition of 8-pixel bold I font
	{
	{ 'I','I','I','I','I','I','I','I' },
	{ 'I','I','I','I','I','I','I','I' },
	{ ' ',' ',' ','I','I',' ',' ',' ' },
	{ ' ',' ',' ','I','I',' ',' ',' ' },
	{ ' ',' ',' ','I','I',' ',' ',' ' },
	{ ' ',' ',' ','I','I',' ',' ',' ' },
	{ 'I','I','I','I','I','I','I','I' },
	{ 'I','I','I','I','I','I','I','I' }};
	static const vector<vector<char>> iB9 =		// definition of 9-pixel bold I font
	{
	{ 'I','I','I','I','I','I','I','I','I' },
	{ 'I','I','I','I','I','I','I','I','I' },
	{ ' ',' ',' ','I','I',' ',' ',' ',' ' },
	{ ' ',' ',' ','I','I',' ',' ',' ',' ' },
	{ ' ',' ',' ','I','I',' ',' ',' ',' ' },
	{ ' ',' ',' ','I','I',' ',' ',' ',' ' },
	{ ' ',' ',' ','I','I',' ',' ',' ',' ' },
	{ 'I','I','I','I','I','I','I','I','I' },
	{ 'I','I','I','I','I','I','I','I','I' }};
	static const vector<vector<char>> iB10	// definitionof 10-pixel bold I font
	{
	{ 'I','I','I','I','I','I','I','I','I','I' },
	{ 'I','I','I','I','I','I','I','I','I','I' },
	{ ' ',' ',' ',' ','I','I',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ','I','I',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ','I','I',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ','I','I',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ','I','I',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ','I','I',' ',' ',' ',' ' },
	{ 'I','I','I','I','I','I','I','I','I','I' },
	{ 'I','I','I','I','I','I','I','I','I','I' } };
	static const vector<vector<char>> iB11 =	// definition of 11-pixel bold I font
	{
	{ 'I','I','I','I','I','I','I','I','I','I','I' },
	{ 'I','I','I','I','I','I','I','I','I','I','I' },
	{ ' ',' ',' ',' ','I','I',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ','I','I',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ','I','I',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ','I','I',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ','I','I',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ','I','I',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ','I','I',' ',' ',' ',' ',' ' },
	{ 'I','I','I','I','I','I','I','I','I','I','I' },
	{ 'I','I','I','I','I','I','I','I','I','I','I' }};

	static const vector<vector<char>> iB12 =		// definition of 12-pixel bold I font
	{
	{ 'I','I','I','I','I','I','I','I','I','I','I','I' },
	{ 'I','I','I','I','I','I','I','I','I','I','I','I' },
	{ ' ',' ',' ',' ',' ','I','I',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ','I','I',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ','I','I',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ','I','I',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ','I','I',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ','I','I',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ','I','I',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ','I','I',' ',' ',' ',' ',' ' },
	{ 'I','I','I','I','I','I','I','I','I','I','I','I' },
	{ 'I','I','I','I','I','I','I','I','I','I','I','I' }};

	// insert a vector of the correct size for the requested font
	switch (fontSize)
	{
	case 8:
		if (weightTyp == boldFont)
		{
			formattedWord.push_back(iB8);
		}
		else
		{
			formattedWord.push_back(iN8);
		}
		break;
	case 9:
		if (weightTyp == boldFont)
		{
			formattedWord.push_back(iB9);
		}
		else
		{
			formattedWord.push_back(iN9);
		}
		break;
	case 10:
		if (weightTyp == boldFont)
		{
			formattedWord.push_back(iB10);
		}
		else
		{
			formattedWord.push_back(iN10);
		}
		break;
	case 11:
		if (weightTyp == boldFont)
		{
			formattedWord.push_back(iB11);
		}
		else
		{
			formattedWord.push_back(iN11);
		}
		break;
	case 12:
		if (weightTyp == boldFont)
		{
			formattedWord.push_back(iB12);
		}
		else
		{
			formattedWord.push_back(iN12);
		}
		break;
	default:
		cout << "LOGIC ERROR: invalid font size encountered: " << fontSize;
		error++;
		break;
	}

	return error;
} // end formatI

int WordFont::formatL(int letIdx)
{//Format the letter L in the 2D vector based on the requested size and weight
	int error = 0;
	static const char thisLetter = 'L';
	//NORMAL font definitions
	static const vector<vector<char>> letN8 = //definition of 8-pixel normal L font
	{
	{ ' ','L',' ',' ',' ',' ',' ',' ' },
	{ ' ','L',' ',' ',' ',' ',' ',' ' },
	{ ' ','L',' ',' ',' ',' ',' ',' ' },
	{ ' ','L',' ',' ',' ',' ',' ',' ' },
	{ ' ','L',' ',' ',' ',' ',' ',' ' },
	{ ' ','L',' ',' ',' ',' ',' ',' ' },
	{ ' ','L',' ',' ',' ',' ',' ',' ' },
	{ ' ','L','L','L','L','L','L',' ' } };
	static const vector<vector<char>> letN9 =   // definition of 9-pixel normal L font
	{
	{ ' ','L',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','L',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','L',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','L',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','L',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','L',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','L',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','L',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','L','L','L','L','L','L','L',' ' }};
	static const vector<vector<char>> letN10 = // definition of 10-pixel normal L font
	{
	{ ' ','L',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','L',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','L',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','L',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','L',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','L',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','L',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','L',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','L',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','L','L','L','L','L','L','L','L',' ' }};
	static const vector<vector<char>> letN11 = // definition of 11-pixel normal L font
	{
	{ ' ','L',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','L',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','L',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','L',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','L',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','L',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','L',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','L',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','L',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','L',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','L','L','L','L','L','L','L','L','L',' ' }};
	static const vector<vector<char>> letN12 = // definition of 12-pixel normal L font
	{
	{ ' ','L',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','L',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','L',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','L',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','L',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','L',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','L',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','L',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','L',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','L',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','L',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','L','L','L','L','L','L','L','L','L','L',' ' }};

	//BOLD font definitions
	static const vector<vector<char>> letB8 =		//definition of 8-pixel bold L font
	{
	{ 'L','L',' ',' ',' ',' ',' ',' ' },
	{ 'L','L',' ',' ',' ',' ',' ',' ' },
	{ 'L','L',' ',' ',' ',' ',' ',' ' },
	{ 'L','L',' ',' ',' ',' ',' ',' ' },
	{ 'L','L',' ',' ',' ',' ',' ',' ' },
	{ 'L','L',' ',' ',' ',' ',' ',' ' },
	{ 'L','L','L','L','L','L','L','L' },
	{ 'L','L','L','L','L','L','L','L' }};
	static const vector<vector<char>> letB9 =		// definition of 9-pixel bold L font
	{
		{ 'L','L',' ',' ',' ',' ',' ',' ',' ' },
	{ 'L','L',' ',' ',' ',' ',' ',' ',' ' },
	{ 'L','L',' ',' ',' ',' ',' ',' ',' ' },
	{ 'L','L',' ',' ',' ',' ',' ',' ',' ' },
	{ 'L','L',' ',' ',' ',' ',' ',' ',' ' },
	{ 'L','L',' ',' ',' ',' ',' ',' ',' ' },
	{ 'L','L',' ',' ',' ',' ',' ',' ',' ' },
	{ 'L','L','L','L','L','L','L','L','L' },
	{ 'L','L','L','L','L','L','L','L','L' }};
	static const vector<vector<char>> letB10	// definitionof 10-pixel bold L font
	{
	{ 'L','L',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ 'L','L',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ 'L','L',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ 'L','L',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ 'L','L',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ 'L','L',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ 'L','L',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ 'L','L',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ 'L','L','L','L','L','L','L','L','L','L' },
	{ 'L','L','L','L','L','L','L','L','L','L' }};
	static const vector<vector<char>> letB11 =	// definition of 11-pixel bold L font
	{
	{ 'L','L',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ 'L','L',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ 'L','L',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ 'L','L',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ 'L','L',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ 'L','L',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ 'L','L',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ 'L','L',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ 'L','L',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ 'L','L','L','L','L','L','L','L','L','L','L' },
	{ 'L','L','L','L','L','L','L','L','L','L','L' }};

	static const vector<vector<char>> letB12 =		// definition of 12-pixel bold L font
	{
		{ 'L','L',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ 'L','L',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ 'L','L',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ 'L','L',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ 'L','L',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ 'L','L',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ 'L','L',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ 'L','L',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ 'L','L',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ 'L','L',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ 'L','L','L','L','L','L','L','L','L','L','L','L' },
	{ 'L','L','L','L','L','L','L','L','L','L','L','L' }};

	// letNsert a vector of the correct size for the requested font
	switch (fontSize)
	{
	case 8:
		if (weightTyp == boldFont)
		{
			formattedWord.push_back(letB8);
		}
		else
		{
			formattedWord.push_back(letN8);
		}
		break;
	case 9:
		if (weightTyp == boldFont)
		{
			formattedWord.push_back(letB9);
		}
		else
		{
			formattedWord.push_back(letN9);
		}
		break;
	case 10:
		if (weightTyp == boldFont)
		{
			formattedWord.push_back(letB10);
		}
		else
		{
			formattedWord.push_back(letN10);
		}
		break;
	case 11:
		if (weightTyp == boldFont)
		{
			formattedWord.push_back(letB11);
		}
		else
		{
			formattedWord.push_back(letN11);
		}
		break;
	case 12:
		if (weightTyp == boldFont)
		{
			formattedWord.push_back(letB12);
		}
		else
		{
			formattedWord.push_back(letN12);
		}
		break;
	default:
		cout << "LOGIC ERROR: invalid font size encountered: " << fontSize;
		error++;
		break;
	}

	return error;
} // end formatL

int WordFont::formatM(int letIdx)
{//Format the letter M in the 2D vector based on the requested size and weight
	int error = 0;
	static const char thisLetter = 'M';
	//NORMAL font definitions
	static const vector<vector<char>> letN8 = //definition of 8-pixel normal M font
	{
	{ ' ','M',' ',' ',' ',' ','M',' ' },
	{ ' ','M','M',' ',' ','M','M',' ' },
	{ ' ','M',' ','M','M',' ','M',' ' },
	{ ' ','M',' ','M','M',' ','M',' ' },
	{ ' ','M',' ',' ',' ',' ','M',' ' },
	{ ' ','M',' ',' ',' ',' ','M',' ' },
	{ ' ','M',' ',' ',' ',' ','M',' ' },
	{ ' ','M',' ',' ',' ',' ','M',' ' }};
	static const vector<vector<char>> letN9 =   // definition of 9-pixel normal M font
	{
	{ ' ','M',' ',' ',' ',' ',' ','M',' ' },
	{ ' ','M','M',' ',' ',' ','M','M',' ' },
	{ ' ','M',' ','M',' ','M',' ','M',' ' },
	{ ' ','M',' ',' ','M',' ',' ','M',' ' },
	{ ' ','M',' ',' ',' ',' ',' ','M',' ' },
	{ ' ','M',' ',' ',' ',' ',' ','M',' ' },
	{ ' ','M',' ',' ',' ',' ',' ','M',' ' },
	{ ' ','M',' ',' ',' ',' ',' ','M',' ' },
	{ ' ','M',' ',' ',' ',' ',' ','M',' ' }};
	static const vector<vector<char>> letN10 = // definition of 10-pixel normal M font
	{
	{ ' ','M',' ',' ',' ',' ',' ',' ','M',' ' },
	{ ' ','M','M',' ',' ',' ',' ','M','M',' ' },
	{ ' ','M',' ','M',' ',' ','M',' ','M',' ' },
	{ ' ','M',' ',' ','M','M',' ',' ','M',' ' },
	{ ' ','M',' ',' ',' ',' ',' ',' ','M',' ' },
	{ ' ','M',' ',' ',' ',' ',' ',' ','M',' ' },
	{ ' ','M',' ',' ',' ',' ',' ',' ','M',' ' },
	{ ' ','M',' ',' ',' ',' ',' ',' ','M',' ' },
	{ ' ','M',' ',' ',' ',' ',' ',' ','M',' ' },
	{ ' ','M',' ',' ',' ',' ',' ',' ','M',' ' }};
	static const vector<vector<char>> letN11 = // definition of 11-pixel normal M font
	{
	{ ' ','M',' ',' ',' ',' ',' ',' ',' ','M',' ' },
	{ ' ','M','M',' ',' ',' ',' ',' ','M','M',' ' },
	{ ' ','M',' ','M',' ',' ',' ','M',' ','M',' ' },
	{ ' ','M',' ',' ','M',' ','M',' ',' ','M',' ' },
	{ ' ','M',' ',' ',' ','M',' ',' ',' ','M',' ' },
	{ ' ','M',' ',' ',' ',' ',' ',' ',' ','M',' ' },
	{ ' ','M',' ',' ',' ',' ',' ',' ',' ','M',' ' },
	{ ' ','M',' ',' ',' ',' ',' ',' ',' ','M',' ' },
	{ ' ','M',' ',' ',' ',' ',' ',' ',' ','M',' ' },
	{ ' ','M',' ',' ',' ',' ',' ',' ',' ','M',' ' },
	{ ' ','M',' ',' ',' ',' ',' ',' ',' ','M',' ' }};
	static const vector<vector<char>> letN12 = // definition of 12-pixel normal M font
	{
	{ ' ','M',' ',' ',' ',' ',' ',' ',' ',' ','M',' ' },
	{ ' ','M','M',' ',' ',' ',' ',' ',' ','M','M',' ' },
	{ ' ','M',' ','M',' ',' ',' ',' ','M',' ','M',' ' },
	{ ' ','M',' ',' ','M',' ',' ','M',' ',' ','M',' ' },
	{ ' ','M',' ',' ',' ','M','M',' ',' ',' ','M',' ' },
	{ ' ','M',' ',' ',' ',' ',' ',' ',' ',' ','M',' ' },
	{ ' ','M',' ',' ',' ',' ',' ',' ',' ',' ','M',' ' },
	{ ' ','M',' ',' ',' ',' ',' ',' ',' ',' ','M',' ' },
	{ ' ','M',' ',' ',' ',' ',' ',' ',' ',' ','M',' ' },
	{ ' ','M',' ',' ',' ',' ',' ',' ',' ',' ','M',' ' },
	{ ' ','M',' ',' ',' ',' ',' ',' ',' ',' ','M',' ' },
	{ ' ','M',' ',' ',' ',' ',' ',' ',' ',' ','M',' ' }};

	//BOLD font definitions
	static const vector<vector<char>> letB8 =		//definition of 8-pixel bold M font
	{
	{ 'M','M','M',' ',' ',' ','M','M' },
	{ 'M','M','M',' ',' ','M','M','M' },
	{ 'M','M','M','M','M','M','M','M' },
	{ 'M','M',' ','M','M',' ','M','M' },
	{ 'M','M',' ',' ',' ',' ','M','M' },
	{ 'M','M',' ',' ',' ',' ','M','M' },
	{ 'M','M',' ',' ',' ',' ','M','M' },
	{ 'M','M',' ',' ',' ',' ','M','M' }};
	static const vector<vector<char>> letB9 =		// definition of 9-pixel bold M font
	{
	{ 'M','M',' ',' ',' ',' ',' ','M','M' },
	{ 'M','M','M',' ',' ',' ','M','M','M' },
	{ 'M','M','M','M',' ','M','M','M','M' },
	{ 'M','M',' ','M','M','M',' ','M','M' },
	{ 'M','M',' ',' ','M',' ',' ','M','M' },
	{ 'M','M',' ',' ',' ',' ',' ','M','M' },
	{ 'M','M',' ',' ',' ',' ',' ','M','M' },
	{ 'M','M',' ',' ',' ',' ',' ','M','M' },
	{ 'M','M',' ',' ',' ',' ',' ','M','M' }};
	static const vector<vector<char>> letB10	// definitionof 10-pixel bold M font
	{
	{ 'M','M',' ',' ',' ',' ',' ',' ','M','M' },
	{ 'M','M','M',' ',' ',' ',' ','M','M','M' },
	{ 'M','M','M','M',' ',' ','M','M','M','M' },
	{ 'M','M',' ','M','M','M','M',' ','M','M' },
	{ 'M','M',' ',' ','M','M',' ',' ','M','M' },
	{ 'M','M',' ',' ',' ',' ',' ',' ','M','M' },
	{ 'M','M',' ',' ',' ',' ',' ',' ','M','M' },
	{ 'M','M',' ',' ',' ',' ',' ',' ','M','M' },
	{ 'M','M',' ',' ',' ',' ',' ',' ','M','M' },
	{ 'M','M',' ',' ',' ',' ',' ',' ','M','M' }};
	static const vector<vector<char>> letB11 =	// definition of 11-pixel bold M font
	{
	{ 'M','M',' ',' ',' ',' ',' ',' ',' ','M','M' },
	{ 'M','M','M',' ',' ',' ',' ',' ','M','M','M' },
	{ 'M','M','M','M',' ',' ',' ','M','M','M','M' },
	{ 'M','M',' ','M','M',' ','M','M',' ','M','M' },
	{ 'M','M',' ',' ','M','M','M',' ',' ','M','M' },
	{ 'M','M',' ',' ',' ','M',' ',' ',' ','M','M' },
	{ 'M','M',' ',' ',' ',' ',' ',' ',' ','M','M' },
	{ 'M','M',' ',' ',' ',' ',' ',' ',' ','M','M' },
	{ 'M','M',' ',' ',' ',' ',' ',' ',' ','M','M' },
	{ 'M','M',' ',' ',' ',' ',' ',' ',' ','M','M' },
	{ 'M','M',' ',' ',' ',' ',' ',' ',' ','M','M' }};

	static const vector<vector<char>> letB12 =		// definition of 12-pixel bold M font
	{
	{ 'M','M',' ',' ',' ',' ',' ',' ',' ',' ','M','M' },
	{ 'M','M','M',' ',' ',' ',' ',' ',' ','M','M','M' },
	{ 'M','M','M','M',' ',' ',' ',' ','M','M','M','M' },
	{ 'M','M',' ','M','M',' ',' ','M','M',' ','M','M' },
	{ 'M','M',' ',' ','M','M','M','M',' ',' ','M','M' },
	{ 'M','M',' ',' ',' ','M','M',' ',' ',' ','M','M' },
	{ 'M','M',' ',' ',' ',' ',' ',' ',' ',' ','M','M' },
	{ 'M','M',' ',' ',' ',' ',' ',' ',' ',' ','M','M' },
	{ 'M','M',' ',' ',' ',' ',' ',' ',' ',' ','M','M' },
	{ 'M','M',' ',' ',' ',' ',' ',' ',' ',' ','M','M' },
	{ 'M','M',' ',' ',' ',' ',' ',' ',' ',' ','M','M' },
	{ 'M','M',' ',' ',' ',' ',' ',' ',' ',' ','M','M' }};

	// letNsert a vector of the correct size for the requested font
	switch (fontSize)
	{
	case 8:
		if (weightTyp == boldFont)
		{
			formattedWord.push_back(letB8);
		}
		else
		{
			formattedWord.push_back(letN8);
		}
		break;
	case 9:
		if (weightTyp == boldFont)
		{
			formattedWord.push_back(letB9);
		}
		else
		{
			formattedWord.push_back(letN9);
		}
		break;
	case 10:
		if (weightTyp == boldFont)
		{
			formattedWord.push_back(letB10);
		}
		else
		{
			formattedWord.push_back(letN10);
		}
		break;
	case 11:
		if (weightTyp == boldFont)
		{
			formattedWord.push_back(letB11);
		}
		else
		{
			formattedWord.push_back(letN11);
		}
		break;
	case 12:
		if (weightTyp == boldFont)
		{
			formattedWord.push_back(letB12);
		}
		else
		{
			formattedWord.push_back(letN12);
		}
		break;
	default:
		cout << "LOGIC ERROR: invalid font size encountered: " << fontSize;
		error++;
		break;
	}

	return error;
} // end formatM

int WordFont::formatN(int letIdx)
{//Format the letter N in the 2D vector based on the requested size and weight
	int error = 0;
	static const char thisLetter = 'N';
	//NORMAL font definitions
	static const vector<vector<char>> letN8 = //definition of 8-pixel normal N font
	{
	{ ' ','N','N',' ',' ',' ','N',' ' },
	{ ' ','N','N',' ',' ',' ','N',' ' },
	{ ' ','N',' ','N',' ',' ','N',' ' },
	{ ' ','N',' ','N',' ',' ','N',' ' },
	{ ' ','N',' ',' ','N',' ','N',' ' },
	{ ' ','N',' ',' ','N',' ','N',' ' },
	{ ' ','N',' ',' ',' ','N','N',' ' },
	{ ' ','N',' ',' ',' ','N','N',' ' }};
	static const vector<vector<char>> letN9 =   // definition of 9-pixel normal N font
	{
	{ ' ','N',' ',' ',' ',' ',' ','N',' ' },
	{ ' ','N','N',' ',' ',' ',' ','N',' ' },
	{ ' ','N',' ','N',' ',' ',' ','N',' ' },
	{ ' ','N',' ',' ','N',' ',' ','N',' ' },
	{ ' ','N',' ',' ','N',' ',' ','N',' ' },
	{ ' ','N',' ',' ',' ','N',' ','N',' ' },
	{ ' ','N',' ',' ',' ','N',' ','N',' ' },
	{ ' ','N',' ',' ',' ',' ','N','N',' ' },
	{ ' ','N',' ',' ',' ',' ',' ','N',' ' }};
	static const vector<vector<char>> letN10 = // definition of 10-pixel normal N font
	{
	{ ' ','N',' ',' ',' ',' ',' ',' ','N',' ' },
	{ ' ','N','N',' ',' ',' ',' ',' ','N',' ' },
	{ ' ','N',' ','N',' ',' ',' ',' ','N',' ' },
	{ ' ','N',' ','N',' ',' ',' ',' ','N',' ' },
	{ ' ','N',' ',' ','N',' ',' ',' ','N',' ' },
	{ ' ','N',' ',' ','N',' ',' ',' ','N',' ' },
	{ ' ','N',' ',' ',' ','N',' ',' ','N',' ' },
	{ ' ','N',' ',' ',' ','N',' ',' ','N',' ' },
	{ ' ','N',' ',' ',' ',' ','N',' ','N',' ' },
	{ ' ','N',' ',' ',' ',' ',' ','N','N',' ' }};
	static const vector<vector<char>> letN11 = // definition of 11-pixel normal N font
	{ 
	{ ' ','N',' ',' ',' ',' ',' ',' ',' ','N',' ' },
	{ ' ','N','N',' ',' ',' ',' ',' ',' ','N',' ' },
	{ ' ','N',' ','N',' ',' ',' ',' ',' ','N',' ' },
	{ ' ','N',' ',' ','N',' ',' ',' ',' ','N',' ' },
	{ ' ','N',' ',' ','N',' ',' ',' ',' ','N',' ' },
	{ ' ','N',' ',' ',' ','N',' ',' ',' ','N',' ' },
	{ ' ','N',' ',' ',' ','N',' ',' ',' ','N',' ' },
	{ ' ','N',' ',' ',' ',' ','N',' ',' ','N',' ' },
	{ ' ','N',' ',' ',' ',' ',' ','N',' ','N',' ' },
	{ ' ','N',' ',' ',' ',' ',' ',' ','N','N',' ' },
	{ ' ','N',' ',' ',' ',' ',' ',' ',' ','N',' ' }};
	static const vector<vector<char>> letN12 = // definition of 12-pixel normal N font
	{
	{ ' ','N',' ',' ',' ',' ',' ',' ',' ',' ','N',' ' },
	{ ' ','N','N',' ',' ',' ',' ',' ',' ',' ','N',' ' },
	{ ' ','N',' ','N',' ',' ',' ',' ',' ',' ','N',' ' },
	{ ' ','N',' ',' ','N',' ',' ',' ',' ',' ','N',' ' },
	{ ' ','N',' ',' ',' ','N',' ',' ',' ',' ','N',' ' },
	{ ' ','N',' ',' ',' ','N',' ',' ',' ',' ','N',' ' },
	{ ' ','N',' ',' ',' ',' ','N',' ',' ',' ','N',' ' },
	{ ' ','N',' ',' ',' ',' ','N',' ',' ',' ','N',' ' },
	{ ' ','N',' ',' ',' ',' ',' ','N',' ',' ','N',' ' },
	{ ' ','N',' ',' ',' ',' ',' ',' ','N',' ','N',' ' },
	{ ' ','N',' ',' ',' ',' ',' ',' ',' ','N','N',' ' },
	{ ' ','N',' ',' ',' ',' ',' ',' ',' ',' ','N',' ' }};

	//BOLD font definitions
	static const vector<vector<char>> letB8 =		//definition of 8-pixel bold N font
	{
	{ 'N','N','N',' ',' ',' ','N','N' },
	{ 'N','N','N','N',' ',' ','N','N' },
	{ 'N','N','N','N',' ',' ','N','N' },
	{ 'N','N',' ','N','N',' ','N','N' },
	{ 'N','N',' ','N','N',' ','N','N' },
	{ 'N','N',' ',' ','N','N','N','N' },
	{ 'N','N',' ',' ',' ','N','N','N' },
	{ 'N','N',' ',' ',' ','N','N','N' }};
	static const vector<vector<char>> letB9 =		// definition of 9-pixel bold N font
	{
	{ 'N','N','N',' ',' ',' ',' ','N','N' },
	{ 'N','N','N','N',' ',' ',' ','N','N' },
	{ 'N','N',' ','N','N',' ',' ','N','N' },
	{ 'N','N',' ','N','N',' ',' ','N','N' },
	{ 'N','N',' ',' ','N','N',' ','N','N' },
	{ 'N','N',' ',' ','N','N',' ','N','N' },
	{ 'N','N',' ',' ',' ','N','N','N','N' },
	{ 'N','N',' ',' ',' ',' ','N','N','N' },
	{ 'N','N',' ',' ',' ',' ','N','N','N' }};
	static const vector<vector<char>> letB10	// definitionof 10-pixel bold N font
	{
	{ 'N','N','N',' ',' ',' ',' ',' ','N','N' },
	{ 'N','N','N','N',' ',' ',' ',' ','N','N' },
	{ 'N','N',' ','N','N',' ',' ',' ','N','N' },
	{ 'N','N',' ','N','N',' ',' ',' ','N','N' },
	{ 'N','N',' ',' ','N','N',' ',' ','N','N' },
	{ 'N','N',' ',' ','N','N',' ',' ','N','N' },
	{ 'N','N',' ',' ',' ','N','N',' ','N','N' },
	{ 'N','N',' ',' ',' ','N','N',' ','N','N' },
	{ 'N','N',' ',' ',' ',' ','N','N','N','N' },
	{ 'N','N',' ',' ',' ',' ',' ','N','N','N' }};
	static const vector<vector<char>> letB11 =	// definition of 11-pixel bold N font
	{
	{ 'N','N','N',' ',' ',' ',' ',' ',' ','N','N' },
	{ 'N','N','N','N',' ',' ',' ',' ',' ','N','N' },
	{ 'N','N',' ','N','N',' ',' ',' ',' ','N','N' },
	{ 'N','N',' ',' ','N','N',' ',' ',' ','N','N' },
	{ 'N','N',' ',' ','N','N',' ',' ',' ','N','N' },
	{ 'N','N',' ',' ',' ','N','N',' ',' ','N','N' },
	{ 'N','N',' ',' ',' ','N','N',' ',' ','N','N' },
	{ 'N','N',' ',' ',' ',' ','N','N',' ','N','N' },
	{ 'N','N',' ',' ',' ',' ',' ','N','N','N','N' },
	{ 'N','N',' ',' ',' ',' ',' ',' ','N','N','N' },
	{ 'N','N',' ',' ',' ',' ',' ',' ','N','N','N' }};

	static const vector<vector<char>> letB12 =		// definition of 12-pixel bold N font
	{
	{ 'N','N','N',' ',' ',' ',' ',' ',' ',' ','N','N' },
	{ 'N','N','N','N',' ',' ',' ',' ',' ',' ','N','N' },
	{ 'N','N',' ','N','N',' ',' ',' ',' ',' ','N','N' },
	{ 'N','N',' ',' ','N','N',' ',' ',' ',' ','N','N' },
	{ 'N','N',' ',' ',' ','N','N',' ',' ',' ','N','N' },
	{ 'N','N',' ',' ',' ','N','N',' ',' ',' ','N','N' },
	{ 'N','N',' ',' ',' ',' ','N','N',' ',' ','N','N' },
	{ 'N','N',' ',' ',' ',' ','N','N',' ',' ','N','N' },
	{ 'N','N',' ',' ',' ',' ',' ','N','N',' ','N','N' },
	{ 'N','N',' ',' ',' ',' ',' ',' ','N','N','N','N' },
	{ 'N','N',' ',' ',' ',' ',' ',' ',' ','N','N','N' },
	{ 'N','N',' ',' ',' ',' ',' ',' ',' ','N','N','N' }};

	// letNsert a vector of the correct size for the requested font
	switch (fontSize)
	{
	case 8:
		if (weightTyp == boldFont)
		{
			formattedWord.push_back(letB8);
		}
		else
		{
			formattedWord.push_back(letN8);
		}
		break;
	case 9:
		if (weightTyp == boldFont)
		{
			formattedWord.push_back(letB9);
		}
		else
		{
			formattedWord.push_back(letN9);
		}
		break;
	case 10:
		if (weightTyp == boldFont)
		{
			formattedWord.push_back(letB10);
		}
		else
		{
			formattedWord.push_back(letN10);
		}
		break;
	case 11:
		if (weightTyp == boldFont)
		{
			formattedWord.push_back(letB11);
		}
		else
		{
			formattedWord.push_back(letN11);
		}
		break;
	case 12:
		if (weightTyp == boldFont)
		{
			formattedWord.push_back(letB12);
		}
		else
		{
			formattedWord.push_back(letN12);
		}
		break;
	default:
		cout << "LOGIC ERROR: invalid font size encountered: " << fontSize;
		error++;
		break;
	}

	return error;
} // end formatN

int WordFont::formatO(int letIdx)
{//Format the letter O in the 2D vector based on the requested size and weight
	int error = 0;
	static const char thisLetter = 'O';
	//NORMAL font definitions
	static const vector<vector<char>> letN8 = //definition of 8-pixel normal O font
	{
	{ ' ',' ','O','O','O','O',' ',' ' },
	{ ' ','O',' ',' ',' ',' ','O',' ' },
	{ ' ','O',' ',' ',' ',' ','O',' ' },
	{ ' ','O',' ',' ',' ',' ','O',' ' },
	{ ' ','O',' ',' ',' ',' ','O',' ' },
	{ ' ','O',' ',' ',' ',' ','O',' ' },
	{ ' ','O',' ',' ',' ',' ','O',' ' },
	{ ' ',' ','O','O','O','O',' ',' ' }};
	static const vector<vector<char>> letN9 =   // definition of 9-pixel normal O font
	{
	{ ' ',' ','O','O','O','O','O',' ',' ' },
	{ ' ','O',' ',' ',' ',' ',' ','O',' ' },
	{ ' ','O',' ',' ',' ',' ',' ','O',' ' },
	{ ' ','O',' ',' ',' ',' ',' ','O',' ' },
	{ ' ','O',' ',' ',' ',' ',' ','O',' ' },
	{ ' ','O',' ',' ',' ',' ',' ','O',' ' },
	{ ' ','O',' ',' ',' ',' ',' ','O',' ' },
	{ ' ','O',' ',' ',' ',' ',' ','O',' ' },
	{ ' ',' ','O','O','O','O','O',' ',' ' }};
	static const vector<vector<char>> letN10 = // definition of 10-pixel normal O font
	{
	{ ' ',' ','O','O','O','O','O','O',' ',' ' },
	{ ' ','O',' ',' ',' ',' ',' ',' ','O',' ' },
	{ ' ','O',' ',' ',' ',' ',' ',' ','O',' ' },
	{ ' ','O',' ',' ',' ',' ',' ',' ','O',' ' },
	{ ' ','O',' ',' ',' ',' ',' ',' ','O',' ' },
	{ ' ','O',' ',' ',' ',' ',' ',' ','O',' ' },
	{ ' ','O',' ',' ',' ',' ',' ',' ','O',' ' },
	{ ' ','O',' ',' ',' ',' ',' ',' ','O',' ' },
	{ ' ','O',' ',' ',' ',' ',' ',' ','O',' ' },
	{ ' ',' ','O','O','O','O','O','O',' ',' ' }};
	static const vector<vector<char>> letN11 = // definition of 11-pixel normal O font
	{
	{ ' ',' ','O','O','O','O','O','O','O',' ',' ' },
	{ ' ','O',' ',' ',' ',' ',' ',' ',' ','O',' ' },
	{ ' ','O',' ',' ',' ',' ',' ',' ',' ','O',' ' },
	{ ' ','O',' ',' ',' ',' ',' ',' ',' ','O',' ' },
	{ ' ','O',' ',' ',' ',' ',' ',' ',' ','O',' ' },
	{ ' ','O',' ',' ',' ',' ',' ',' ',' ','O',' ' },
	{ ' ','O',' ',' ',' ',' ',' ',' ',' ','O',' ' },
	{ ' ','O',' ',' ',' ',' ',' ',' ',' ','O',' ' },
	{ ' ','O',' ',' ',' ',' ',' ',' ',' ','O',' ' },
	{ ' ','O',' ',' ',' ',' ',' ',' ',' ','O',' ' },
	{ ' ',' ','O','O','O','O','O','O','O',' ',' ' }};
	static const vector<vector<char>> letN12 = // definition of 12-pixel normal O font
	{ { ' ',' ','O','O','O','O','O','O','O','O',' ',' ' },
	{ ' ','O',' ',' ',' ',' ',' ',' ',' ',' ','O',' ' },
	{ ' ','O',' ',' ',' ',' ',' ',' ',' ',' ','O',' ' },
	{ ' ','O',' ',' ',' ',' ',' ',' ',' ',' ','O',' ' },
	{ ' ','O',' ',' ',' ',' ',' ',' ',' ',' ','O',' ' },
	{ ' ','O',' ',' ',' ',' ',' ',' ',' ',' ','O',' ' },
	{ ' ','O',' ',' ',' ',' ',' ',' ',' ',' ','O',' ' },
	{ ' ','O',' ',' ',' ',' ',' ',' ',' ',' ','O',' ' },
	{ ' ','O',' ',' ',' ',' ',' ',' ',' ',' ','O',' ' },
	{ ' ','O',' ',' ',' ',' ',' ',' ',' ',' ','O',' ' },
	{ ' ','O',' ',' ',' ',' ',' ',' ',' ',' ','O',' ' },
	{ ' ',' ','O','O','O','O','O','O','O','O',' ',' ' }};

	//BOLD font definitions
	static const vector<vector<char>> letB8 =		//definition of 8-pixel bold O font
	{
	{ ' ','O','O','O','O','O','O',' ' },
	{ 'O','O','O','O','O','O','O','O' },
	{ 'O','O',' ',' ',' ',' ','O','O' },
	{ 'O','O',' ',' ',' ',' ','O','O' },
	{ 'O','O',' ',' ',' ',' ','O','O' },
	{ 'O','O',' ',' ',' ',' ','O','O' },
	{ 'O','O','O','O','O','O','O','O' },
	{ ' ','O','O','O','O','O','O',' ' }};
	static const vector<vector<char>> letB9 =		// definition of 9-pixel bold O font
	{
	{ ' ','O','O','O','O','O','O','O',' ' },
	{ 'O','O','O','O','O','O','O','O','O' },
	{ 'O','O',' ',' ',' ',' ',' ','O','O' },
	{ 'O','O',' ',' ',' ',' ',' ','O','O' },
	{ 'O','O',' ',' ',' ',' ',' ','O','O' },
	{ 'O','O',' ',' ',' ',' ',' ','O','O' },
	{ 'O','O',' ',' ',' ',' ',' ','O','O' },
	{ 'O','O','O','O','O','O','O','O','O' },
	{ ' ','O','O','O','O','O','O','O',' ' }};
	static const vector<vector<char>> letB10	// definitionof 10-pixel bold O font
	{
	{ ' ','O','O','O','O','O','O','O','O',' ' },
	{ 'O','O','O','O','O','O','O','O','O','O' },
	{ 'O','O',' ',' ',' ',' ',' ',' ','O','O' },
	{ 'O','O',' ',' ',' ',' ',' ',' ','O','O' },
	{ 'O','O',' ',' ',' ',' ',' ',' ','O','O' },
	{ 'O','O',' ',' ',' ',' ',' ',' ','O','O' },
	{ 'O','O',' ',' ',' ',' ',' ',' ','O','O' },
	{ 'O','O',' ',' ',' ',' ',' ',' ','O','O' },
	{ 'O','O','O','O','O','O','O','O','O','O' },
	{ ' ','O','O','O','O','O','O','O','O',' ' }};
	static const vector<vector<char>> letB11 =	// definition of 11-pixel bold O font
	{
	{ ' ','O','O','O','O','O','O','O','O','O',' ' },
	{ 'O','O','O','O','O','O','O','O','O','O','O' },
	{ 'O','O',' ',' ',' ',' ',' ',' ',' ','O','O' },
	{ 'O','O',' ',' ',' ',' ',' ',' ',' ','O','O' },
	{ 'O','O',' ',' ',' ',' ',' ',' ',' ','O','O' },
	{ 'O','O',' ',' ',' ',' ',' ',' ',' ','O','O' },
	{ 'O','O',' ',' ',' ',' ',' ',' ',' ','O','O' },
	{ 'O','O',' ',' ',' ',' ',' ',' ',' ','O','O' },
	{ 'O','O',' ',' ',' ',' ',' ',' ',' ','O','O' },
	{ 'O','O','O','O','O','O','O','O','O','O','O' },
	{ ' ','O','O','O','O','O','O','O','O','O',' ' }};

	static const vector<vector<char>> letB12 =		// definition of 12-pixel bold O font
	{
	{ ' ','O','O','O','O','O','O','O','O','O','O',' ' },
	{ 'O','O','O','O','O','O','O','O','O','O','O','O' },
	{ 'O','O',' ',' ',' ',' ',' ',' ',' ',' ','O','O' },
	{ 'O','O',' ',' ',' ',' ',' ',' ',' ',' ','O','O' },
	{ 'O','O',' ',' ',' ',' ',' ',' ',' ',' ','O','O' },
	{ 'O','O',' ',' ',' ',' ',' ',' ',' ',' ','O','O' },
	{ 'O','O',' ',' ',' ',' ',' ',' ',' ',' ','O','O' },
	{ 'O','O',' ',' ',' ',' ',' ',' ',' ',' ','O','O' },
	{ 'O','O',' ',' ',' ',' ',' ',' ',' ',' ','O','O' },
	{ 'O','O',' ',' ',' ',' ',' ',' ',' ',' ','O','O' },
	{ 'O','O','O','O','O','O','O','O','O','O','O','O' },
	{ ' ','O','O','O','O','O','O','O','O','O','O',' ' }};

	// letNsert a vector of the correct size for the requested font
	switch (fontSize)
	{
	case 8:
		if (weightTyp == boldFont)
		{
			formattedWord.push_back(letB8);
		}
		else
		{
			formattedWord.push_back(letN8);
		}
		break;
	case 9:
		if (weightTyp == boldFont)
		{
			formattedWord.push_back(letB9);
		}
		else
		{
			formattedWord.push_back(letN9);
		}
		break;
	case 10:
		if (weightTyp == boldFont)
		{
			formattedWord.push_back(letB10);
		}
		else
		{
			formattedWord.push_back(letN10);
		}
		break;
	case 11:
		if (weightTyp == boldFont)
		{
			formattedWord.push_back(letB11);
		}
		else
		{
			formattedWord.push_back(letN11);
		}
		break;
	case 12:
		if (weightTyp == boldFont)
		{
			formattedWord.push_back(letB12);
		}
		else
		{
			formattedWord.push_back(letN12);
		}
		break;
	default:
		cout << "LOGIC ERROR: invalid font size encountered: " << fontSize;
		error++;
		break;
	}

	return error;
} // end formatO

int WordFont::formatR(int letIdx)
{//Format the letter R in the 2D vector based on the requested size and weight
	int error = 0;
	static const char thisLetter = 'R';
	//NORMAL font definitions
	static const vector<vector<char>> letN8 = //definition of 8-pixel normal R font
	{
	{ ' ','R','R','R','R','R',' ',' ' },
	{ ' ','R',' ',' ',' ',' ','R',' ' },
	{ ' ','R',' ',' ',' ',' ','R',' ' },
	{ ' ','R',' ',' ',' ',' ','R',' ' },
	{ ' ','R','R','R','R','R',' ',' ' },
	{ ' ','R',' ',' ','R',' ',' ',' ' },
	{ ' ','R',' ',' ',' ','R',' ',' ' },
	{ ' ','R',' ',' ',' ',' ','R',' ' }};
	static const vector<vector<char>> letN9 =   // definition of 9-pixel normal R font
	{
		{ ' ','R','R','R','R','R','R',' ',' ' },
	{ ' ','R',' ',' ',' ',' ',' ','R',' ' },
	{ ' ','R',' ',' ',' ',' ',' ','R',' ' },
	{ ' ','R',' ',' ',' ',' ',' ','R',' ' },
	{ ' ','R',' ',' ',' ',' ',' ','R',' ' },
	{ ' ','R','R','R','R','R','R',' ',' ' },
	{ ' ','R',' ',' ',' ','R',' ',' ',' ' },
	{ ' ','R',' ',' ',' ',' ','R',' ',' ' },
	{ ' ','R',' ',' ',' ',' ',' ','R',' ' }};
	static const vector<vector<char>> letN10 = // definition of 10-pixel normal R font
	{
		{ ' ','R','R','R','R','R','R','R',' ',' ' },
	{ ' ','R',' ',' ',' ',' ',' ',' ','R',' ' },
	{ ' ','R',' ',' ',' ',' ',' ',' ','R',' ' },
	{ ' ','R',' ',' ',' ',' ',' ',' ','R',' ' },
	{ ' ','R',' ',' ',' ',' ',' ',' ','R',' ' },
	{ ' ','R','R','R','R','R','R','R',' ',' ' },
	{ ' ','R',' ',' ',' ','R',' ',' ',' ',' ' },
	{ ' ','R',' ',' ',' ',' ','R',' ',' ',' ' },
	{ ' ','R',' ',' ',' ',' ',' ','R',' ',' ' },
	{ ' ','R',' ',' ',' ',' ',' ',' ','R',' ' }};
	static const vector<vector<char>> letN11 = // definition of 11-pixel normal R font
	{
		{ ' ','R','R','R','R','R','R','R','R',' ',' ' },
	{ ' ','R',' ',' ',' ',' ',' ',' ',' ','R',' ' },
	{ ' ','R',' ',' ',' ',' ',' ',' ',' ','R',' ' },
	{ ' ','R',' ',' ',' ',' ',' ',' ',' ','R',' ' },
	{ ' ','R',' ',' ',' ',' ',' ',' ',' ','R',' ' },
	{ ' ','R','R','R','R','R','R','R','R',' ',' ' },
	{ ' ','R',' ',' ',' ','R',' ',' ',' ',' ',' ' },
	{ ' ','R',' ',' ',' ',' ','R',' ',' ',' ',' ' },
	{ ' ','R',' ',' ',' ',' ',' ','R',' ',' ',' ' },
	{ ' ','R',' ',' ',' ',' ',' ',' ','R',' ',' ' },
	{ ' ','R',' ',' ',' ',' ',' ',' ',' ','R',' ' }};
	static const vector<vector<char>> letN12 = // definition of 12-pixel normal R font
	{
		{ ' ','R','R','R','R','R','R','R','R','R',' ',' ' },
	{ ' ','R',' ',' ',' ',' ',' ',' ',' ',' ','R',' ' },
	{ ' ','R',' ',' ',' ',' ',' ',' ',' ',' ','R',' ' },
	{ ' ','R',' ',' ',' ',' ',' ',' ',' ',' ','R',' ' },
	{ ' ','R',' ',' ',' ',' ',' ',' ',' ',' ','R',' ' },
	{ ' ','R',' ',' ',' ',' ',' ',' ',' ',' ','R',' ' },
	{ ' ','R','R','R','R','R','R','R','R','R',' ',' ' },
	{ ' ','R',' ',' ',' ',' ','R',' ',' ',' ',' ',' ' },
	{ ' ','R',' ',' ',' ',' ',' ','R',' ',' ',' ',' ' },
	{ ' ','R',' ',' ',' ',' ',' ',' ','R',' ',' ',' ' },
	{ ' ','R',' ',' ',' ',' ',' ',' ',' ','R',' ',' ' },
	{ ' ','R',' ',' ',' ',' ',' ',' ',' ',' ','R',' ' }};

	//BOLD font definitions
	static const vector<vector<char>> letB8 =		//definition of 8-pixel bold R font
	{
		{ 'R','R','R','R','R','R','R',' ' },
	{ 'R','R','R','R','R','R','R','R' },
	{ 'R','R',' ',' ',' ',' ','R','R' },
	{ 'R','R','R','R','R','R','R','R' },
	{ 'R','R','R','R','R','R','R',' ' },
	{ 'R','R',' ',' ','R','R',' ',' ' },
	{ 'R','R',' ',' ',' ','R','R',' ' },
	{ 'R','R',' ',' ',' ',' ','R','R' }};
	static const vector<vector<char>> letB9 =		// definition of 9-pixel bold R font
	{
		{ 'R','R','R','R','R','R','R','R',' ' },
	{ 'R','R','R','R','R','R','R','R','R' },
	{ 'R','R',' ',' ',' ',' ',' ','R','R' },
	{ 'R','R',' ',' ',' ',' ',' ','R','R' },
	{ 'R','R','R','R','R','R','R','R','R' },
	{ 'R','R','R','R','R','R','R','R',' ' },
	{ 'R','R',' ',' ',' ','R','R',' ',' ' },
	{ 'R','R',' ',' ',' ',' ','R','R',' ' },
	{ 'R','R',' ',' ',' ',' ',' ','R','R' }};
	static const vector<vector<char>> letB10	// definitionof 10-pixel bold R font
	{
		{ 'R','R','R','R','R','R','R','R','R',' ' },
	{ 'R','R','R','R','R','R','R','R','R','R' },
	{ 'R','R',' ',' ',' ',' ',' ',' ','R','R' },
	{ 'R','R',' ',' ',' ',' ',' ',' ','R','R' },
	{ 'R','R','R','R','R','R','R','R','R','R' },
	{ 'R','R','R','R','R','R','R','R','R',' ' },
	{ 'R','R',' ',' ',' ','R','R',' ',' ',' ' },
	{ 'R','R',' ',' ',' ',' ','R','R',' ',' ' },
	{ 'R','R',' ',' ',' ',' ',' ','R','R',' ' },
	{ 'R','R',' ',' ',' ',' ',' ',' ','R','R' }};
	static const vector<vector<char>> letB11 =	// definition of 11-pixel bold R font
	{
		{ 'R','R','R','R','R','R','R','R','R','R',' ' },
	{ 'R','R','R','R','R','R','R','R','R','R','R' },
	{ 'R','R',' ',' ',' ',' ',' ',' ',' ','R','R' },
	{ 'R','R',' ',' ',' ',' ',' ',' ',' ','R','R' },
	{ 'R','R','R','R','R','R','R','R','R','R','R' },
	{ 'R','R','R','R','R','R','R','R','R','R',' ' },
	{ 'R','R',' ',' ',' ','R','R',' ',' ',' ',' ' },
	{ 'R','R',' ',' ',' ',' ','R','R',' ',' ',' ' },
	{ 'R','R',' ',' ',' ',' ',' ','R','R',' ',' ' },
	{ 'R','R',' ',' ',' ',' ',' ',' ','R','R',' ' },
	{ 'R','R',' ',' ',' ',' ',' ',' ',' ','R','R' }};

	static const vector<vector<char>> letB12 =		// definition of 12-pixel bold R font
	{ { 'R','R','R','R','R','R','R','R','R','R','R',' ' },
	{ 'R','R','R','R','R','R','R','R','R','R','R','R' },
	{ 'R','R',' ',' ',' ',' ',' ',' ',' ',' ','R','R' },
	{ 'R','R',' ',' ',' ',' ',' ',' ',' ',' ','R','R' },
	{ 'R','R',' ',' ',' ',' ',' ',' ',' ',' ','R','R' },
	{ 'R','R','R','R','R','R','R','R','R','R','R','R' },
	{ 'R','R','R','R','R','R','R','R','R','R','R',' ' },
	{ 'R','R',' ',' ',' ',' ','R','R',' ',' ',' ',' ' },
	{ 'R','R',' ',' ',' ',' ',' ','R','R',' ',' ',' ' },
	{ 'R','R',' ',' ',' ',' ',' ',' ','R','R',' ',' ' },
	{ 'R','R',' ',' ',' ',' ',' ',' ',' ','R','R',' ' },
	{ 'R','R',' ',' ',' ',' ',' ',' ',' ',' ','R','R' }};

	// letNsert a vector of the correct size for the requested font
	switch (fontSize)
	{
	case 8:
		if (weightTyp == boldFont)
		{
			formattedWord.push_back(letB8);
		}
		else
		{
			formattedWord.push_back(letN8);
		}
		break;
	case 9:
		if (weightTyp == boldFont)
		{
			formattedWord.push_back(letB9);
		}
		else
		{
			formattedWord.push_back(letN9);
		}
		break;
	case 10:
		if (weightTyp == boldFont)
		{
			formattedWord.push_back(letB10);
		}
		else
		{
			formattedWord.push_back(letN10);
		}
		break;
	case 11:
		if (weightTyp == boldFont)
		{
			formattedWord.push_back(letB11);
		}
		else
		{
			formattedWord.push_back(letN11);
		}
		break;
	case 12:
		if (weightTyp == boldFont)
		{
			formattedWord.push_back(letB12);
		}
		else
		{
			formattedWord.push_back(letN12);
		}
		break;
	default:
		cout << "LOGIC ERROR: invalid font size encountered: " << fontSize;
		error++;
		break;
	}

	return error;
} // end formatR

int WordFont::formatS(int letIdx)
{//Format the letter S in the 2D vector based on the requested size and weight
	int error = 0;
	static const char thisLetter = 'S';
	//NORMAL font definitions
	static const vector<vector<char>> letN8 = //definition of 8-pixel normal S font
	{ { ' ',' ','S','S','S','S',' ',' ' },
	{ ' ','S',' ',' ',' ',' ','S',' ' },
	{ ' ','S',' ',' ',' ',' ',' ',' ' },
	{ ' ',' ','S','S','S',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ','S',' ',' ' },
	{ ' ',' ',' ',' ',' ',' ','S',' ' },
	{ ' ','S',' ',' ',' ',' ','S',' ' },
	{ ' ',' ','S','S','S','S',' ',' ' }};
	static const vector<vector<char>> letN9 =   // definition of 9-pixel normal S font
	{ { ' ',' ','S','S','S','S','S',' ',' ' },
	{ ' ','S',' ',' ',' ',' ',' ','S',' ' },
	{ ' ','S',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','S',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ',' ','S','S','S','S',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ',' ','S',' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ','S',' ' },
	{ ' ','S',' ',' ',' ',' ',' ','S',' ' },
	{ ' ',' ','S','S','S','S','S',' ',' ' }};
	static const vector<vector<char>> letN10 = // definition of 10-pixel normal S font
	{ { ' ',' ','S','S','S','S','S','S',' ',' ' },
	{ ' ','S',' ',' ',' ',' ',' ',' ','S',' ' },
	{ ' ','S',' ',' ',' ',' ',' ',' ','S',' ' },
	{ ' ','S',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ',' ','S','S','S','S','S',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ','S',' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ','S',' ' },
	{ ' ','S',' ',' ',' ',' ',' ',' ','S',' ' },
	{ ' ','S',' ',' ',' ',' ',' ',' ','S',' ' },
	{ ' ',' ','S','S','S','S','S','S',' ',' ' }};
	static const vector<vector<char>> letN11 = // definition of 11-pixel normal S font
	{ { ' ',' ','S','S','S','S','S','S','S',' ',' ' },
	{ ' ','S',' ',' ',' ',' ',' ',' ',' ','S',' ' },
	{ ' ','S',' ',' ',' ',' ',' ',' ',' ','S',' ' },
	{ ' ','S',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','S',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ',' ','S','S','S','S','S','S','S',' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ','S',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ','S',' ' },
	{ ' ','S',' ',' ',' ',' ',' ',' ',' ','S',' ' },
	{ ' ','S',' ',' ',' ',' ',' ',' ',' ','S',' ' },
	{ ' ',' ','S','S','S','S','S','S','S',' ',' ' } };
	static const vector<vector<char>> letN12 = // definition of 12-pixel normal S font
	{ { ' ',' ','S','S','S','S','S','S','S','S',' ',' ' },
	{ ' ','S',' ',' ',' ',' ',' ',' ',' ',' ','S',' ' },
	{ ' ','S',' ',' ',' ',' ',' ',' ',' ',' ','S',' ' },
	{ ' ','S',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','S',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ',' ','S','S','S','S','S','S','S',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ','S',' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','S',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','S',' ' },
	{ ' ','S',' ',' ',' ',' ',' ',' ',' ',' ','S',' ' },
	{ ' ','S',' ',' ',' ',' ',' ',' ',' ',' ','S',' ' },
	{ ' ',' ','S','S','S','S','S','S','S','S',' ',' ' }};

	//BOLD font definitions
	static const vector<vector<char>> letB8 =		//definition of 8-pixel bold S font
	{ { ' ','S','S','S','S','S','S','S' },
	{ 'S','S','S','S','S','S','S','S' },
	{ 'S','S',' ',' ',' ',' ',' ','S' },
	{ ' ','S','S','S','S',' ',' ',' ' },
	{ ' ',' ','S','S','S','S',' ',' ' },
	{ 'S',' ',' ',' ',' ','S','S',' ' },
	{ 'S','S','S','S','S','S','S',' ' },
	{ ' ','S','S','S','S','S',' ',' ' }};
	static const vector<vector<char>> letB9 =		// definition of 9-pixel bold S font
	{ { ' ','S','S','S','S','S','S','S','S' },
	{ 'S','S','S','S','S','S','S','S','S' },
	{ 'S','S',' ',' ',' ',' ',' ',' ','S' },
	{ 'S','S',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','S','S','S','S','S','S',' ',' ' },
	{ ' ',' ','S','S','S','S','S','S',' ' },
	{ 'S',' ',' ',' ',' ',' ','S','S',' ' },
	{ 'S','S','S','S','S','S','S','S',' ' },
	{ 'S','S','S','S','S','S','S',' ',' ' }};
	static const vector<vector<char>> letB10	// definitionof 10-pixel bold S font
	{ { ' ','S','S','S','S','S','S','S','S',' ' },
	{ 'S','S','S','S','S','S','S','S','S','S' },
	{ 'S','S',' ',' ',' ',' ',' ',' ','S','S' },
	{ 'S','S',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','S','S','S','S','S','S',' ',' ',' ' },
	{ ' ',' ','S','S','S','S','S','S',' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ','S','S',' ' },
	{ 'S','S',' ',' ',' ',' ',' ','S','S',' ' },
	{ 'S','S','S','S','S','S','S','S','S',' ' },
	{ ' ','S','S','S','S','S','S','S',' ',' ' }};
	static const vector<vector<char>> letB11 =	// definition of 11-pixel bold S font
	{ { ' ','S','S','S','S','S','S','S','S','S',' ' },
	{ 'S','S','S','S','S','S','S','S','S','S','S' },
	{ 'S','S',' ',' ',' ',' ',' ',' ',' ','S','S' },
	{ 'S','S',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ 'S','S',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ','S','S','S','S','S','S','S','S','S',' ' },
	{ ' ',' ','S','S','S','S','S','S','S','S','S' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ','S','S' },
	{ 'S','S',' ',' ',' ',' ',' ',' ',' ','S','S' },
	{ 'S','S','S','S','S','S','S','S','S','S','S' },
	{ ' ','S','S','S','S','S','S','S','S','S',' ' }};

	static const vector<vector<char>> letB12 =		// definition of 12-pixel bold S font
	{ { ' ','S','S','S','S','S','S','S','S','S','S',' ' },
	{ 'S','S','S','S','S','S','S','S','S','S','S','S' },
	{ 'S','S',' ',' ',' ',' ',' ',' ',' ',' ','S','S' },
	{ 'S','S',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ 'S','S',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ 'S','S','S','S','S','S','S','S','S','S','S',' ' },
	{ ' ','S','S','S','S','S','S','S','S','S','S','S' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','S','S' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','S','S' },
	{ 'S','S',' ',' ',' ',' ',' ',' ',' ',' ','S','S' },
	{ 'S','S','S','S','S','S','S','S','S','S','S','S' },
	{ ' ','S','S','S','S','S','S','S','S','S','S',' ' }};

	// letNsert a vector of the correct size for the requested font
	switch (fontSize)
	{
	case 8:
		if (weightTyp == boldFont)
		{
			formattedWord.push_back(letB8);
		}
		else
		{
			formattedWord.push_back(letN8);
		}
		break;
	case 9:
		if (weightTyp == boldFont)
		{
			formattedWord.push_back(letB9);
		}
		else
		{
			formattedWord.push_back(letN9);
		}
		break;
	case 10:
		if (weightTyp == boldFont)
		{
			formattedWord.push_back(letB10);
		}
		else
		{
			formattedWord.push_back(letN10);
		}
		break;
	case 11:
		if (weightTyp == boldFont)
		{
			formattedWord.push_back(letB11);
		}
		else
		{
			formattedWord.push_back(letN11);
		}
		break;
	case 12:
		if (weightTyp == boldFont)
		{
			formattedWord.push_back(letB12);
		}
		else
		{
			formattedWord.push_back(letN12);
		}
		break;
	default:
		cout << "LOGIC ERROR: invalid font size encountered: " << fontSize;
		error++;
		break;
	}

	return error;
} // end formatS

int WordFont::formatT(int letIdx)
{//Format the letter T in the 2D vector based on the requested size and weight
	int error = 0;
	static const char thisLetter = 'T';
	//NORMAL font definitions
	static const vector<vector<char>> letN8 = //definition of 8-pixel normal T font
	{ { ' ','T','T','T','T','T','T',' ' },
	{ ' ',' ',' ','T',' ',' ',' ',' ' },
	{ ' ',' ',' ','T',' ',' ',' ',' ' },
	{ ' ',' ',' ','T',' ',' ',' ',' ' },
	{ ' ',' ',' ','T',' ',' ',' ',' ' },
	{ ' ',' ',' ','T',' ',' ',' ',' ' },
	{ ' ',' ',' ','T',' ',' ',' ',' ' },
	{ ' ',' ',' ','T',' ',' ',' ',' ' }};
	static const vector<vector<char>> letN9 =   // definition of 9-pixel normal T font
	{ { ' ','T','T','T','T','T','T','T',' ' },
	{ ' ',' ',' ',' ','T',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ','T',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ','T',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ','T',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ','T',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ','T',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ','T',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ','T',' ',' ',' ',' ' }};
	static const vector<vector<char>> letN10 = // definition of 10-pixel normal T font
	{ { ' ','T','T','T','T','T','T','T','T',' ' },
	{ ' ',' ',' ',' ','T',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ','T',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ','T',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ','T',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ','T',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ','T',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ','T',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ','T',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ','T',' ',' ',' ',' ',' ' }};
	static const vector<vector<char>> letN11 = // definition of 11-pixel normal T font
	{ { ' ','T','T','T','T','T','T','T','T','T',' ' },
	{ ' ',' ',' ',' ',' ','T',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ','T',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ','T',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ','T',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ','T',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ','T',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ','T',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ','T',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ','T',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ','T',' ',' ',' ',' ',' ' }};
	static const vector<vector<char>> letN12 = // definition of 12-pixel normal T font
	{ { ' ','T','T','T','T','T','T','T','T','T','T',' ' },
	{ ' ',' ',' ',' ',' ','T',' ',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ','T',' ',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ','T',' ',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ','T',' ',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ','T',' ',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ','T',' ',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ','T',' ',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ','T',' ',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ','T',' ',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ','T',' ',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ','T',' ',' ',' ',' ',' ',' ' }};

	//BOLD font definitions
	static const vector<vector<char>> letB8 =		//definition of 8-pixel bold T font
	{ { 'T','T','T','T','T','T','T','T' },
	{ 'T','T','T','T','T','T','T','T' },
	{ ' ',' ',' ','T','T',' ',' ',' ' },
	{ ' ',' ',' ','T','T',' ',' ',' ' },
	{ ' ',' ',' ','T','T',' ',' ',' ' },
	{ ' ',' ',' ','T','T',' ',' ',' ' },
	{ ' ',' ',' ','T','T',' ',' ',' ' },
	{ ' ',' ',' ','T','T',' ',' ',' ' }};
	static const vector<vector<char>> letB9 =		// definition of 9-pixel bold T font
	{ { 'T','T','T','T','T','T','T','T','T' },
	{ ' ','T','T','T','T','T','T','T','T' },
	{ ' ',' ',' ','T','T',' ',' ',' ',' ' },
	{ ' ',' ',' ','T','T',' ',' ',' ',' ' },
	{ ' ',' ',' ','T','T',' ',' ',' ',' ' },
	{ ' ',' ',' ','T','T',' ',' ',' ',' ' },
	{ ' ',' ',' ','T','T',' ',' ',' ',' ' },
	{ ' ',' ',' ','T','T',' ',' ',' ',' ' },
	{ ' ',' ',' ','T','T',' ',' ',' ',' ' }};
	static const vector<vector<char>> letB10	// definitionof 10-pixel bold T font
	{ { 'T','T','T','T','T','T','T','T','T','T' },
	{ 'T','T','T','T','T','T','T','T','T','T' },
	{ ' ',' ',' ',' ','T','T',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ','T','T',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ','T','T',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ','T','T',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ','T','T',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ','T','T',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ','T','T',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ','T','T',' ',' ',' ',' ' }};
	static const vector<vector<char>> letB11 =	// definition of 11-pixel bold T font
	{ { 'T','T','T','T','T','T','T','T','T','T','T' },
	{ ' ','T','T','T','T','T','T','T','T','T','T' },
	{ ' ',' ',' ',' ','T','T',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ','T','T',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ','T','T',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ','T','T',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ','T','T',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ','T','T',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ','T','T',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ','T','T',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ','T','T',' ',' ',' ',' ',' ' }};

	static const vector<vector<char>> letB12 =		// definition of 12-pixel bold T font
	{ { 'T','T','T','T','T','T','T','T','T','T','T','T' },
	{ 'T','T','T','T','T','T','T','T','T','T','T','T' },
	{ ' ',' ',' ',' ',' ','T','T',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ','T','T',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ','T','T',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ','T','T',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ','T','T',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ','T','T',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ','T','T',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ','T','T',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ','T','T',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ','T','T',' ',' ',' ',' ',' ' }};

	// letNsert a vector of the correct size for the requested font
	switch (fontSize)
	{
	case 8:
		if (weightTyp == boldFont)
		{
			formattedWord.push_back(letB8);
		}
		else
		{
			formattedWord.push_back(letN8);
		}
		break;
	case 9:
		if (weightTyp == boldFont)
		{
			formattedWord.push_back(letB9);
		}
		else
		{
			formattedWord.push_back(letN9);
		}
		break;
	case 10:
		if (weightTyp == boldFont)
		{
			formattedWord.push_back(letB10);
		}
		else
		{
			formattedWord.push_back(letN10);
		}
		break;
	case 11:
		if (weightTyp == boldFont)
		{
			formattedWord.push_back(letB11);
		}
		else
		{
			formattedWord.push_back(letN11);
		}
		break;
	case 12:
		if (weightTyp == boldFont)
		{
			formattedWord.push_back(letB12);
		}
		else
		{
			formattedWord.push_back(letN12);
		}
		break;
	default:
		cout << "LOGIC ERROR: invalid font size encountered: " << fontSize;
		error++;
		break;
	}

	return error;
} // END formatT

int WordFont::formatU(int letIdx)
{//Format the letter U in the 2D vector based on the requested size and weight
	int error = 0;
	static const char thisLetter = 'U';
	//NORMAL font definitions
	static const vector<vector<char>> letN8 = //definition of 8-pixel normal U font
	{ { ' ','U',' ',' ',' ',' ','U',' ' },
	{ ' ','U',' ',' ',' ',' ','U',' ' },
	{ ' ','U',' ',' ',' ',' ','U',' ' },
	{ ' ','U',' ',' ',' ',' ','U',' ' },
	{ ' ','U',' ',' ',' ',' ','U',' ' },
	{ ' ','U',' ',' ',' ',' ','U',' ' },
	{ ' ','U',' ',' ',' ',' ','U',' ' },
	{ ' ',' ','U','U','U','U',' ',' ' }};
	static const vector<vector<char>> letN9 =   // definition of 9-pixel normal U font
	{ { ' ','U',' ',' ',' ',' ',' ','U',' ' },
	{ ' ','U',' ',' ',' ',' ',' ','U',' ' },
	{ ' ','U',' ',' ',' ',' ',' ','U',' ' },
	{ ' ','U',' ',' ',' ',' ',' ','U',' ' },
	{ ' ','U',' ',' ',' ',' ',' ','U',' ' },
	{ ' ','U',' ',' ',' ',' ',' ','U',' ' },
	{ ' ','U',' ',' ',' ',' ',' ','U',' ' },
	{ ' ','U',' ',' ',' ',' ',' ','U',' ' },
	{ ' ',' ','U','U','U','U','U',' ',' ' }};
	static const vector<vector<char>> letN10 = // definition of 10-pixel normal U font
	{ { ' ','U',' ',' ',' ',' ',' ',' ','U',' ' },
	{ ' ','U',' ',' ',' ',' ',' ',' ','U',' ' },
	{ ' ','U',' ',' ',' ',' ',' ',' ','U',' ' },
	{ ' ','U',' ',' ',' ',' ',' ',' ','U',' ' },
	{ ' ','U',' ',' ',' ',' ',' ',' ','U',' ' },
	{ ' ','U',' ',' ',' ',' ',' ',' ','U',' ' },
	{ ' ','U',' ',' ',' ',' ',' ',' ','U',' ' },
	{ ' ','U',' ',' ',' ',' ',' ',' ','U',' ' },
	{ ' ','U',' ',' ',' ',' ',' ',' ','U',' ' },
	{ ' ',' ','U','U','U','U','U','U',' ',' ' }};
	static const vector<vector<char>> letN11 = // definition of 11-pixel normal U font
	{ { ' ','U',' ',' ',' ',' ',' ',' ',' ','U',' ' },
	{ ' ','U',' ',' ',' ',' ',' ',' ',' ','U',' ' },
	{ ' ','U',' ',' ',' ',' ',' ',' ',' ','U',' ' },
	{ ' ','U',' ',' ',' ',' ',' ',' ',' ','U',' ' },
	{ ' ','U',' ',' ',' ',' ',' ',' ',' ','U',' ' },
	{ ' ','U',' ',' ',' ',' ',' ',' ',' ','U',' ' },
	{ ' ','U',' ',' ',' ',' ',' ',' ',' ','U',' ' },
	{ ' ','U',' ',' ',' ',' ',' ',' ',' ','U',' ' },
	{ ' ','U',' ',' ',' ',' ',' ',' ',' ','U',' ' },
	{ ' ','U',' ',' ',' ',' ',' ',' ',' ','U',' ' },
	{ ' ',' ','U','U','U','U','U','U','U',' ',' ' }};
	static const vector<vector<char>> letN12 = // definition of 12-pixel normal U font
	{ { ' ','U',' ',' ',' ',' ',' ',' ',' ',' ','U',' ' },
	{ ' ','U',' ',' ',' ',' ',' ',' ',' ',' ','U',' ' },
	{ ' ','U',' ',' ',' ',' ',' ',' ',' ',' ','U',' ' },
	{ ' ','U',' ',' ',' ',' ',' ',' ',' ',' ','U',' ' },
	{ ' ','U',' ',' ',' ',' ',' ',' ',' ',' ','U',' ' },
	{ ' ','U',' ',' ',' ',' ',' ',' ',' ',' ','U',' ' },
	{ ' ','U',' ',' ',' ',' ',' ',' ',' ',' ','U',' ' },
	{ ' ','U',' ',' ',' ',' ',' ',' ',' ',' ','U',' ' },
	{ ' ','U',' ',' ',' ',' ',' ',' ',' ',' ','U',' ' },
	{ ' ','U',' ',' ',' ',' ',' ',' ',' ',' ','U',' ' },
	{ ' ','U',' ',' ',' ',' ',' ',' ',' ',' ','U',' ' },
	{ ' ',' ','U','U','U','U','U','U','U','U',' ',' ' }};

	//BOLD font definitions
	static const vector<vector<char>> letB8 =		//definition of 8-pixel bold U font
	{ { 'U','U',' ',' ',' ',' ','U',' ' },
	{ 'U','U',' ',' ',' ',' ','U',' ' },
	{ 'U','U',' ',' ',' ',' ','U',' ' },
	{ 'U','U',' ',' ',' ',' ','U',' ' },
	{ 'U','U',' ',' ',' ',' ','U',' ' },
	{ 'U','U',' ',' ',' ',' ','U',' ' },
	{ 'U','U','U','U','U','U','U',' ' },
	{ ' ','U','U','U','U','U','U',' ' },
	};
	static const vector<vector<char>> letB9 =		// definition of 9-pixel bold U font
	{ { 'U','U',' ',' ',' ',' ',' ','U','U' },
	{ 'U','U',' ',' ',' ',' ',' ','U','U' },
	{ 'U','U',' ',' ',' ',' ',' ','U','U' },
	{ 'U','U',' ',' ',' ',' ',' ','U','U' },
	{ 'U','U',' ',' ',' ',' ',' ','U','U' },
	{ 'U','U',' ',' ',' ',' ',' ','U','U' },
	{ 'U','U',' ',' ',' ',' ',' ','U','U' },
	{ 'U','U','U','U','U','U','U','U','U' },
	{ ' ','U','U','U','U','U','U','U',' ' }};
	static const vector<vector<char>> letB10	// definitionof 10-pixel bold U font
	{ { 'U','U',' ',' ',' ',' ',' ',' ','U','U' },
	{ 'U','U',' ',' ',' ',' ',' ',' ','U','U' },
	{ 'U','U',' ',' ',' ',' ',' ',' ','U','U' },
	{ 'U','U',' ',' ',' ',' ',' ',' ','U','U' },
	{ 'U','U',' ',' ',' ',' ',' ',' ','U','U' },
	{ 'U','U',' ',' ',' ',' ',' ',' ','U','U' },
	{ 'U','U',' ',' ',' ',' ',' ',' ','U','U' },
	{ 'U','U',' ',' ',' ',' ',' ',' ','U','U' },
	{ 'U','U','U','U','U','U','U','U','U','U' },
	{ ' ','U','U','U','U','U','U','U','U',' ' }};
	static const vector<vector<char>> letB11 =	// definition of 11-pixel bold U font
	{ { 'U','U',' ',' ',' ',' ',' ',' ',' ','U','U' },
	{ 'U','U',' ',' ',' ',' ',' ',' ',' ','U','U' },
	{ 'U','U',' ',' ',' ',' ',' ',' ',' ','U','U' },
	{ 'U','U',' ',' ',' ',' ',' ',' ',' ','U','U' },
	{ 'U','U',' ',' ',' ',' ',' ',' ',' ','U','U' },
	{ 'U','U',' ',' ',' ',' ',' ',' ',' ','U','U' },
	{ 'U','U',' ',' ',' ',' ',' ',' ',' ','U','U' },
	{ 'U','U',' ',' ',' ',' ',' ',' ',' ','U','U' },
	{ 'U','U',' ',' ',' ',' ',' ',' ',' ','U','U' },
	{ 'U','U','U','U','U','U','U','U','U','U','U' },
	{ ' ','U','U','U','U','U','U','U','U','U',' ' }};

	static const vector<vector<char>> letB12 =		// definition of 12-pixel bold U font
	{ { 'U','U',' ',' ',' ',' ',' ',' ',' ',' ','U','U' },
	{ 'U','U',' ',' ',' ',' ',' ',' ',' ',' ','U','U' },
	{ 'U','U',' ',' ',' ',' ',' ',' ',' ',' ','U','U' },
	{ 'U','U',' ',' ',' ',' ',' ',' ',' ',' ','U','U' },
	{ 'U','U',' ',' ',' ',' ',' ',' ',' ',' ','U','U' },
	{ 'U','U',' ',' ',' ',' ',' ',' ',' ',' ','U','U' },
	{ 'U','U',' ',' ',' ',' ',' ',' ',' ',' ','U','U' },
	{ 'U','U',' ',' ',' ',' ',' ',' ',' ',' ','U','U' },
	{ 'U','U',' ',' ',' ',' ',' ',' ',' ',' ','U','U' },
	{ 'U','U',' ',' ',' ',' ',' ',' ',' ',' ','U','U' },
	{ 'U','U','U','U','U','U','U','U','U','U','U','U' },
	{ ' ','U','U','U','U','U','U','U','U','U','U',' ' }};

	// letNsert a vector of the correct size for the requested font
	switch (fontSize)
	{
	case 8:
		if (weightTyp == boldFont)
		{
			formattedWord.push_back(letB8);
		}
		else
		{
			formattedWord.push_back(letN8);
		}
		break;
	case 9:
		if (weightTyp == boldFont)
		{
			formattedWord.push_back(letB9);
		}
		else
		{
			formattedWord.push_back(letN9);
		}
		break;
	case 10:
		if (weightTyp == boldFont)
		{
			formattedWord.push_back(letB10);
		}
		else
		{
			formattedWord.push_back(letN10);
		}
		break;
	case 11:
		if (weightTyp == boldFont)
		{
			formattedWord.push_back(letB11);
		}
		else
		{
			formattedWord.push_back(letN11);
		}
		break;
	case 12:
		if (weightTyp == boldFont)
		{
			formattedWord.push_back(letB12);
		}
		else
		{
			formattedWord.push_back(letN12);
		}
		break;
	default:
		cout << "LOGIC ERROR: invalid font size encountered: " << fontSize;
		error++;
		break;
	}

	return error;
}

void WordFont::maskLetter(int letIdx, char letter)
{
	static const char blank = ' ';
	char pChar;

	if (pixelChar == ' ')
	{
		pChar = letter;
	}
	else
	{
		pChar = pixelChar;
	}

	// now replace with correct pixel character
	for (size_t row = 0; row < formattedWord.at(letIdx).size(); row++)
	{
		for (size_t col = 0; col < formattedWord.at(letIdx).size(); col++)
		{ //replaces zeros with blank and ones with the pixel char
			if (formattedWord.at(letIdx).at(row).at(col) == letter)
			{
				formattedWord.at(letIdx).at(row).at(col) = pChar;
			}
		}
	}
	return;
}

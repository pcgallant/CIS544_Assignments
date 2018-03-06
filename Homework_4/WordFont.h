#include <string>
#include <vector>
#include <stdexcept>
using namespace std;
class WordFont
{
public:
	WordFont();  //default constructor

	void setFontSize(int fSize);  //set the fontSize for the word
	int getFontSize();
	void setFontWeight(char weight);
	char getFontWeight();
	void setPixelChar(char inputC);
	char getPixelChar();

	int const getMaxFontSize();
	int const getMinFontSize();
	size_t const getMaxWordLength();
	string getImplementedLetters();  // will return the list of implemented letters
	
	bool validateFontSize(int fSize);
	bool validateFontWeight(char fWeight);
	bool validateWordLength(string inWord);

	void printWord(int fontSize, char pixelChar, char fontWeight, string word);




private:
	int const minFontSize;
	int const maxFontSize;
	size_t const maxWordLength;
	int const normalFont;
	int const boldFont;
	char pixelChar;  //The character the user wants to use to draw the letters
	int fontSize;   // the size of the font -- between 8 (default) and 12
	char weightTyp;   //The weight of the character B = bold, N = Normal (default)
	const string implementedLetters;

	bool setFormattedWord(string word);  // this helper method will create the appropriate 2D vector for each letter of the word in preparation for printing
	
	// vector declaration
	vector<vector<vector<char>>> formattedWord;
	
	string word;  // the word being drawn this needs to be an array of 2D vectors, one for each letter in the word
	// implemented letters (minimum of 15 required)
	int formatA(int letIdx);  //must have
	int formatB(int letIdx);
	int formatC(int letIdx);
	int formatD(int letIdx);
	int formatE(int letIdx); //must have
	int formatH(int letIdx);
	int formatI(int letIdx); //must have
	int formatL(int letIdx);
	int formatM(int letIdx);
	int formatN(int letIdx);
	int formatO(int letIdx); // must have
	int formatR(int letIdx);
	int formatS(int letIdx);
	int formatT(int letIdx);
	int formatU(int letIdx); // must have

	void maskLetter(int letIdx, char letter);
//TODO if you have time
//	int formatF(int letIdx);
//	int formatG(int letIdx);
//	int formatJ(int letIdx);
//	int formatK(int letIdx);
//	int formatP(int letIdx);
//	int formatQ(int letIdx);
//	int formatV(int letIdx);
//	int formatW(int letIdx);
//	int formatX(int letIdx);
//	int formatY(int letIdx);
//	int printZ(int letIdx);

};


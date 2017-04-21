#include <iostream>
#include <iomanip>

#include "FileInspector.h"

using namespace std;
using namespace fileinspector;

const int kDefaultListSize = 5000;
const int kNumberOfLettersInAlphabet = 26;

int main()
{
	string selectedWords[100];
	InitializeList(selectedWords, 100, " ");
	int wordCount[kDefaultListSize];
	InitializeList(wordCount, kDefaultListSize, 0);
	float wordFrequencies[kDefaultListSize];
	InitializeList(wordFrequencies, kDefaultListSize, 0.0);
	string shortestWord = " ";
	string longestWord = " ";
	int numberOfLetters[kNumberOfLettersInAlphabet];
	InitializeList(numberOfLetters, kNumberOfLettersInAlphabet, 0);
	int numberOfNonLetters = 0;
	int numberOfNumbers = 0;
	int numberOfVowels = 0;
	int numberOfWords = 0;
	int totalNumberOfCharacters = 0;
	double averageWordLength = 0.0;


	return 0;
}
#ifndef FILEINSPECTOR_H
#define FILEINSPECTOR_H

using namespace std;

namespace fileinspector
{
	/*
	Takes input from user to select which text to inspect
	*/
	int UserInput();

	/*
	Tests to see if the values are the proper type and within a specified range

	@param variable the input from the user
	@param minimum the minimum value of the desired range
	@param maximum the maximum value of the desired range
	*/
	int InvalidInput(int variable, int min, int max);

	/*
	Writes the select words into the arrray selectedWords[]

	@param selectedWords[] the array that the words will be stored in
	@param size the size of the array
	*/
	void FillSelectedWordsArray(string selectedWords[], int size);

	/*
	Fills a specified array with a default value

	@param list[] the array to be iniatialized
	@param size the size of the array
	@param the default value to be inserted into the array
	*/
	void InitializeList(string list[], int size, string defaultValue);

	/*
	Fills a specified array with a default value

	@param list[] the array to be iniatialized
	@param size the size of the array
	@param the default value to be inserted into the array
	*/
	void InitializeList(int list[], int size, int defaultValue);

	/*
	Fills a specified array with a default value

	@param list[] the array to be iniatialized
	@param size the size of the array
	@param the default value to be inserted into the array
	*/
	void InitializeList(float list[], int size, float defaultValue);

	/*
	Increments by one the corresponding position in the array numberOfLetters when a letter is found

	@param letter the given character
	*/
	void LetterCounter(int numberOfLetters[], int size, char letter);

	/*
	Checks to if the given letter is a vowel in the English alphabet

	@ param letter a single ascii character

	@return isVowel returns true if the given character is a vowel
	*/
	bool IsVowel(char letter);

	/*
	Checks if a word contains (or is solely) a character or symbol other than the 26 letters of the English alphabet

	@param word the English word currently in the input stream

	@return isPunctuation returns true if the string is solely puncuation or the string ends with punctuation
	*/
	bool IsPunctuation(char letter);

	/*
	Replaces all uppercase letters in a string with lowercase letters

	@param word the current string input from the chosen file
	*/
	string ToLowercase(string word);

	/*
	Checks if the character is a number

	@param character the current character
	*/
	bool IsNumber(char word);

	/*
	Fills an array with each letter of the alphabet
	*/
	void AlphabetArray(char alphabet[], int kNumberOfLettersInAlphabet);

	/*Contains code to test functions*/
	void TestCode();
}

#endif


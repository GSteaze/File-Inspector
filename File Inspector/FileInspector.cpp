#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

#include "FileInspector.h"

using namespace std;

const int kEndOfLine = 1024;
const int kSelectedWordsListSize = 100;
const int kNumberOfLettersInAlphabet = 26;
const int kColumnWidthOne = 8;
const int kColumnWidthTwo = 15;
const int kNumberOfSignificantDigits = 4;


namespace fileinspector
{
	/*
	Takes input from user to select which text to inspect
	*/
	int UserInput()
	{
		int textNumber = 0;

		cout << "Which text would you like to inspect?" << endl
			<< "1. A Modest Proposal" << endl
			<< "2. Apology" << endl
			<< "Enter 1 or 2 to select the text : ";
		cin >> textNumber;
		textNumber = InvalidInput(textNumber, 1, 2);
		return textNumber;
	}

	/*
	Tests to see if the values are the proper type and within a specified range

	@param variable the input from the user
	@param minimum the minimum value of the desired range
	@param maximum the maximum value of the desired range
	*/
	int InvalidInput(int variable, int min, int max)
	{
		bool isInvalid = cin.fail() || (variable < min || variable > max);
		while (isInvalid)
		{
			cin.clear();
			cin.ignore(kEndOfLine, '\n');
			cout << "Please Try Again : ";
			cin >> variable;
			isInvalid = cin.fail() || (variable < min || variable > max);
		}
		return variable;
	}

	/*
	Writes the select words into the arrray selectedWords[]

	@param selectedWords[] the array that the words will be stored in
	@param size the size of the array
	*/
	void FillSelectedWordsArray(string selectedWords[], int size)
	{
		ifstream fin;
		fin.open("SelectWords.txt");
		for (int index = 0; index < size; index++)
		{
			fin >> selectedWords[index];
		}
		fin.close();
	}

	/*
	Fills a specified array with a default value

	@param list[] the array to be iniatialized
	@param size the size of the array
	@param the default value to be inserted into the array
	*/
	void InitializeList(string list[], int size, string defaultValue)
	{
			for (int index = 0; index < size; index++)
			{
				list[index] = defaultValue;
			}
	}

	/*
	Fills a specified array with a default value

	@param list[] the array to be iniatialized
	@param size the size of the array
	@param the default value to be inserted into the array
	*/
	void InitializeList(int list[], int size, int defaultValue)
	{
		for (int index = 0; index < size; index++)
		{
			list[index] = defaultValue;
		}
	}

	/*
	Fills a specified array with a default value

	@param list[] the array to be iniatialized
	@param size the size of the array
	@param the default value to be inserted into the array
	*/
	void InitializeList(float list[], int size, float defaultValue)
	{
		for (int index = 0; index < size; index++)
		{
			list[index] = defaultValue;
		}
	}

	/*
	Increments by one the corresponding position in the array numberOfLetters when a letter is found

	@param letter the given character
	*/
	void LetterCounter(int numberOfLetters[], int size, char letter)
	{
		if (letter == 'a')
		{
			numberOfLetters[0]++;
		}
		else if (letter == 'b')
		{
			numberOfLetters[1]++;
		}
		else if (letter == 'c')
		{
			numberOfLetters[2]++;
		}
		else if (letter == 'd')
		{
			numberOfLetters[3]++;
		}
		else if (letter == 'e')
		{
			numberOfLetters[4]++;
		}
		else if (letter == 'f')
		{
			numberOfLetters[5]++;
		}
		else if (letter == 'g')
		{
			numberOfLetters[6]++;
		}
		else if (letter == 'h')
		{
			numberOfLetters[7]++;
		}
		else if (letter == 'i')
		{
			numberOfLetters[8]++;
		}
		else if (letter == 'j')
		{
			numberOfLetters[9]++;
		}
		else if (letter == 'k')
		{
			numberOfLetters[10]++;
		}
		else if (letter == 'l')
		{
			numberOfLetters[11]++;
		}
		else if (letter == 'm')
		{
			numberOfLetters[12]++;
		}
		else if (letter == 'n')
		{
			numberOfLetters[13]++;
		}
		else if (letter == 'o')
		{
			numberOfLetters[14]++;
		}
		else if (letter == 'p')
		{
			numberOfLetters[15]++;
		}
		else if (letter == 'q')
		{
			numberOfLetters[16]++;
		}
		else if (letter == 'r')
		{
			numberOfLetters[17]++;
		}
		else if (letter == 's')
		{
			numberOfLetters[18]++;
		}
		else if (letter == 't')
		{
			numberOfLetters[19]++;
		}
		else if (letter == 'u')
		{
			numberOfLetters[20]++;
		}
		else if (letter == 'v')
		{
			numberOfLetters[21]++;
		}
		else if (letter == 'w')
		{
			numberOfLetters[22]++;
		}
		else if (letter == 'x')
		{
			numberOfLetters[23]++;
		}
		else if (letter == 'y')
		{
			numberOfLetters[24]++;
		}
		else if (letter == 'z')
		{
			numberOfLetters[25]++;
		}
	}

	/*
	Checks to if the given letter is a vowel in the English alphabet

	@ param letter a single ascii character

	@return isVowel returns true if the given character is a vowel
	*/
	bool IsVowel(char letter)
	{
		bool isVowel = 0;

		if (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u' ||
			letter == 'A' || letter == 'E' || letter == 'I' || letter == 'O' || letter == 'U')
		{
			isVowel = 1;
			return isVowel;
		}
		else
		{
			return isVowel;
		}

	}

	/*
	Checks if a word contains (or is solely) a character or symbol other than the 26 letters of the English alphabet

	@param word the English word currently in the input stream

	@return isPunctuation returns true if the string is solely puncuation or the string ends with punctuation
	*/
	bool IsPunctuation(char letter)
	{
		bool isPunctuation = 0;

		if ((letter < 'A' || letter > 'z') && !IsNumber(letter) && letter != ' ')
		{
			isPunctuation = 1;
			return isPunctuation;
		}
		return isPunctuation;
	}

	/*
	Replaces all uppercase letters in a string with lowercase letters

	@param word the current string input from the chosen file
	*/
	string ToLowercase(string word)
	{
		for (int index = 0; index < word.size(); index++)
		{
			if (word[index] >= 'A'  && word[index] <= 'Z')
			{
				word[index] = (word[index] + 32);
			}
		}
		return word;
	}

	/*
	Checks if the character is a number

	@param character the current character
	*/
	bool IsNumber(char character)
	{
		bool isNumber = 0;

		if (character >= '0' && character <= '9')
		{
			isNumber = 1;
			return isNumber;
		}
		else
		{
			return isNumber;
		}
	}

	/*
	Fills an array with each letter of the alphabet
	*/
	void AlphabetArray(char alphabet[], int kNumberOfLettersInAlphabet)
	{
		for (int index = 0; index < kNumberOfLettersInAlphabet; index++)
		{
			if (index == 0)
			{
				alphabet[index] = 'A';
			}
			if (index > 0)
			{
				alphabet[index] = ('A' + index);
			}

		}
	}

	void TestCode()
	{
		//AlphabetArray
		char alphabet[kNumberOfLettersInAlphabet];
		AlphabetArray(alphabet, kNumberOfLettersInAlphabet);
		for (int index = 0; index < kNumberOfLettersInAlphabet; index++)
		{
			cout << alphabet[index] << endl;
		}

		//RemovePunctuation
		string word = "!Dog?";
		if (IsPunctuation(word[0]))
		{
			word.erase(0, 1);
		}
		if (IsPunctuation(word[(word.size()-1)]))
		{
			word.erase((word.size() - 1), 1);	
		}
		cout << word << endl;
		
		//ToLowercase
		string wordUpperOne = "ABC";
		wordUpperOne = ToLowercase(wordUpperOne);
		cout << wordUpperOne << endl;
		return;
	}
}
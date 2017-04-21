#include <iostream>
#include <iomanip>

#include "FileInspector.h"

using namespace std;

namespace fileinspector
{
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
	Checks to if the given letter is a vowel in the English alphabet

	@ param letter a single ascii character

	@return isVowel returns true if the given character is a vowel
	*/
	bool IsVowel(char letter)
	{
		bool isVowel = 0;

		if (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u' || letter == 'y' ||
			letter == 'A' || letter == 'E' || letter == 'I' || letter == 'O' || letter == 'U' || letter == 'Y')
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

	void TestCode()
	{
		return;
	}
}
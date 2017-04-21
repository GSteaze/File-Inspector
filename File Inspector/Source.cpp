#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

#include "FileInspector.h"

using namespace std;
using namespace fileinspector;

const int kDefaultListSize = 5000;
const int kSelectedWordsListSize = 100;
const int kNumberOfLettersInAlphabet = 26;

int main()
{
	string selectedWords[kSelectedWordsListSize];
	InitializeList(selectedWords, kSelectedWordsListSize, " ");
	FillSelectedWordsArray(selectedWords, kSelectedWordsListSize);

	int textNumber = UserInput();
	ifstream fin;
	if (textNumber == 1)
	{
		fin.open("A Modest Proposal.txt");
	}
	else if (textNumber == 2)
	{
		fin.open("Apology.txt");
	}

	int wordCount[kSelectedWordsListSize];
	InitializeList(wordCount, kSelectedWordsListSize, 0);
	float wordFrequencies[kSelectedWordsListSize];
	InitializeList(wordFrequencies, kSelectedWordsListSize, 0.0);
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

	while (!fin.eof())
	{
		string word = " ";
		fin >> word;
		if (IsPunctuation(word[0]))
		{
			word.erase(0, 1);
			numberOfNonLetters++;
		}
		else if (IsPunctuation(word[word.size() - 1]))
		{
			word.erase((word.size() - 1));
			numberOfNonLetters++;
		}
		if (word.size() > 0)
		{
			numberOfWords++;
			totalNumberOfCharacters += word.size();
			word = ToLowercase(word);
			if (word.size() < shortestWord.size())
			{
				shortestWord = word;
			}
			else if (word.size > longestWord.size())
			{
				longestWord = word;
			}
			for (int index = 0; index < kSelectedWordsListSize; index++)
			{
				if (word == selectedWords[index])
				{
					wordCount[index]++;
				}
			}
			for (int index = 0; index > word.size(); index++)
			{
				if (IsVowel(word[index]))
				{
					numberOfVowels++;
				}
				else if (IsNumber(word[index]))
				{
					numberOfNumbers++;
				}
				else if (IsPunctuation(word[index]))
				{
					numberOfNonLetters++;
				}
			}
		}
	}

	averageWordLength = totalNumberOfCharacters / numberOfWords;

	for (int index = 0; index < kSelectedWordsListSize; index++)
	{
		wordFrequencies[index] = wordCount[index] / numberOfWords;
	}



	//TestCode();
	return 0;
}
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

#include "FileInspector.h"

using namespace std;
using namespace fileinspector;

const int kSelectedWordsListSize = 100;
const int kNumberOfLettersInAlphabet = 26;
const int kColumnWidthOne = 8;
const int kColumnWidthTwo = 15;
const int kNumberOfSignificantDigits = 4;

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
	string shortestWord = "             ";
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
		totalNumberOfCharacters += word.size();
		if (IsPunctuation(word[0]))
		{
			word.erase(0, 1);
			numberOfNonLetters++;
		}
		if (word.size() > 0)
		{
			if (IsPunctuation(word[(word.size() - 1)]))
			{
				word.erase((word.size() - 1), 1);
				numberOfNonLetters++;
			}
		}
		if (word.size() > 0)
		{
			numberOfWords++;
			word = ToLowercase(word);
			if ((word.size() < shortestWord.size()) && word  != " " && !IsNumber)
			{
				shortestWord = word;
			}
			else if (word.size() > longestWord.size())
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
			for (int index = 0; index < word.size(); index++)
			{
				LetterCounter(numberOfLetters, kNumberOfLettersInAlphabet, word[index]);
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

	averageWordLength = static_cast<double>(totalNumberOfCharacters) / static_cast<double>(numberOfWords);

	for (int index = 0; index < kSelectedWordsListSize; index++)
	{
		wordFrequencies[index] = wordCount[index] / numberOfWords;
	}

	cout << "Selected Text : ";
	if (textNumber == 1)
	{
		cout << "A Modest Proposal" << endl;
	}
	else if (textNumber == 2)
	{
		cout << "Apology" << endl;
	}

	cout << "Shortest Word : " << shortestWord << endl;
	cout << "Longest Word : " << longestWord << endl;
	cout << "Word Count : " << numberOfWords << endl;

	cout << setw(kColumnWidthOne) << "Selected Words" << setw(kColumnWidthOne) << "Counts"
		<< setw(kColumnWidthOne) << "Frequency" << endl;
	for (int index = 0; index < kSelectedWordsListSize; index++)
	{
		cout << setw(kColumnWidthTwo) << left << selectedWords[index] << " ";
		cout << setprecision(kNumberOfSignificantDigits) << setw(kColumnWidthOne) << wordCount[index] << " ";
		cout << setprecision(kNumberOfSignificantDigits) << setw(kColumnWidthOne) << wordFrequencies[index] << " " << endl;
	}
	cout << "Number of Characters : " << totalNumberOfCharacters << endl;
	cout << "Number of Vowels : " << numberOfVowels << endl;
	cout << "Number of Non Letters : " << numberOfNonLetters << endl;
	cout << "Number of Numbers : " << numberOfNumbers << endl;
	cout << "Average Word Length : " << averageWordLength << endl;

	char alphabet[kNumberOfLettersInAlphabet];
	AlphabetArray(alphabet, kNumberOfLettersInAlphabet);

	cout << "Number of Letters" << endl;
	for (int index = 0; index < kNumberOfLettersInAlphabet; index++)
	{
		cout << setw(kColumnWidthOne) << alphabet[index] << ":"
			<< setw(kColumnWidthOne) << numberOfLetters[index] << endl;
	}

	//TestCode();
	return 0;
}
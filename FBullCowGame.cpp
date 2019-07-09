/*all Game Logic Are implemented here*/

#include "FBullCowGame.h"
#include <map>
#define TMap std::map

//To make Code As Per Unreal Engine Coding Standards
using FString = std::string;
using int32 = int;

FBullCowGame::FBullCowGame() //default Constructor
{
	Reset();
}

void FBullCowGame::Reset() //Resetting the Value of Game
{
	MyCurrentTry = 1;

	FString HIDDEN_WORD = "light";//must be an lowercase isogram
	MyHiddenWord = HIDDEN_WORD;

	return;
}

int32 FBullCowGame::GetHiddenWordLength() const // Calculating Length Of Hidden word
{
	return MyHiddenWord.length();
}

int32 FBullCowGame::GetMaxTries() const	//using Map Data Structure to Change Number of Tries Based On Word Length
{
	TMap<int32, int32> WordLengthToMaxTries{ { 3,5 },{ 4,6 },{ 5,5 },{ 6,7 } };
	return WordLengthToMaxTries[MyHiddenWord.length()];
}

int32 FBullCowGame::GetCurrentTry() const //Accessing the Value of Current Try
{
	return MyCurrentTry;
}

bool FBullCowGame::IsGameWon() const //Win the Game or Not
{
	return bGameIsWon;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const //To check the guess Validity
{
	int32 HiddenWordLength = GetHiddenWordLength();
	int32 GuessLength = Guess.length();

	if (!IsIsogram(Guess)) //If the Guess isn't an Isogram,
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (!IsLower(Guess)) //If the Guess isn't all lowercases,
	{
		return EGuessStatus::Not_Lowercases;
	}
	else if (GuessLength != HiddenWordLength) //If the Guess Length is wrong,
	{
		return EGuessStatus::Not_Same_Length;
	}
	else //Otherwise
	{
		return EGuessStatus::ok;
	}
}

//receives a Valid Guess, increaments Turns & returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	//increment the turn number
	MyCurrentTry++;

	//setup return value
	FBullCowCount BullCowCount;

	//loop through all letters in Hidden Word
	int32 WordLength = MyHiddenWord.length();// Hidden word Length and Guess length have to be same
	for (int32 Hidden_Char = 0; Hidden_Char < WordLength; Hidden_Char++)
	{
		//compare letters against the Guess
		for (int32 Guess_Char = 0; Guess_Char < WordLength; Guess_Char++)
		{
			//if they match then
			if (Guess[Guess_Char] == MyHiddenWord[Hidden_Char])
			{
				//if letters are in same  place
				if (Hidden_Char == Guess_Char)
				{
					BullCowCount.Bulls++;	//increment bulls
				}
				else//if letters are in wrong place
				{
					BullCowCount.Cows++;	//increment cows 
				}
			}
		}

	}
	//winning Condition
	if (BullCowCount.Bulls == WordLength)
	{
		bGameIsWon = true;
	}
	else
	{
		bGameIsWon = false;
	}
	return BullCowCount;
}

//Function To check Isogram
/*
Methods To Check Isogram
No. 	Name				Time Complexity
1.		Looping Method		{(n^2-n)/2} or O(n^2)
2.		Sorting Method
(Merge Sort)		O(n*logn)
3.		Hash Map			O(n)

Due to Lower Complexity  Hash Map is used here
*/
bool FBullCowGame::IsIsogram(FString Word) const
{
	//treat 0 and 1 letter words as isogram
	if (Word.length() <= 1)
	{
		return true;
	}

	TMap<char, bool> LetterSeen;//setup our map
	for (auto Letter : Word) //for all letters in the word
	{
		//Letter = tolower(Letter); //handle the mixed case
		if (LetterSeen[Letter])//if the letter is in map
		{
			return false;// NOT ISOGRAM
		}
		else
		{
			LetterSeen[Letter] = true;// add the letter to the map as seen
		}
	}
	return true;//when /0 is entered
}

//Function To Check Lower Case
bool FBullCowGame::IsLower(FString Word) const
{
	for (auto Letter : Word)
	{
		if (!islower(Letter))// Not Lowercase
		{
			return false;
		}
	}
	return true;//when /0 is entered

}

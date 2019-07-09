/*The Game Logic Implementation
All Variables and functions are declared in FBullCowGame.h
To se all Logic Implementations Check FBullCowGame.cpp*/

#pragma once
#include <string>

//To make Code As Per Unreal Engine Coding Standards
using FString = std::string;
using int32 = int;

//Bulls And Cows are initialised
struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;

};

enum class EGuessStatus
{
	ok,
	Not_Isogram,
	Not_Same_Length,
	Not_Lowercases,
	Invalid,
};

class FBullCowGame
{
public:
	FBullCowGame(); //Constructor

	FString MyHiddenWord;

	void Reset(); //Default Function

	int32 GetHiddenWordLength() const;
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;

	bool IsGameWon() const; //Winning Function 

	EGuessStatus CheckGuessValidity(FString) const; //Funcion To Check The Validity of Guess
	FBullCowCount SubmitValidGuess(FString);//Get Valid Guess,Returns Count,Increase Turn

											//Ignore this
private:
	//Using Constructor to initialise these
	int32 MyCurrentTry;
	int32 MyMaxTries;
	bool bGameIsWon;

	bool IsIsogram(FString) const;
	bool IsLower(FString) const;
};

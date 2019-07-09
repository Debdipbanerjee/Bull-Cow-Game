/*This Game is A simple Word Guessing game based on
This Main Function is used for User Interaction
To see Game Logic please Check FBullCowGame.cpp*/

/* UPDATE 1.0 : Unreal Coding Standards is added fot future ReUsability */

#pragma once
#include <iostream>
#include <string>
#include "FBullCowGame.h"

//To make Code As Per Unreal Engine Coding Standards
using FString = std::string;
using int32 = int;

void Intro();
FString GetValidGuess();
void PlayGame();
bool AskToPlayAgain();
void PrintGameSummery();
void PrintHint();

FBullCowGame BCGame; //Instantiate a New Game

					 //Starting Point for The Program
int32 main()
{
	Intro();
	PlayGame();
	while (AskToPlayAgain() != 0);

	return 0; //End of Program
}

//Introduce the Game
void Intro()
{
	int32 Word_length = BCGame.GetHiddenWordLength();

	std::cout << "Created By Debdip Banerjee on January-March 2019\n" << std::endl;
	std::cout << "...........Welcome to Bulls & Cow Game.........." << std::endl;
	std::cout << std::endl;
	std::cout << " Bull is Right          }   {         ___             Cow is " << std::endl;
	std::cout << " Letter in              (o o)        (o o)            Right Letter " << std::endl;
	std::cout << " Right Position  /-------\\ /          \\ /-------\\     in Worng position" << std::endl;
	std::cout << "                /| BULL |O            O| COW  | \\ " << std::endl;
	std::cout << "               * |-,--- |              |------|  * " << std::endl;
	std::cout << "                 ^      ^              ^      ^ " << std::endl;
	std::cout << "Hint: Isogram is Word with NO REPEATED letters. EX: planet" << std::endl;
	std::cout << "_____________________________________________________________________________" << std::endl;
	std::cout << "Can you guess " << Word_length;
	std::cout << " letters Isogram I'm Thinking of?\n" << std::endl;

}

//Loop untill player gives right Guess
FString GetValidGuess()
{
	FString Guess = "";
	EGuessStatus Status = EGuessStatus::Invalid;
	do {
		int32 CurrentTry = BCGame.GetCurrentTry();

		//get a guess from player
		std::cout << "Try " << CurrentTry << " of " << BCGame.GetMaxTries() << ". Enter your guess: ";
		getline(std::cin, Guess);

		//checking the valid guess
		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
		case EGuessStatus::Not_Same_Length:
			std::cout << "Please Enter " << BCGame.GetHiddenWordLength() << " Letters word\n" << std::endl;
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please Enter an Isogram\n" << std::endl;
			break;
		case EGuessStatus::Not_Lowercases:
			std::cout << "Please enter letters with lowercases\n" << std::endl;
			break;
		default:
			//assume the guess is valid
			break;
		}
	} while (Status != EGuessStatus::ok); //Keep Looping untill we get no error
	return Guess;

}

//Function of times you play a single Game
void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	//Loop Asking for guesses while game is not won and tries still remaining
	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries)
	{
		FString Guess = GetValidGuess(); //Getting Valid Guess From Player

										 //submit valid guess to game and recieves counts
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);

		//Printing the number of bulls and cows
		std::cout << "Bulls = " << BullCowCount.Bulls << std::endl;
		std::cout << "Cows = " << BullCowCount.Cows << std::endl;
		std::cout << std::endl;
		if(BCGame.IsGameWon() == false)
		{
			PrintHint();//Hint to Find the answer
		}
		std::cout << std::endl;
	}
	PrintGameSummery();
}

//Function Asking To Play Again
bool AskToPlayAgain()
{
	std::cout << "Do you wanna Play again?" << std::endl;
	std::cout << "Y/N" << std::endl;
	FString Response = "";
	getline(std::cin, Response);

	std::cout << "Your response is:" << Response << std::endl;
	if ((Response[0] == 'y') || (Response[0] == 'Y'))
	{
		PlayGame();
		AskToPlayAgain();
		return 1;
	}
	else if ((Response[0] == 'n') || (Response[0] == 'N'))
	{
		exit(0);
	}
	else
	{
		std::cout << "Please,give valid input" << std::endl;
		AskToPlayAgain();
	}

	return false;
}

void PrintGameSummery()
{
	if (BCGame.IsGameWon())
	{
		std::cout << "Congrats,You Win \n\n";
	}
	else
	{
		std::cout << "Better Luck Next time \n\n";
	}
}

void PrintHint()
{
	std::cout << "Clue:" << std::endl;
	std::cout << "I can fill a room but take up no space.\nlook out at night, and i am in no place\nwhat am i?" << std::endl;
}

//This is the VIEW
//LOGIC IS IN FullBullCowGame

#pragma once

#include<iostream>
#include<conio.h>
#include<string>
#include<stdlib.h>
#include<stdio.h>
#include "FBullCowGame.h"
using FText = std::string; //using int3232 = int32; same as typedef int int32;
using int32 = int;
FBullCowGame BCGame;
int32 CurrentTry = BCGame.GetCurrentTry();

FText GetValidGuess()
{
	EGuessStatus Status = EGuessStatus::OK;
	FText Guess = "";
	do
	{
		//Guess

		std::cout << "Try " << CurrentTry <<" of "<<BCGame.GetMaxTries() <<"\nEnter your Guess: ";
		std::getline(std::cin, Guess);

		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
		case EGuessStatus::Not_Isogram:
			std::cout << "Please Enter a Isogram(A word with all diff letters) \n\n";
			break;

		case EGuessStatus::Not_Lowercase:
			std::cout << "Please Enter Everything in lowercases\n\n";
			break;

		case EGuessStatus::Wrong_Length:
			std::cout << "Please Enter a " << BCGame.GetHiddenWordLength() << " Character Word\n\n";
			break;

		default: 
			break;
		}
		
	} while (Status != EGuessStatus::OK);

	return Guess;
}

void Printintro()
{
	std::cout << R"(
	            ____        _ _                          _    _____
		   |  _ \      | | |         /\             | |  / ____|                 
		   | |_) |_   _| | |___     /  \   _ __   __| | | |     _____      _____ 
		   |  _ <| | | | | / __|   / /\ \ | '_ \ / _` | | |    / _ \ \ /\ / / __|
		   | |_) | |_| | | \__ \  / ____ \| | | | (_| | | |___| (_) \ V  V /\__ \
		   |____/ \__,_|_|_|___/ /_/    \_\_| |_|\__,_|  \_____\___/ \_/\_/ |___/
                                                                        
                                                                       	
	)" << std::endl << std::endl;
	
	std::cout << "The player tries to guess their Secret Word.\n If the matching Letters are in their right positions,\n they are bulls, if in different positions, they are cows.\n\n ";
	std::cout << R"( 
                           /|                        /|
                          | \           __ _ _     / ;
                    ___    \ \   _.-"-" `~"\  `"--' /
                _.-'   ""-._\ ""   ._,"  ; "\"--._./
            _.-'       \./    "-""", )  ~"  |
           / ,- .'          ,     '  `o.  ;  )
           \ ;/       '                 ;   /
            |/        '      |      \   '   |
            /        |             J."\  ,  |
           "         :       \   .'  : | ,. _)
           |         |     /     f |  |`--"--'
            \_        \    \    / _/  |
             \ "-._  _.|   (   j/; -'/
              \  | "/  (   |   /,    |
               | \  |  /\  |\_///   /
               \ /   \ | \  \  /   /
                ||    \ \|  |  |  |
                ||     \ \  |  | /
                |\      |_|/   ||
                L \       ||   ||
                `"'       |\   |\
                          ( \. \ `.
                          |_ _\|_ _\
                            "    ")";

	std::cout << R"( .        .
           \'.____.'/
          __'-.  .-'__                         .--.
          '_i:'oo':i_'---...____...----i"""-.-'.-"\\
            /._  _.\       :       /   '._   ;/    ;'-._
           (  o  o  )       '-.__.'       '. '.     '-."
            '-.__.-' _.--.                 '-.:
             : '-'  /     ;   _..--,  /       ;
             :      '-._.-'  ;     ; :       :
              :  `      .'    '-._.' :      /
               \  :    /    ____....--\    :
                '._\  :"""""    '.     !.   :
                 : |: :           'www'| \ '|
                 | || |              : |  | :
                 | || |             .' !  | |
                .' !| |            /__I   | |
               /__I.' !                  .' !
                  /__I                  /__I   
)" << std::endl;
	
	const int32 WORD_LENGTH = BCGame.GetHiddenWordLength();
	std::cout << "\nCan you guess the " << WORD_LENGTH + 1 << " letter isogram I'm thinking of?\n";
	std::cout << "You have " << BCGame.GetMaxTries() << " Tries\n\n";
}

void PlayGame()
{	
	
	BCGame.Reset();
	int32 count = 0;
	bool bGameWinLocal = false;

	while (bGameWinLocal == false && BCGame.GetCurrentTry() <= BCGame.GetMaxTries())
	{
		FText Guess = GetValidGuess();
		BullCowCount objBullCowCount = BCGame.SubmitValidGuess(Guess);
		std::cout << "Bulls = " << objBullCowCount.Bulls<<" ";
		std::cout << "Cows = " << objBullCowCount.Cows << std::endl<< std::endl;
		CurrentTry = BCGame.GetCurrentTry();
		count++;

		if (Guess == BCGame.GetHiddenWord())
		{
			std::cout << "\nCongrats! That is CORRECT\n";
			bGameWinLocal = true;

		}

	}

	if (BCGame.GetCurrentTry() > BCGame.GetMaxTries())
	{
		std::cout << "\nBetter Luck Next Time! :(\n";
	}
	CurrentTry = 1;
}

bool PlayAgain()
{
	std::cout << "Do you want to play again?(yes/no): ";
	char response[5];
	std::cin >> response;

	if (strcmpi(response, "yes") == 0)
	{
		return 1;
		CurrentTry = 1;
	}

	else
	{
		return 0;
	}

}


int32 main()
{
	bool bresp;
	do
	{
		Printintro();
		PlayGame();
		bresp = PlayAgain();
	} while (bresp == true);
	
return 0;
}


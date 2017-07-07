#include "FBullCowGame.h"
#include<map>
#include<stdlib.h>
#define TMap std::map

FBullCowGame::FBullCowGame() { Reset(); }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyWord.length(); }
FString FBullCowGame::GetHiddenWord() {return MyWord;}
bool FBullCowGame::IsGameWon() { return bGameWon; }


void FBullCowGame::Reset()
{
	int32 x = rand()%10;
	MyCurrentTry = 1;
	constexpr int32 MAX_TRIES = 5;
	bGameWon = true;
	MyWord = Isograms[x];

}

int32 FBullCowGame::GetMaxTries() const 
{ 
	TMap<int32, int32> WordLengthToMaxTries{ {3,5}, {4,8},{5,10},{6,16},{7,20},{15,30} };
	return WordLengthToMaxTries[MyWord.length()];
}


bool FBullCowGame::IsIsogram(FString Guess) const
{	
	if (MyWord.length() <= 0) { return true; }
	

	TMap <char, bool> SeenLetter;
	for (auto Letter : Guess)//For all letters in the word
	{	
		Letter = tolower(Letter);
		if (SeenLetter[Letter]) { return false; }
		else { SeenLetter[Letter] = true;}
	}
	
	return true;
}

bool FBullCowGame::IsLowerCase(FString Guess) const
{
	for (int i = 0; i < MyWord.length();i++)
	{
		if (isupper(Guess[0]))
		{
			return false;
			break;
		}
	}

}




EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (Guess.length() != MyWord.length())
	{
		return EGuessStatus::Wrong_Length;
	}

	if (!IsIsogram(Guess))
	{
		return EGuessStatus::Not_Isogram;
	}
	
	else if (!IsLowerCase(Guess))
	{
		return EGuessStatus::Not_Lowercase;
	}

	else
	{
		return EGuessStatus::OK;
	}

}

BullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	
	MyCurrentTry++;
	BullCowCount objBullCowCount;
	int32 HiddenWordlength = MyWord.length();
	for (int32 i = 0; i < HiddenWordlength; i++)
	{
		for (int32 j = 0; j < HiddenWordlength; j++)
		{
			if (Guess[i] == MyWord[j])
			{
				if (i == j)
				{
					objBullCowCount.Bulls++;
				}
				else
				{
					objBullCowCount.Cows++;
				}
			
			}
		}

	}
	return objBullCowCount;
}






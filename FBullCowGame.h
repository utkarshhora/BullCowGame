#pragma once
#include<string>
using FString = std::string;
using int32 = int;

struct BullCowCount {

	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus {

	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase,
	Invalid
};

class FBullCowGame {

public:
	FBullCowGame();
	void Reset();
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon();
	EGuessStatus CheckGuessValidity(FString) const;
	BullCowCount SubmitValidGuess(FString);
	int32 GetHiddenWordLength() const;
	FString GetHiddenWord();

private:
	int32 MyCurrentTry;
	FString MyWord;
	bool bGameWon;
	bool IsIsogram(FString) const;
	bool IsLowerCase(FString) const;
	FString Isograms[10] = { "planet","shit","hockey","ant","boy","lame","game","shame","dermatoglyphics" };
 };



#pragma once
#include <iostream>
#include <time.h>

using namespace std;

class Puzzle
{
public:
	Puzzle();

	void fillField();

	void showField();

	void correctField();

	void movementRight();

	void movementLeft();

	void movementDown();

	void movementUp();

	bool checkVictory();

	std::wstring returnField() const;

	bool operator==(const Puzzle& game) const;

private:
	int field[4][4];
	int direction;
	int x, y;
	static bool isRandomStarted;

	void randomGeneration(int &i, int &j, int &newRandomValue, bool &alreadyThere);
};

void printMenu();
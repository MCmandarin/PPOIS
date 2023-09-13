#pragma once
#include <iostream>
#include <time.h>

using namespace std;

class pazle
{
public:
	pazle();

	void fillField();

	void showField();

	void correctField();

	void movementRight();

	void movementLeft();

	void movementDown();

	void movementUp();

	void checkVictory();

	std::wstring returnField() const;

	bool operator==(const pazle& game) const;

private:
	int field[4][4];
	int direction;
	int x, y;
	static bool isRandomStarted;
};

void printMenu();
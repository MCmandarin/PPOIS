#include "Game.h"

bool Puzzle::isRandomStarted = false;

Puzzle::Puzzle() {
	if (!isRandomStarted) {
		srand(time(NULL));
		isRandomStarted = true;
	}
	fillField();
	correctField();
}

std::wstring Puzzle::returnField() const {
	wstring str;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			str += field[i][j] + L" ";
		}
		str += '\n';
	}
	return str;
}

bool Puzzle::operator==(const Puzzle& game) const {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (field[i][j] != game.field[i][j])
				return false;
		}
	}
	return true;
}

void Puzzle::randomGeneration(int &i, int &j, int &newRandomValue, bool &alreadyThere) {
	for (int a = 0; a <= i; a++) {
		for (int b = 0; b < 4; b++) {
			if (field[a][b] == newRandomValue) {
				alreadyThere = true;
				break;
			}
		}
		if (alreadyThere) {
			break;
		}
	}
	if (!alreadyThere) {
		field[i][j] = newRandomValue;
		j++;
	}
}

void Puzzle::fillField() {
	bool alreadyThere;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4;) {
			bool alreadyThere = false;
			int newRandomValue = rand() % 16;

			randomGeneration(i, j, newRandomValue, alreadyThere);
		}
	}
}

void Puzzle::showField() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << field[i][j] << "\t";
		}
		cout << endl;
	}
}

void Puzzle::correctField()
{
	int movingZero;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (field[i][j] == 0) {
				x = 3;
				y = 3;
				movingZero = field[3][3];
				field[3][3] = field[i][j];
				field[i][j] = movingZero;
			}
		}
	}
}

void Puzzle::movementRight()
{
	if (y == 3) {
		cout << "movement is not possible!" << endl;
	}
	else {
		direction = field[x][y + 1];
		field[x][y + 1] = field[x][y];
		field[x][y] = direction;
		y = y + 1;
	}
}

void Puzzle::movementLeft()
{
	if (y == 0) {
		cout << "movement is not possible!" << endl;
	}
	else {
		direction = field[x][y - 1];
		field[x][y - 1] = field[x][y];
		field[x][y] = direction;
		y = y - 1;
	}
}

void Puzzle::movementDown()
{
	if (x == 3) {
		cout << "movement is not possible!" << endl;
	}
	else {
		direction = field[x + 1][y];
		field[x + 1][y] = field[x][y];
		field[x][y] = direction;
		x = x + 1;
	}
}

void Puzzle::movementUp()
{
	if (x == 0) {
		cout << "movement is not possible!" << endl;
	}
	else {
		direction = field[x - 1][y];
		field[x - 1][y] = field[x][y];
		field[x][y] = direction;
		x = x - 1;
	}
}

bool Puzzle::checkVictory()
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 3 && j == 2)
			{
				return true;
				exit;
			}
			else if (field[i][j] > field[i][j + 1])
			{
				return false;
			}
		}
	}
}

void printMenu()
{
	system("cls");
	cout << "\t---Menu---" << endl;
	cout << "1. Start" << endl;
	cout << "2. Exit" << endl;
}
#include "Game.h"

bool pazle::isRandomStarted = false;

pazle::pazle() {
	if (!isRandomStarted) {
		srand(time(NULL));
		isRandomStarted = true;
	}
	fillField();
	correctField();
}

std::wstring pazle::returnField() const {
	wstring str;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			str += field[i][j] + L" ";
		}
		str += '\n';
	}
	return str;
}

bool pazle::operator==(const pazle& game) const {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (field[i][j] != game.field[i][j])
				return false;
		}
	}
	return true;
}

void pazle::fillField() {
	bool alreadyThere;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4;) {
			bool alreadyThere = false;
			int newRandomValue = rand() % 16;

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
	}
}

void pazle::showField() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << field[i][j] << "\t";
		}
		cout << endl;
	}
}

void pazle::correctField()
{
	int temp;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (field[i][j] == 0) {
				x = 3;
				y = 3;
				temp = field[3][3];
				field[3][3] = field[i][j];
				field[i][j] = temp;
			}
		}
	}
}

void pazle::movementRight()
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

void pazle::movementLeft()
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

void pazle::movementDown()
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

void pazle::movementUp()
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

void pazle::checkVictory()
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 3 && j == 2)
			{
				cout << "Field is ordered" << endl;
				exit;
			}
			else if (field[i][j] > field[i][j + 1])
			{
				cout << "Field is not ordered" << endl;
				return;
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
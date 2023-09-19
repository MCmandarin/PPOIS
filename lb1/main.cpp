#include "Game.h"

int main()
{
	printMenu();
	int variant;
	int movement;
	Puzzle game;

	cin >> variant;

	if (variant == 1) {
		game.showField();
	}
	else if (variant == 2) {
		exit(EXIT_FAILURE);
	}

	do {

		cout << "1.Move right" << endl;
		cout << "2.Move left" << endl;
		cout << "3.Move down" << endl;
		cout << "4.Move up" << endl;
		cout << "5.Check for victory" << endl;
		cout << "6.Exit" << endl;
		cin >> movement;
		switch (movement) {
		case 1:
			system("cls");
			game.movementRight();
			game.showField();
			break;
		case 2:
			system("cls");
			game.movementLeft();
			game.showField();
			break;
		case 3:
			system("cls");
			game.movementDown();
			game.showField();
			break;
		case 4:
			system("cls");
			game.movementUp();
			game.showField();
			break;
		case 5:
			system("cls");
			game.checkVictory();
			game.showField();
			break;
		}
	} while (movement != 6);
}
#include "GraWzycie.h"

#include <iostream>

using namespace std;


GameOfLife& GameOfLife::operator=(const GameOfLife& s) {
	return *this;
}

void GameOfLife::Play(const char* fName) {
	Init(fName);
	View();

	for (int i = 0; i < 100; i++)
	{
		system("cls");
		cout << endl << "Pokolenie: " << i << endl << endl;
		NewStatus();
		View();
	}
}



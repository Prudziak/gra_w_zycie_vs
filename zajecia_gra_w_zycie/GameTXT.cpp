#include "GameTXT.h"
#include <iostream>
#include <Windows.h>
using namespace std;

void GameTxt::View() {
	for (int i = 0; i < nw; i++)
	{
		for (int j = 0; j < nk; j++)
		{
			if (stany[i][j] == 0)
				cout << " . ";
			else
				cout << " O ";
		}
		cout << endl;
	}
}

GameTxt& GameTxt::operator=(const GameTxt& k) {
	return *this;
}
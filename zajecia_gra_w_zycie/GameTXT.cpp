#include "GameTXT.h"
#include <iostream>
#include <windows.h>
using namespace std;

void GameTxt::View() {
	for (int i = 0; i < nw; i++)
	{
		for (int j = 0; j < nk; j++)
		{
			if (stany[i][j] == false)
				cout << " . ";
			else
				cout << " O ";
		}
		cout << endl;
	}
	Sleep(600);
}

GameTxt& GameTxt::operator=(const GameTxt& k) {
	return *this;
}
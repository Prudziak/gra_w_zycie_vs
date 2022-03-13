#include "GameTXT.h"
#include <iostream>
#include <Windows.h>
using namespace std;

void GameTxt::View() {
	for (int i = 0; i < nw; i++)
		for (int j = 0; j < nk; j++)
		{
			if (stany_temp[i][j] == true)
				cout << " O ";
			else
				cout << " . ";
		}
}

GameTxt& GameTxt::operator=(const GameTxt& k) {
	return *this;
}
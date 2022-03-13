#include "GraWzycie.h"
#include <Windows.h>


GameOfLife& GameOfLife::operator=(const GameOfLife& s) {
	return *this;
}

void GameOfLife::Play(const char* fName) {
	Init(fName);
	View();

	for (int i = 0; i < 10000; i++)
	{
		CheckNeighbours(nw, nk);
		NewStatus(nw, nk);
		View();
		Sleep(600);	
	}
}



#include "Silnik.h"
#include <fstream>
#include <iostream>

using namespace std;

Engine::~Engine()
{
	for (int x = 0; x < nw; x++)
	{
		delete[] stany[x];
		delete[] stany_temp[x];
	}
	delete[] stany;
	delete[] stany_temp;
}


Engine::Engine(int w, int k) : nw(w), nk(k)
{
	this->stany = new int* [nw];
	this->stany_temp = new int* [nw];
	for (int i = 0; i < nk; i++)
	{
		stany[i] = new int[nk];
		stany_temp[i] = new int[nk];
	}
	for (int i = 0; i < nw; i++)
		for (int j = 0; j < nk; j++)
		{
			stany[i][j] = 0;
			stany_temp[i][j] = 0;
		}
}

Engine& Engine::operator=(const Engine& e)
{
	return *this;
}

void Engine::Init(const char* fName) {
	ifstream dane(fName);

	if (dane.is_open())
	{
		while (!dane.eof())
		{
			int a, b;
			dane >> a >> b;
			stany[a][b] = 1;
			stany_temp[a][b] = 1;
		}
	}
}


int Engine::CheckNeighbours(int i, int j) {
	int ip, im, jp, jm;
	if (i < nw - 1) ip = i + 1; else ip = 0;
	if (i > 0) im = i - 1; else im = nw - 1;
	if (j < nk - 1) jp = j + 1; else jp = 0;
	if (j > 0) jm = j - 1; else jm = nk - 1;
	
	return stany[ip][j] + stany[im][j] + stany[i][jp] + stany[i][jm] +
		stany[ip][jp] + stany[im][jm] + stany[im][jp] + stany[ip][jm];// zwrocenie ilosci zywych sasiadow danej komorki
}

void Engine::NewStatus() {
	// Jezeli zywa komorka ma 2 lub 3 zywych sasiadow to dalej jest zywa
	for (int x = 0 ; x < nw ; x++)
		for (int y = 0; y < nk; y++)
		{
			if (stany[x][y] == 1 && (CheckNeighbours(x, y) == 2 || CheckNeighbours(x, y) == 3))
				stany_temp[x][y] = 1;

			else if (stany[x][y] == 0 && CheckNeighbours(x, y) == 3)
				stany_temp[x][y] = 1;

			else
				stany_temp[x][y] = 0;
		}
	for (int x = 0 ; x < nw ; x++)
		for (int y = 0; y < nk; y++)
		{
			stany[x][y] = stany_temp[x][y];
		}

}

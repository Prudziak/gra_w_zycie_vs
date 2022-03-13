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


Engine::Engine(int w, int k)
{
	nw = w;
	nk = k;
	stany = new bool* [nw];
	stany_temp = new bool* [nw];
	for (int i = 0; i < k; k++)
	{
		stany[i] = new bool[nk];
		stany_temp[i] = new bool[nk];
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
			stany[a][b] = true;
		}
	}
}

int Engine::CheckNeighbours(int nw, int nk) {
	int ip, im, jp, jm;
	if (nw < nw - 1) ip = nw + 1; else ip = 0;
	if (nw > 0) im = nw - 1; else im = nw - 1;
	if (nk < nk - 1) jp = nk + 1; else jp = 0;
	if (nk > 0) jm = nk - 1; else jm = nk - 1;
	return stany[ip][nk] + stany[im][nk] + stany[nw][jp] + stany[nw][jm] +
		stany[ip][jp] + stany[im][jm] + stany[im][jp] + stany[ip][jm];  // zwrocenie ilosci zywych sasiadow danej komorki
}

void Engine::NewStatus(int nw, int nk) {
	// Jezeli zywa komorka ma 2 lub 3 zywych sasiadow to dalej jest zywa
	for (int x = 0 ; x < nw ; x++)
		for (int y = 0; y < nk; y++)
		{
			int s = CheckNeighbours(nw, nk);
			if ((stany[x][y] && (s == 2 || s == 3)) || (!stany[x][y] && (s == 3)))
				stany_temp[x][y] = true;
			else
				stany_temp[x][y] = false;

			stany[x][y] = stany_temp[x][y];
		}
}

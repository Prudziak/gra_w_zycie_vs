#pragma once
#include "GraWzycie.h"

class GameTxt : public GameOfLife
{
public:
	int xw, xk;
	GameTxt(int w, int k) : GameOfLife(w, k), xw(w), xk(k) {}
	virtual void View();
private:
	GameTxt(const GameTxt& k);
	GameTxt& operator=(const GameTxt& k);

};


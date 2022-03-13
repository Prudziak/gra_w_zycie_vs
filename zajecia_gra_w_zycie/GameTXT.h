#pragma once
#include "GraWzycie.h"

class GameTxt : public GameOfLife
{
public:
	GameTxt(int w, int k) : GameOfLife(w, k) {}
	virtual void View();
private:
	GameTxt(const GameTxt& k);
	GameTxt& operator=(const GameTxt& k);

};


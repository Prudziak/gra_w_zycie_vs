#pragma once
#include "Silnik.h"

class GameOfLife : public Engine
{
public:
	GameOfLife(int w, int k) : Engine(w, k) {}
	void Play(const char* fName);
	virtual void View() = 0;
	virtual ~GameOfLife() {}
private:
	GameOfLife(const GameOfLife& s);
	GameOfLife& operator=(const GameOfLife& s);
};


#pragma once


class Engine
{
protected:
	bool** stany;
	bool** stany_temp;
	int nw, nk;
protected:
	Engine(int w, int k);
	void Init(const char* fName);
	virtual ~Engine();
	//void wyswietl();
private:
	int CheckNeighbours(int i, int j);
	void NewStatus();
	friend class GameOfLife;
private:
	Engine(const Engine& e);
	Engine& operator=(const Engine& e);
};


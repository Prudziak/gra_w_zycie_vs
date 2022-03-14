#pragma once


class Engine
{
protected:
	int** stany;
	int** stany_temp;
	int nw, nk;
public:
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


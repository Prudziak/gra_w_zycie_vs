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
private:
	int CheckNeighbours(int nw, int nk);
	void NewStatus(int nw, int nk);
	friend class GameOfLife;
private:
	Engine(const Engine& e);
	Engine& operator=(const Engine& e);
};


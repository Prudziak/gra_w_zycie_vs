#include <iostream>
#include <math.h>

using namespace std;

class Engine
{
protected:
	Engine();
	bool** stany;
	bool** stany_temp;
protected:
	Engine(int w, int k);
	void Init(const char& fName);
	int Analiza();
	virtual ~Engine() {}
private:
	int CheckNeighbours(int i, int j);
	bool NewStatus(int i, int j);
private:
	Engine(const Engine& e);
	Engine& operator=(const Engine& e);
};

Engine::Engine(int w, int k)
{
	stany = new bool*[w];
	stany_temp = new bool* [w];
	for (int i = 0; i < k; k++)
	{
		stany[i] = new bool[k];
		stany_temp[i] = new bool[k];
	}

}

Engine& Engine::operator=(const Engine& e)
{
	return *this;
}

void Engine::Init(const char& fName) {}

int Engine::Analiza(){
	return 0;
}

int Engine::CheckNeighbours(int i, int j) {
	return 0;
}

bool Engine::NewStatus(int i, int j) {
	return false;
}


class GameOfLife : public Engine
{
public:
	GameOfLife();
	GameOfLife(int w, int k);
	void Play();
	virtual void View();
	virtual ~GameOfLife() {}
private:
	GameOfLife(const GameOfLife& s);
	GameOfLife& operator=(const GameOfLife& s);
};

GameOfLife& GameOfLife::operator=(const GameOfLife& s) {
	return *this;
}


GameOfLife::GameOfLife(int w, int k)
{

}

void GameOfLife::Play() {}

void GameOfLife::View() {}	

class GameTxt : public GameOfLife
{
protected:
	void View();
private:
	GameTxt(const GameTxt& k);
	GameTxt& operator=(const GameTxt& k);

};

void GameTxt::View() {}

GameTxt& GameTxt::operator=(const GameTxt& k) {
	return *this;
}

int main()
{
	GameOfLife K;
	K.Play();
	return 0;
}



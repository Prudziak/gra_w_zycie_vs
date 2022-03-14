#include <iostream>
#include <math.h>
#include "GameTXT.h"
#include <Fstream>
#include <Windows.h>

using namespace std;

int main()
{
	GameTxt K(25, 25);
	K.Play("init.txt");

	return 0;
}



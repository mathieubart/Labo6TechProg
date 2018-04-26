
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <random>

using namespace std;

int main()
{
	cout << "Instructions" << endl;

	vector<vector<char>> plaquette = vector<vector<char>>();
	vector<vector<char>> pions = vector<vector<char>>();
	vector<char> couleurs = vector<char>({ 'R', 'B', 'J', 'V', 'O' });

	int tour = 1;

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			plaquette[i][j] = ' ';
		}
		for (int j = 0; j < 2; j++)
		{
			pions[i][j] = ' ';
		}
	}


}


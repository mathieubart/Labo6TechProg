
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <random>
#include <string>

using namespace std;

//bool CheckWin();
//void TourJoueur(char& choixTour);
//vector<char> ChoixCPU(vector<char>& couleurs);
void AfficherPlaquette(vector<vector<char>>& plaquette, vector<vector<char>>& pions);

int main()
{
	cout << "Instructions" << endl;

	vector<vector<char>> plaquette = vector<vector<char>>();
	vector<vector<char>> pions = vector<vector<char>>();
	vector<char> couleurs = vector<char>({ 'R', 'B', 'J', 'V', 'O' });

	int tour = 1;

	for (int i = 0; i < 10; i++)
	{
		plaquette.push_back(vector<char>());
		pions.push_back(vector<char>());
		for (int j = 0; j < 4; j++)
		{
			plaquette[i].push_back(' ');
		}
		for (int j = 0; j < 2; j++)
		{
			pions[i].push_back(' ');
		}
	}
	AfficherPlaquette(plaquette, pions);

}

void AfficherPlaquette(vector<vector<char>>& plaquette, vector<vector<char>>& pions)
{
	string ligne = "|";
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			ligne = ligne + plaquette[i][j] + "|";
		}
		ligne = ligne + " B:" + pions[i][0];
		ligne = ligne + " N:" + pions[i][1];
		cout << ligne << endl;
		ligne = "|";
	}
}
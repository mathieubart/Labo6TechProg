
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <random>
#include <string>

using namespace std;

//bool CheckWin();
void TourJoueur(vector<char>& choixTour);
vector<char> ChoixCPU(vector<char>& couleurs);
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
	vector<char> choixCpu = ChoixCPU(couleurs);

	for (int i = 0; i < choixCpu.size(); i++)
	{
		cout << choixCpu[i];
	}

	do
	{
		TourJoueur(plaquette[tour]);

	} while (tour <= plaquette.size()); //|| victoire == 1)


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

vector<char> ChoixCPU(vector<char>& couleurs)
{
	char choix1 = couleurs[rand() % (couleurs.size())];
	char choix2 = couleurs[rand() % (couleurs.size())];
	char choix3 = couleurs[rand() % (couleurs.size())];
	char choix4 = couleurs[rand() % (couleurs.size())];

	vector<char> cpuchoice = vector<char>({'[', choix1, ' ', choix2, ' ', choix3, ' ', choix4, ']'});

	return cpuchoice;
}

void TourJoueur(vector<char>& choixTour)
{
	cout << "Entrer 4 couleurs: ";
	cin >> choixTour[0];
	cin >> choixTour[1];
	cin >> choixTour[2];
	cin >> choixTour[3];
}
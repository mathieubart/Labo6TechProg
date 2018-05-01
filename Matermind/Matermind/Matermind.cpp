
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <random>
#include <string>
#include <ctime>

using namespace std;

int CheckWin(vector<char> choixCpu, vector<char> choixJoueur, vector<string>& pions);
void TourJoueur(vector<char>& choixTour);
vector<char> ChoixCPU(vector<char>& couleurs);
void AfficherPlaquette(vector<vector<char>>& plaquette, vector<vector<string>>& pions);

int main()
{
	srand(static_cast<unsigned int>(time(NULL)));

	cout << "Instructions" << endl;

	vector<vector<char>> plaquette = vector<vector<char>>();
	vector<vector<string>> pions = vector<vector<string>>();
	vector<char> couleurs = vector<char>({ 'R', 'B', 'J', 'V', 'O' });

	int tour = 1;

	for (int i = 0; i < 10; i++)
	{
		plaquette.push_back(vector<char>());
		pions.push_back(vector<string>());
		for (int j = 0; j < 4; j++)
		{
			plaquette[i].push_back(' ');
		}
		for (int j = 0; j < 2; j++)
		{
			pions[i].push_back(" ");
		}
	}
	AfficherPlaquette(plaquette, pions);
	vector<char> choixCpu = ChoixCPU(couleurs);

	for (int i = 0; i < choixCpu.size(); i++)
	{
		cout << choixCpu[i];
	}

	int victoire = 0;

	do
	{
		TourJoueur(plaquette[tour - 1]);
		victoire = CheckWin(choixCpu, plaquette[tour - 1], pions[tour - 1]);
		if (victoire == 0)
		{
			AfficherPlaquette(plaquette, pions);
		}
		tour++;
	} while (tour <= plaquette.size() && victoire != 1);

	if (victoire == 1)
	{
		cout << "Vous avez gagne!!!";
	}
	else
	{
		cout << "Vous avez perdu!!!";
	}
}

void AfficherPlaquette(vector<vector<char>>& plaquette, vector<vector<string>>& pions)
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

	vector<char> cpuchoice = vector<char>({ choix1, choix2, choix3, choix4});

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

int CheckWin(vector<char> choixCpu, vector<char> choixJoueur, vector<string>& pions)
{
	int victoire = 0;
	int blanc = 0;
	int noir = 0;

	for (int i = choixCpu.size() - 1; i >= 0; i--)
	{
		if (choixCpu[i] == choixJoueur[i])
		{
			choixCpu.erase(choixCpu.begin() + i);
			choixJoueur.erase(choixJoueur.begin() + i);
			blanc++;
		}
	}

	if (blanc == 4)
	{
		victoire++;
	}
	else
	{
		pions[0] = to_string(blanc);

		int i = choixCpu.size() - 1;
		do
		{
			int j = choixJoueur.size() - 1;
			do
			{
				if(choixJoueur[j] == choixCpu[i])
				{
					choixCpu.erase(choixCpu.begin() + i);
					choixJoueur.erase(choixJoueur.begin() + j);
					j = 0;
					noir++;
				}

				j--;

			} while (j >= 0);

			i--;

		} while (i >= 0);

		pions[1] = to_string(noir);
	}

	return victoire;
}
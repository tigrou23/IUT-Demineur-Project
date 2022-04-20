#include <iostream>
#include <cassert>

using namespace std;

#include "Commande.h"
#include "Fonction.h"

void problem(Grid* g) {
	registration(g);
	initializationBox(g);
	initializationInt(g);
	clear(g);
	for (unsigned int i = 0; i < g->settings.nbM; ++i) {
		g->settings.pos[i] = random(g);
		g->box[i].value = BOMB;
	}
	cout << g->settings.lin << " " << g->settings.col << " " << g->settings.nbM << " ";
	for (unsigned int i = 0; i < g->settings.nbM; ++i) cout << g->settings.pos[i] << " ";
	cout << endl;
	destructionBox(g);
}

void show(Grid* g) {
	registration(g);
	initializationBox(g);
	initializationInt(g);
	clear(g);
	bombRegistration(g); 
	history(g);
	showGrid(g);
	destructionBox(g);
	destructionHistory(g);
}

void win(Grid* g) {
	unsigned int r = 0;
	registration(g);
	initializationBox(g);
	initializationInt(g);
	clear(g);
	bombRegistration(g);
	history(g);
	if (g->settings.game != LOSE)
		if (verifWin(g)) winGame(g);
	r = gameStatement(g);
	if (r == 1 || r == 0) cout << "game not won" << endl;
	else cout << "game won" << endl;
	destructionBox(g);
	destructionInt(g);
	destructionHistory(g);
}

void lose(Grid* g) {
	unsigned int r = 0;
	registration(g);
	initializationBox(g);
	initializationInt(g);
	clear(g);
	bombRegistration(g);
	history(g);
	r = gameStatement(g);
	if (r == 1 || r == 2) cout << "game not lost" << endl;
	else cout << "game lost" << endl;
	destructionBox(g);
	destructionInt(g);
	destructionHistory(g);
}

void play(Grid* g) {
	cin >> g->settings.lin >> g->settings.col;
	initializationBox(g);
	read(g);
	g->history.nbMove = 0;
	initializationHistory(g);
	action(g);
	destructionBox(g);
	destructionHistory(g);
}
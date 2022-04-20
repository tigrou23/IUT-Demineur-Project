#include <iostream>
#include <cassert>

using namespace std;

#include "Commande.h"
#include "Fonction.h"

void registration(Grid* g) {
	g->settings.game = PROGRESS;
	cin >> g->settings.lin >> g->settings.col >> g->settings.nbM;
}

void clear(Grid* g) {
	//initialization of each box
	for (unsigned int i = 0; i < g->settings.col * g->settings.lin; ++i) {
		g->box[i].value = EMPTY;
		g->box[i].cptBombe = 0;
	}
	hidden(g);
}

void hidden(Grid* g) {
	for (int j = 0; j < (g->settings.col) * (g->settings.lin); ++j) {
		g->box[j].etat = UNKNOWN;
	}
}

void bombRegistration(Grid* g) {
	for (unsigned int i = 0; i < g->settings.nbM; ++i) {
		cin >> g->settings.pos[i];
		//check if the bomb's position is valid
		assert((g->settings.pos[i] <= (g->settings.lin) * (g->settings.col)) && (g->settings.pos[i] >= 0));
	}
	placingBomb(g);
}

void initializationInt(Grid* g) {
	unsigned int nbBomb = g->settings.nbM;
	g->settings.pos = new unsigned int[nbBomb];
}


void placingBomb(Grid* g) {
	unsigned int indexBomb;
	for (unsigned int i = 0; i < g->settings.nbM; ++i) {
		indexBomb = g->settings.pos[i];
		g->box[indexBomb].value = BOMB;
	}
	numbering(g);
}

bool boxExists(Grid* g, int position) {
	if (position >= 0 && position < (g->settings.col) * (g->settings.lin)) return true;
	else return false;
}

void history(Grid* g) {
	cin >> g->history.nbMove;
	initializationHistory(g);
	for (unsigned int i = 0; i < g->history.nbMove; ++i) {
		cin >> g->history.t[i].move;
		cin >> g->history.t[i].pos;
	}
	for (unsigned int j = 0; j < g->history.nbMove; ++j) {
		analysisMove(g, j);
	}
}

void initializationHistory(Grid* g) {
	unsigned int capacity = g->history.nbMove;
	g->history.t = new Box[capacity];
}

void extensionHistory(Grid* g) {
	unsigned int newCapacity = g->history.nbMove;
	Box* newT = new Box[newCapacity];
	for (unsigned int i = 0; i < newCapacity - 1; ++i)
		newT[i] = g->history.t[i];
	delete[] g->history.t;
	g->history.t = newT;
}
void initializationBox(Grid* g) {
	unsigned int capacity = (g->settings.col) * (g->settings.lin);
	g->box = new Box[capacity];
}


void analysisMove(Grid* g, unsigned int position) {
	unsigned int positionC = g->history.t[position].pos;
	if (g->history.t[position].move == MARKED) {
		g->box[positionC].etat = FLAG;
		if (!verifBomb(g, positionC)) endGame(g);
	}
	else {
		g->box[positionC].etat = KNOWN;
		if (true * verifBomb(g, positionC)) endGame(g);
		verifEmpty(g, positionC);
	}
}

bool verifBomb(Grid* g, unsigned int position) {
	if (g->box[position].value == BOMB)
		return true;
	else return false;
}

bool verifEmpty(Grid* g, unsigned int position) {
	unsigned int capacityMin = 8; //there are 8 boxes around one
	if (g->box[position].value == EMPTY) {
		initializationQueue(g, capacityMin);
		boxEmpty(g, position);
		uncover(g);
		return true;
	}
	else return false;
}

void endGame(Grid* g) {
	g->settings.game = LOSE;
}

void winGame(Grid* g) {
	g->settings.game = WIN;
}

bool etat(Grid* g, unsigned int position) {
	return (g->box[position].etat == UNKNOWN);
}

void numbering(Grid* g) {
	unsigned int boxB = 0;
	int position = 0;
	for (unsigned int i = 0; i < g->settings.nbM; ++i) {
		boxB = g->settings.pos[i];
		int j = -1, k = -1, pJ = -1, pK = -1, maxK = 2;
		if (boxB % (g->settings.col) == 0) {
			pJ = -1;
			pK = 0;
		}
		else if ((boxB + 1) % g->settings.col == 0) {
			maxK = 1;
		}
		for (j; j < 2; ++j) {
			for (k = pK; k < maxK; ++k) {
				position = (boxB + k) + (g->settings.col * j);
				if (boxExists(g, position) && position != boxB) {
					++(g->box[position].cptBombe);
					if (g->box[position].value != BOMB) {
						g->box[position].value = NUMBER;

					}
				}
			}
		}
	}
}

bool searchD(Grid* g, unsigned int boxB) {
	unsigned int cpt = 0;
	int position = 0;
	int j = -1, k = -1, pJ = -1, pK = -1, maxK = 2;
	if (boxB % (g->settings.col) == 0) {
		pJ = -1;
		pK = 0;
	}
	else if ((boxB + 1) % g->settings.col == 0) {
		maxK = 1;
	}
	for (j; j < 2; ++j) {
		for (k = pK; k < maxK; ++k) {
			position = (boxB + k) + (g->settings.col * j);
			if (boxExists(g, position) && position != boxB && g->box[position].etat == FLAG) {
				++cpt;
			}
		}
	}
	if (cpt == g->box[boxB].cptBombe) {
		if (!unmask(g, boxB))
			return false;
		return true;
	}
	return false;
}

bool unmask(Grid* g, unsigned int boxB) {
	assert(g->box[boxB].value == NUMBER);
	int position = 0;
	int j = -1, k = -1, pJ = -1, pK = -1, maxK = 2;
	if (boxB % (g->settings.col) == 0) {
		pJ = -1;
		pK = 0;
	}
	else if ((boxB + 1) % g->settings.col == 0)
		maxK = 1;

	for (j; j < 2; ++j) {
		for (k = pK; k < maxK; ++k) {
			position = (boxB + k) + (g->settings.col * j);
			if (boxExists(g, position) && position != boxB && g->box[position].etat == UNKNOWN) {
				g->box[position].etat = KNOWN;
				addHistory(g, D, position);
				cout << DEMASKED << position;
				return true;
			}
		}
	}
	return false;
}

bool search(Grid* g, unsigned int boxB) {
	unsigned int cpt = 0;
	int position = 0;
	int j = -1, k = -1, pJ = -1, pK = -1, maxK = 2;
	if (boxB % (g->settings.col) == 0) {
		pJ = -1;
		pK = 0;
	}
	else if ((boxB + 1) % g->settings.col == 0) {
		maxK = 1;
	}
	for (j; j < 2; ++j) {
		for (k = pK; k < maxK; ++k) {
			position = (boxB + k) + (g->settings.col * j);
			if (boxExists(g, position) && position != boxB && g->box[position].etat != KNOWN) {
				++cpt;
			}
		}
	}
	if (cpt == g->box[boxB].cptBombe) {
		if (!marked(g, boxB))
			return false;
		return true;
	}
	else return false;
}

bool marked(Grid* g, unsigned int boxB) {
	assert(g->box[boxB].value == NUMBER);
	int position = 0;
	int j = -1, k = -1, pJ = -1, pK = -1, maxK = 2;
	if (boxB % (g->settings.col) == 0) {
		pJ = -1;
		pK = 0;
	}
	else if ((boxB + 1) % g->settings.col == 0)
		maxK = 1;

	for (j; j < 2; ++j) {
		for (k = pK; k < maxK; ++k) {
			position = (boxB + k) + (g->settings.col * j);
			if (boxExists(g, position) && position != boxB && g->box[position].etat == UNKNOWN) {
				g->box[position].etat = FLAG;
				addHistory(g, M, position);
				cout << MARKED << position;
				return true;
			}
		}
	}
	return false;
}

void addHistory(Grid* g, MOVE movement, unsigned int position) {
	++(g->history.nbMove);
	extensionHistory(g);
	g->history.t[g->history.nbMove].move = movement;
	g->history.t[g->history.nbMove].pos = position;
}

unsigned int random(Grid* g) {
	unsigned int choice_box;
	do {
		choice_box = rand() % ((g->settings.col * g->settings.lin) - 1);
	} while ((etat(g, choice_box) == 0) || (boxExists(g, choice_box) - 1));
	return choice_box;
}

void showGrid(Grid* g) {
	unsigned int car = (g->settings.col * 3) + (g->settings.col + 1), compteurCase = 0;
	cout << g->settings.lin << " " << g->settings.col << endl;
	for (unsigned int i = 0; i < g->settings.lin; ++i) {
		for (unsigned int j = 0; j < car - 1; ++j) ((j + 4) % 4 == 0) ? cout << " " : cout << "_";
		cout << endl;
		for (unsigned int j = 0; j < car; ++j) {
			if ((j + 4) % 4 == 0) cout << "|";
			else if ((j + 2) % 2 == 0) { show_etat(g, compteurCase); ++compteurCase; }
			else cout << " ";
		}
		cout << endl;
	}
	for (unsigned int j = 0; j < car - 1; ++j) ((j + 4) % 4 == 0) ? cout << " " : cout << "_";
	cout << endl;
}

void show_etat(Grid* g, unsigned int j) {
	if ((g->settings.game) == LOSE)
		if (g->box[j].value == BOMB) g->box[j].etat = KNOWN;
	switch (g->box[j].etat) {
	case UNKNOWN: cout << "."; break;
	case FLAG: cout << "x"; break;
	case KNOWN:
		switch (g->box[j].value) {
		case NUMBER: cout << g->box[j].cptBombe; break;
		case EMPTY: cout << " "; break;
		case BOMB: cout << "m"; break;
		}; break;
	}

}

void boxEmpty(Grid* g, unsigned int pEmpty) {
	assert(g->box[pEmpty].value == EMPTY);
	int position = 0, cpt = 0;
	int j = -1, k = -1, pJ = -1, pK = -1, maxK = 2;
	if (pEmpty % (g->settings.col) == 0) {
		pJ = -1;
		pK = 0;
	}
	else if ((pEmpty + 1) % g->settings.col == 0) {
		maxK = 1;
	}

	for (j; j < 2; ++j) {
		for (k = pK; k < maxK; ++k) {
			position = (pEmpty + k) + (g->settings.col * j);
			if (boxExists(g, position) && position != pEmpty && g->box[position].etat == UNKNOWN) {
				g->box[position].etat = KNOWN;
				if (g->box[position].value == EMPTY) {
					addQueue(g, position);
				}
			}
		}
	}

}

void uncover(Grid* g) {
	while (!isEmpty(g)) {
		unsigned int tmp = unstack(g);
		boxEmpty(g, tmp);
	}
}
void initializationQueue(Grid* g, unsigned int capacity) {
	g->settings.q.capacity = capacity;
	g->settings.q.nb = 0;
	g->settings.q.queue = new unsigned int[capacity];
}
void extensionQueue(Grid* g) {
	unsigned int newCapacity = (g->settings.q.capacity) * 2; // "2" is the step of extention
	unsigned int* newT = new unsigned int[newCapacity];
	for (unsigned int i = 0; i < (g->settings.q.nb); ++i) {
		newT[i] = g->settings.q.queue[i];
	}
	delete[] g->settings.q.queue;
	g->settings.q.queue = newT;
	g->settings.q.capacity = newCapacity;
}

//empty the queue
unsigned int unstack(Grid* g) {
	unsigned int tmp = g->settings.q.queue[0];
	for (unsigned int i = 1; i < (g->settings.q.nb); ++i) {
		g->settings.q.queue[i - 1] = g->settings.q.queue[i];
	}
	--(g->settings.q.nb);
	return tmp;
}
//add to the queue
void addQueue(Grid* g, unsigned int position) {
	if (g->settings.q.capacity == (g->settings.q.nb)) {
		extensionQueue(g);
	}
	unsigned int newPos = g->settings.q.nb;
	g->settings.q.queue[newPos] = position;
	++(g->settings.q.nb);
}
bool isEmpty(Grid* g) {
	if (g->settings.q.nb == 0)
		return true;
	else return false;
}

bool verifWin(Grid* g) {
	for (unsigned int i = 0; i < (g->settings.col * g->settings.lin); ++i)
		if ((g->box[i].value == BOMB)) {
			if (!boxFull(g, i)) {
				return false;
			}
		}
	return true;
}

bool boxFull(Grid* g, unsigned int pBox) {
	assert(g->box[pBox].value == BOMB);
	unsigned int cpt = 0;
	int position = 0;
	int j = -1, k = -1, pJ = -1, pK = -1, maxK = 2;
	if (pBox % (g->settings.col) == 0) {
		pJ = -1;
		pK = 0;
	}
	else if ((pBox + 1) % g->settings.col == 0) {
		maxK = 1;
	}
	for (j; j < 2; ++j) {
		for (k = pK; k < maxK; ++k) {
			position = (pBox + k) + (g->settings.col * j);
			if (boxExists(g, position) && position != pBox && g->box[position].etat == KNOWN)
				++cpt;
		}
	}
	unsigned int boxes = 0;
	position = 0;
	j = -1, k = -1, pJ = -1, pK = -1, maxK = 2;
	if (pBox % (g->settings.col) == 0) {
		pJ = -1;
		pK = 0;
	}
	else if ((pBox + 1) % g->settings.col == 0) {
		maxK = 1;
	}
	for (j; j < 2; ++j) {
		for (k = pK; k < maxK; ++k) {
			position = (pBox + k) + (g->settings.col * j);
			if (boxExists(g, position) && position != pBox && g->box[position].value == NUMBER)
				++boxes;
		}
	}
	if (cpt == boxes) {
		return true;
	}
	else return false;
}

GAME gameStatement(Grid* g) {
	return g->settings.game;
}

void read(Grid* g) {
	char bin, binBefore = '?';
	unsigned int lines = g->settings.lin, columns = g->settings.col, position = 0, carL1 = (columns * 3), carL2 = (columns * 2);
	for (unsigned int i = 0; i < lines; ++i) {
		for (unsigned int j = 0; j < carL1; ++j)
			cin >> bin;
		for (unsigned int j = 0; j < carL2 + 1;) {
			cin >> bin;
			if ((j + 1) % 2 == 0) {
				if (binBefore == bin) { valueBox(g, ' ', position); ++j; }
				else valueBox(g, bin, position);
				++position;
			}
			binBefore = bin;
			++j;
		}

	}
	for (unsigned int j = 0; j < carL1; ++j) cin >> bin;


}

//assess the character
void valueBox(Grid* g, char character, unsigned int position) {
	switch (character) {
	case ' ': g->box[position].etat = KNOWN; g->box[position].value = EMPTY; break;
	case '.': g->box[position].etat = UNKNOWN; break;
	case 'x': g->box[position].etat = FLAG; break;
	case 'm': endGame(g); break;
	default: 
		unsigned int number = character - '0'; // we use '0' to have the value of the number
		g->box[position].etat = KNOWN; g->box[position].value = NUMBER;
		g->box[position].cptBombe = number;
		break;
	}
}

void action(Grid* g) {
	unsigned int cpt = 0;
	for (unsigned int i = 0; i < (g->settings.col) * (g->settings.lin); ++i) {
		if (g->box[i].value == NUMBER && g->box[i].etat == KNOWN) {
			cpt = search(g, i);
			if (cpt) break;
			cpt = searchD(g, i);
			if (cpt) break;
		}
	}
	if (!cpt) {
		unsigned int box = random(g);
		g->box[box].etat = KNOWN;
		cout << DEMASKED << box;
	}
}

void destructionBox(Grid* g) {
	delete[] g->box;
	g->box = NULL;
}

void destructionHistory(Grid* g) {
	delete[] g->history.t;
	g->history.t = NULL;
}


void destructionInt(Grid* g) {
	delete[] g->settings.pos;
	g->settings.pos = NULL;
}

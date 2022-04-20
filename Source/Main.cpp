/**
 @file Main.cpp
 @author Félix Liburski (111) - Hugo Pereira (105)
 @brief source file
 */

#include <iostream>
#include <iomanip>
#include <assert.h>

using namespace std;

#include "Header.h"
#include "Commande.h"
#include "Fonction.h"

int main() {
	srand(time(NULL));
	Grid g;
	unsigned int commande = 0;
	cin >> commande;
	switch (commande) {
	case 1: problem(&g); break;
	case 2: show(&g); break;
	case 3: win(&g); break;
	case 4: lose(&g); break;
	case 5: play(&g); break;
	default: cout << "commande invalide" << endl;
	}
}

/**
 @file Commande.h
 @author Félix Liburski (111) - Hugo Pereira (105)
 @brief defines all in-game controls
 */

#pragma once
#include "Header.h"
#include "Fonction.h"

 /**@brief function that saves and displays grid settings
  @param[in,out] g the grid
 */
void problem(Grid* g);

/**@brief function that displays the grid
 @param[in,out] g the grid
*/
void show(Grid* g);

/**@brief function that defines the state of the party
 @param[in,out] g the grid
*/
void win(Grid* g);

/**@brief function that defines the state of the party
 @param[in,out] g the grid
*/
void lose(Grid* g);

/**@brief function that records a new move
 @param[in,out] g the grid
*/
void play(Grid* g);
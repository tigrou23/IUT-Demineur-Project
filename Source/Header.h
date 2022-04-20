/**
 @file Header.h
 @author Felix Liburski (111) - Hugo Pereira (105)
 @brief define all types and structures
 */

#pragma once

 /********************
 *		TYPES		*
 *********************/
 /*States of a box*/
typedef enum { UNKNOWN, KNOWN, FLAG } ETAT;
/*Values ​​of a box*/
typedef enum { BOMB, NUMBER, EMPTY } VALUE;
/*Movement value*/
typedef enum { M, D }MOVE;
/*States of the game*/
typedef enum { LOSE = 0, PROGRESS = 1, WIN = 2 }GAME;


#define MARKED 'M'
#define DEMASKED 'D'

/************************
*		STRUCTURES		*
*************************/

typedef struct { unsigned int* queue; unsigned int capacity; unsigned int nb; }Queue;

/*Structure of the state and value of a box*/
typedef struct { ETAT etat; VALUE value; char move; unsigned int pos; unsigned int cptBombe; }Box;

/*Structure of the shot history*/
typedef struct { unsigned int nbMove; Box* t; }History;

/*Structure des reglages de la grille*/
typedef struct { Queue q; unsigned int lin; unsigned int col; unsigned int nbM; unsigned int* pos; GAME game; } Settings;

/*Grid structure*/
typedef struct { Box* box; History history; Settings settings; }Grid;

/*Game structure*/
typedef struct { MOVE movement; unsigned int position; }Play;


/**
 @file Fonction.h
 @author FÃ©lix Liburski (111) - Hugo Pereira (105)
 @brief define all functions of the game
 */

#pragma once
#include "Header.h"

 /**@brief function that saves the parameters of the grid
  @param[in,out] g the grid
 */
void registration(Grid* g);

/**@brief function that cleans the grid
 @param[out] g the grid
*/
void clear(Grid* g);

/**@brief function displays the status and value of a box
 @param[in,out] g the grid
 @param[in] j the case
*/
void show_etat(Grid* g, unsigned int j);

/**@brief function that records the position of bombs and places
 @param[in,out] g the grid
*/
void bombRegistration(Grid* g);

/**@brief function that places bombs
 @param[in,out] g the grid
 @pre the position of the box is less than or equal to the number of boxes in the grid
 @pre the position of the box is higher than or equal to 0
 */
void placingBomb(Grid* g);

/**@brief function hides all box values
 @param[out] g the grid
*/
void hidden(Grid* g);

/**@brief function that lists the blows
 @param[in,out] g the grid
*/
void history(Grid* g);

/**@brief function that numbers the boxes
 @param[in,out] g the grid
*/
void numbering(Grid* g);

/**@brief function that indicates whether the case exists or not
 @param[in,out] g the grid
 @param[in] j the box whose existence is to be proved
 @return if the box exists
*/
bool boxExists(Grid* g, int j);

/**@brief function that returns an unknown box in the grid at random
 @param[out] g the grid
 @return a random box
*/
unsigned int random(Grid* g);

/**@brief function that makes the game lost
 @param[in,out] g the grid
*/
void endGame(Grid* g);

/**@brief function that indicates whether the case does not contain a bomb
 @param[in,out] g the grid
 @param[in] position position of the box
 @return the box does not contain a bomb
 */
bool verifBomb(Grid* g, unsigned int position);

/**@brief function that indicates whether the check box is empty
 @param[in,out] g the grid
 @param[in] position position of the box
 @return the box is empty
 */
bool verifEmpty(Grid* g, unsigned int position);

/**@brief function that displays the grid
 @param[in,out] g the grid
 */
void showGrid(Grid* g);

/**@brief function that assigns an action to the stroke
 @param[in,out] g the grid
 @param[in] position position of the case in question
 */
void analysisMove(Grid* g, unsigned int position);

/**@brief function that reveals adjacent empty boxes
 @param[in,out] g the grid
 @param[in] pEmpty the box in question
 @cond the box is empty
 */
void boxEmpty(Grid* g, unsigned int pEmpty);

/**@brief function that marks a box (flag)
 @param[in,out] g the grid
 @param[in] boxB the box in question
 @cond the box in question is numbered
 @return the marked box
 */
bool marked(Grid* g, unsigned int boxB);

/**@brief function that searches for and counts the number of empty boxes adjacent to a selected box
 @param[in,out] g the grid
 @param[in] boxB the box in question
 @return the number of empty boxes
 */
bool search(Grid* g, unsigned int boxB);

/**@brief function that adds to the stroke history
 @param[in,out] g the grid
 @param[in] movement recorded movement
 @param[in] position the box in question
 */
void addHistory(Grid* g, MOVE movement, unsigned int position);

/**@brief function that identifies if boxes can be revealed
 @param[in,out] g the grid
 @param[in] boxB the box in question
 @return
 */
bool searchD(Grid* g, unsigned int boxB);

/**@brief function which turn a box over if it exists
 @param[in,out] g the grid
 @param[in] boxB the box in question
 @cond the box in question is numbered
 @return if the program returned a box
 */
bool unmask(Grid* g, unsigned int boxB);

/**@brief function that makes the game win
 @param[in,out] g the grid
*/
void winGame(Grid* g);

/**@brief function that indicates the status of the party
 @param[in,out] g the grid
*/
GAME gameStatement(Grid* g);

/**@brief function that checks if the boxes around are discovered
 @param[in,out] g the grid
 @return if the boxes around are full
*/
bool boxFull(Grid* g, unsigned int pBox);

/**@brief checks whether every boxes around the bomb are discovered
 @param[in,out] g the grid
 @return true
*/
bool verifWin(Grid* g);

/**@brief function that saves a grid
 @param[in,out] g the grid
*/
void read(Grid* g);

/**@brief function that takes the value of a character
 @param[in,out] g the grid
 @param[in] the character on question
 */
void valueBox(Grid* g, char character, unsigned int position);

/**@brief function that makes a hit
 @param[in,out] g the grid
*/
void action(Grid* g);

/**@brief function that initializes the history's table
 @param[in,out] g the grid
*/
void initializationHistory(Grid* g);

/**@brief function that extends the history's table
 @param[in,out] g the grid
*/
void extensionHistory(Grid* g);

/**@brief function that initializes the grid's table
 @param[in,out] g the grid
*/
void initializationBox(Grid* g);

/**@brief function that destroys the grid's table
 @param[in,out] g the grid
*/
void destructionBox(Grid* g);

/**@brief function that destroys the history's table
 @param[in,out] g the grid
*/
void destructionHistory(Grid* g);

/**@brief function that initializes the bombs' table
 @param[in,out] g the grid
*/
void initializationInt(Grid* g);

/**@brief function that destroys the bombs' table
 @param[in,out] g the grid
*/
void destructionInt(Grid* g);

/**@brief function that uncover boxes around empty ones
 @param[in,out] g the grid
*/
void uncover(Grid* g);

/**@brief function that initializes a queue
 @param[in,out] g the grid
 @param[in] capacity queue capacity
*/
void initializationQueue(Grid* g, unsigned int capacity);

/**@brief function which unstacks a queue
 @param[in,out] g the grid
 @return the position of the first box after having unstacked
*/
unsigned int unstack(Grid* g);

/**@brief function that extends a queue
 @param[in,out] g the grid
*/
void extensionQueue(Grid* g);

/**@brief function that adds an element to a queue
 @param[in] position position we add
 @param[in,out] g the grid
*/
void addQueue(Grid* g, unsigned int position);

/**@brief function that checks if a queue is empty
 @param[in,out] g the grid
 @return if the queue is empty
*/
bool isEmpty(Grid* g);

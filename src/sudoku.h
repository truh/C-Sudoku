/*
  Name of file  : sudoku.h
  Author        : Martin Haidn <mhaidn@student.tgm.ac.at>
                  Jakob Klepp  <jklepp@student.tgm.ac.at>
  Version       : 20131112.1
  Description   : Stell das Sudoku Struct sowie Funktionsprototypen zum loesen
                  von Sudokus und X-Sudokus zur verfuegung.
*/

#ifndef SUDOKU_H
#define SUDOKU_H

/* boolean typ */ 
typedef int bool;
#define TRUE 1
#define FALSE 0

#define SUDOKU_SIZE 9
//#define SUDOKU_PATTERN "%d %d %d %d %d %d %d %d %d"

/*! \brief Um zu unterscheiden um was fuer einen Typ es sich bei einen Sudoku 
 *         handelt
 */
typedef int SUDOKU_TYPE 
#define NORMAL_SUDOKU 0
#define X_SUDOKU 1

/*! \brief Struct welches das Sudokufeld sowie den Typ des Sudokus enthaelt
 */
typedef struct 
{
    int field[SUDOKU_SIZE][SUDOKU_SIZE];
    SUDOKU_TYPE type;
} Sudoku;

/*! \brief Loest das gegebene Raetsel
 *
 * \param spiel Reaetsel das geloest werden soll
 * 
 * \return FALSE wenn keine loesung gefunden werden konnte
 */
bool solve(Sudoku * spiel);
int fillsudoku(Sudoku * spiel, int row, int col);
int isAvailable(Sudoku * spiel, int row, int col, int num);

#endif

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
enum SUDOKU_TYPE 
{
    NORMAL_SUDOKU,
    X_SUDOKU
};

/*! \brief Struct welches das Sudokufeld sowie den Typ des Sudokus enthaelt
 */
typedef struct 
{
    int field[SUDOKU_SIZE][SUDOKU_SIZE];
    enum SUDOKU_TYPE type;
} Sudoku;

/*! \brief Loest das gegebene Raetsel
 *
 * \param spiel Reaetsel das geloest werden soll
 * 
 * \return FALSE wenn keine loesung gefunden werden konnte
 */
bool solve(Sudoku * spiel);
int fillsudoku(int sudoku[][9], int row, int col)
int isAvailable(int field[][9], int row, int col, int num);

#endif

/*
  Name of file  : io.h
  Author        : Martin Haidn <mhaidn@student.tgm.ac.at>
                  Jakob Klepp  <jklepp@student.tgm.ac.at>
  Version       : 20131112.1
  Description   : Stellt Funktionsprototypen zum einlesen von CSV zur
                  verfuegung.
*/
#ifndef IO_H
#define IO_H

#include "sudoku.h"

#include <stdio.h>
#include <stdlib.h>

/*! \brief Liesst ein Sudoku aus dem gegebenen Stream.
 *
 * \param stream Stream aus dem gelesen werden soll
 * 
 * \param spiel Referenz in die der Stream gelesen werden soll
 */
void read_sudoku(FILE * stream, Sudoku * spiel);

/*! \brief Schreibt ein Sudoku in den gegebenen Stream
 *
 * \param stream Stream in den geschrieben werden soll
 *
 * \param spiel Sudoku die geschrieben werden soll
 */
void write_sudoku(FILE * stream, Sudoku * spiel);
#endif
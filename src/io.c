/*
  Name of file  : io.h
  Author        : Martin Haidn <mhaidn@student.tgm.ac.at>
                  Jakob Klepp  <jklepp@student.tgm.ac.at>
  Version       : 20131112.1
  Description   : Implementiert Funktionen zum einlesen von CSV.
*/
#include "io.h"

/*! \brief Liesst ein Sudoku aus dem gegebenen Stream.
 *
 * \param stream Stream aus dem gelesen werden soll
 * 
 * \param spiel Referenz in die der Stream gelesen werden soll
 */
void read_sudoku(FILE * stream, Sudoku * spiel)
{
    size_t i = 0;
    int buffer = 0;

    while((fscanf(stream, "%d", &buffer)) != EOF )
    {
        if(i > SUDOKU_SIZE * SUDOKU_SIZE)
        {
            break;
        }
        if(buffer > SUDOKU_SIZE || buffer <= 0) 
        {
            printf("Feld nummer: %zu enthaelt ungueltigen Wert: %d\n", i, buffer);
            buffer = 0;
        }
        **((*spiel).field + i) = buffer;
        ++i;
    }
    if(i < SUDOKU_SIZE * SUDOKU_SIZE)
    {
        printf("Zu wenige Werte!\n");
    }
}

/*! \brief Schreibt ein Sudoku in den gegebenen Stream
 *
 * \param stream Stream in den geschrieben werden soll
 *
 * \param spiel Sudoku die geschrieben werden soll
 */
void write_sudoku(FILE * stream, Sudoku * spiel)
{
    size_t i, j;
    for(i = 0; i < SUDOKU_SIZE; ++i)
    {
        for(j = 0; j < SUDOKU_SIZE; ++j)
        {
            fprintf(stream, "%d ", **((*spiel).field + i * SUDOKU_SIZE + j));
        }
        fprintf(stream, "\n");
    }
}
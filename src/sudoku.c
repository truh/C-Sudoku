/*
  Name of file  : sudoku.h
  Author        : Martin Haidn <mhaidn@student.tgm.ac.at>
                  Jakob Klepp  <jklepp@student.tgm.ac.at>
  Version       : 20131112.1
  Description   : Implementiert Funktionen zum loesen von Sudokus und X-Sudokus
*/

#include <stdio.h>
#include "sudoku.h"

/*! \brief Loest das gegebene Raetsel
 *
 * \param spiel Reaetsel das geloest werden soll
 *
 * \return FALSE wenn keine loesung gefunden werden konnte
 */
bool solve(Sudoku * spiel)
{
    if (spiel->type == NORMAL_SUDOKU) {
        if( fillsudoku(spiel, 0, 0) )
        {
#ifdef DEBUG//Debug Code---------------------------------------------------
            printf("Debugcode------------------------NORMAL_SUDOKU\n");
            int a,b;
            for(a=0; a<9; ++a)
            {
                for(b=0; b<9; ++b)
                    printf("%d ", *(spiel->field + SUDOKU_SIZE * a + b));
                printf("\n");
            }
            printf("----------EODBG\n");
#endif
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }

    if (spiel->type == X_SUDOKU) {
        if( fillsudoku(spiel, 0, 0) )
        {
#ifdef DEBUG//Debug Code---------------------------------------------------
            printf("Debugcode------------------------X_SUDOKU\n");
            int a,b;
            for(a=0; a<9; ++a)
            {
                for(b=0; b<9; ++b)
                    printf("%d ", *(spiel->field + SUDOKU_SIZE * a + b));
                    printf("\n");
            }
            printf("----------EODBG\n");
#endif
            return TRUE;
        }
        else
        {
#ifdef DEBUG//Debug Code---------------------------------------------------
            printf("Debugcode------------------------X_SUDOKU\n");
            printf("GESCHEITERT\n");
            int a,b;
            for(a=0; a<9; ++a)
            {
                for(b=0; b<9; ++b)
                    printf("%d ", *(spiel->field + SUDOKU_SIZE * a + b));
                printf("\n");
            }
            printf("----------EODBG\n");
#endif
            return FALSE;
        }
    }
#ifdef DEBUG//Debug Code---------------------------------------------------
    printf("Debugcode------------------------SUDOKU?\n");
    printf("GESCHEITERT\n");
    int a,b;
    for(a=0; a<9; ++a)
    {
        for(b=0; b<9; ++b)
            printf("%d ", *(spiel->field + SUDOKU_SIZE * a + b));
        printf("\n");
    }
    printf("----------EODBG\n");
#endif

    return FALSE;
}

int isAvailable(Sudoku * spiel, int row, int col, int num)
{
    int i, j;
    for(i=0; i<SUDOKU_SIZE; ++i)
        if( (*(spiel->field + SUDOKU_SIZE * row + i) == num) || ( *(spiel->field + SUDOKU_SIZE * i + col) == num )  )//checking in row and col
            return 0;

    //checking in the grid
    int rowStart = (row/3) * 3;
    int colStart = (col/3) * 3;

    for(i=rowStart; i<(rowStart+3); ++i)
    {
        for(j=colStart; j<(colStart+3); ++j)
        {
            if( *(spiel->field + SUDOKU_SIZE * i + j) == num )
                return 0;
        }
    }

    //checking the x
    if (spiel->type==X_SUDOKU)
    {
        int i;
        if(row == col)
        {
            for(i=0; i < SUDOKU_SIZE; ++i)
            {
                if (*(spiel->field + SUDOKU_SIZE * i + i) == num) 
                {   return 0;
                }
            }
        }
        if((row + col) == (SUDOKU_SIZE -1))
        for(i=0; i < SUDOKU_SIZE; ++i)
        {
            if (*(spiel->field + SUDOKU_SIZE * i + SUDOKU_SIZE - (i+1)) == num)
            {   return 0;
            }
        }
    }

    return 1;
}

/* Methode zum Lösen des normalen Sudokus.
 * Quelle: http://codereview.stackexchange.com/questions/13677/c-code-to-solve-sudoku
 */

int fillsudoku(Sudoku * spiel, int row, int col)
{
    int i;
    if( row < SUDOKU_SIZE && col < SUDOKU_SIZE )
    {
        if( *(spiel->field + SUDOKU_SIZE * row + col) != 0 )//pre filled
        {
            if( (col+1)<SUDOKU_SIZE )
                return fillsudoku(spiel, row, col+1);
            else if( (row+1)<SUDOKU_SIZE )
                return fillsudoku(spiel, row+1, 0);
            else
                return 1;
        }
        else
        {
            for(i= 0; i < SUDOKU_SIZE; ++i)
            {
                if( isAvailable(spiel, row, col, i+1) )
                {
                    *(spiel->field + SUDOKU_SIZE * row + col) = i+1;

                    if( (col+1) < SUDOKU_SIZE )
                    {
                    if( fillsudoku(spiel, row, col +1) )
                        return 1;
                        else
                            *(spiel->field + SUDOKU_SIZE * row + col) = 0;
                    }
                    else if( (row+1)<SUDOKU_SIZE )
                    {
                        if( fillsudoku(spiel, row+1, 0) )
                            return 1;
                        else
                            *(spiel->field + SUDOKU_SIZE * row + col) = 0;
                    }
                    else
                        return 1;
                }
            }
        }
        return 0;
    }
    else
    {
        return 1;
    }
}

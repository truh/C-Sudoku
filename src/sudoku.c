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
	int *sudoku= (*spiel).field;
	if ((*spiel).type == NORMAL_SUDOKU) {
		if( fillsudoku(sudoku, 0, 0) )
		{

			for(i=0; i<9; ++i)
			{
				for(j=0; j<9; ++j)
					printf("%d ", sudoku[i][j]);
				printf("\n");
			}
		}
		else
		{
			printf("\n\nNO SOLUTION\n\n");
		}
	} else {
		printf("X-Sudoku");
	}
}

int isAvailable(int sudoku[][9], int row, int col, int num)
{
    int i, j;
    for(i=0; i<9; ++i)
        if( (sudoku[row][i] == num) || ( sudoku[i][col] == num )  )//checking in row and col
            return 0;

    //checking in the grid
    int rowStart = (row/3) * 3;
    int colStart = (col/3) * 3;

    for(i=rowStart; i<(rowStart+3); ++i)
    {
        for(j=colStart; j<(colStart+3); ++j)
        {
            if( sudoku[i][j] == num )
                return 0;
        }
    }

    return 1;
}

/* Methode zum Lösen des normalen Sudokus.
 * Quelle: http://codereview.stackexchange.com/questions/13677/c-code-to-solve-sudoku
 */

int fillsudoku(int sudoku[][9], int row, int col)
{
    int i;
    if( row<9 && col<9 )
    {
        if( sudoku[row][col] != 0 )//pre filled
        {
            if( (col+1)<9 )
                return fillsudoku(sudoku, row, col+1);
            else if( (row+1)<9 )
                return fillsudoku(sudoku, row+1, 0);
            else
                return 1;
        }
        else
        {
            for(i=0; i<9; ++i)
            {
                if( isAvailable(sudoku, row, col, i+1) )
                {
                    sudoku[row][col] = i+1;

                    if( (col+1)<9 )
                    {
                    if( fillsudoku(sudoku, row, col +1) )
                        return 1;
                        else
                            sudoku[row][col] = 0;
                    }
                    else if( (row+1)<9 )
                    {
                        if( fillsudoku(sudoku, row+1, 0) )
                            return 1;
                        else
                            sudoku[row][col] = 0;
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

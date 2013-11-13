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
	if ((*spiel).type == NORMAL_SUDOKU) {
		if( fillsudoku((*spiel).field, 0, 0, FALSE) )
		{
	    	//Debug Code---------------------------------------------------
	    	printf("Debugcode------------------------NORMAL_SUDOKU\n");
	    	int a,b;
	        for(a=0; a<9; ++a)
	        {
	            for(b=0; b<9; ++b)
	                printf("%d ", (*spiel).field[a][b]);
	            printf("\n");
	        }
	        printf("----------EODBG\n");
	    	//EODBG
			return TRUE;
		}
		else
		{
			return FALSE;
		}
	}

	if ((*spiel).type == NORMAL_SUDOKU) {
		if( fillsudoku((*spiel).field, 0, 0, TRUE) )
		{
		  	//Debug Code---------------------------------------------------
			    	printf("Debugcode------------------------X_SUDOKU\n");
			    	int a,b;
			        for(a=0; a<9; ++a)
			        {
			            for(b=0; b<9; ++b)
			                printf("%d ", (*spiel).field[a][b]);
			            printf("\n");
			        }
			        printf("----------EODBG\n");
			    	//EODBG
			return TRUE;
		}
		else
		{
		  	//Debug Code---------------------------------------------------
				    	printf("Debugcode------------------------X_SUDOKU\n");
				    	printf("GESCHEITERT\n");
				    	int a,b;
				        for(a=0; a<9; ++a)
				        {
				            for(b=0; b<9; ++b)
				                printf("%d ", (*spiel).field[a][b]);
				            printf("\n");
				        }
				        printf("----------EODBG\n");
				    	//EODBG
			return FALSE;
		}
	}
	//Debug Code---------------------------------------------------
				    	printf("Debugcode------------------------X_SUDOKU\n");
				    	printf("GESCHEITERT\n");
				    	int a,b;
				        for(a=0; a<9; ++a)
				        {
				            for(b=0; b<9; ++b)
				                printf("%d ", (*spiel).field[a][b]);
				            printf("\n");
				        }
				        printf("----------EODBG\n");
				    	//EODBG
	return FALSE;
}

int isAvailable(int sudoku[SUDOKU_SIZE][SUDOKU_SIZE], int row, int col, int num, bool isX)
{
    int i, j;
    for(i=0; i<SUDOKU_SIZE; ++i)
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

    //checking the x
     if (isX)
     {
    	 int x,y;
    	 for (x= 0; x < SUDOKU_SIZE; x++)
    	 {
    		 for (y= 0; y < SUDOKU_SIZE; y++)
    		 {
    			 if ((x == y) && (sudoku[x][y] == num)) return 0;
    			 if ((x+y == 8) && (sudoku[x][y] == num)) return 0;
    		 }
    	 }
     }

    return 1;
}

/* Methode zum Lösen des normalen Sudokus.
 * Quelle: http://codereview.stackexchange.com/questions/13677/c-code-to-solve-sudoku
 */

int fillsudoku(int sudoku[SUDOKU_SIZE][SUDOKU_SIZE], int row, int col, bool isX)
{
    int i;
    if( row < SUDOKU_SIZE && col < SUDOKU_SIZE )
    {
        if( sudoku[row][col] != 0 )//pre filled
        {
            if( (col+1)<SUDOKU_SIZE )
                return fillsudoku(sudoku, row, col+1, isX);
            else if( (row+1)<SUDOKU_SIZE )
                return fillsudoku(sudoku, row+1, 0, isX);
            else
                return 1;
        }
        else
        {
            for(i= 0; i < SUDOKU_SIZE; ++i)
            {
                if( isAvailable(sudoku, row, col, i+1, isX) )
                {
                    sudoku[row][col] = i+1;

                    if( (col+1) < SUDOKU_SIZE )
                    {
                    if( fillsudoku(sudoku, row, col +1, isX) )
                        return 1;
                        else
                            sudoku[row][col] = 0;
                    }
                    else if( (row+1)<SUDOKU_SIZE )
                    {
                        if( fillsudoku(sudoku, row+1, 0, isX) )
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

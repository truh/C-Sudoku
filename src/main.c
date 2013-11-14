/*
  Name of file  : main.c
  Author        : Martin Haidn <mhaidn@student.tgm.ac.at>
                  Jakob Klepp  <jklepp@student.tgm.ac.at>
  Version       : 20131112.1
  Description   : Eine CLI Applikation zum loesen normaler Sudokus und
                  X-Sudokus
*/
#include "io.h"
#include "sudoku.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG
int main(int argc, char** argv)
{
    FILE * stream = stdin; //Default stream
    SUDOKU_TYPE type = NORMAL_SUDOKU;
    bool result;

    Sudoku *spiel = NULL;
    spiel = malloc(sizeof(Sudoku));

    spiel->field = malloc(sizeof(int) * SUDOKU_SIZE * SUDOKU_SIZE);

    if(!spiel) 
    {
        printf("Speicher konnte nicht angefordert werden.\n");
        return EXIT_FAILURE;
    }

    if(argc > 1)
    {
        if(strstr(argv[1], "x"))
        {
            type = X_SUDOKU;
        }
        if(strstr(argv[1], "h"))
        {
            printf("Verwendung: \n");
            printf("csudoku [x] < file\n");
        }
    }

    spiel->type = type;
    //raetsel aus stream einlesen
    read_sudoku(stream, spiel);
    write_sudoku(stdout, spiel);
    printf("\n");

    //raetsel loesen
    result = solve(spiel);

    //raetsel ausgeben
    write_sudoku(stdout, spiel);

    fclose(stream);
    free(spiel);

#ifdef DEBUG
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
#endif

    return EXIT_SUCCESS;
}

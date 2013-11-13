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

int main(int argc, char** argv)
{
    FILE * stream = stdin; //Default stream
    enum SUDOKU_TYPE type = NORMAL_SUDOKU;
    bool result;

    Sudoku *spiel = NULL;
    spiel = malloc(sizeof(Sudoku));
    if(!spiel) 
    {
        printf("Speicher konnte nicht angefordert werden.\n");
        return EXIT_FAILURE;
    }

    if(argc > 0)
    {
        if(strstr(argv[0], "x"))
        {
            type = X_SUDOKU;
        }
        if(strstr(argv[0], "f"))
        {
            if(argc < 2) {
                printf("Kein file angegeben.\n");
            } else
            {
                stream = fopen(argv[1], "r");
            }
        }
        if(strstr(argv[0], "h"))
        {
            printf("Verwendung: \n");
            printf("csudoku [x][f file]\n");
        }
    }

    //raetsel aus stream einlesen
    read_sudoku(stream, spiel);

    //raetsel loesen
    result = solve(spiel);
    //raetsel ausgeben
    write_sudoku(stdout, spiel);

    fclose(stream);
    free(spiel);
    return EXIT_SUCCESS;
}

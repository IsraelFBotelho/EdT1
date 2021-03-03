#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "path.h"

void startAnalysis(char* pathOut, int numberVisit, int listSize){
    char* fullPath = catPath(pathOut, "analysis.txt");
    FILE *txt = fopen(fullPath, "w");

    if(!txt){
        printf("Relatorio nao foi possivel ser criado!");
        free(fullPath);
        return;
    }

    fprintf(txt, "size %d visit %d\n", listSize, numberVisit);    

    fclose(txt);
    free(fullPath);
}

void continueAnalysis(char* pathOut, int numberVisit, int listSize){
    char* fullPath = catPath(pathOut, "analysis.txt");
    FILE *txt = fopen(fullPath, "a");

    if(!txt){
        printf("Relatorio nao foi possivel ser continuado!");
        free(fullPath);
        return;
    }

    fprintf(txt, "size %d visit %d\n", listSize, numberVisit);    

    fclose(txt);
    free(fullPath);
}
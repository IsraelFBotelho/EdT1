#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "rectangle.h"
#include "geo.h"
#include "argv.h"
#include "svg.h"
#include "qry.h"
#include "analysis.h"

int main(int argc, char* argv[]){

    char *pathOut = NULL;
    char *nameArqGeo = NULL;
    char *pathIn = NULL;
    char *nameArqQry = NULL;
    char *nameArqAnalysis = NULL;
    char *titleAnalysys = NULL;
    int numberVisits = 0;
    int swAnalysis = 0;
    int numberListSize = 0;
    // swList é um int que armazena 1 para usar lista dinamica e 0 para usar lista estatica
    int swList = 1;
    List listRect = NULL;

    readArgv(argc, argv, &pathOut, &pathIn, &nameArqGeo, &nameArqQry, &swList, &swAnalysis, &nameArqAnalysis, &titleAnalysys);

    readGeo(pathIn, nameArqGeo, &listRect, swList);

    numberListSize = getListSize(listRect, swList);

    writeSvg(listRect, NULL, pathOut, nameArqGeo, swList);

    readQry(pathIn, pathOut, nameArqQry, nameArqGeo, listRect, swList);



    endAllRectangle(listRect,swList);
    endList(listRect, swList, &numberVisits);



    if(swAnalysis == 1){

        startAnalysis(pathOut, numberVisits, numberListSize);
    }else if(swAnalysis == 2){

        continueAnalysis(pathOut, numberVisits, numberListSize);
    }else if(swAnalysis == 3){

        endAnalysis(pathOut, numberVisits, numberListSize, titleAnalysys, nameArqAnalysis);
    }


    free(titleAnalysys);
    free(nameArqAnalysis);
    free(pathOut);
    free(nameArqGeo);
    free(pathIn);
    free(nameArqQry);

    return 0;
}
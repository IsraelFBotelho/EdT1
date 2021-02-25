#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "rectangle.h"
#include "geo.h"
#include "argv.h"
#include "svg.h"
#include "path.h"
#include "qry.h"

int main(int argc, char* argv[]){

    char *pathOut = NULL;
    char *nameArqGeo = NULL;
    char *pathIn = NULL;
    char *nameArqQry = NULL;
    // swList é um int que armazena 1 para usar lista dinamica e 0 para usar lista estatica
    int swList = 1;
    List listRect = NULL;

    readArgv(argc, argv, &pathOut, &pathIn, &nameArqGeo, &nameArqQry, &swList);

    readGeo(pathIn, nameArqGeo, &listRect, swList);

//    tpCommand(listRect,nameArqQry, nameArqGeo, swList);

    writeSvg(listRect, pathOut, nameArqGeo, swList);


    free(pathOut);
    free(nameArqGeo);
    free(pathIn);
    free(nameArqQry);
    endAllRectangle(listRect,swList);
//    printf("%d", getListVisit(listRect,swList));
    endList(listRect, swList);
    return 0;
}
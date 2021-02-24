#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "rectangle.h"
#include "geo.h"
#include "argv.h"
#include "svg.h"
#include "path.h"

int main(int argc, char* argv[]){

    char *pathOut = NULL;
    char *nameArqGeo = NULL;
    char *pathIn = NULL;
    char *nameArqQry = NULL;
    char* nameArqSvg = NULL;
    // swList é um int que armazena 1 para usar lista dinamica e 0 para usar lista estatica
    int swList = 1;
    List listRect = NULL;
    FILE * svg = NULL;

    readArgv(argc, argv, &pathOut, &pathIn, &nameArqGeo, &nameArqQry, &swList);

    printf("%s\n%s\n%s\n%s\n",pathOut, pathIn, nameArqGeo, nameArqQry);


    readGeo(pathIn, nameArqGeo, &listRect, swList);

    nameArqSvg = extractName(nameArqGeo);

    createSvg(svg, pathOut, nameArqSvg);


for(Node aux = getFirst(listRect, swList); aux ; aux = getNext(listRect, aux, swList)){

    drawRectangle(svg, pathOut, nameArqSvg, getInfo(aux, swList));
}
    endSvg(svg, pathOut, nameArqSvg);

    free(nameArqSvg);
    free(pathOut);
    free(nameArqGeo);
    free(pathIn);
    free(nameArqQry);
    endAllRectangle(listRect,swList);
    endList(listRect, swList);
    return 0;
}
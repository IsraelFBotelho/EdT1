#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "path.h"
#include "rectangle.h"


void createSvg(FILE *svg, char* path, char* name){
    char s[] = "svg";
    char* nameSvg = s;
    char *nameArqSvg = insertExtension(name, nameSvg);
    char *fullPathSvg = catPath(path, nameArqSvg);

    svg = fopen(fullPathSvg, "w");

    if(!svg){
        fclose(svg);
        printf("Erro na criacao do SVG!!\n");
        free(nameArqSvg);
        free(fullPathSvg);
        exit(1);
    }

    fprintf(svg, "<svg xmlns=\"http://www.w3.org/2000/svg\">\n");
    fclose(svg);
    free(nameArqSvg);
    free(fullPathSvg);
}

void endSvg(FILE *svg, char* path, char* name){
    char s[] = "svg";
    char* nameSvg = s;
    char *nameArqSvg = insertExtension(name, nameSvg);
    char *fullPathSvg = catPath(path, nameArqSvg);

    svg = fopen(fullPathSvg, "a");

    if(!svg){
        fclose(svg);
        printf("Erro na finalizacao do SVG!!\n");
        free(nameArqSvg);
        free(fullPathSvg);
        exit(1);
    }

    fprintf(svg, "</svg>");
    fclose(svg);
    free(nameArqSvg);
    free(fullPathSvg);
}

void drawRectangle(FILE *svg, char* path, char* name, Rectangle rectangle){
    char s[] = "svg";
    char* nameSvg = s;
    char *nameArqSvg = insertExtension(name, nameSvg);
    char *fullPathSvg = catPath(path, nameArqSvg);

    double x, y, height, width;
    char *id, *fill, *stroke;

    svg = fopen(fullPathSvg, "a");

    if(!svg){
        fclose(svg);
        printf("Erro na edicao do SVG!!\n");
        free(nameArqSvg);
        free(fullPathSvg);
        exit(1);
    }

    x = getRectangleX(rectangle);
    y = getRectangleY(rectangle);
    height = getRectangleHeight(rectangle);
    width = getRectangleWidth(rectangle);
    id = getRectangleId(rectangle);
    fill = getRectangleFill(rectangle);
    stroke = getRectangleStroke(rectangle);
    
    fprintf(svg, "\t<rect id=\"%s\" x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" stroke=\"%s\" fill=\"%s\"/>\n",id, x, y, width, height, stroke, fill);
    fflush(svg);
    fclose(svg);
    free(nameArqSvg);
    free(fullPathSvg);

}

void writeSvg(List list, char *pathOut, char * nameArq, int swList){
    FILE *svg = NULL;

    char *nameArqSvg =(char *) extractName(nameArq);

    createSvg(svg, pathOut, nameArqSvg);


    for(Node aux = getFirst(list, swList); aux ; aux = getNext(list, aux, swList)){

        drawRectangle(svg, pathOut, nameArqSvg, getInfo(aux, swList));
    }

    endSvg(svg, pathOut, nameArqSvg);

    free(nameArqSvg);
}
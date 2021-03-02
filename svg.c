#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "path.h"
#include "rectangle.h"


FILE* createSvg(char *fullPathSvg){

    FILE *svg = fopen(fullPathSvg, "w");

    if(!svg){
        printf("Erro na criacao do SVG!!\n");
        free(fullPathSvg);
        exit(1);
    }

    fprintf(svg, "<svg xmlns=\"http://www.w3.org/2000/svg\">\n");
    return svg;
}

void endSvg(FILE *svg){

    if(!svg){
        printf("Erro na finalizacao do SVG!!\n");
        exit(1);
    }

    fprintf(svg, "</svg>");
    fclose(svg);
}

void drawRectangle(FILE *svg, Rectangle rectangle){

    double x, y, height, width;
    char *id, *fill, *stroke;
    int stroke_op = 100;
    int fill_op = 50;

    x = getRectangleX(rectangle);
    y = getRectangleY(rectangle);
    height = getRectangleHeight(rectangle);
    width = getRectangleWidth(rectangle);
    id = getRectangleId(rectangle);
    fill = getRectangleFill(rectangle);
    stroke = getRectangleStroke(rectangle);

    if(strcmp(fill, "@") == 0){
        fill_op = 0;
    }

    if(strcmp(stroke, "@") == 0){
        stroke_op = 0;
    }
    
    fprintf(svg, "\t<rect id=\"%s\" x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" stroke=\"%s\" fill=\"%s\" fill-opacity=\"%d%%\" stroke-opacity=\"%d%%\"/>\n",id, x, y, width, height, stroke, fill, fill_op, stroke_op);
}

void drawBoundingBox(FILE *svg, List list_bb){

    for(Node *aux = getFirst(list_bb, 1); aux; aux = getNext(list_bb, aux, 1)){
        Rectangle *rectangle = getInfo(aux, 1);
        double x = getRectangleX(rectangle);
        double y = getRectangleY(rectangle);
        double height = getRectangleHeight(rectangle);
        double width = getRectangleWidth(rectangle);
        fprintf(svg, "\t<rect id=\"Bounding Box\" x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" stroke=\"red\" fill=\"@\" fill-opacity=\"0%%\" stroke-opacity=\"100%%\" stroke-dasharray=\"4\" />\n",x, y, width, height);
    }
}

void writeSvg(List list, List list_bb, char *pathOut, char * nameArq, int swList){
    char s[] = "svg";
    char* nameSvg = s;
    char *nameArqExtr =(char *) extractName(nameArq);
    char *nameArqSvg = insertExtension(nameArqExtr, nameSvg);
    char *fullPathSvg = catPath(pathOut, nameArqSvg);

    FILE* svg = createSvg(fullPathSvg);


    for(Node aux = getFirst(list, swList); aux ; aux = getNext(list, aux, swList)){

        drawRectangle(svg, getInfo(aux, swList));
    }
    
    if(list_bb){
        drawBoundingBox(svg, list_bb);
    }
    

    endSvg(svg);

    free(nameArqExtr);
    free(nameArqSvg);
    free(fullPathSvg);
}
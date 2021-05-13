#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "path.h"
#include "rectangle.h"
#include "circle.h"


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

    x = getRectangleX(rectangle);
    y = getRectangleY(rectangle);
    height = getRectangleHeight(rectangle);
    width = getRectangleWidth(rectangle);
    id = getRectangleId(rectangle);
    fill = getRectangleFill(rectangle);
    stroke = getRectangleStroke(rectangle);

    if(strcmp(fill, "@") == 0){
        fill = "none";
    }

    if(strcmp(stroke, "@") == 0){
        fill = "none";
    }
    
    fprintf(svg, "\t<rect id=\"%s\" x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" stroke=\"%s\" fill=\"%s\" fill-opacity=\"50%%\" />\n",id, x, y, width, height, stroke, fill);
}

void drawBoundingBox(FILE *svg, List list_bb){

    for(Node *aux = getFirst(list_bb, 1); aux; aux = getNext(list_bb, aux, 1)){
        Rectangle *rectangle = getInfo(aux, 1);
        double x = getRectangleX(rectangle);
        double y = getRectangleY(rectangle);
        double height = getRectangleHeight(rectangle);
        double width = getRectangleWidth(rectangle);
        fprintf(svg, "\t<rect id=\"Bounding Box\" x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" stroke=\"red\" fill=\"none\" fill-opacity=\"0%%\" stroke-opacity=\"100%%\" stroke-dasharray=\"4\" stroke-width=\"2\"/>\n",x, y, width, height);
    }
}

void drawCircle(FILE *svg, List list_c,int swList){

    for(Node *aux = getFirst(list_c, swList); aux; aux = getNext(list_c, aux, swList)){
        Circle *circle = getInfo(aux, swList);
        double x = getCircleX(circle);
        double y = getCircleY(circle);
        double r = getCircleR(circle);
        char *id = getCircleId(circle);
        char *fill = getCircleFill(circle);
        char *stroke = getCircleStroke(circle);

        fprintf(svg, "\t<circle id=\"%s\" cx=\"%lf\" cy=\"%lf\" r=\"%lf\" stroke=\"%s\" fill=\"%s\"/>\n", id, x, y, r, stroke, fill);
    }
}

void writeSvg(List list, List list_bb, List list_c, char *pathOut, char * nameArq, int swList){
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

    if(list_c){
        drawCircle(svg, list_c, 1);
    }    

    endSvg(svg);

    free(nameArqExtr);
    free(nameArqSvg);
    free(fullPathSvg);
}
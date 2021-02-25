#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rectangle.h"
#include "list.h"

typedef struct rectangleStruct{
    double x;
    double y;
    double height;
    double width;
    char id[30];
    char fill[25];
    char stroke[25];
} RectangleStruct;

Rectangle createRectangle(double x, double y, double height, double width, char id[30], char fill[25], char stroke[25]){
    RectangleStruct *new = (RectangleStruct *) malloc(sizeof(RectangleStruct));

    new->x = x;
    new->y = y;
    new->height = height;
    new->width = width;
    strcpy(new->id, id);
    strcpy(new->fill, fill);
    strcpy(new->stroke, stroke);
    
    return new;
}

void endRectangle(Rectangle rectangle){
    RectangleStruct *rectangle_aux = (RectangleStruct *) rectangle;
    free(rectangle_aux);
}

void endAllRectangle(List list, int swList){
    Node * node_aux = getFirst(list, swList);

    if(node_aux){
        endRectangle(getInfo(node_aux, swList));
    }

    while(getNext(list, node_aux, swList)){
        node_aux = getNext(list, node_aux, swList);
        endRectangle(getInfo(node_aux, swList));
    }
}


char* getRectangleId(Rectangle rectangle){
    RectangleStruct *rectangle_aux = (RectangleStruct *) rectangle;

    return rectangle_aux->id;
}

double getRectangleX(Rectangle rectangle){
    RectangleStruct *rectangle_aux = (RectangleStruct *) rectangle;

    return rectangle_aux->x;
}

double getRectangleY(Rectangle rectangle){
    RectangleStruct *rectangle_aux = (RectangleStruct *) rectangle;

    return rectangle_aux->y;
}

double getRectangleHeight(Rectangle rectangle){
    RectangleStruct *rectangle_aux = (RectangleStruct *) rectangle;

    return rectangle_aux->height;
}

double getRectangleWidth(Rectangle rectangle){
    RectangleStruct *rectangle_aux = (RectangleStruct *) rectangle;

    return rectangle_aux->width;
}

char* getRectangleFill(Rectangle rectangle){
    RectangleStruct *rectangle_aux = (RectangleStruct *) rectangle;

    return rectangle_aux->fill;
}

char* getRectangleStroke(Rectangle rectangle){
    RectangleStruct *rectangle_aux = (RectangleStruct *) rectangle;

    return rectangle_aux->stroke;
}

void setRectangleFill(Rectangle rectangle, char fill[25]){
    RectangleStruct *rectangle_aux = (RectangleStruct *) rectangle;

    strcpy(rectangle_aux->fill, fill);
}

void setRectangleStroke(Rectangle rectangle, char stroke[25]){
    RectangleStruct *rectangle_aux = (RectangleStruct *) rectangle;

    strcpy(rectangle_aux->stroke, stroke);
}

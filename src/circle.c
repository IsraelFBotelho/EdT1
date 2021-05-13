#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "circle.h"

typedef struct circleStruct{
    double x;
    double y;
    double r;
    char id[30];
    char fill[25];
    char stroke[25];
}CircleStruct;

Circle createCircle(double x, double y, double r, char id[30], char fill[25], char stroke[25]){

    CircleStruct *new = (CircleStruct *) malloc(sizeof(CircleStruct));

    new->x = x;
    new->y = y;
    new->r = r;
    strcpy(new->id, id);
    strcpy(new->fill, fill);
    strcpy(new->stroke, stroke);
    
    return new;
}

void endCircle(Circle circle){
    CircleStruct *circle_aux = (CircleStruct *) circle;
    free(circle_aux);
}

void endAllCircle(List list, int swList){

    for(Node *aux = getFirst(list, swList); aux; aux = getNext(list, aux, swList)){
        endCircle(getInfo(aux, swList));
    }
}

double getCircleX(Circle circle){
    CircleStruct *circle_aux = (CircleStruct *) circle;

    return circle_aux->x;
}

double getCircleY(Circle circle){
    CircleStruct *circle_aux = (CircleStruct *) circle;

    return circle_aux->y;
}

double getCircleR(Circle circle){
    CircleStruct *circle_aux = (CircleStruct *) circle;

    return circle_aux->r;
}

char* getCircleId(Circle circle){
    CircleStruct *circle_aux = (CircleStruct *) circle;

    return circle_aux->id;
}

char* getCircleFill(Circle circle){
    CircleStruct *circle_aux = (CircleStruct *) circle;

    return circle_aux->fill;
}

char* getCircleStroke(Circle circle){
    CircleStruct *circle_aux = (CircleStruct *) circle;

    return circle_aux->stroke;
}
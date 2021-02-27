#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "qry.h"
#include "list.h"
#include "rectangle.h"
#include "path.h"
#include "svg.h"

void setOverlapColor(Rectangle rect1, Rectangle rect2);
int isOverlapped(Rectangle rect1, Rectangle rect2);

void readQry(char *path, char *nameQry, char *nameGeo, List list, int swList){

    char id[30], command[30];
    int k;
    double x, y, height, width;

    char* fullPathQry = catPath(path, nameQry);

    FILE *qry = fopen(fullPathQry, "r");

    if(qry == NULL){
        printf("\nArquivo .qry nao foi encontrado");
        free(fullPathQry);
        return;
    }

    while(!feof(qry)){
        fscanf(qry,"%s",command);

        if(strcmp(command, "tp") == 0){

        }else if(strcmp(command, "tpr") == 0){

        }else if(strcmp(command, "dpi") == 0){

        }else if(strcmp(command, "dr") == 0){
            
        }else if(strcmp(command, "bbi") == 0){

        }else if(strcmp(command, "bbid") == 0){

        }else if(strcmp(command, "iid") == 0){

        }else if(strcmp(command, "ddid") == 0){
            
        }
    }


    free(fullPathQry);
}

void tpCommand(List list, int swList){
    for(Node *aux = getFirst(list,swList); aux;){
        int test = 1;
        for(Node *aux2 = getNext(list,aux,swList); aux2; aux2 = getNext(list,aux2,swList)){
            if(isOverlapped(getInfo(aux, swList),getInfo(aux2, swList))){
                setOverlapColor(getInfo(aux,swList),getInfo(aux2,swList));
            }
        }
        for(Node *aux2 = getFirst(list,swList); aux2; aux2 = getNext(list,aux2,swList)){
            if(isOverlapped(getInfo(aux,swList), getInfo(aux2, swList)) && aux != aux2){
                test = 0;
                break;
            }
        }
        if(test && getInfo(aux,swList)){
            Node *aux2 = aux;
            aux = getNext(list,aux,swList);
            Rectangle rect = getInfo(aux2,swList);
            endRectangle(rect);
            removeNode(list, aux2, swList);
        }else{
            aux = getNext(list,aux,swList);
        }
    }
}

void setOverlapColor(Rectangle rect1, Rectangle rect2){

    char color[30];

    int r = rand() % 10;

    switch(r){
        case 1:
            strcpy(color,"lightcyan");
            break;
        case 2:
            strcpy(color,"lightgoldenrodyellow");
            break;
        case 3:
            strcpy(color,"lightgrey");
            break;
        case 4:
            strcpy(color,"lightsalmon");
            break;
        case 5:
            strcpy(color,"lightcoral");
            break;
        case 6:
            strcpy(color,"lightskyblue");
            break;
        case 7:
            strcpy(color,"lightyellow");
            break;
        case 8:
            strcpy(color,"lightpink");
            break;
        case 9:
            strcpy(color,"lightseagreen");
            break;
        case 10:
            strcpy(color,"lightsteelblue");
            break;
        default:
            strcpy(color,"black");
            break;
    }

    setRectangleFill(rect1, color);
    setRectangleFill(rect2, color);
}

int isOverlapped(Rectangle rect1, Rectangle rect2){

    if(!rect1 || !rect2){
        return 0;
    }

    double x1, x2, w1, w2, h1, h2, y1, y2;

        x1 = getRectangleX(rect1);
        x2 = getRectangleX(rect2);
        y1 = getRectangleY(rect1);
        y2 = getRectangleY(rect2);
        w1 = getRectangleWidth(rect1);
        w2 = getRectangleWidth(rect2);
        h1 = getRectangleHeight(rect1);
        h2 = getRectangleHeight(rect2);

        if((x1 <= x2 && x1 + h1 >= x2) || (x2 <= x1 && x2 + h2 >= x1)){
            if((y1 <= y2 && y1 + w1 >= y2) || (y2 <= y1 && y2 + w2 >= y1)){
                return 1;
            }
        }
        return 0;
}
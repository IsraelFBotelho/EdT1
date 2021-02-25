#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "qry.h"
#include "list.h"
#include "rectangle.h"
#include "path.h"

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

void tpCommand(List list, char *nameQry, char *nameGeo, int swList){

    char tp[getListSize(list,swList)][30];
    int size = 0;
    
    for(Node aux = getFirst(list, swList); aux; aux = getNext(list, aux, swList)){
        for(Node aux2 = getNext(list, aux, swList); aux2; aux2 = getNext(list, aux2, swList)){
            Rectangle rect1 = getInfo(aux,swList);
            Rectangle rect2 = getInfo(aux2, swList);

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
                    strcpy(tp[size],getRectangleId(rect1));
                    size++;
                    strcpy(tp[size],getRectangleId(rect2));
                    size++;
                    printf("Chegou aqui\n");
                    break;
                }
            }
        }
    }
}
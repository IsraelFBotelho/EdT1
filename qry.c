#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "qry.h"
#include "list.h"
#include "rectangle.h"
#include "path.h"
#include "svg.h"

FILE *getTxtFile(char* nameArq, char* pathOut){
    char t[] = "txt";
    char* nameTxt = t;
    char *nameArqExtr =(char *) extractName(nameArq);
    char *nameArqTxt = insertExtension(nameArqExtr, nameTxt);
    char *fullPathTxt = catPath(pathOut, nameArqTxt);

    FILE *txt = fopen(fullPathTxt, "w");

    if(!txt){
        printf("Erro na criacao do TXT!!\n");
        free(fullPathTxt);
        exit(1);
    }

    free(nameArqExtr);
    free(nameArqTxt);
    free(fullPathTxt);
    return txt;
    
}

char *getQryFileName(char* fullNameGeo, char* nameQry){
    char* nameGeo = extractName(fullNameGeo);
    char* fullName = malloc((strlen(nameGeo) + strlen(nameQry) + 2) *sizeof(char));
    sprintf(fullName,"%s-%s",nameGeo,nameQry);

    free(nameGeo);
    return fullName;
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

        if((x1 <= x2 && x1 + w1 >= x2) || (x2 <= x1 && x2 + w2 >= x1)){
            if((y1 <= y2 && y1 + h1 >= y2) || (y2 <= y1 && y2 + h2 >= y1)){
                return 1;
            }
        }
        return 0;
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

void tpCommand(List list, int swList, FILE* txt){
    Node *aux = getFirst(list,swList);


    while(aux){
        int test = 1;
        for(Node *aux2 = getNext(list,aux,swList); aux2; aux2 = getNext(list,aux2,swList)){
            if(isOverlapped(getInfo(aux, swList),getInfo(aux2, swList))){
                setOverlapColor(getInfo(aux,swList),getInfo(aux2,swList));
                fprintf(txt, "%s %s\n", getRectangleId(getInfo(aux,swList)), getRectangleId(getInfo(aux2,swList)));
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

void readQry(char *pathIn,char* pathOut ,char *nameQry, char *nameGeo, List list, int swList){

    if(!nameQry){
        return;
    }

    char id[30], command[30];
    int k;
    double x, y, height, width;

    char* fullPathQry = catPath(pathIn, nameQry);

    FILE *qry = fopen(fullPathQry, "r");

    if(qry == NULL){
        printf("\nArquivo .qry nao foi encontrado");
        free(fullPathQry);
        return;
    }

    char* fullNameQry = getQryFileName(nameGeo,nameQry);

    FILE *txt = getTxtFile(fullNameQry, pathOut);

    while(!feof(qry)){
        fscanf(qry,"%s",command);

        if(strcmp(command, "tp") == 0){
            fscanf(qry,"\n");
            fprintf(txt,"tp\n");
            tpCommand(list, swList, txt);
            
        }else if(strcmp(command, "tpr") == 0){

        }else if(strcmp(command, "dpi") == 0){

        }else if(strcmp(command, "dr") == 0){
            
        }else if(strcmp(command, "bbi") == 0){

        }else if(strcmp(command, "bbid") == 0){

        }else if(strcmp(command, "iid") == 0){

        }else if(strcmp(command, "ddid") == 0){
            
        }
    }

    writeSvg(list, pathOut, fullNameQry, swList);

    fclose(txt);
    free(fullNameQry);
    free(fullPathQry);
    fclose(qry);
}
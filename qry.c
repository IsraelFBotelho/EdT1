#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "qry.h"
#include "list.h"

void readQry(char *path, char* name, List list, int swList){

    char id[30], command[30];
    int k;
    double x, y, height, width;

    char* fullPathQry = catPath(path, name);

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
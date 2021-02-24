#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "rectangle.h"
#include "path.h"

void readGeo(char* path, char* name, List *list, int swList){
    double x, y, width, height;
    char id[30], stroke[25] = "black", fill[25] = "black";
    char command[30];
    int nx = 0;

    char* fullPathGeo = catPath(path, name);

printf("%s\n%s\n%s",path,name,fullPathGeo);

    FILE *geo = fopen(fullPathGeo,"r");

    if(geo == NULL){
        printf("Arquivo .geo nao encontrado!!\n");
        free(fullPathGeo);
        exit(1);
    }

    if(!swList){
        fscanf(geo, "%s", command);
        if(strcmp(command, "nx") == 0){
            fscanf(geo,"%d", &nx);
        }
    }
    *list = createList(nx, swList);

    while(!feof(geo)){

        fscanf(geo,"%s", command);

        if(strcmp(command, "cc") == 0){
            fscanf(geo, "%s\n", stroke);
        }else if(strcmp(command, "cp") == 0){
            fscanf(geo, "%s\n", fill);
        }else if(strcmp(command, "r") == 0){
            fscanf(geo,"%s %lf %lf %lf %lf\n", id, &x, &y, &width, &height);
            Info aux = createRectangle(x, y, height, width, id, fill, stroke);
            insertElement(*list, aux, swList);
        }
    }
    printf("%d",getListSize(*list, swList));
    free(fullPathGeo);
    fclose(geo);
}
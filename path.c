#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "path.h"


char* extractName(char* path){
    int b = -1, d = 0;
    int size = (int) strlen(path);

    for(int i = 0; i < size ; i++){
        if(path[i] == '/'){
            b = i;

        } else if(path[i] == '.'){
            d = i;
        }
    }

    if(b == -1 && d == 0){
        char * name = malloc((strlen(path) + 1) * sizeof(char));
        strcpy(name, path);
        return name;
    }

    char *name = malloc((strlen(path) - b + 1) * sizeof(char));

    strncpy(name, &(path[b+1]), (d - 1) - b);
    printf("\n\n%s\n\n\n",name);

    return name;
}

char* catPath(char* path1, char* path2){

    if(!path1){
        char * fullPath = (char *) malloc((strlen(path2) + 1) * sizeof(char));
        strcpy(fullPath, path2);
        return fullPath;
    }else if(!path2){
        char * fullPath = (char *) malloc((strlen(path1) + 1) * sizeof(char));
        strcpy(fullPath, path1);
        return fullPath;
    }

    char * fullPath;
    printf("%s",path1);

    if(path1[strlen(path1) - 1] != '/'){
        fullPath = (char *) malloc((strlen(path1) + strlen(path2) + 2) * sizeof(char));
        sprintf(fullPath,"%s/%s",path1,path2);
    }else{
        fullPath = (char *) malloc((strlen(path1) + strlen(path2) + 1) * sizeof(char));
        sprintf(fullPath,"%s%s",path1,path2);
    }
    return fullPath;
}

char* extractExtension(char* path){
    int d;
    int size = (int) strlen(path);

    for(int i = 0; i < size ; i++){
        if(path[i] == '.'){
            d = i;
            break;
        }
    }
    char *extension = (char *) malloc((strlen(path) - d + 1) * sizeof(char));
    strcpy(extension, &(path[d + 1]));
    printf("%s",extension);
    return extension;
}

char* insertExtension(char* name, char* extension){

    if(!name || !extension){
        return NULL;
    }

    char *fullFile = (char *) malloc((strlen(name) + strlen(extension) + 2) * sizeof(char));
    sprintf(fullFile,"%s.%s",name, extension);

    return fullFile;
}
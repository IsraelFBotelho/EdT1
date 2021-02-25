#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "path.h"


char* extractName(char* path){
    char* name = NULL;

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
        name = (char *) malloc((strlen(path) + 1) * sizeof(char));
        strcpy(name, path);
        return name;
    }

    name = (char *) malloc((strlen(path) - (d - 1) - b + 1) * sizeof(char));

    strncpy(name, &(path[b+1]),((d - 1) - b + 1));
    int siz = (int) strlen(path) - d - 1 - b + 1;
    name[siz] = '\0';
    return name;
}

char* catPath(char* path1, char* path2){
    char * fullPath;

    if(!path1){
        fullPath = (char *) malloc((strlen(path2) + 1) * sizeof(char));
        strcpy(fullPath, path2);
        return fullPath;
    }else if(!path2){
        char * fullPath = (char *) malloc((strlen(path1) + 1) * sizeof(char));
        strcpy(fullPath, path1);
        return fullPath;
    }else if(!path1 && !path2){
        return NULL;
    }

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
    char *extension = NULL;
    if(!path){
        return extension;
    }

    int d;
    int size = (int) strlen(path);

    for(int i = 0; i < size ; i++){
        if(path[i] == '.'){
            d = i;
            break;
        }
    }
    extension = (char *) malloc((strlen(path) - d + 1) * sizeof(char));
    strcpy(extension, &(path[d + 1]));
    return extension;
}

char* insertExtension(char* name, char* extension){
    char * fullFile = NULL;

    if(!name || !extension){
        return fullFile;
    }

    fullFile = (char *) malloc((strlen(name) + strlen(extension) + 2) * sizeof(char));
    sprintf(fullFile,"%s.%s",name, extension);

    return fullFile;
}
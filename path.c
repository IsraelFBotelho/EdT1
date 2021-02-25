#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "path.h"


char* extractName(char* path_aux){

    char * path = (char *) malloc((strlen(path_aux) + 1) *sizeof(char));
    strcpy(path,path_aux);

    char *name = NULL;

    name = strchr(path, '/') != NULL ? strrchr(path, '/') + 1 : path;
    name = strtok(name, ".");

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

char* insertExtension(char* name, char* extension){
    char * fullFile = NULL;

    if(!name || !extension){
        return fullFile;
    }

    fullFile = (char *) malloc((strlen(name) + strlen(extension) + 2) * sizeof(char));
    sprintf(fullFile,"%s.%s",name, extension);

    return fullFile;
}
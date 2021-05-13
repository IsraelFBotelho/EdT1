#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "argv.h"

void readArgv(int argc, char** argv, char** pathOut, char** pathIn, char** nameArqGeo, char** nameArqQry, int* swList, int* swAnalysis, char** nameArqAnalysis, char ** titleAnalysys){

    int i = 1;

    while(i < argc){
        if(strcmp("-f", argv[i]) == 0){
            i++;
            *nameArqGeo = (char *) malloc((strlen(argv[i])+ 1) * sizeof(char));
            strcpy(*nameArqGeo, argv[i]);

        }else if(strcmp("-o", argv[i]) == 0){
            i++;
            *pathOut = (char *) malloc((strlen(argv[i]) + 1) * sizeof(char));
            strcpy(*pathOut, argv[i]);

        }else if(strcmp("-e", argv[i]) == 0){
            i++;
            *pathIn = (char *) malloc((strlen(argv[i]) + 1) * sizeof(char));
            strcpy(*pathIn, argv[i]);

        }else if(strcmp("-q", argv[i]) == 0){
            i++;
            *nameArqQry = (char *) malloc((strlen(argv[i]) + 1) * sizeof(char));
            strcpy(*nameArqQry, argv[i]);
        }else if(strcmp("-ib", argv[i]) == 0){

            *swAnalysis = 1;

        }else if(strcmp("-cb", argv[i]) == 0){

            *swAnalysis = 2;

        }else if(strcmp("-fb", argv[i]) == 0){
            *swAnalysis = 3;
            
            i++;
            *nameArqAnalysis = (char *) malloc((strlen(argv[i]) + 1) * sizeof(char));
            strcpy(*nameArqAnalysis, argv[i]);
            i++;
            *titleAnalysys = (char *) malloc((strlen(argv[i]) + 1) * sizeof(char));
            strcpy(*titleAnalysys, argv[i]);

        }else if(strcmp("-lse", argv[i]) == 0){
            *swList = 0;

        }else if(strcmp("-ldd", argv[i]) == 0){
            *swList = 1;
        }
        i++;
    }

    if(!*pathOut || !*nameArqGeo){
        printf("Caminho de saida e/ou nome do arquivo .geo nao encontrado!\n");
        exit(1);
    }

}
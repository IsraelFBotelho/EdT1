#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "path.h"


void startAnalysis(char* pathOut, int numberVisit, int listSize){
    char* fullPath = catPath(pathOut, "analysis.txt");
    FILE *txt = fopen(fullPath, "w");

    if(!txt){
        printf("Relatorio nao foi possivel ser criado!");
        free(fullPath);
        return;
    }

    fprintf(txt, "size/visit %d %d\n", listSize, numberVisit);    

    fclose(txt);
    free(fullPath);
}

void continueAnalysis(char* pathOut, int numberVisit, int listSize){
    char* fullPath = catPath(pathOut, "analysis.txt");
    FILE *txt = fopen(fullPath, "a");

    if(!txt){
        printf("Relatorio nao foi possivel ser continuado!");
        free(fullPath);
        return;
    }

    fprintf(txt, "size/visit %d %d\n", listSize, numberVisit);    

    fclose(txt);
    free(fullPath);
}


void endAnalysis(char* pathOut, int numberVisit, int listSize, char* titleAnalysis, char* nameArqAnalysis){
    double x1 = 0, x2 = numberVisit, y1 = 0, y2 = listSize;
    double visit, size;
    char* fullPath = catPath(pathOut, "analysis.txt");
    FILE *txt = fopen(fullPath, "r");

    free(fullPath);
    char *nameArq = insertExtension(nameArqAnalysis, "svg");
    fullPath = catPath(pathOut,nameArq);
    FILE *svg = fopen(fullPath, "w");

    if(!svg){
        printf("Erro ao formar o svg!!\n");
        return;
    }

    fprintf(svg,"<svg xmlns=\"http://www.w3.org/2000/svg\">\n");

    fprintf(svg, "\t<circle cx=\"%lf\" cy=\"%lf\" r=\"10\" stroke=\"black\" stroke-width=\"3\" fill=\"red\" />\n", x2, y2);
    fprintf(svg, "\t<rect x=\"0\" y=\"0\" width=\"%lf\" height=\"%lf\" stroke=\"black\" fill=\"none\" stroke-dasharray=\"1\"/>\n", x2, y2);

    if(!txt){
        printf("Arquivo temporario nao encontrado");
    }else{
        char command[15];
        while(!feof(txt)){
            fscanf(txt, "%s", command);
            if(strcmp(command, "size/visit") == 0){
                fscanf(txt, "%lf %lf\n", &size, &visit);
                fprintf(svg, "\t<circle cx=\"%lf\" cy=\"%lf\" r=\"10\" stroke=\"black\" stroke-width=\"3\" fill=\"red\" />\n", visit, size);
                fprintf(svg, "\t<rect x=\"0\" y=\"0\" width=\"%lf\" height=\"%lf\" stroke=\"black\" fill=\"none\" stroke-dasharray=\"1\"/>\n", visit, size);
                if(visit > x2){
                    x2 = visit;
                }
                if(size > y2){
                    y2 = size;
                }
            }
        }
    }

    fprintf(svg, "\t<line x1=\"0\" y1=\"0\" x2=\"%lf\" y2=\"0\" style=\"stroke:rgb(255,0,0);stroke-width:2\"/>\n", x2);
    fprintf(svg, "\t<line x1=\"0\" y1=\"0\" x2=\"0\" y2=\"%lf\" style=\"stroke:rgb(255,0,0);stroke-width:2\"/>\n", y2);

    free(fullPath);
    fullPath = catPath(pathOut, "analysis.txt");
    remove(fullPath);


    fprintf(svg, "</svg>");
    fclose(svg);
    free(fullPath);
    free(nameArq);
}

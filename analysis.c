#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "path.h"
/*
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
    int x1 = 0, x2 = numberVisit, y1 = 0, y2 = listSize;
    int visit, size;
    char* fullPath = catPath(pathOut, "analysis.txt");
    FILE *txt = fopen(fullPath, "a");

    free(fullPath);
    char *nameArq = insertExtension(nameArqAnalysis, "svg");
    fullPath = catPath(pathOut,nameArq);
    FILE *svg = fopen(fullPath, "w");

    if(!svg){
        printf("Erro ao formar o svg!!\n");
        return;
    }

    fprintf(svg,"<svg xmlns=\"http://www.w3.org/2000/svg\">\n");

    if(txt){
        char command[15];
        while(!feof(txt)){
            fscanf(txt, "%s", command);
            if(strcmp(command, "size/visit") == 0){
                fscanf(txt, "%d %d\n", &size, &visit);
                if(size > y2){
                    y2 = size;
                }
                if(visit > x2){
                    x2 = visit;
                }
            }
        }
    }


    fprintf(svg, "\t<line x1=\"0\" y1=\"0\" x2=\"0\" y2=\"%d\" width=\"2\"/>", y2);

    fprintf(svg, "\t<line x1=\"0\" y1=\"0\" x2=\"%d\" y2=\"0\" width=\"2\"/>", x2);

    fprintf(svg, "\t<circle cx=\"%d\" cy=\"%d\" r=\"2\" stroke=\"black\" stroke-width=\"3\" fill=\"red\" />", numberVisit, (y2 - listSize));

    fprintf(svg, "\t<rect x=\"0\" y=\"%d\" width=\"%lf\" height=\"%lf\" stroke=\"black\" fill=\"none\"/>\n",);

    rewind(txt);

    if(!txt){
        printf("Arquivo temporario nao encontrado");
    }else{
        char command[15];
        while(!feof(txt)){
            fscanf(txt, "%s", command);
            if(strcmp(command, "size/visit") == 0){
                fscanf(txt, "%d %d\n", &size, &visit);
                fprintf(svg, "\t<circle cx=\"%d\" cy=\"%d\" r=\"2\" stroke=\"black\" stroke-width=\"3\" fill=\"red\" />", visit, (y2 - size));
            }
        }
    }
    free(fullPath);
    char* fullPath = catPath(pathOut, "analysis.txt");
    remove(fullPath);


    fprintf(svg, "</svg>");
}
*/
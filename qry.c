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

int isInside(Rectangle rect, double x, double y){
    if(!rect){
        return 0;
    }
    double x_aux = getRectangleX(rect);
    double y_aux = getRectangleY(rect);
    double h_aux = getRectangleHeight(rect);
    double w_aux = getRectangleWidth(rect);

    if(x >= x_aux && x <= x_aux + w_aux){
        if(y >= y_aux && y <= y_aux + h_aux){
            return 1;
        }
    }
    return 0;
}

int isInsideOf(Rectangle rect1, Rectangle rect2){

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

    if(x1 <= x2 && ((x1 + w1) >= (x2 + w2))){
        if(y1 <= y2 && ((y1 + h1) >= (y2 + h2))){
            return 1;
        }
    }
    return 0;
}

int isCovered(Rectangle rect, double x, double y, double height, double width){
    if(!rect){
        return 0;
    }
    double x_aux = getRectangleX(rect);
    double y_aux = getRectangleY(rect);
    double h_aux = getRectangleHeight(rect);
    double w_aux = getRectangleWidth(rect);

    if(x_aux >= x && (x + width) >= (x_aux + w_aux)){
        if(y_aux >= y && (y + height) >= (y_aux + h_aux)){
            return 1;
        }
    }
    return 0;
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

    if((x1 < x2 && x1 + w1 > x2) || (x2 < x1 && x2 + w2 > x1)){
        if((y1 < y2 && y1 + h1 > y2) || (y2 < y1 && y2 + h2 > y1)){
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
            strcpy(color,"cyan");
            break;
        case 2:
            strcpy(color,"yellow");
            break;
        case 3:
            strcpy(color,"blue");
            break;
        case 4:
            strcpy(color,"crimson");
            break;
        case 5:
            strcpy(color,"coral");
            break;
        case 6:
            strcpy(color,"firebrick");
            break;
        case 7:
            strcpy(color,"magenta");
            break;
        case 8:
            strcpy(color,"lawngreen");
            break;
        case 9:
            strcpy(color,"fuchsia");
            break;
        case 10:
            strcpy(color,"indigo");
            break;
        default:
            strcpy(color,"deepskyblue");
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
            setRectangleFill(getInfo(aux, swList), "lightgrey");
            setRectangleStroke(getInfo(aux, swList), "lightgrey");
        }
        aux = getNext(list,aux,swList);
        
    }
}

void tprCommand(List list, int swList, FILE *txt, double x, double y, double height, double width){
    Node *aux = getFirst(list, swList);

    while(aux){
        if(!isCovered(getInfo(aux, swList), x, y, height, width)){
            setRectangleFill(getInfo(aux, swList), "lightgrey");
            setRectangleStroke(getInfo(aux, swList), "lightgrey");
        }
        aux = getNext(list,aux,swList);
        
    }

    aux = getFirst(list,swList);


    while(aux){
        int test = 1;
        if(isCovered(getInfo(aux, swList), x, y, height, width)){
            for(Node *aux2 = getNext(list,aux,swList); aux2; aux2 = getNext(list,aux2,swList)){
                if(isOverlapped(getInfo(aux, swList),getInfo(aux2, swList)) && isCovered(getInfo(aux2, swList), x, y, height, width)){
                    setOverlapColor(getInfo(aux,swList),getInfo(aux2,swList));
                    fprintf(txt, "%s %s\n", getRectangleId(getInfo(aux,swList)), getRectangleId(getInfo(aux2,swList)));
                }
            }
            for(Node *aux2 = getFirst(list,swList); aux2; aux2 = getNext(list,aux2,swList)){
                if(isOverlapped(getInfo(aux,swList), getInfo(aux2, swList)) && (aux != aux2 && isCovered(getInfo(aux2, swList), x, y, height, width))){
                    test = 0;
                    break;
                }
            }
            if(test && getInfo(aux,swList)){
                setRectangleFill(getInfo(aux, swList), "lightgrey");
                setRectangleStroke(getInfo(aux, swList), "lightgrey");
            }
        }
        aux = getNext(list,aux,swList);
    }
}

void dpiCommand(List list, int swList, double x, double y, FILE *txt){

    Node *aux = getFirst(list, swList);

    while(aux){
        if(isInside(getInfo(aux, swList), x, y)){
            fprintf(txt, "%s\n", getRectangleId(getInfo(aux, swList)));
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

void drCommand(List list, int swList, char* id, FILE *txt){
    Rectangle rect1 = NULL;
    for(Node *aux = getFirst(list, swList); aux; aux = getNext(list, aux, swList)){
        if(strcmp(id, getRectangleId(getInfo(aux, swList))) == 0){
            rect1 = getInfo(aux, swList);
            break;
        }
    }
    Node *aux = getFirst(list, swList);

    while(aux){
        if(isInsideOf(rect1, getInfo(aux, swList)) && getInfo(aux, swList) != rect1){
            fprintf(txt, "%s\n", getRectangleId(getInfo(aux, swList)));
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

void bbiCommand(List list, List list_bb, int swList, double x, double y, FILE *txt){
    double x_aux = 0, y_aux = 0, w_aux = 0, h_aux = 0, x2_aux = 0, y2_aux = 0;
    int first = 1;

    for(Node *aux = getFirst(list, swList); aux; aux = getNext(list, aux, swList)){
        if(isInside(getInfo(aux, swList), x, y)){


            char color_fill[25];
            char color_stroke[25];
            strcpy(color_fill, getRectangleFill(getInfo(aux, swList)));
            strcpy(color_stroke, getRectangleStroke(getInfo(aux, swList)));

            fprintf(txt, "%s %s %s\n", getRectangleId(getInfo(aux, swList)), color_fill, color_stroke);

            setRectangleFill(getInfo(aux, swList), color_stroke);
            setRectangleStroke(getInfo(aux, swList), color_fill);


            if(first){

                x_aux = getRectangleX(getInfo(aux, swList));
                y_aux = getRectangleY(getInfo(aux, swList));
                x2_aux = getRectangleX(getInfo(aux, swList)) + getRectangleWidth(getInfo(aux, swList));
                y2_aux = getRectangleY(getInfo(aux, swList)) + getRectangleHeight(getInfo(aux, swList));
                first = 0;

            }else{

                if((getRectangleWidth(getInfo(aux, swList)) + getRectangleX(getInfo(aux, swList))) > x2_aux){
                    x2_aux = (getRectangleWidth(getInfo(aux, swList)) + getRectangleX(getInfo(aux, swList)));
                }

                if((getRectangleHeight(getInfo(aux, swList)) + getRectangleY(getInfo(aux, swList))) > y2_aux){
                    y2_aux = (getRectangleHeight(getInfo(aux, swList)) + getRectangleY(getInfo(aux, swList)));
                }

                if(getRectangleX(getInfo(aux, swList)) < x_aux){
                    x_aux = getRectangleX(getInfo(aux, swList));
                }

                if(getRectangleY(getInfo(aux, swList)) < x_aux){
                    y_aux = getRectangleY(getInfo(aux, swList));
                }


            }
        }
    }
    h_aux = y2_aux - y_aux;
    w_aux = x2_aux - x_aux;
    Rectangle rect = createRectangle(x_aux, y_aux, h_aux, w_aux, "Bouding box", "@", "red");
    insertElement(list_bb, rect, 1);
}

void bbidCommand(List list, List list_bb, int swList, char* id, FILE *txt){
    Rectangle rect = NULL;
    for(Node *aux = getFirst(list, swList); aux; aux = getNext(list, aux, swList)){
        if(strcmp(getRectangleId(getInfo(aux, swList)), id ) == 0){
            rect = getInfo(aux, swList);
            break;
        }
    }

    if(!rect){
        return;
    }

    for(Node *aux = getFirst(list, swList); aux; aux = getNext(list, aux, swList)){
        if(isInsideOf(rect, getInfo(aux, swList))){

            char color_fill[25];
            char color_stroke[25];
            strcpy(color_fill, getRectangleFill(getInfo(aux, swList)));
            strcpy(color_stroke, getRectangleStroke(getInfo(aux, swList)));

            fprintf(txt, "%s %s %s\n", getRectangleId(getInfo(aux, swList)), color_fill, color_stroke);

            setRectangleFill(getInfo(aux, swList), color_stroke);
            setRectangleStroke(getInfo(aux, swList), color_fill);

        }
    }

    double x_aux = getRectangleX(rect);
    double y_aux = getRectangleY(rect);
    double h_aux = getRectangleHeight(rect);
    double w_aux = getRectangleWidth(rect);
    Rectangle rect1 = createRectangle(x_aux, y_aux, h_aux, w_aux, "Bouding box", "@", "red");
    insertElement(list_bb, rect1, 1);
}

void iidCommand(List list, int swList, char *id, int k, FILE *txt){
    Node node_aux = NULL;
    int id_n = 0;

    for(Node *aux = getFirst(list, swList); aux; aux = getNext(list, aux, swList)){
        if(strcmp(getRectangleId(getInfo(aux, swList)), id) == 0){
            node_aux = aux;
            break;
        }
        id_n++;
    }

    if(!node_aux){
        return;
    }

    if(k > 0){
        node_aux = getNext(list, node_aux, swList);
        while(node_aux && k > 0){
            Rectangle rect = getInfo(node_aux, swList);
            fprintf(txt, "Id=%s X=%lf Y=%lf Height=%lf Width =%lf Fill=%s Stroke=%s\n", getRectangleId(rect), getRectangleX(rect), getRectangleY(rect), getRectangleHeight(rect), getRectangleWidth(rect), getRectangleFill(rect), getRectangleStroke(rect));
            node_aux = getNext(list, node_aux, swList);
            k--;
        }
    }else if(k < 0){
        int i = 0;
        for(Node *aux = getFirst(list, swList); aux; aux = getNext(list, aux, swList)){
            if(i >= id_n + k && i < id_n){
                Rectangle rect = getInfo(aux, swList);
                fprintf(txt, "Id=%s X=%lf Y=%lf Height=%lf Width =%lf Fill=%s Stroke=%s\n", getRectangleId(rect), getRectangleX(rect), getRectangleY(rect), getRectangleHeight(rect), getRectangleWidth(rect), getRectangleFill(rect), getRectangleStroke(rect));
            }
        i++;
        }
    }
}

void diidCommand(List list, int swList, char *id, int k, FILE *txt){
    Node node_aux = NULL;
    int id_n = 0;

    for(Node *aux = getFirst(list, swList); aux; aux = getNext(list, aux, swList)){
        if(strcmp(getRectangleId(getInfo(aux, swList)), id) == 0){
            node_aux = aux;
            break;
        }
        id_n++;
    }

    if(!node_aux){
        return;
    }

    if(k > 0){
        node_aux = getNext(list, node_aux, swList);
        while(node_aux && k > 0){
            Rectangle rect = getInfo(node_aux, swList);
            fprintf(txt, "Id=%s X=%lf Y=%lf Height=%lf Width =%lf Fill=%s Stroke=%s\n", getRectangleId(rect), getRectangleX(rect), getRectangleY(rect), getRectangleHeight(rect), getRectangleWidth(rect), getRectangleFill(rect), getRectangleStroke(rect));
            Node *aux2 = node_aux;
            node_aux = getNext(list,node_aux,swList);
            Rectangle rect2 = getInfo(aux2,swList);
            endRectangle(rect2);
            removeNode(list, aux2, swList);
            k--;
        }
    }else if(k < 0){
        int i = 0;
        node_aux = getFirst(list, swList);
        while(node_aux){
            if(i >= id_n + k && i < id_n){
                Rectangle rect = getInfo(node_aux, swList);
                fprintf(txt, "Id=%s X=%lf Y=%lf Height=%lf Width =%lf Fill=%s Stroke=%s\n", getRectangleId(rect), getRectangleX(rect), getRectangleY(rect), getRectangleHeight(rect), getRectangleWidth(rect), getRectangleFill(rect), getRectangleStroke(rect));
                Node *aux2 = node_aux;
                node_aux = getNext(list,node_aux,swList);
                Rectangle rect2 = getInfo(aux2,swList);
                endRectangle(rect2);
                removeNode(list, aux2, swList);
            }else{
                node_aux = getNext(list, node_aux, swList);
            }
        i++;
        }
    }
}


void readQry(char *pathIn,char* pathOut ,char *nameQry, char *nameGeo, List list, int swList){

    if(!nameQry){
        return;
    }

    char id[30], command[30];
    int k = 0;
    double x = 0, y = 0, height = 0, width = 0;

    char* fullPathQry = catPath(pathIn, nameQry);

    FILE *qry = fopen(fullPathQry, "r");

    if(qry == NULL){
        printf("\nArquivo .qry nao foi encontrado");
        free(fullPathQry);
        return;
    }

    char* fullNameQry = getQryFileName(nameGeo,nameQry);

    FILE *txt = getTxtFile(fullNameQry, pathOut);


    List list_bb = createList(0, 1);

    while(!feof(qry)){
        fscanf(qry,"%s",command);

        if(strcmp(command, "tp") == 0){
            fscanf(qry,"\n");
            fprintf(txt,"tp\n");
            tpCommand(list, swList, txt);
            
        }else if(strcmp(command, "tpr") == 0){
            fscanf(qry, "%lf %lf %lf %lf\n", &x, &y, &width, &height);
            fprintf(txt,"tpr\n");
            tprCommand(list, swList, txt, x, y, height, width);

        }else if(strcmp(command, "dpi") == 0){
            fscanf(qry, "%lf %lf\n",&x,&y);
            fprintf(txt,"dpi\n");
            dpiCommand(list, swList, x, y, txt);

        }else if(strcmp(command, "dr") == 0){
            fscanf(qry, "%s\n", id);
            fprintf(txt, "dr\n");
            drCommand(list, swList, id, txt);

        }else if(strcmp(command, "bbi") == 0){
            fscanf(qry, "%lf %lf\n", &x, &y);
            fprintf(txt, "bbi\n");
            bbiCommand(list, list_bb, swList, x, y, txt);

        }else if(strcmp(command, "bbid") == 0){
            fscanf(qry, "%s\n", id);
            fprintf(txt, "bbid\n");
            bbidCommand(list, list_bb, swList, id, txt);

        }else if(strcmp(command, "iid") == 0){
            fscanf(qry, "%s %d\n",id, &k);
            fprintf(txt, "iid\n");
            iidCommand(list, swList, id, k, txt);

        }else if(strcmp(command, "diid") == 0){
            fscanf(qry, "%s %d\n", id, &k);
            fprintf(txt, "diid\n");
            diidCommand(list, swList, id, k, txt);
        }
    }

    writeSvg(list, list_bb, pathOut, fullNameQry, swList);

    endAllRectangle(list_bb, 1);
    endList(list_bb, 1, NULL);
    fclose(txt);
    free(fullNameQry);
    free(fullPathQry);
    fclose(qry);
}
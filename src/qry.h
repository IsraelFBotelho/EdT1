#ifndef __QRY__
#define __QRY__

#include "list.h"
/*
* Le um arquivo qry e gera um SVG com base nas mudanças desse arquivo, as mudanças sao salvas na lista
* Pre: Um char* com o caminho de entrada, Um char* com o caminho de saida, Um char* com o nome do qry,
       Um char* com o nome do geo, Um void* com o endereço da lista, Um int com o swList
* Pos: Nenhum retorno
*/
void readQry(char *pathIn,char* pathOut ,char *nameQry, char *nameGeo, List list, int swList);

#endif

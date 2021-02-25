#ifndef __GEO__
#define __GEO__

#include "list.h"
/*
* Abre e Lê um arquivo .geo, le os seus comandos e armazena as informaçoes em uma lista
* Pre: Um char* com a string do caminho de entrada, Um char* com a string do nome do .geo, Um void* com o endereço da lista, Um int com o swList
* Pos: Nenhum retorno
*/
void readGeo(char* path, char* name, List *list, int swList);

#endif

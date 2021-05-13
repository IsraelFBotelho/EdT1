#ifndef __LIST__
#define __LIST__

typedef void* List;
typedef void* Node;
typedef void* Info;

/*
* Insere um elemento criando um no apos um no informado na lista dinamica
* Pre: Um void* com o endereço da lista, Um void* com o endereço do no, Um void* com o endereço da informaçao
* Pos: Nenhum retorno
*/
void dInsertAfter(List list, Node node, Info info);

/*
* Recupera o no anterior apontado por outro no na lista dinamica
* Pre: Um void* com o endereço do no
* Pos: Um void* com o endereço do no
*/
Node dGetBack(List list, Node node);

/*
* Cria Uma lista dinamica se swList = 1, Cria uma lista estatica se swList = 0
* Pre: Um int com o numero de elementos da lista estatica(se nao for, passar 0), Um int com o swList
* Pos: Retorna um void* com o endereço da lista
*/
List createList(int nx, int swList);

/*
* Encerra uma lista dinamica se swList = 1, Encerra uma lista estatica se swList = 0
* Pre: Um void* com o endereço da lista, Um int com o swList
* Pos: Nenhum retorno
*/
void endList(List list, int swList, int* numberVisits);

/*
* Insere um elemento criando um no na ultima posição da lista dinamica se swList = 1, Insere um elemento criando um no na ultima posição da lista estatica se swList = 0
* Pre: Um void* com o endereço da lista, Um void* com o endereço da informaçao, Um int com o swList
* Pos: Nenhum retorno
*/
void insertElement(List list, Info info, int swList);

/*
* Remove um no informado na lista dinamica se swList = 1, Remove um no informado na lista estatica se swList = 0
* Pre: Um void* com o endereço da lista, Um void* com o endereço do no, Um int com o swList
* Pos: Nenhum retorno
*/
void removeNode(List list, Node node, int swList);

/*
* Recupera um void* de informaçao de um no na lista dinamica se swList = 1, Recupera um void* de informaçao de um no na lista estatica se swList = 0
* Pre: Um void* com o endereço do no, Um int com o swList
* Pos: Um void* com o endereço da informaçao
*/
Info getInfo(Node node, int swList);

/*
* Recupera o proximo no apontado por outro no na lista dinamica se swList = 1, Recupera o proximo no apontado por outro no na lista estatica se swList = 0
* Pre: Um void* com o endereço da lista, Um void* com o endereço do no, Um int com o swList
* Pos: Um void* com o endereço do no
*/
Node getNext(List list, Node node, int swList);

/*
* Recupera o primeiro no de uma lista dinamica se swList = 1, Recupera o primeiro no de uma lista estatica se swList = 0,
* Pre: Um void* com o endereço da lista, Um int com o swList;
* Pos: Um void* com o endereço do no
*/
Node getFirst(List list, int swList);

/*
 Recupera a quantidade de elementos dentro da lista dinamica se swList = 1, Recupera a quantidade de elementos dentro da lista estatica se swList = 0
* Pre: Um void* com o endereço da lista, Um int com o swList
* Pos: Um int com o valor
*/
int getListSize(List list, int swList);

/*
* Recupera a quantidade de visitas relativo a lista dinamica se swList = 1, Recupera a quantidade de visitas relativo a lista estatica se swList = 0
* Pre: Um void* com o endereço da lista, Um int com o swList
* Pos: Um int com o valor
*/
int getListVisit(List list, int swList);

#endif

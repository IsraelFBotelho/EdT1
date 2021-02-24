#ifndef __LIST__
#define __LIST__

typedef void* List;
typedef void* Node;
typedef void* Info;

/*
* Cria Uma lista dinamica duplamente encadeada
* Pre: Nenhum requesito
* Pos: Retorna um void* com o endereço da lista
*/
List dCreateList();

/*
* Encerra uma lista dinamica duplamente encadeada
* Pre: Um void* com o endereço da lista
* Pos: Nenhum retorno
*/
void dEndList(List list);

/*
* Insere um elemento criando um no na ultima posição da lista dinamica
* Pre: Um void* com o endereço da lista, Um void* com o endereço da informaçao
* Pos: Nenhum retorno
*/
void dInsertElement(List list, Info info);

/*
* Insere um elemento criando um no apos um no informado na lista dinamica
* Pre: Um void* com o endereço da lista, Um void* com o endereço do no, Um void* com o endereço da informaçao
* Pos: Nenhum retorno
*/
void dInsertAfter(List list, Node node, Info info);

/*
* Remove um no informado na lista dinamica
* Pre: Um void* com o endereço da lista, Um void* com o endereço do no
* Pos: Nenhum retorno
*/
void dRemoveNode(List list, Node node);

/*
* Recupera um void* de informaçao de um no da lista dinamica
* Pre: Um void* com o endereço do no
* Pos: Um void* com o endereço da informaçao
*/
Info dGetInfo(Node node);

/*
* Recupera o primeiro no de uma lista dinamica
* Pre: Um void* com o endereço da lista
* Pos: Um void* com o endereço do no
*/
Node dGetFirst(List list);

/*
* Recupera o proximo no apontado por outro no na lista dinamica
* Pre: Um void* com o endereço do no
* Pos: Um void* com o endereço do no
*/
Node dGetNext(List list, Node node);

/*
* Recupera o no anterior apontado por outro no na lista dinamica
* Pre: Um void* com o endereço do no
* Pos: Um void* com o endereço do no
*/
Node dGetBack(List list, Node node);

/*
Recupera a quantidade de elementos dentro da lista dinamica
* Pre: Um void* com o endereço da lista
* Pos: Um int com o valor
*/
int dGetListSize(List list);

/*
* Cria uma lista estatica simplesmente encadeada
* Pre: Um int com o tamanho da lista
* Pos: Retorna um void* com o endereço da lista
*/
List sCreateList(int nx);

/*
* Encerra uma lista estatica simplesmente encadeada
* Pre: Um void* com o endereço da lista
* Pos: Nenhum retorno
*/
void sEndList(List slist);

/*
* Insere um elemento ultilizando o proximo endereço da lista
* Pre: Um void* com o endereço da lista, Um void* com o endereço da informaçao
* Pos: Nenhum retorno
*/
void sInsertElement(List slist, Info info);

/*
* Remove um no informado na lista estatica, movendo os outros elementos para a esquerda
* Pre: Um void* com o endereço da lista, Um void* com o endereço do no
* Pos: Nenhum retorno
*/
void sRemoveNode(List slist, Node snode);

/*
* Recupera um void* de informaçao de um no da lista estatica
* Pre: Um void* com o endereço do no
* Pos: Um void* com o endereço da informaçao
*/
Info sGetInfo(Node snode);

/*
* Recupera o primeiro no de uma lista estatica
* Pre: Um void* com o endereço da lista
* Pos: Um void* com o endereço do no
*/
Node sGetFirst(List slist);

/*
* Recupera o no anterior apontado por outro no na lista estatica
* Pre: Um void* com o endereço do no
* Pos: Um void* com o endereço do no
*/
Node sGetNext(List slist, Node snode);

/*
* Recupera a quantidade de elementos dentro da lista estatica
* Pre: Um void* com o endereço da lista
* Pos: Um int com o valor
*/
int sGetListSize(List slist);

List createList(int nx, int swList);

void endList(List list, int swList);

void removeNode(List list, Node node, int swList);

Info getInfo(Node node, int swList);

Node getNext(List list, Node node, int swList);

Node getFirst(List list, int swList);

int getListSize(List list, int swList);

void insertElement(List list, Info info, int swList);

#endif

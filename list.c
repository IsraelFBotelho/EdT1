#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

typedef struct nodeStruct{ 
    Info info;
    struct nodeStruct *next;
    struct nodeStruct *back;
} NodeStruct;

typedef struct listStruct{
    NodeStruct *head;
    NodeStruct *tail;
    int size;
    int visit;
} ListStruct;


typedef struct snodeStruct{
    Info info;
    struct snodeStruct *next;
} SNodeStruct;

typedef struct slistStruct{
    int nx;
    int size;
    int visit;
    SNodeStruct *head;
    SNodeStruct *tail;
    SNodeStruct *array;
} SListStruct;


/*
        Funções de Lista Dinamica Duplamente Encadeada
*/

void dRemoveNode(List list, Node node);


List dCreateList(){
    ListStruct *new = (ListStruct *) malloc(sizeof(ListStruct));

    new->head = NULL;
    new->tail = NULL;
    new->size = 0;
    new->visit = 0;

    return new;
}

void dEndList(List list){
    ListStruct *list_aux = (ListStruct*) list;
    if(list_aux->size != 0){
        NodeStruct *aux;
        while(list_aux->head){
            aux = list_aux->head;
            list_aux->visit++;
            dRemoveNode(list, aux);
        }
    }

    free(list_aux);
    printf("Uma lista foi encerrada!!\n");
}

void dInsertElement(List list, Info info){
    ListStruct *list_aux = (ListStruct *) list;

    NodeStruct *new = (NodeStruct *) malloc(sizeof(NodeStruct));

    if(list_aux->size == 0){
        new->info = info;
        new->next = NULL;
        new->back = NULL;
        list_aux->head = new;
        list_aux->tail = new;
        list_aux->size++;
    }else{
        new->info = info;
        new->next = NULL;
        new->back = list_aux->tail;
        list_aux->tail->next = new;
        list_aux->tail = new;
        list_aux->size++;
    }
}

void dInsertAfter(List list, Node node, Info info){
    ListStruct *list_aux = (ListStruct *) list;
    NodeStruct *node_aux = (NodeStruct *) node;

    NodeStruct *new = (NodeStruct *) malloc(sizeof(NodeStruct));

    if(list_aux->size == 0){
        dInsertElement(list, info);
        return;
    }

    NodeStruct *aux = list_aux->head;
    list_aux->visit++;

    for(int i = 0; i < list_aux->size; i++){
        if(node_aux == aux){
            new->info = info;
            new->next = node_aux->next;
            if(aux->next){
                aux = aux->next;
                list_aux->visit++;
                aux->back = new;
            }
            node_aux->next = new;
            if(list_aux->tail == node_aux)
                list_aux->tail = new;
            list_aux->size++;
            break;
        }
        if(aux->next){
            aux = aux->next;
            list_aux->visit++;
        }
    }
}

void dRemoveNode(List list, Node node){
    ListStruct *list_aux = (ListStruct *) list;
    NodeStruct *node_aux = (NodeStruct *) node;
    

    if(list_aux->size == 0)
        return;

    if(!node_aux){
        return;
    }
       
    NodeStruct *aux;

    if(node_aux->back){
        aux = node_aux->back;
        list_aux->visit++;
        aux->next = node_aux->next;
    }else{
        list_aux->head = node_aux->next;
    }

    if(node_aux->next){
        aux = node_aux->next;
        list_aux->visit++;
        aux->back = node_aux->back;
    }else{
        list_aux->tail = node_aux->back;
    }

    free(node_aux);
    list_aux->size--;
}

Info dGetInfo(Node node){
    NodeStruct *node_aux = (NodeStruct *) node;

    return node_aux->info;
}

Node dGetFirst(List list){
    ListStruct *list_aux = (ListStruct *) list;
    list_aux->visit++;

    return list_aux->head;
}

Node dGetNext(List list, Node node){
    NodeStruct *node_aux = (NodeStruct *) node;
    ListStruct *list_aux = (ListStruct *) list;
    list_aux->visit++;

    return node_aux->next;
}

Node dGetBack(List list, Node node){
    NodeStruct *node_aux = (NodeStruct *) node;
    ListStruct *list_aux = (ListStruct *) list;
    list_aux->visit++;

    return node_aux->back;
}

int dGetListSize(List list){
    ListStruct *list_aux = (ListStruct *) list;

    return list_aux->size;
}

int dGetListVisit(List list){
    ListStruct *list_aux = (ListStruct *) list;

    return list_aux->visit;
}

/*
        Funções de Lista Estatica Simplesmente Encadeada
*/

void sRelocateElement(List slist, Node snode){
    SNodeStruct *snode_aux = (SNodeStruct *) snode;
    SListStruct *slist_aux = (SListStruct *) slist;

    while(snode_aux->next){
        SNodeStruct *aux2 = snode_aux->next;
        slist_aux->visit++;
        snode_aux->info = aux2->info;
        snode_aux = snode_aux->next;
        slist_aux->visit++;
    }
}

List sCreateList(int nx){
    SListStruct *new = (SListStruct *) malloc(sizeof(SListStruct));

    new->nx = nx;
    new->size = 0;
    new->visit = 0;
    new->array = (SNodeStruct *) malloc(nx * sizeof(SNodeStruct));

    new->head = NULL;
    new->tail = NULL;


    return new;

}

void sEndList(List slist){
    SListStruct *slist_aux = (SListStruct *) slist;
    free(slist_aux->array);
    free(slist_aux);
    printf("Lista Estatica Encerrada!!\n");
}

void sInsertElement(List slist, Info info){
    SListStruct *slist_aux = (SListStruct *) slist;

    SNodeStruct *new;

    if(slist_aux->size == 0){
        slist_aux->size++;
        new = &(slist_aux->array[0]);
        slist_aux->head = new;
        slist_aux->tail = new;
        new->info = info;
        new->next = NULL;
    }else{
        slist_aux->size++;
        new = &(slist_aux->array[slist_aux->size - 1]);
        new->info = info;
        new->next = NULL;
        slist_aux->tail->next = new;
        slist_aux->tail = new;
    }
}

void sRemoveNode(List slist, Node snode){
    SListStruct *slist_aux = (SListStruct *) slist;

    if(slist_aux->size == 0){
        return;
    }
    sRelocateElement(slist, snode);
    slist_aux->array[slist_aux->size - 2].next = NULL;
    slist_aux->tail = &(slist_aux->array[slist_aux->size - 2]);
    slist_aux->size--;
}

Info sGetInfo(Node snode){
    SNodeStruct *snode_aux = (SNodeStruct *) snode;

    return snode_aux->info;
}

Node sGetFirst(List slist){
    SListStruct *slist_aux = (SListStruct *) slist;
    slist_aux->visit++;

    return slist_aux->head;
}

Node sGetNext(List slist, Node snode){
    SNodeStruct *snode_aux = (SNodeStruct *) snode;
    SListStruct *slist_aux = (SListStruct *) slist;
    slist_aux->visit++;

    return snode_aux->next;
}

int sGetListSize(List slist){
    SListStruct *slist_aux = (SListStruct *) slist;

    return slist_aux->size;
}

int sGetListVisit(List slist){
    SListStruct *slist_aux = (SListStruct *) slist;

    return slist_aux->visit;
}

/*
    Praticidade Apenas!!!
*/

void insertElement(List list, Info info, int swList){
    if(swList){
        dInsertElement(list, info);
    }else{
        sInsertElement(list, info);
    }
}

List createList(int nx, int swList){
    if(swList){
        return dCreateList();
    }else{
        return sCreateList(nx);
    }

}

void endList(List list, int swList){
    if(swList){
        dEndList(list);
    }else{
        sEndList(list);
    }
}

void removeNode(List list, Node node, int swList){
    if(swList){
        dRemoveNode(list, node);
    }else{
        sRemoveNode(list, node);
    }
}

Info getInfo(Node node, int swList){
    if(swList){
        return dGetInfo(node);
    }else{
        return sGetInfo(node);
    }
}

Node getNext(List list, Node node, int swList){
    if(swList){
        return dGetNext(list, node);
    }else{
        return sGetNext(list, node);
    }
}

Node getFirst(List list, int swList){
    if(swList){
        return dGetFirst(list);
    }else{
        return sGetFirst(list);
    }
}

int getListSize(List list, int swList){
    if(swList){
        return dGetListSize(list);
    }else{
        return sGetListSize(list);
    }
}

int getListVisit(List list, int swList){
    if(swList){
        return dGetListVisit(list);
    }else{
        return sGetListVisit(list);
    }
}
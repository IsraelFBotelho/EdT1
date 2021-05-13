#ifndef __ANALYSIS__
#define __ANALYSIS__

/*
* Cria um arquivo temporario com as informaçoes das visitas e tamanho da lista do programa atual
* Pre: Um char* com o caminho de saida, Um int com o numero de visitas, Um int com o tamanho da lista
* Pos: Nenhum retorno
*/
void startAnalysis(char* pathOut, int numberVisit, int listSize);

/*
* Pega um arquivo temporario ja existente e escreve informaçoes das visitas e tamanho da lista do programa atual
* Um char* com o caminho de saida, Um int com o numero de visitas, Um int com o tamanho da lista
* Pos: Nenhum retorno
*/
void continueAnalysis(char* pathOut, int numberVisit, int listSize);

/*
* Pega um arquivo temporario ja existente com informaçoes de visitas e tamanho de listas, além das informaçoes do programa atual
*    e cria um grafico Visita x Tamanho com pontos no svg, além de tracejados apontando os pontos, tambpém escreve o nome da analise em baixo
* Pre: Um char* com o caminho de saida, Um int com o numero de visitas, Um int com o tamanho da lista, Um char* com o titulo da analise
*      Um char* com o nome do arquivo gerado
* Pos: Nenhum retorno
*/
void endAnalysis(char* pathOut, int numberVisit, int listSize, char* titleAnalysis, char* nameArqAnalysis);


#endif
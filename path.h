#ifndef __PATH__
#define __PATH__
/*
* Recupera o nome de um arquivo, estando ele dentro ou nao de um caminho
* Pre: Um char* com o nome e extensao e/ou caminho do arquivo
* Pos: Um char* com o nome do arquivo
*/
char* extractName(char* path);

/*
* Concatena dois caminhos, em caso de barras e/ou pontos duplos, ele corrige
* Pre: Um char* com o caminho, Um char* com o caminho
* Pos: Um char* com o caminho combinado
*/
char* catPath(char* path1, char* path2);

/*
* Recupera a extensão de um arquivo, estando ele dentro ou nao de um caminho
* Pre: Um char* com o nome e extensao e/ou caminho do arquivo
* Pos: Um char* com a extensao do arquivo
*/
char* extractExtension(char *path);

/*
* Recupera um nome de arquivo com extensao, somente nome e extensao, sem caminho
* Pre: Um char* com o nome do arquivo, Um char* com a extensao do arquivo
* Pos: Um char* com o arquivo com extensao
*/
char* insertExtension(char* name, char* extension);

#endif

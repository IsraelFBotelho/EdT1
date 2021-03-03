#ifndef __ARGV__
#define __ARGV__
/*
* Lê e armazena os valores de argumentos de entrada da main, os armazenando em suas devidas variaveis
* Pre: Um int com o argc, Um char** com o argv, Uma referencia de char* do caminho de saida, Uma referencia de char* do caminho de entrada, 
*      Uma referencia de char* do nome do .geo, Uma referencia de char* do nome do .qry, Um int com o swList
* Pos: Nenhum retorno
*/
void readArgv(int argc, char** argv, char** pathOut, char** pathIn, char** nameArqGeo, char** nameArqQry, int* swList, int* swAnalysis, char** nameArqAnalysis, char ** titleAnalysys);

#endif
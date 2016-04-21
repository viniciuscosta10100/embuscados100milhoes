#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define TAM_HTABLE 256
typedef struct node{
	unsigned char letra;
	int frequencia;
	char huffbin[8];
}Node;

typedef struct hashtable{
	Node * elementos[TAM_HTABLE];
}HTable;

HTable * initHTable(){
	int i;
	HTable *hTable = (HTable*)malloc(sizeof(HTable));
	for(i=0; i<TAM_HTABLE; i++){
		hTable->elementos[i] = (Node*)malloc(sizeof(Node));
		hTable->elementos[i]->letra = i;
		hTable->elementos[i]->frequencia = 0;
	}
	return hTable;
}

int getFrequencia(HTable *table, int posicao){
	return table->elementos[posicao]->frequencia;
}

int getTamHTable(){
	return TAM_HTABLE;
}

void addCFrequency(HTable *table, unsigned char c){
	table->elementos[c]->frequencia++;
}

void addFrequency(HTable * table, unsigned char *strOrdenada, int strSize){
	unsigned char c, c1;
	int cont=0, i;
	c1 = strOrdenada[0];
	for(i=1; i<strSize; i++){
		c = strOrdenada[i];
		if(c != c1 && c1>=0){
			table->elementos[c1]->frequencia += cont;
			cont = 1;
		}else{
			cont++;
		}
		c1 = c;
	}
	table->elementos[c1]->frequencia += cont;
}

void addCharBits(HTable *table, unsigned char c, char *bits){
	strcpy(table->elementos[(int)c]->huffbin, bits);
}

char *getCharBits(HTable *table, unsigned char c){
	return table->elementos[(int)c]->huffbin;
}


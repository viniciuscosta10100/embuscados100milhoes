#include "hashtable_frequency.h"

#define TAM_HTABLE 256
typedef struct node{
	unsigned char letra;
	int frequencia;
	char huffbin[30];
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

void addCharBits(HTable *table, unsigned char c, char *bits){
	strcpy(table->elementos[(int)c]->huffbin, bits);
}

char *getCharBits(HTable *table, unsigned char c){
	return table->elementos[(int)c]->huffbin;
}


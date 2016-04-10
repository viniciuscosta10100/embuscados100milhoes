#include <stdlib.h>

#define TAM_HTABLE 256
typedef struct node{
	char letra;
	int frequencia;
	unsigned char huffbin[8];
}Node;

typedef struct hashtable{
	Node * elementos[TAM_HTABLE];
}HTable;

HTable * initHTable(){
	int i;
	HTable *hTable = (HTable*)malloc(sizeof(HTable));
	for(i=0; i<TAM_HTABLE; i++){
		hTable->elementos[i] = (Node*)malloc(sizeof(Node));
		hTable->elementos[i]->letra = i+1;
		hTable->elementos[i]->frequencia = 0;
	}
	return hTable;
}

HTable * addFrequency(HTable * table, char c, int frequency){
	table->elementos[c+1]->frequencia += frequency;
	return table;
}

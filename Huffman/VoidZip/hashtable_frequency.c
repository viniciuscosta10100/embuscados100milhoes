#include <stdlib.h>
#include <string.h>
#include "priority_queue.h"
#include "arvore_huffman.h"

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

PQueue * gerarFilaPrioridade(HTable * table){
	PQueue *queue;
	queue = initPQueue();
	int i;
	for(i=0; i<TAM_HTABLE; i++){
		if(table->elementos[i]->frequencia != 0){
			ArvoreHuff *newArvore = newArvore(table->elementos[i]->letra, NULL, NULL);
			enqueue(queue, newArvore, table->elementos[i]->frequencia);
		}
	}
	return queue;
}

HTable * addFrequency(HTable * table, char *strOrdenada){
	char c, c1;
	int cont=0, strSize, i;
	strSize = strlen(strOrdenada);
	c1 = strOrdenada[0];
	for(i=1; i<strSize; i++){
		c = strOrdenada[i];
		if(c != c1){
			table->elementos[c1-1]->frequencia += cont;
			cont = 1;
		}else{
			cont++;
		}
		c1 = c;
	}
	table->elementos[c1-1]->frequencia += cont;
	//printf("TABLE::\n");
	//printTable(table);
	return table;
}

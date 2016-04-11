#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "hashtable_frequency.h"
#include "arvore_huffman.h"


#ifndef NULL
#define NULL   ((void *) 0)
#endif

ArvoreHuff * criarArvore(PQueue *queue){
	ArvoreHuff *a1, *a2, *novaArvore;
	int p1, p2;
	while(!unicoElemento(queue)){
		p1 = getPrioridade(queue);
		a1 = dequeue(queue);
		p2 = getPrioridade(queue);
		a2 = dequeue(queue);
		novaArvore = newArvore('*',a1,a2);
		enqueue(queue,novaArvore,p1+p2);
	}
	return dequeue(queue);
}

HTable * criarHTable(){
	return NULL;
}

void compactar(char* urlArquivo){
	FILE *fp;
	HTable *htable = initHTable();
	char *arvorePreOrder;
	char buffer[256];
	fp = fopen(urlArquivo, "r");
	while(fgets(buffer, 255, fp)){
		quicksort(buffer);
		addFrequency(htable, buffer);
	}

	PQueue *queue = gerarFilaPrioridade(htable);
	ArvoreHuff *arvore = criarArvore(queue);

	arvorePreOrder = (char*)malloc(256*sizeof(char));
	initString(arvorePreOrder, 256);
	pre_order(arvore, arvorePreOrder);
	printf("%s", arvorePreOrder);

	printf("\nFinalizando");
	fclose(fp);
}

void descompactar(){

}

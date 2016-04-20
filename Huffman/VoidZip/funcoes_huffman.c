#include "funcoes_huffman.h"

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

PQueue *gerarFilaPrioridade(HTable * table){
	PQueue *queue;
	ArvoreHuff *novaArvore;
	queue = initPQueue();
	int i;
	for(i=0; i<getTamHTable(); i++){
		if(getFrequencia(table, i) != 0){
			novaArvore = newArvore(i, NULL, NULL);
			enqueue(queue, novaArvore, getFrequencia(table, i));
		}
	}
	return queue;
}

void compactar(char* urlArquivo){
	FILE *fp;
	HTable *htable = initHTable();
	unsigned char *buffer, *arvorePreOrder;
	int fpSize;

	fp = fopen(urlArquivo, "rb");

	if (fp == NULL){
		printf("Problemas na abertura do arquivo\n");
		return;
	}
	fseek (fp , 0 , SEEK_END);
	fpSize = ftell(fp);
	rewind(fp);
	buffer = (unsigned char*) malloc(sizeof(char)*fpSize);
	fread (buffer, 1, fpSize, fp);

	quicksort(buffer, fpSize);
	addFrequency(htable, buffer, fpSize);

	PQueue *queue = gerarFilaPrioridade(htable);
	ArvoreHuff *arvore = criarArvore(queue);

	arvorePreOrder = (unsigned char*)malloc(1000*sizeof(char));
	int tamPreorder = 0;
	pre_order(arvore, arvorePreOrder, &tamPreorder);
	arvorePreOrder[tamPreorder] = '\0';
	printf("%s", arvorePreOrder);

	char *treeTam = (char*)malloc(14*sizeof(char));
	intToBin(treeTam,tamPreorder,13);
	printf("\nbin %s\n", treeTam);

	preencherBitsHuff(arvore, htable);

	printf("Bits do n: %s\n", getCharBits(htable, 'n'));

	printf("\nFinalizando");
	fclose(fp);
}

void descompactar(char* urlArquivo){

}

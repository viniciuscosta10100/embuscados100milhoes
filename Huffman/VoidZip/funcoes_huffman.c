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

	fp = fopen(urlArquivo, "rb");printf("abriu arquivo\n");

	if (fp == NULL){
		printf("Problemas na abertura do arquivo\n");
		return;
	}
	fseek (fp , 0 , SEEK_END);printf("buscou arquivo\n");
	fpSize = ftell(fp);
	rewind(fp);
	buffer = (unsigned char*) malloc(sizeof(char)*fpSize);
	fread (buffer, 1, fpSize, fp);printf("leu arquivo\n");

	/*quicksort(buffer, fpSize);
	addFrequency(htable, buffer, fpSize);*/

	int i;
	for(i=0; i<fpSize; i++){
		addCFrequency(htable, buffer[i]);
	}

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

	printf("Bits do T: %s\n\n", getCharBits(htable, 'T'));


	//char *bytes_compactado = NULL;
	FILE *nFile;
	unsigned char byteLido;
	unsigned char byte = 0;
	char *bitshuff;
	int tamc = 0;
	int bitpos = 7;
	int j;printf("chegou aqui\n");
	rewind(fp);
	nFile = fopen ("myfile.huff","wb");
	while(fscanf(fp, "%c", &byteLido) > 0){
		//printf("%s ", getCharBits(htable, byteLido));
		bitshuff = getCharBits(htable, byteLido);
		for(j = 0 ; j<strlen(bitshuff); j++){
			if(bitshuff[j] != '0'){
				byte = setBit(byte, bitpos);
			}
			bitpos--;
			if(bitpos < 0){printf("  byte %d\n", byte);
				bitpos = 7;
				fprintf(nFile, "%c", byte);
				byte = 0;
			}
		}printf("  pbyte %d", byte);printf(" -  %c\n", byteLido);
		tamc += strlen(getCharBits(htable, byteLido));
	}
	printf("\nFinalizando");
	fclose(nFile);
	fclose(fp);
//Descompactar
	fp = fopen("myfile.huff","rb");
	nFile = fopen("myfile.png", "wb");
	ArvoreHuff *a = arvore;printf("\n");
	while(fscanf(fp, "%c", &byteLido) > 0){
		for(i=7; i>=0; i--){
			if(getBit(byteLido, i) == 0){
				a = getLeft(a);printf("0");}
			else{
				a = getRight(a);printf("1");}
			if(folha(a)){
				fprintf(nFile, "%c", getValor(a));printf(" - %c\n", getValor(a));
				a = arvore;
			}
		}
	}
	printf("\nFinalizando descompactar");
	fclose(nFile);
	fclose(fp);
}

void descompactar(char* urlArquivo){

}

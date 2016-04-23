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

void escreverBitsArquivo(FILE *arquivo, char *bits, int tam){
	int i;
	unsigned char byte = 0;
	int bitpos = 7;
	for(i = 0 ; i<tam; i++){
		if(bits[i] != '0'){
			byte = setBit(byte, bitpos);
		}
		bitpos--;
		if(bitpos < 0){
			bitpos = 7;
			fprintf(arquivo, "%c", byte);
			byte = 0;
		}
	}
}


void compactar(char* urlArquivo){
	FILE *arquivoCompactar, *arquivoCompactado;
	HTable *htable = initHTable();
	unsigned char *buffer;
	int tamanhoCompactar, i;

	arquivoCompactar = fopen(urlArquivo, "rb");
	arquivoCompactado = fopen("meu-arquivo.huff", "wb");

	if (arquivoCompactar == NULL || arquivoCompactado == NULL){
		printf("Problemas na abertura dos arquivos\n");
		return;
	}
	fseek(arquivoCompactar , 0 , SEEK_END);
	tamanhoCompactar = ftell(arquivoCompactar);
	rewind(arquivoCompactar);
	buffer = (unsigned char*) malloc(sizeof(char)*tamanhoCompactar);
	fread(buffer, 1, tamanhoCompactar, arquivoCompactar);

	for(i=0; i<tamanhoCompactar; i++){
		addCFrequency(htable, buffer[i]);
	}

	PQueue *queue = gerarFilaPrioridade(htable);
	ArvoreHuff *arvore = criarArvore(queue);

	fprintf(arquivoCompactado, "AA");

	int tamPreorder = 0;
	pre_order(arvore, arquivoCompactado, &tamPreorder);

	char *treeTam = (char*)malloc(13*sizeof(char));
	intToBin(treeTam,tamPreorder,13);
	printf("\nbin %s\n", treeTam);

	printf("tamanho arvore %d\n", tamPreorder);

	preencherBitsHuff(arvore, htable);

	unsigned char byteLido;
	unsigned char byte = 0;
	char *bitshuff;
	int bitpos = 7;
	int lixoqtd;
	int j;printf("chegou aqui\n");
	rewind(arquivoCompactar);
	while(fscanf(arquivoCompactar, "%c", &byteLido) > 0){
		bitshuff = getCharBits(htable, byteLido);
		for(j = 0 ; j<strlen(bitshuff); j++){
			if(bitshuff[j] != '0'){
				byte = setBit(byte, bitpos);
			}
			bitpos--;
			if(bitpos < 0){
				bitpos = 7;
				fprintf(arquivoCompactado, "%c", byte);
				byte = 0;
			}
		}
	}
	lixoqtd = bitpos+1;
	if(lixoqtd == 8)
		lixoqtd = 0;
	else
		fprintf(arquivoCompactado, "%c", byte);


	char *qtdLixo = (char*)malloc(4*sizeof(char));
	intToBin(qtdLixo,lixoqtd,3);
	qtdLixo[3] = '\0';
	printf("\nlixo %s\n", qtdLixo);

	char inicioCabecalho[17] = "";
	strcpy(inicioCabecalho, qtdLixo);
	inicioCabecalho[3] = '\0';
	strcat(inicioCabecalho, treeTam);
	inicioCabecalho[16] = '\0';
	printf("inicio cabecalho: %s\n", inicioCabecalho);

	rewind(arquivoCompactado);
	escreverBitsArquivo(arquivoCompactado, inicioCabecalho, 16);

	printf("\nFinalizando");
	fclose(arquivoCompactado);
	fclose(arquivoCompactar);

}

void descompactar(char* urlArquivo){
	int i, j;
	FILE *arquivoCompactado, *arquivoDescompactado;
	int tamanhoCompactado, qtdLixo, tamArvore;
	unsigned char *buffer;
	char inicioCabecalho[17];
	ArvoreHuff *arvore, *a;

	arquivoCompactado = fopen(urlArquivo, "rb");
	arquivoDescompactado = fopen("teste.txt", "wb");

	if (arquivoCompactado == NULL){// || arquivoDescompactado == NULL){
		printf("Problemas na abertura dos arquivos\n");
		return;
	}
	fseek(arquivoCompactado , 0 , SEEK_END);
	tamanhoCompactado = ftell(arquivoCompactado);
	rewind(arquivoCompactado);
	buffer = (unsigned char*) malloc(sizeof(char)*tamanhoCompactado);
	fread(buffer, 1, tamanhoCompactado, arquivoCompactado);

	initString(inicioCabecalho, 17);
	for(i=0; i<2; i++){
		for(j=7; j>=0; j--){
			if(getBit(buffer[i], j) == 0)
				inicioCabecalho[strlen(inicioCabecalho)] = '0';
			else
				inicioCabecalho[strlen(inicioCabecalho)] = '1';
		}
	}
	printf("%s\n", inicioCabecalho);
	qtdLixo = binToInt(inicioCabecalho, 3);
	tamArvore = binToInt(inicioCabecalho+3, 13);

	printf("Qtd lixo %d\n", qtdLixo);
	printf("Tam Arvore %d\n", tamArvore);

	unsigned char arvore_preorder[tamArvore];
	for(i=2; i<tamArvore+2; i++){
		arvore_preorder[i-2] = buffer[i];
	}

	printf("\narvore:\n");
	for(i=0; i<tamArvore; i++){
		printf("%c", arvore_preorder[i]);
	}
	printf("\n");

	arvore = generate_tree(arvore_preorder);pre_order(arvore, NULL, &i);
	a = arvore;

	int byteFinal;
	for(i=2+tamArvore; i<tamanhoCompactado; i++){
		if(i == tamanhoCompactado-1)
			byteFinal = qtdLixo;
		else
			byteFinal = 0;
		for(j=7; j>=byteFinal; j--){
			if(getBit(buffer[i], j) == 0)
				a = getLeft(a);
			else
				a = getRight(a);
			if(folha(a)){
				fprintf(arquivoDescompactado, "%c", getValor(a));
				a = arvore;
			}
		}
	}
	printf("\nFinalizando descompactar");
	fclose(arquivoCompactado);
	fclose(arquivoDescompactado);
}

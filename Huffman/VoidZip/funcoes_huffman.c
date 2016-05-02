#include "funcoes_huffman.h"

ArvoreHuff * criarArvore(PQueue *queue){
	ArvoreHuff *a1, *a2, *novaArvore;
	int p1, p2;
	if(unicoElemento(queue)){
		p1 = getPrioridade(queue);
		a1 = dequeue(queue);
		novaArvore = newArvore('*',a1,NULL);
		enqueue(queue,novaArvore,p1);
	}
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

void f_preencherBitsHuff(ArvoreHuff *arvore, HTable *table, char bits[]){
	if(arvore != NULL){
		if(folha(arvore)){
			addCharBits(table, getValor(arvore), bits);
		}else{
			int bitsLength = strlen(bits);
			bits[bitsLength] = '0';
			bits[bitsLength+1] = '\0';
			f_preencherBitsHuff(getLeft(arvore), table, bits);
			bits[bitsLength] = '1';
			bits[bitsLength+1] = '\0';
			f_preencherBitsHuff(getRight(arvore), table, bits);
		}
	}

}

void preencherBitsHuff(ArvoreHuff *arvore, HTable *table){
	char bits[30];
	initString(bits, 30);
	f_preencherBitsHuff(arvore, table, bits);
}

int escreverArquivoCompactado(FILE *arquivoCompactar, FILE *arquivoCompactado, HTable* htable){
	unsigned char byteLido;
	unsigned char byte = 0;
	char *bitshuff;
	int bitpos = 7;
	int lixoqtd;
	int j;
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

	return lixoqtd;
}

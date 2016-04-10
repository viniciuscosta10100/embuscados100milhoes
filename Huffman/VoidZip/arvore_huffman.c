#include <stdlib.h>

#ifndef NULL
#define NULL   ((void *) 0)
#endif

typedef struct arvore_huffman{
	char valor;
	struct arvore_huffman *left;
	struct arvore_huffman *right;
}ArvoreHuff;

ArvoreHuff * init(){
	return NULL;
}

ArvoreHuff * create(char valor, ArvoreHuff *left, ArvoreHuff *right){
	ArvoreHuff *newTree = (ArvoreHuff*)malloc(sizeof(ArvoreHuff));
	newTree->valor = valor;
	newTree->left = left;
	newTree->right = right;
	return newTree;
}

char * pre_order(ArvoreHuff *arvore){
	return NULL;
}

int folha(ArvoreHuff *arvore){
	return (arvore->left == NULL && arvore->right == NULL);
}

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#ifndef NULL
#define NULL   ((void *) 0)
#endif

typedef struct arvore_huffman{
	char valor;
	struct arvore_huffman *left;
	struct arvore_huffman *right;
}ArvoreHuff;

ArvoreHuff * newArvore(char valor, ArvoreHuff *left, ArvoreHuff *right){
	ArvoreHuff *newTree = (ArvoreHuff*)malloc(sizeof(ArvoreHuff));
	newTree->valor = valor;
	newTree->left = left;
	newTree->right = right;
	return newTree;
}

void pre_order(ArvoreHuff *arvore, char c[]){
	if(arvore != NULL){
		c[strlen(c)] = arvore->valor;
		pre_order(arvore->left, c);
		pre_order(arvore->right, c);
	}
}

int folha(ArvoreHuff *arvore){
	return (arvore->left == NULL && arvore->right == NULL);
}

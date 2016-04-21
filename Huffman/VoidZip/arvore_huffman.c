#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hashtable_frequency.h"
#include "util.h"

typedef struct arvore_huffman{
	unsigned char valor;
	struct arvore_huffman *left;
	struct arvore_huffman *right;
	int visited;
}ArvoreHuff;

ArvoreHuff * newArvore(unsigned char valor, ArvoreHuff *left, ArvoreHuff *right){
	ArvoreHuff *newTree = (ArvoreHuff*)malloc(sizeof(ArvoreHuff));
	newTree->valor = valor;
	newTree->left = left;
	newTree->right = right;
	newTree->visited = 0;
	return newTree;
}

void pre_order(ArvoreHuff *arvore, unsigned char c[], int *tam){
	if(arvore != NULL){
		c[*tam] = arvore->valor;
		*tam = *tam + 1;
		pre_order(arvore->left, c, tam);
		pre_order(arvore->right, c, tam);
	}
}

int folha(ArvoreHuff *arvore){
	return (arvore->left == NULL && arvore->right == NULL);
}

void f_preencherBitsHuff(ArvoreHuff *arvore, HTable *table, char bits[]){
	if(arvore != NULL){
		if(folha(arvore)){
			addCharBits(table, arvore->valor, bits);
		}else{
			int bitsLength = strlen(bits);
			bits[bitsLength] = '0';
			bits[bitsLength+1] = '\0';
			f_preencherBitsHuff(arvore->left, table, bits);
			bits[bitsLength] = '1';
			bits[bitsLength+1] = '\0';
			f_preencherBitsHuff(arvore->right, table, bits);
		}
	}

}

void preencherBitsHuff(ArvoreHuff *arvore, HTable *table){
	char bits[8];
	initString(bits, 8);
	f_preencherBitsHuff(arvore, table, bits);
}

ArvoreHuff *getLeft(ArvoreHuff *arvore){
	return arvore->left;
}

ArvoreHuff *getRight(ArvoreHuff *arvore){
	return arvore->right;
}

unsigned char getValor(ArvoreHuff *arvore){
	return arvore->valor;
}


/*ArvoreHuff * generate_tree(char *preorder){
	ArvoreHuff *a1, *a2;
	if(*preorder == '*'){
		preorder = preorder + 1;
		if(*preorder != '*' && *(preorder+1) != '*'){
			a1 = newArvore(*preorder, NULL, NULL);
			preorder = preorder + 1;
			a2 = newArvore(*preorder, NULL, NULL);
			preorder = preorder + 1;
			return newArvore('*',a1,a2);
		}else if(*preorder == '*' && *(preorder+1) != '*'){
			a1 = newArvore(*preorder, NULL, NULL);
			preorder = preorder + 1;
			a2 = newArvore(*preorder, NULL, NULL);
			preorder = preorder + 1;
			return newArvore('*',a1,a2);
		}else if(*preorder != '*' && *(preorder+1) == '*'){
			a1 = newArvore(*preorder, NULL, NULL);
			preorder = preorder + 1;
			a2 = newArvore(*preorder, NULL, NULL);
			preorder = preorder + 1;
			return newArvore('*',a1,a2);
		}else if(*preorder == '*' && *(preorder+1) == '*'){
			a1 = newArvore(*preorder, NULL, NULL);
			preorder = preorder + 1;
			a2 = newArvore(*preorder, NULL, NULL);
			preorder = preorder + 1;
			return newArvore('*',a1,a2);
		}
	}
}*/

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

unsigned char *preorder_string;

ArvoreHuff * newArvore(unsigned char valor, ArvoreHuff *left, ArvoreHuff *right){
	ArvoreHuff *newTree = (ArvoreHuff*)malloc(sizeof(ArvoreHuff));
	newTree->valor = valor;
	newTree->left = left;
	newTree->right = right;
	newTree->visited = 0;
	return newTree;
}

int folha(ArvoreHuff *arvore){
	return (arvore->left == NULL && arvore->right == NULL);
}

void pre_order(ArvoreHuff *arvore, FILE *arquivo, int *tam){
	if(arvore != NULL){
		if(arvore->valor == 13){
			fprintf(arquivo, "\\&");
			//printf("\\&");
			*tam = *tam + 2;
		}else{
			if((arvore->valor == 42 && folha(arvore)) || arvore->valor == '\\'){
				fprintf(arquivo, "\\");
				//printf("\\");
				*tam = *tam + 1;
			}
			fprintf(arquivo, "%c", arvore->valor);
			//printf("%c", arvore->valor);
			*tam = *tam + 1;
			pre_order(arvore->left, arquivo, tam);
			pre_order(arvore->right, arquivo, tam);
		}
	}
}

ArvoreHuff *f_generate_tree(){
	ArvoreHuff *a1, *a2;
	if(*preorder_string == 42){
		preorder_string = preorder_string+1;
		a1 = f_generate_tree();
		preorder_string = preorder_string+1;
		a2 = f_generate_tree();
		return newArvore('*', a1, a2);
	}else{
		if(*preorder_string == '\\'){
			preorder_string = preorder_string+1;
			if(*preorder_string == '&')
				return newArvore(13,NULL,NULL);
			else
				return newArvore(*preorder_string,NULL,NULL);
		}else
			return newArvore(*preorder_string,NULL,NULL);
	}
}

ArvoreHuff *generate_tree(unsigned char *preorder){
	preorder_string = preorder;
	return f_generate_tree();
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

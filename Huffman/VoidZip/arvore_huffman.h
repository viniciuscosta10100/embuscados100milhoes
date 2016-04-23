#include <stdio.h>

typedef struct arvore_huffman ArvoreHuff;

ArvoreHuff * newArvore(unsigned char valor, ArvoreHuff *left, ArvoreHuff *right);

void pre_order(ArvoreHuff *root, FILE *arquivo, int *tam);

int folha(ArvoreHuff *arvore);

ArvoreHuff *generate_tree(unsigned char *preorder);

ArvoreHuff *getLeft(ArvoreHuff *arvore);

ArvoreHuff *getRight(ArvoreHuff *arvore);

unsigned char getValor(ArvoreHuff *arvore);

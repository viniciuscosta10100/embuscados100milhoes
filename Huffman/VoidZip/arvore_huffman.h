#include "hashtable_frequency.h"

typedef struct arvore_huffman ArvoreHuff;

ArvoreHuff * newArvore(unsigned char valor, ArvoreHuff *left, ArvoreHuff *right);

void pre_order(ArvoreHuff *root, unsigned char c[], int *tam);

int folha(ArvoreHuff *arvore);

void preencherBitsHuff(ArvoreHuff *arvore, HTable *table);

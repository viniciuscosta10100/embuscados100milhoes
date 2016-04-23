#include "util.h"
#include "hashtable_frequency.h"
#include "arvore_huffman.h"
#include "priority_queue.h"

ArvoreHuff * criarArvore(PQueue *queue);

PQueue *gerarFilaPrioridade(HTable * table);

void preencherBitsHuff(ArvoreHuff *arvore, HTable *table);

int escreverArquivoCompactado(FILE *arquivoCompactar, FILE *arquivoCompactado, HTable* htable);

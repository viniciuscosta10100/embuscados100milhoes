#include "arvore_huffman.h"

typedef struct priorityQueue PQueue;

PQueue * enqueue(PQueue *queue, ArvoreHuff *item);

ArvoreHuff * dequeue(PQueue *queue);

int unicoElemento(PQueue *queue);

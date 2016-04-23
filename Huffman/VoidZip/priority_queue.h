#include <stdlib.h>
#include "arvore_huffman.h"

typedef struct priority_queue PQueue;

PQueue *initPQueue();

void enqueue(PQueue *queue, ArvoreHuff *item, int frequencia);

ArvoreHuff *dequeue(PQueue *queue);

int unicoElemento(PQueue *queue);

int getPrioridade(PQueue *queue);

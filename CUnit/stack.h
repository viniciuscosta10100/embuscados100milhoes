#include "stdlib.h"

typedef struct pilha Pilha;

Pilha *initStack();

void push(Pilha *pilha, int valor);

void pop(Pilha *pilha);

int peek(Pilha *pilha);

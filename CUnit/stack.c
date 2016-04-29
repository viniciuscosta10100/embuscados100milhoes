#include "stack.h"

typedef struct node{
	int valor;
	struct Node *next;
}Node;

typedef struct pilha{
	Node *topo;
}Pilha;

Pilha *initStack(){
	Pilha *novaPilha = (Pilha*)malloc(sizeof(Pilha));
	novaPilha->topo = NULL;
	return novaPilha;
}

void push(Pilha *pilha, int valor){
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->valor = valor;
	newNode->next = pilha->topo;
	pilha->topo = newNode;
}

void pop(Pilha *pilha){
	Node *aux;
	aux = pilha->topo;
	pilha->topo = aux->next;
	free(aux);
}

int peek(Pilha *pilha){
	if (pilha->topo == NULL){
		return -1;
	}
	return pilha->topo->valor;
}

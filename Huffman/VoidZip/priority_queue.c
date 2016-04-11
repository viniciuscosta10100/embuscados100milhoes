#include <stdlib.h>
#include "arvore_huffman.h"

typedef struct node{
	int prioridade;
	ArvoreHuff *arvore;
	struct node *next;
}Node;

typedef struct priority_queue{
	Node *inicio;
	Node *fim;
}PQueue;

PQueue * initPQueue(){
	PQueue *queue = (PQueue*)malloc(sizeof(PQueue));
	queue->inicio = NULL;
	queue->fim = NULL;
	return queue;
}

void enqueue(PQueue *queue, ArvoreHuff *item, int frequencia){
	Node *aux, *aux2;
	Node *newNode;
	newNode = (Node*)malloc(sizeof(Node));
	newNode->arvore = item;
	newNode->prioridade = frequencia;
	if(queue->fim == NULL){
		newNode->next = NULL;
		queue->inicio = newNode;
		queue->fim = newNode;
	}else if(frequencia < queue->inicio->prioridade){
		newNode->next = queue->inicio;
		queue->inicio = newNode;
	}else{
		aux = queue->inicio;
		while(aux != NULL && frequencia >= aux->prioridade){
			aux2 = aux;
			aux = aux->next;
		}
		newNode->next = aux;
		aux2->next = newNode;
		if(aux == NULL)
			queue->fim = newNode;
	}
}

int unicoElemento(PQueue *queue){
	return (queue->inicio->next == NULL);
}

ArvoreHuff * dequeue(PQueue *queue){
	ArvoreHuff *arvore = queue->inicio->arvore;
	Node *aux = queue->inicio;
	if(unicoElemento(queue))
		queue->fim = NULL;
	queue->inicio = queue->inicio->next;
	free(aux);
	return arvore;
}

int getPrioridade(PQueue *queue){
	return queue->inicio->prioridade;
}



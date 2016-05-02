#ifndef FUNCOESUTEIS_H__
#define FUNCOESUTEIS_H__

#include <stdlib.h>
#include <time.h>

struct amostra{
    int *array;
    long long int *trocas;
};
typedef struct amostra amostra;

int left(int i);

int right(int i);

void swap(int *hp,int i,int j);

amostra* criarAmostra(int num_de_elementos);

void criarArrayDesordenado(int *vetor,int size);

void criarArrayCrescente(int *vetor,int size);

void criarArrayDecrescente(int *vetor,int size);

#endif /* FUNCOESUTEIS_H__*/

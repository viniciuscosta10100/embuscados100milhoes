#ifndef FUNCOESUTEIS_H__
#define FUNCOESUTEIS_H__

#include <stdlib.h>
#define TAM_NUM_MAX 100000
#define ELEMENTOS_LIMITES 1000000

struct amostra{
    int array[ELEMENTOS_LIMITES];
    int trocas[ELEMENTOS_LIMITES];
};
typedef struct amostra amostra;

int left(int i);

int right(int i);

void swap(int *hp,int i,int j);

amostra* criarAmostra();

void criarArrayDesordenado(int *vetor,int size);

void criarArrayCrescente(int *vetor,int size);

void criarArrayDecrescente(int *vetor,int size);

#endif /* FUNCOESUTEIS_H__*/

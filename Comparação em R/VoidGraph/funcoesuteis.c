#include "funcoesuteis.h"

#define TAM_NUM_MAX 100001

int left(int i){
    return 2*i;
}
int right(int i){
    return (2*i) + 1;
}
void swap(int *hp,int i,int j){
    hp[i-1] = hp[i-1] + hp[j-1];
    hp[j-1] = hp[i-1] - hp[j-1];
    hp[i-1] = hp[i-1] - hp[j-1];
}
amostra* criarAmostra(int num_de_elementos){
    amostra* newamostra = (amostra*) malloc(sizeof(amostra));
    newamostra->array = (int*) malloc((num_de_elementos*sizeof(int))+1);
    newamostra->trocas = (long long int*) malloc((num_de_elementos*sizeof(long long int))+1);
    return newamostra;
}
void criarArrayDesordenado(int *vetor,int size){
	srand(time(NULL));
    int i;
    for (i = 0 ; i < size ; i++){
        vetor[i] = rand()%TAM_NUM_MAX;
    }
}
void criarArrayCrescente(int *vetor,int size){
    int i;
    for (i = 0 ; i < size ; i++){
        vetor[i] = i;
    }
}

void criarArrayDecrescente(int *vetor,int size){
    int i;
    int aux;
    for(i = 0, aux = size ; i < size ; i++ , aux--){
        vetor[i] = aux;
    }
}

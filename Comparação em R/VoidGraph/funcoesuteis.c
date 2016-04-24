#include "funcoesuteis.h"

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
amostra* criarAmostra(){
    amostra* newamostra = (amostra*) malloc(sizeof(amostra));
    return newamostra;
}
void criarArrayDesordenado(int *vetor,int size){
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

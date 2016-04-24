#include "algoritmosdeordenacao.h"

int bubblesortTest (int *vetor, int size){
    int trocas = 0;
    int i,j,aux;
    for (i = size-1 ; i>0 ; i--){
        for(j=0 ; j<i ; j++){
            if (vetor[j] > vetor[j+1]){
                trocas++;
                aux=vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;
            }
        }
    }
    return trocas;
}
int max_heapfy(int *hp,int i,int size_hp){
    int trocas = 0;
    int largest;
    int l = left(i);
    int r = right(i);
    if (l <= size_hp && hp[l-1] > hp[i-1]){
        largest = l;
    }
    else{
        largest = i;
    }
    if (r <= size_hp && hp[r-1] > hp[largest-1]){
        largest = r;
    }
    if (largest != i){
        trocas++;
        swap(hp,i,largest);
        trocas+=max_heapfy(hp,largest,size_hp);
    }
    return trocas;
}

int buildmaxHeap(int *vetor,int size){
    int i;
    int trocas = 0;
    for (i = (size/2) ; i >= 1 ; i--){
        trocas+=max_heapfy(vetor,i,size);
    }
    return trocas;
}

int heapsort(int *vetor,int size){
    int i,aux,tam;
    int trocas = 0;
    tam = size;
    trocas+=buildmaxHeap(vetor,size);
    for(i = tam ; i >=2 ; i--){
        swap(vetor,1,i);
        tam--;
        aux = max_heapfy(vetor,1,tam);
        trocas+=aux;
        trocas++;
    }
    return trocas;
}

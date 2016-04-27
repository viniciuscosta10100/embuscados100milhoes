#include "algoritmosdeordenacao.h"

long long int bubblesortTest (int *vetor, int size){
    long long int comparacoes = 0;
    int i,j,aux;
    for (i = size-1 ; i>0 ; i--){
        for(j=0 ; j<i ; j++){
        	comparacoes++;
            if (vetor[j] > vetor[j+1]){
                aux=vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;
            }
        }
    }
    return comparacoes;
}
long long int max_heapfy(int *hp,int i,int size_hp){
    long long int comparacoes = 0;
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
        comparacoes++;
        swap(hp,i,largest);
        comparacoes+=max_heapfy(hp,largest,size_hp);
    }
    return comparacoes;
}

long long int buildmaxHeap(int *vetor,int size){
    int i;
    long long int comparacoes = 0;
    for (i = (size/2) ; i >= 1 ; i--){
        comparacoes+=max_heapfy(vetor,i,size);
    }
    return comparacoes;
}

long long int heapsort(int *vetor,int size){
    int i,tam;
    long long int comparacoes = 0;
    tam = size;
    comparacoes+=buildmaxHeap(vetor,size);
    for(i = tam ; i >=2 ; i--){
        swap(vetor,1,i);
        tam--;
        comparacoes+=max_heapfy(vetor,1,tam);
        comparacoes++;
    }
    return comparacoes;
}

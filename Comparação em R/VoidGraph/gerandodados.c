#include "gerandodados.h"
#include "funcoesuteis.h"
#include <stdio.h>
#include <conio.h>
void efficiencytest(amostra *bubble,amostra *heap,int gatilho,int num_de_elementos){
	if (gatilho == 0){
		criarArrayCrescente(bubble->array,num_de_elementos);
        criarArrayCrescente(heap->array,num_de_elementos);
    }
    else if(gatilho == 1){
        criarArrayDecrescente(bubble->array,num_de_elementos);
        criarArrayDecrescente(heap->array,num_de_elementos);
    }
    else{
       criarArrayDesordenado(bubble->array,num_de_elementos);
       criarArrayDesordenado(heap->array,num_de_elementos);
    }
    bubble->trocas[num_de_elementos] = bubblesortTest(bubble->array,num_de_elementos);
    heap->trocas[num_de_elementos] = heapsort(heap->array,num_de_elementos);
}
int gerandoComparacoesBarPlot(int num_de_elementos){
    int i;
    amostra *Bubblesort[3];
    amostra *Heapsort[3];
    for (i = 0 ; i < 3 ; i++){
        Bubblesort[i] = criarAmostra(num_de_elementos);
        Heapsort[i] = criarAmostra(num_de_elementos);
    }
    for (i = 0 ; i < 3 ; i++){
        efficiencytest(Bubblesort[i],Heapsort[i],i,num_de_elementos);
    }

    printBarPlot(Bubblesort,Heapsort,num_de_elementos);
    return 1;
}
int gerandoComparacoesLinePlot(int num_lim_de_elementos){
	int i,j;
	int begin;
	int marcador;
	int num = num_lim_de_elementos;
	amostra *Bubblesort[3];
	amostra *Heapsort[3];
	for (i = 0 ; i < 3 ; i++){
	    Bubblesort[i] = criarAmostra(num_lim_de_elementos);
	    Heapsort[i] = criarAmostra(num_lim_de_elementos);
	}
	for (i = 0 ; i < 3 ; i++){
		marcador = -1;
		begin = 10;
		Bubblesort[i]->trocas[num] = -1;
		for (j = 0 ; j <= num ; j+=begin){
			efficiencytest(Bubblesort[i],Heapsort[i],i,j);
			marcador++;
			if (marcador == 10){
				begin = begin * marcador;
				marcador = 1;
			}
		}
		if (Bubblesort[i]->trocas[num] == -1){
			efficiencytest(Bubblesort[i],Heapsort[i],i,num);
		}
	}
	printLinePlot(Bubblesort,Heapsort,num);
	return 1;
}

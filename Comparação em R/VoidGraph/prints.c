

#include "prints.h"

void printBarPlot(amostra **bubble,amostra **heap,int num_de_elementos){
    int i;
    char titulo[]={"BARPLOT.txt"};
    FILE *myfile = fopen(titulo,"w");
    fprintf(myfile,"    Bubblesort Heapsort\n");
    for (i=0 ; i < 3 ; i++){
        if (i==0){
            fprintf(myfile,"Crescente %lld %lld\n",bubble[i]->trocas[num_de_elementos],
                    heap[i]->trocas[num_de_elementos]);
        }
        else if (i == 1){
            fprintf(myfile,"Decrescente %lld %lld\n",bubble[i]->trocas[num_de_elementos],
                    heap[i]->trocas[num_de_elementos]);
        }
        else{
            fprintf(myfile,"Aleatório %lld %lld\n",bubble[i]->trocas[num_de_elementos],
                    heap[i]->trocas[num_de_elementos]);
        }
    }
    fclose(myfile);
}
void printLinePlot(amostra **bubble,amostra **heap,int num_de_elementos){
	int i;
	int begin = 10;
	int marcador = -1;
    char titulo1[] = {"BUBBLESORT-PLOTLINE.txt"};
    char titulo2[] = {"HEAPSORT-PLOTLINE.txt"};
    FILE *myfile1 = fopen(titulo1,"w");
    FILE *myfile2 = fopen(titulo2,"w");
    fprintf(myfile1,"Elementos Crescente Decrescente Aleatório\n");
    fprintf(myfile2,"Elementos Crescente Decrescente Aleatório\n");
    for (i = 0 ; i <= num_de_elementos ; i+=begin){
        fprintf(myfile1,"%d %lld %lld %lld\n",i,bubble[0]->trocas[i],
        		bubble[1]->trocas[i],bubble[2]->trocas[i]);
        fprintf(myfile2,"%d %lld %lld %lld\n",i,heap[0]->trocas[i],
                heap[1]->trocas[i],heap[2]->trocas[i]);
        marcador++;
        if (marcador == 10){
        	begin = begin * marcador;
        	marcador = 1;
        }
    }
    if (i-begin != num_de_elementos){
    	i = num_de_elementos;
    	fprintf(myfile1,"%d %lld %lld %lld\n",i,bubble[0]->trocas[i],
    	        		bubble[1]->trocas[i],bubble[2]->trocas[i]);
    	fprintf(myfile2,"%d %lld %lld %lld\n",i,heap[0]->trocas[i],
    	                heap[1]->trocas[i],heap[2]->trocas[i]);
    }
    fclose(myfile1);
    fclose(myfile2);
}

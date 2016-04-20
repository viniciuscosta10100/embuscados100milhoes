#include <string.h>
#include <stdio.h>

void swap_str(unsigned char *a, unsigned char *b){
	if(!a || !b)
		return;
    char temp = *(a);
    *(a) = *(b);
    *(b) = temp;
}

void f_quicksort(unsigned char* string, int inicio, int final){
	int i, j;
	char pivo;
	i = inicio;
	j = final;
	pivo = string[(i+j)/2];
	while(i <= j){
		while(string[i] < pivo && i < final)
			i++;
		while(string[j] > pivo && j > inicio)
			j--;
		if(i <= j){
			swap_str(string+i, string+j);
			i++;
			j--;
		}
	}
	if(j > inicio)
		f_quicksort(string, inicio, j);
	if(i < final)
		f_quicksort(string, i, final);
}

void quicksort(unsigned char *string, int tamanho){
	f_quicksort(string, 0, tamanho-1);
}

int setBit(unsigned char c, int i){
	unsigned char mask = 1 << i;
	return mask | c;
}

int getBit(unsigned char c, int i){
	unsigned char mask = 1 << i;
	return mask & c;
}

int getUniqueBit(unsigned char c, int i){
	unsigned char mask = c >> i;
	return mask & 1;
}

void initString(char *s, int tam){
	int i;
	for(i=0; i<tam; i++){
		s[i] = '\0';
	}
}

void intToBin(char* bin, int num, int bits){
	int i;
	for(i=0; i<bits; i++){
		bin[bits-i-1] = getUniqueBit(num,i)+'0';
	}
	bin[strlen(bin)] = '\0';
}

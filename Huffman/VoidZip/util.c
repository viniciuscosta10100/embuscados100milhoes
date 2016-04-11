#include <string.h>

void swap_str(char *a, char *b){
	if(!a || !b)
		return;
    char temp = *(a);
    *(a) = *(b);
    *(b) = temp;
}

void f_quicksort(char* string, int inicio, int final){
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

void quicksort(char *string){
	int tamanho = strlen(string);
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

void initString(char *s, int tam){
	int i;
	for(i=0; i<tam; i++)
		s[i] = '\0';
}

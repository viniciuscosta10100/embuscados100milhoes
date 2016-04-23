#include "util.h"

int setBit(unsigned char c, int i){
	unsigned char mask = 1 << i;
	return mask | c;
}

int getBit(unsigned char c, int i){
	unsigned char mask = 1 << i;
	return mask & c;
}

int getUniqueBit(unsigned int c, int i){
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

int binToInt(char *bin, int tam){
	int valor = 0;
	while(tam>0){
		if(*bin == '1')
			valor += pow(2,(tam-1));
		tam--;
		bin = bin+1;
	}
	return valor;
}

void escreverBitsArquivo(FILE *arquivo, char *bits, int tam){
	int i;
	unsigned char byte = 0;
	int bitpos = 7;
	for(i = 0 ; i<tam; i++){
		if(bits[i] != '0'){
			byte = setBit(byte, bitpos);
		}
		bitpos--;
		if(bitpos < 0){
			bitpos = 7;
			fprintf(arquivo, "%c", byte);
			byte = 0;
		}
	}
}

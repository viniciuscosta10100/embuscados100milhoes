#include <string.h>
#include <stdio.h>
#include <math.h>

int setBit(unsigned char c, int i);

int getBit(unsigned char c, int i);

void initString(char *s, int tam);

void intToBin(char* bin, int num, int bits);

int binToInt(char *bin, int tam);

void escreverBitsArquivo(FILE *arquivo, char *bits, int tam);

#include <string.h>

char * quicksort(char* string){
	return NULL;
}

int setBit(unsigned char c, int i){
	unsigned char mask = 1 << i;
	return mask | c;
}

int getBit(unsigned char c, int i){
	unsigned char mask = 1 << i;
	return mask & c;
}

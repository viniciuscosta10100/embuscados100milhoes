#include <stdlib.h>
#include <string.h>

typedef struct hashtable HTable;

HTable * initHTable();

void addCharBits(HTable *table, unsigned char c, char *bits);

char *getCharBits(HTable *table, unsigned char c);

int getFrequencia(HTable *table, int posicao);

void addCFrequency(HTable *table, unsigned char c);

int getTamHTable();

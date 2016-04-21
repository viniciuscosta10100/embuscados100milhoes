typedef struct hashTable HTable;

HTable * initHTable();

void addFrequency(HTable * table, unsigned char *strOrdenada, int strSize);

void addCharBits(HTable *table, char c, char *bits);

char *getCharBits(HTable *table, char c);

int getFrequencia(HTable *table, int posicao);

void addCFrequency(HTable *table, unsigned char c);

int getTamHTable();

#include "priority_queue.h"

typedef struct node Node;
typedef struct hashTable HTable;

HTable * initHTable();

HTable * addFrequency(HTable * table, char *strOrdenada);

PQueue * gerarFilaPrioridade(HTable * table);



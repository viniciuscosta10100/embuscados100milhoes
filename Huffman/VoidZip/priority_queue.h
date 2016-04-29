#include <stdlib.h>
#include "arvore_huffman.h"

/* Essa estrutura contém dois ponteiros que
 * apontam para uma estrutura do tipo Node,
 * representando o início da fila e o fim.
 * */
typedef struct priority_queue PQueue;

/* A função initPQueue não recebe nenhum parâmetro
 * e retorna um ponteiro de uma estrutura do tipo
 * PQueue. A função tem como objetivo inicializar
 * a nossa fila.
 * */
PQueue *initPQueue();

/* A função enqueue recebe um ponteiro de uma estrutura
 * do tipo PQueue, um ponteiro pra uma estrutura do tipo
 * ArvoreHuff e um inteiro correspondente a frequencia.
 * A função não retorna nada e tem como objetivo colocar
 * o nó raiz da árvore no seu devido lugar na fila de
 * prioridade.
 * */
void enqueue(PQueue *queue, ArvoreHuff *item, int frequencia);

/* A função dequeue recebe um ponteiro de uma estrutura
 * do tipo PQueue, e retorna um ponteiro de uma estrutura
 * do tipo ArvoreHuff, que será o nó raiz de uma sub-árvore.
 * */
ArvoreHuff *dequeue(PQueue *queue);

/* A função unicoElemento recebe um ponteiro de uma estrutura
 * do tipo PQueue, e retorna um inteiro, onde esse inteiro
 * será 1 ou 0, para se a fila estiver vazia ou não,
 * respectivamente.
 * */
int unicoElemento(PQueue *queue);

/* A função getPrioridade recebe um ponteiro de uma estrutura
 * do tipo PQueue, e retorna um inteiro, onde esse inteiro será
 * a prioridade do primeiro elemento da fila.
 * */
int getPrioridade(PQueue *queue);

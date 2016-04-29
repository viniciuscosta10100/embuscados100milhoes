#include <stdlib.h>
#include "arvore_huffman.h"

/* Essa estrutura cont�m dois ponteiros que
 * apontam para uma estrutura do tipo Node,
 * representando o in�cio da fila e o fim.
 * */
typedef struct priority_queue PQueue;

/* A fun��o initPQueue n�o recebe nenhum par�metro
 * e retorna um ponteiro de uma estrutura do tipo
 * PQueue. A fun��o tem como objetivo inicializar
 * a nossa fila.
 * */
PQueue *initPQueue();

/* A fun��o enqueue recebe um ponteiro de uma estrutura
 * do tipo PQueue, um ponteiro pra uma estrutura do tipo
 * ArvoreHuff e um inteiro correspondente a frequencia.
 * A fun��o n�o retorna nada e tem como objetivo colocar
 * o n� raiz da �rvore no seu devido lugar na fila de
 * prioridade.
 * */
void enqueue(PQueue *queue, ArvoreHuff *item, int frequencia);

/* A fun��o dequeue recebe um ponteiro de uma estrutura
 * do tipo PQueue, e retorna um ponteiro de uma estrutura
 * do tipo ArvoreHuff, que ser� o n� raiz de uma sub-�rvore.
 * */
ArvoreHuff *dequeue(PQueue *queue);

/* A fun��o unicoElemento recebe um ponteiro de uma estrutura
 * do tipo PQueue, e retorna um inteiro, onde esse inteiro
 * ser� 1 ou 0, para se a fila estiver vazia ou n�o,
 * respectivamente.
 * */
int unicoElemento(PQueue *queue);

/* A fun��o getPrioridade recebe um ponteiro de uma estrutura
 * do tipo PQueue, e retorna um inteiro, onde esse inteiro ser�
 * a prioridade do primeiro elemento da fila.
 * */
int getPrioridade(PQueue *queue);

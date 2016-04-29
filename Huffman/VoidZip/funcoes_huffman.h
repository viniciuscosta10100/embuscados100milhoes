#include "util.h"
#include "hashtable_frequency.h"
#include "arvore_huffman.h"
#include "priority_queue.h"

/* A fun��o criarArvore recebe um ponteiro de uma estrutura
 * do tipo PQueue, retorna um ponteiro para uma estrutura
 * do tipo ArvoreHuff e tem como objetivo criar a �rvore
 * bin�ria que representa o arquivo a ser compactado.
 * */
ArvoreHuff * criarArvore(PQueue *queue);

/* A fun��o gerarFilaPrioridade recebe um ponteiro de uma estrutura
 * do tipo HTable, retorna um ponteiro de uma estrutura do tipo
 * PQueue e tem como objetivo gerar a fila de prioridade pela
 * primeira vez.
 * */
PQueue *gerarFilaPrioridade(HTable * table);

/* A fun��o preencherBitsHuff recebe dois ponteiros, um da estrutura
 * do tipo ArvoreHuff e outro do tipo HTable, n�o retorna nada, e tem
 * como objetivo preencher na hash table os bits corresponder a cada
 * caracter.
 * */
void preencherBitsHuff(ArvoreHuff *arvore, HTable *table);

/* A fun��o escreverArquivoCompactado recebe dois ponteiros de arquivos
 * e um ponteiro do tipo HTable, retorna um inteiro, que ser�
 * a quantidade de lixo que temos, e tem como objetivo escrever os bits
 * do lixo no nosso arquivo compactado.
 * */
int escreverArquivoCompactado(FILE *arquivoCompactar, FILE *arquivoCompactado, HTable* htable);

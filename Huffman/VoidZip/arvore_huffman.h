#include <stdio.h>

/* Definimos uma estrutura do tipo arvore_huffman, onde
 * ela cont�m um caracter, que ser� o nosso valor do n�,
 * dois ponteiros(left e right) que apontam para uma
 * estrutura do mesmo tipo(arvore_huffman), e um inteiro
 * que ser� usado para ver se o n� foi visitado.
 * */
typedef struct arvore_huffman ArvoreHuff;

/* A fun��o newArvore recebe o valor do n�, representado por
 * um caracter, e dois ponteiros que apontam para a estrutura
 * do tipo arvore_huffman, ela retorna um ponteiro para uma
 * estrutura desse mesmo tipo. Essa fun��o tem como objetivo
 * criar um novo n� para a nossa arvore bin�ria.
 * */
ArvoreHuff * newArvore(unsigned char valor, ArvoreHuff *left, ArvoreHuff *right);

/* A fun��o pre_order recebe um ponteiro para uma estrutura do
 * tipo arvore_huffman, um ponteiro para um arquivo e
 * um ponteiro para o tamanho da �rvore. A fun��o retorna nulo
 * e tem como objetivo escrever a nossa arvore bin�ria no
 * arquivo recebido como par�metro.
 * */
void pre_order(ArvoreHuff *root, FILE *arquivo, int *tam);

/* A fun��o folha recebe um ponteiro para uma estrutura do
 * tipo arvore_huffman e retorna um inteiro, 1 ou 0, que
 * representa se o n� recebido como par�metro � uma folha
 * ou n�o, respectivamente.
 * */
int folha(ArvoreHuff *arvore);

/* A fun��o generate_tree recebe uma string, que representa
 * uma �rvore lida de um arquivo, e retorna um ponteiro para
 * uma estrutura do tipo arvore_huffman, que ser� a arvore
 * gerada a partir da string.
 * */
ArvoreHuff *generate_tree(unsigned char *preorder);

/* A fun��o getLeft recebe um ponteiro para uma estrutura do
 * tipo arvore_huffman, e retorna o ponteiro left, do
 * par�metro recebido.
 * */
ArvoreHuff *getLeft(ArvoreHuff *arvore);

/* A fun��o getRight recebe um ponteiro para uma estrutura do
 * tipo arvore_huffman, e retorna o ponteiro right, do
 * par�metro recebido.
 * */
ArvoreHuff *getRight(ArvoreHuff *arvore);

/* A fun��o getValor recebe um ponteiro para uma estrutura do
 * tipo arvore_huffman, e retorna um caracter que ser� o valor
 * do n� passado como par�metro.
 * */
unsigned char getValor(ArvoreHuff *arvore);

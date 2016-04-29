#include <stdio.h>

/* Definimos uma estrutura do tipo arvore_huffman, onde
 * ela contém um caracter, que será o nosso valor do nó,
 * dois ponteiros(left e right) que apontam para uma
 * estrutura do mesmo tipo(arvore_huffman), e um inteiro
 * que será usado para ver se o nó foi visitado.
 * */
typedef struct arvore_huffman ArvoreHuff;

/* A função newArvore recebe o valor do nó, representado por
 * um caracter, e dois ponteiros que apontam para a estrutura
 * do tipo arvore_huffman, ela retorna um ponteiro para uma
 * estrutura desse mesmo tipo. Essa função tem como objetivo
 * criar um novo nó para a nossa arvore binária.
 * */
ArvoreHuff * newArvore(unsigned char valor, ArvoreHuff *left, ArvoreHuff *right);

/* A função pre_order recebe um ponteiro para uma estrutura do
 * tipo arvore_huffman, um ponteiro para um arquivo e
 * um ponteiro para o tamanho da árvore. A função retorna nulo
 * e tem como objetivo escrever a nossa arvore binária no
 * arquivo recebido como parâmetro.
 * */
void pre_order(ArvoreHuff *root, FILE *arquivo, int *tam);

/* A função folha recebe um ponteiro para uma estrutura do
 * tipo arvore_huffman e retorna um inteiro, 1 ou 0, que
 * representa se o nó recebido como parâmetro é uma folha
 * ou não, respectivamente.
 * */
int folha(ArvoreHuff *arvore);

/* A função generate_tree recebe uma string, que representa
 * uma árvore lida de um arquivo, e retorna um ponteiro para
 * uma estrutura do tipo arvore_huffman, que será a arvore
 * gerada a partir da string.
 * */
ArvoreHuff *generate_tree(unsigned char *preorder);

/* A função getLeft recebe um ponteiro para uma estrutura do
 * tipo arvore_huffman, e retorna o ponteiro left, do
 * parâmetro recebido.
 * */
ArvoreHuff *getLeft(ArvoreHuff *arvore);

/* A função getRight recebe um ponteiro para uma estrutura do
 * tipo arvore_huffman, e retorna o ponteiro right, do
 * parâmetro recebido.
 * */
ArvoreHuff *getRight(ArvoreHuff *arvore);

/* A função getValor recebe um ponteiro para uma estrutura do
 * tipo arvore_huffman, e retorna um caracter que será o valor
 * do nó passado como parâmetro.
 * */
unsigned char getValor(ArvoreHuff *arvore);

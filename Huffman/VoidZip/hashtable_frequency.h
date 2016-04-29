#include <stdlib.h>
#include <string.h>

/* Essa estrutura cont�m um array de ponteiros para um node,
 * com o tamanho do n�mero m�ximo de caracteres
 * na tabela ASCII.
 * */
typedef struct hashtable HTable;

/*A fun��o initHTable n�o recebe nenhum par�metro, e retorna
 * um ponteiro inicializado de uma estrutura do tipo HTable.
 * */
HTable * initHTable();

/* A fun��o addCharBits recebe um ponteiro de uma estrutura
 * do tipo HTable, um caracter, e uma string representando
 * os bits desse caracter. N�o retorna nada, e tem como
 * objetivo inserir na hash table os bits do caracter
 * correspondente.
 * */
void addCharBits(HTable *table, unsigned char c, char *bits);

/* A fun��o getCharBits recebe um ponteiro de uma estrutura
 * do tipo HTable e um caracter, e retorna os bits que
 * representam esse caracter.
 * */
char *getCharBits(HTable *table, unsigned char c);

/* A fun��o getFrequencia recebe um ponteiro de uma estrutura
 * do tipo HTable e um inteiro que representa sua posi��o. A
 * fun��o retorna um inteiro que ser� a frequencia do caracter
 * correspondente a posi��o dada.
 * */
int getFrequencia(HTable *table, int posicao);

/* A fun��o addCFrequency recebe um ponteiro de uma estrutura
 * do tipo HTable e um caracter. N�o retorna nada, e tem como
 * objetivo aumentar a frequencia que esse caracter aparece
 * no nosso arquivo a ser compactado.
 * */
void addCFrequency(HTable *table, unsigned char c);

/* A fun��o getTamHTable n�o recebe nada, e retorna um inteiro
 * representando o n�mero m�ximo de elementos na hash table.
 * */
int getTamHTable();

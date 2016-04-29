#include <stdlib.h>
#include <string.h>

/* Essa estrutura contém um array de ponteiros para um node,
 * com o tamanho do número máximo de caracteres
 * na tabela ASCII.
 * */
typedef struct hashtable HTable;

/*A função initHTable não recebe nenhum parâmetro, e retorna
 * um ponteiro inicializado de uma estrutura do tipo HTable.
 * */
HTable * initHTable();

/* A função addCharBits recebe um ponteiro de uma estrutura
 * do tipo HTable, um caracter, e uma string representando
 * os bits desse caracter. Não retorna nada, e tem como
 * objetivo inserir na hash table os bits do caracter
 * correspondente.
 * */
void addCharBits(HTable *table, unsigned char c, char *bits);

/* A função getCharBits recebe um ponteiro de uma estrutura
 * do tipo HTable e um caracter, e retorna os bits que
 * representam esse caracter.
 * */
char *getCharBits(HTable *table, unsigned char c);

/* A função getFrequencia recebe um ponteiro de uma estrutura
 * do tipo HTable e um inteiro que representa sua posição. A
 * função retorna um inteiro que será a frequencia do caracter
 * correspondente a posição dada.
 * */
int getFrequencia(HTable *table, int posicao);

/* A função addCFrequency recebe um ponteiro de uma estrutura
 * do tipo HTable e um caracter. Não retorna nada, e tem como
 * objetivo aumentar a frequencia que esse caracter aparece
 * no nosso arquivo a ser compactado.
 * */
void addCFrequency(HTable *table, unsigned char c);

/* A função getTamHTable não recebe nada, e retorna um inteiro
 * representando o número máximo de elementos na hash table.
 * */
int getTamHTable();

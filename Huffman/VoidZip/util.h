#include <string.h>
#include <stdio.h>
#include <math.h>

/*A função setBit recebe um char que representará,
 * o byte que queremos alterar, e um inteiro i, que
 * representa qual bit queremos setar. A função retorna
 * um inteiro que será o valor do bit setado, e ela tem como
 * objetivo setar um bit especifico do nosso byte.
 * */
int setBit(unsigned char c, int i);

/* A função getBit recebe um char que representará
 * o byte que queremos analisar, e um inteiro i, que
 * representa qual bit queremos verificar desse byte.
 * A função retorna 0 para se o bit não estiver setado,
 * e 1 para se ele estiver setado.
 * */
int getBit(unsigned char c, int i);


/*A função initString recebe uma string e o seu tamanho,
 * não retorna nada, e tem como objetivo inicializar toda
 * a string com o caracter nulo.
 * */
void initString(char *s, int tam);

/* A função recebe uma string, um inteiro, representando
 * o número a ser convertido para binário, e a quantidade
 * de bits que ele deve ter. A função retorna vazio. E
 * tem como objetivo transformar o número inteiro passado
 * em binário.
 * */
void intToBin(char* bin, int num, int bits);

/*A função binToIin recebe uma string, que representa
 * um número binário, e um inteiro, que representa o tamanho
 * desse número, e retorna um inteiro que será esse número em
 * decimal.
 * */
int binToInt(char *bin, int tam);

/* A função escreverBitsArquivo recebe um arquivo, onde iremos
 * escrever, uma string de bits, e o tamanho dessa string. Não
 * retorna nada e tem como objetivo escrever no arquivo esses bits.
 * */
void escreverBitsArquivo(FILE *arquivo, char *bits, int tam);

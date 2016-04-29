#include <string.h>
#include <stdio.h>
#include <math.h>

/*A fun��o setBit recebe um char que representar�,
 * o byte que queremos alterar, e um inteiro i, que
 * representa qual bit queremos setar. A fun��o retorna
 * um inteiro que ser� o valor do bit setado, e ela tem como
 * objetivo setar um bit especifico do nosso byte.
 * */
int setBit(unsigned char c, int i);

/* A fun��o getBit recebe um char que representar�
 * o byte que queremos analisar, e um inteiro i, que
 * representa qual bit queremos verificar desse byte.
 * A fun��o retorna 0 para se o bit n�o estiver setado,
 * e 1 para se ele estiver setado.
 * */
int getBit(unsigned char c, int i);


/*A fun��o initString recebe uma string e o seu tamanho,
 * n�o retorna nada, e tem como objetivo inicializar toda
 * a string com o caracter nulo.
 * */
void initString(char *s, int tam);

/* A fun��o recebe uma string, um inteiro, representando
 * o n�mero a ser convertido para bin�rio, e a quantidade
 * de bits que ele deve ter. A fun��o retorna vazio. E
 * tem como objetivo transformar o n�mero inteiro passado
 * em bin�rio.
 * */
void intToBin(char* bin, int num, int bits);

/*A fun��o binToIin recebe uma string, que representa
 * um n�mero bin�rio, e um inteiro, que representa o tamanho
 * desse n�mero, e retorna um inteiro que ser� esse n�mero em
 * decimal.
 * */
int binToInt(char *bin, int tam);

/* A fun��o escreverBitsArquivo recebe um arquivo, onde iremos
 * escrever, uma string de bits, e o tamanho dessa string. N�o
 * retorna nada e tem como objetivo escrever no arquivo esses bits.
 * */
void escreverBitsArquivo(FILE *arquivo, char *bits, int tam);

#include"f_entrada.c"
/*
    faz a operação "sinal" entre os valores binarios V1 e V2
*/
char somaArvore(char V1,char V2, char sinal);

/*
    percorrer a avr2 ate achar uma folha com valor 1 ou 0 para chamar a função somaArvore com o valor achado
    junto com o valor de soma_arvore_part1
*/
void Apply_part2(Arvore** avr1,Arvore** avr2,Arvore* sinal);

/*
    percorrer a avr2 ate achar uma folha com valor 1 ou 0 e passa como parametro para soma_arvore_part2
*/
void Apply_part1(Arvore** avr1,Arvore** avr2,Arvore* sinal);

/*
    retira as tres arvores de cima da pilha, verifica se alguma não estar negada, efetuar um apply entre elas e retorna o resultado do apply
*/
void desempilharArvore(Pilha** Topo);

/*
    percorrer a string construindo com cada char uma arvore, node_não_folha, e desempilhando as arvores criadas com a
    função desempilharArvore que faz um apply com as arvores desempilhadas
*/
Arvore* Ler_entrada(char* entrada);

#include"arvore.cpp"

/*
    cria arvore com ponteiro NULL
*/

Arvore* criar_arvore();

/*
    cria um node que aponta somente para NULL
*/
Arvore* novo_node_folha(char valor);

/*
    cria um node que aponta para outros dois nodes com valores de 1 e 0
*/
Arvore* novo_node_nao_folha(char variavel);

/*
    pega todos os terminais de uma Arvore e negar seu valor
*/
void NegarArvore(Arvore* avr);

/*
    verifica se a Arvore não é uma folha
*/
int node_nao(Arvore* avr);

/*
    return o ponteiro da copia de  Arvore avr1
*/
Arvore* copiar_arvore(Arvore* avr1);



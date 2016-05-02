#include"f_booleanas.h"
#include"arvore.h"
#include"pilha.cpp"
#include"f_entrada.h"
int continuar=1;

/*
    inicializa uma pilha com um ponteiro NULL
*/
Pilha* criar_pilha();

/*
    empilha a arvore recebida na pilha
*/
Pilha* empilhar(Pilha* Topo, Arvore* avr);

/*
    coloca o de baixo do topo como novo topo e returna o antigo topo
*/
Pilha* desempilhar(Pilha** Topo);

/*
    returna o tamanho da pilha
*/
int tamanho_pilha(Pilha* Topo);


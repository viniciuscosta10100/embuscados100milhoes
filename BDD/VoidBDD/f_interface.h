#include"f_interface.cpp"

/*
    cria novos nodes com um ponteiro para um ponteiro de um node de avr e a prioridade que é a profundidade do node
*/
Nodes* criar_node(Arvore* avr,int prioridade);

/*
    adiciona um node na lista de nodes da BDD
*/
void put_Lista_nodesBDD(Nodes* node);

/*
    percorrer a BDD adicionando os nodes de cada node da BDD
*/
void put_Lista(Arvore* BDD);

/*
    desenha na screem uma linha entre a ponta de baixo do circulo com centro em p1 ate a parte de cima de um circulo com centro em p2
*/
void ligar_nodes(Local p1, Local p2,string cor);

/*
    calcula o lugar de cada node da lista_de_nodes de acordo com o tamanho da lista
*/
void preencher_locais();

/*
    desenha na screem os circulos representando os nodes da BDD
*/
void printar();

/*
    chama as funçoes que escrevem na screem
*/
void desenhar();


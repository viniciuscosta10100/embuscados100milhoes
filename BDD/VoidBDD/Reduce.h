#include"Reduce.cpp"

// criar os terminais 1 e 0 para efetuar o o reduce
Arvore* criar_terminal(char saida);

// chamar a funcao criar_terminal criando os dois terminais necessarios para o reduce
void iniciar_terminais();

// pega todos os nodes com variaveis 1 e 0 libera o node e returna algum dos terminais, de acordo com valor do node
Arvore* C1(Arvore* BDD);

// returna 1 se  arvore node1 igual arvore node2 caso contrario returna 0
int comparar_nodes(Arvore* node1,Arvore* node2);

/*
busca um node igual ao node recebido em uma lista de nodes visitados,
caso nao ache adiciona o node na lista e returna o node, caso ache retorna o node achado
*/
Arvore* BuscarNodeLista(Arvore* node);

/* se os ponteiros esq e dir de um node da BDD apontar para o mesmo node ele libera
 o node e returna o ponteiro esq do node para quem apontava para o node
*/
Arvore* C3(Arvore* BDD);

/* ele procura na BDD outro semi arvore indentico de cada node da BDD caso ache libera uma das sub arvores e return a outra
*/
Arvore* C2(Arvore* node);



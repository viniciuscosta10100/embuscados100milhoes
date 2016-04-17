/*
 essa fun��o faz um free em todos os no de uma sub_arvore
 */
 void liberar_node(struct arvore* node);


/*
essa fun��o compara dois nodes casos sejam iguais retorn 1 caso n�o retorna 0
*/
int comparar_nodes(struct arvore* node1,struct arvore* node2);



/*
    essa fun��o inicializa os terminais do ROBDD terminal 1 e terminal 0,
    recebe o valor do terminal, 1 ou 0 ,e retorna uma ponteiro para um struct arvore
*/
struct arvore* criar_terminal(char saida);



/*
    essa fun��o pega as variavis globais verdadeiro e falso e chamar a fun��o criar_terminal para casa uma delas
*/
void iniciar_terminais();



/*
    essa fun��o faz uma busca na lista_node, que � uma lista que salva nodes ja pesquisados, essa fun��o
    compara, usando a fun��o comparar_nodes, um node recebido com os nodes ja salvos na lista_node, casos ela encontre um node igual ela retorna
    este um ponteiro para o node igual , caso n�o encontre o node recebido � adicionado na lista_node e a fun��o retorna o node recebido
    o node recebido recebe o retorno desta fun��o ou seja caso ele encontre um node igual eliminamos o node e retonamos o node igual a ele
*/
struct arvore* BuscarNodeLista(struct arvore* node);



/*
    essa fun��o faz com que todos os terminais apontem para os terminais verdadeiro e falso inicializados na fun��o iniciar_terminais
*/
struct arvore* RTD(struct arvore* BDD);



/*
essa fun��o remove nodes da BDD que sejam iguais, usa-se as fun�oes buscarNodeLista e comparar_nodes
*/
struct arvore* RnTD(struct arvore* BDD); ///remover n�o-terminais duplicados



/*
essa fun��o verifica se o node->esq e node->dir aponta para o mesmo node caso sim ela elimina o node e retorna o node->esq
*/
struct arvore* RTR(struct arvore* node);//remover testes reduntantes



/*
essa fun��o percorrer o BDD diarcordo com valores salvos na hash "valores" e retorna o resultado da expre��o boolenada representada pelo BDD
*/
char percorrer_ROBDD(struct arvore* BDD);



/*
nesta fun��o vc passar os valores das variaveis da expre��o representada pelo BDD
e ela imprimi o resultado da expre��o com valores passador pelo usuario
*/
int usar_ROBDD(struct arvore* BDD);



/*
essa fun��o imprimi em pre ordem o BDD, n�o imprimindo nodes ja visitados
*/
void imprimir(struct arvore* node);



/* as fun�oes abaixo semvem pra receber uma string no formato de parentses e tranforma em uma arvore,
ainda estou motificando essas pois foram reaproveitadas do the huxley,
*/
char string_to_int(char* texto,int inicio,int fim);

struct arvore* criar_arvore(string stg_arvore);



#include<bits/stdc++.h>
#ifndef NULL
#define NULL   ((void *) 0)
#endif

using  namespace std;
std::vector<struct arvore*> lista_node;//
std::map<char,int> variaveis;
std::map<char,int> valores;
map<int,int> hash_table;
int inicio=0;

struct arvore{
    char valor;
    struct arvore* esq;
    struct arvore* dir;
};
struct arvore* verdadeiro;
struct arvore* falso ;

struct arvore* criar_terminal(char saida){//criar terminais do tipo 1 e 0
    struct arvore* terminal = (struct arvore*) malloc(sizeof(struct arvore));
    terminal->valor=saida;
    terminal->dir=NULL;
    terminal->esq=NULL;
    return terminal;
}
void iniciar_terminais(){
     verdadeiro=criar_terminal('1');
     falso = criar_terminal('0');
}
struct arvore* RTD(struct arvore* BDD){//remover terminais duplicados

    if(BDD->valor!='1'&&BDD->valor!='0'){
            BDD->esq=RTD(BDD->esq);
            BDD->dir=RTD(BDD->dir);
            return BDD;
    }
    else if(BDD->valor=='1'){
        free(BDD);
        return verdadeiro;
    }
    else if(BDD->valor=='0'){
        free(BDD);
        return falso;
    }
}
void liberar_node(struct arvore* node){
    if(node!=NULL){
        liberar_node(node->esq);
        liberar_node(node->dir);
        free(node);
    }
}
int comparar_nodes(struct arvore* node1,struct arvore* node2){
    if(node1!=NULL||node2!=NULL){
        if(node1!=NULL&&node2!=NULL){
            if(node1->valor==node2->valor){
                return comparar_nodes(node1->esq,node2->esq) & comparar_nodes(node1->dir,node2->dir);
            }
        }
        return 0;
    }
    return 1;
}

struct arvore* BuscarNodeLista(struct arvore* node){
    vector<struct arvore*>::iterator it=lista_node.begin();
    for(it;it!=lista_node.end();++it){
        if(comparar_nodes(node,*it)){
            return *it;
        }
    }
    lista_node.push_back(node);
    return node;
}
struct arvore* RnTD(struct arvore* BDD){ ///remover não-terminais duplicados
    if(BDD!=NULL){
        struct arvore* aux;
        aux=BuscarNodeLista(BDD);//verificar se ja não teve um node igual ao BDD e o retorna se não retotorna o BDD
        if(aux!=BDD){
           // liberar_node(BDD);
            return aux;
        }
        BDD->esq=RnTD(BDD->esq);
        BDD->dir=RnTD(BDD->dir);
        return BDD;
    }
}
struct arvore* RTR(struct arvore* node){//remover testes reduntantes
    if(node!=verdadeiro&&node!=falso){
        if(node->esq==node->dir)
            return node->esq;
        else{
            node->esq=RTR(node->esq);
            node->dir=RTR(node->dir);
            return node;
        }
    }
}
char percorrer_ROBDD(struct arvore* BDD){
    if(BDD!=verdadeiro&&BDD!=falso){
        if(valores[BDD->valor]==1)
                return percorrer_ROBDD(BDD->dir);
        else if(valores[BDD->valor]==0)
                return percorrer_ROBDD(BDD->esq);
        else
            printf("erro de valores na variaveis\n");
    }
    else {
        return BDD->valor;
    }
}
void usar_ROBDD(struct arvore* BDD){
    int aux;
    char aux2;
    map<char,int>::iterator it;
    printf("encontrar valores com ROBDD criado? S/N");
    scanf("%c",&aux2);
    while(aux2=='S'){
        for(it=variaveis.begin();it!=variaveis.end();++it){
            printf("valor de %c?\n", it->first);
            scanf("%d",&aux);
            valores[it->first]=aux;
        }
        printf("resultado %c\n",percorrer_ROBDD(BDD));
        valores.clear();
        printf("encontrar valores com ROBDD criado? S/N");
        getchar();
        scanf("%c",&aux2);
    }
}
void aux_imprimir(struct arvore* node)
{
    if(node!=NULL){
            if(hash_table[(int)node]==1){
               // printf("ja foi %c ",n->valor);
               // printf("ponteiros: %d\n",node);
            }
            else{
                printf("%c ",node->valor);
                aux_imprimir(node->esq);
                aux_imprimir(node->dir);
                hash_table[(int)node]=1;
            }
        }
}
void imprimir(struct arvore* node){
    hash_table.clear();//hash usada na função imprimir
    aux_imprimir(node);
}
char string_to_int(string texto,int inicio,int fim){
    if(fim-inicio>1)
        printf("erro de tamanho de variavel\n");

    if(texto[inicio]!='1'&&texto[inicio]!='0')
       variaveis[texto[inicio]]=1;

    return texto[inicio];
}
struct arvore* criar_arvore(string stg_arvore){
    int s1,s2,valor;
    struct arvore* avr=NULL;
    while(stg_arvore[inicio]==' ')
        inicio++;
    if(stg_arvore[inicio]!='(')
        printf("%d erro de entrada, formato estranho\n",inicio);
    inicio++;
    if(stg_arvore[inicio]!=')'){
        s1=inicio;
        while(stg_arvore[inicio]!='(')
            inicio++;
        s2=inicio-1;
        valor=string_to_int(stg_arvore,s1,s2);
        avr=(struct arvore*) malloc(sizeof(struct arvore));
        avr->valor=valor;
        avr->esq=criar_arvore(stg_arvore);
        avr->dir=criar_arvore(stg_arvore);
        inicio++;
    }
    else
        inicio++;
    return avr;
}

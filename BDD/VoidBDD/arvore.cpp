
typedef struct arvore{
    char variavel;
    struct arvore* esq;
    struct arvore* dir;

}Arvore;
Arvore* criar_arvore()
{
    return NULL;
}
Arvore* novo_node_folha(char valor){

    Arvore* aux = (Arvore*) malloc(sizeof(Arvore));
    aux->variavel=valor;
    aux->dir=NULL;
    aux->esq=NULL;
    return aux;
}
Arvore* novo_node_nao_folha(char variavel)
{
    Arvore* aux=novo_node_folha(variavel);
    aux->dir=novo_node_folha('1');
    aux->esq=novo_node_folha('0');
    return aux;
}
void imprimir_preOrdem(Arvore* avr)
{
    if(avr!=NULL)
    {
        printf("%c ",avr->variavel);
        imprimir_preOrdem(avr->esq);
        imprimir_preOrdem(avr->dir);
    }
}
void NegarArvore(Arvore* avr){
    if(avr!=NULL)
    {
        if(avr->variavel=='1'||avr->variavel=='0')
            avr->variavel=Negar(avr->variavel);
        else{
            NegarArvore(avr->esq);
            NegarArvore(avr->dir);
        }
    }
}
int node_nao(Arvore* avr)
{
    if(avr->variavel=='~')
        return 1;
    return 0;
}
struct arvore* copiar_arvore(Arvore* avr1)
{
    if(avr1!=NULL){
            Arvore* aux = novo_node_folha(avr1->variavel);
            aux->esq=copiar_arvore(avr1->esq);
            aux->dir=copiar_arvore(avr1->dir);
            return aux;
    }
}

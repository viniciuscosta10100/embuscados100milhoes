
struct fila_prioridade
{
    int prioridade;
    char variavel;
    struct fila_prioridade* prox;
};
void imprimir_fila(struct fila_prioridade* aux)
{
    while(aux!=NULL)
    {
        printf("(%c -> %d)",aux->variavel,aux->prioridade);
        aux=aux->prox;
    }
}
struct fila_prioridade* novo_node_fila()
{
    return (struct fila_prioridade*) malloc(sizeof(fila_prioridade));
}
struct fila_prioridade*  put(struct fila_prioridade* fila, char variavel, int prioridade){

    struct fila_prioridade* novo=novo_node_fila();

    struct fila_prioridade* aux=fila;

    novo->variavel=variavel;

    novo->prioridade=prioridade;
    struct fila_prioridade* anterior=NULL;
    //printf("antes do while\n");
    if(fila!=NULL&&prioridade <= fila->prioridade){
        while(fila!=NULL&&prioridade <= fila->prioridade)
        {
            anterior=fila;
            fila=fila->prox;
        }
        anterior->prox=novo;
        novo->prox=fila;
    }
    else{
        novo->prox=fila;
        return novo;
    }
    return aux;
}
int prioridade_buffer=0;
struct fila_prioridade* leitura(struct fila_prioridade* myfila,struct arvore* BDD)
{
    if(BDD!=NULL)
    {
        myfila=put(myfila,BDD->variavel,prioridade_buffer);
        prioridade_buffer++;
        myfila=leitura(myfila,BDD->esq);
        myfila=leitura(myfila,BDD->dir);
        prioridade_buffer--;
        return myfila;
    }
}
void imprimir_em_largura(Arvore* BDD)
{
     struct fila_prioridade* mfila=NULL;
     mfila=leitura(mfila,BDD);

    imprimir_fila(mfila);
}


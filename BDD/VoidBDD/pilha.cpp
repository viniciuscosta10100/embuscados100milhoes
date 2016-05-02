
typedef struct pilha{

    struct arvore* avr;
    struct pilha* debaixo;
}Pilha;
Pilha* criar_pilha(){

        return NULL;
}
Pilha* empilhar(Pilha* Topo, Arvore* avr)
{
    Pilha* novo_topo = (Pilha*) malloc(sizeof(Pilha));
    novo_topo->debaixo=Topo;
    novo_topo->avr=avr;
    return novo_topo;
}
Pilha* desempilhar(Pilha** Topo){

    Pilha* aux= *Topo;
    *Topo=(*Topo)->debaixo;

    if(*Topo!=NULL)
    if(node_nao(  (*Topo)->avr)  ){
        NegarArvore(aux->avr);
        *Topo=(*Topo)->debaixo;
    }
    return aux;
}
int tamanho_pilha(Pilha* Topo)
{
    int i=0;
    while(Topo!=NULL)

    {
        i++;
        Topo=Topo->debaixo;
    }
    return i;
}
